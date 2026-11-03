#include <iostream>

// Nous allons implémenter une pile d'entiers de manière très basique.
// Nous la complexifierons par la suite.

// La pile est constituée :
//   - d'un tableau d'entier (stack), avec sa taille (size)
//   - du nombre des d'éléments empilés (top)
//     ce qui vous donne l'indice du prochain élément à empiler
//   - des fonctions :
//     - push (empile un élément dans la pile)
//     - pop (renvoie l'élement en haut de la pile
//            et considère que cet élément n'est plus dans la pile)
//     - print (affiche les éléments empilés) [ 12 67 23 [
// Les cas d'erreur :
//     - is_empty (teste si la pile est vide :
//                 on ne dépile pas une pile vide)
//     - is_full (testent si la pile est pleine
//                on n'empile pas sur une pile pleine)
//    en cas d'erreur pour l'instant on ne fait pas l'opération
//    (notre pile est potentiellement fausse avec des éléments non empilés et/ou non dépilés)

// Voici les entêtes des fonctions où vous devez passer les arguments :

void print(int stack[], int top)
// cette fonction affiche les entiers empilés
// elle a besoin de la pile et du nombre d'éléments empilés
{
for (int i=0; i<top;i++){
    std::cout<<stack[i]<<" ";
}
}

// renvoie true si la pile est vide, false sinon
bool is_empty(int  top)
{
    return top==0;
     // pour compiler/exécuter l'exemple
}

// renvoie true si la pile est pleine, false sinon
bool is_full(int size, int top)
{
    return size == top ;
     // pour compiler/exécuter l'exemple
}

void push(int stack [], int e, int size, int& top) // e est l'élément à empiler
// cette fonction ajoute un entier à la pile passé en argument
// elle vérifie que la pile n'est pas pleine avant d'empiler
// et ne fait rien sinon
{
    if (is_full(size,top)==false){
        stack[top]=e;
        top++;
    }
}

int pop(int stack[], int& top) // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
{
    if (is_empty(top)==false){
        top--;
        return stack[top];
    }
    return -9999; // pour compiler/exécuter l'exemple

}

int* create_stack(int n){
    return new int[n];
}

void delete_stack(int* t){
        delete [] t;
    }

struct IntStack{
    int size;
    int top;
    int* stack;
    IntStack (int s){
        size = s;
        top = 0;
        stack = new int[size];
    }
    void push(int e){
    if (not is_full()){
        stack[top]=e;
        top++;
    }
    }

    int pop(){
    if (not is_empty()){
        top--;
        return stack[top];
    }
    return -9999;
    }

    void print(){
        for (int i=0; i<top;i++){
        std::cout<<stack[i]<<" ";
        }
    }
    
    bool is_empty(){
    return top==0;
    }

    bool is_full(){
    return size == top ;
    }
};


int main()
{
    
    // on définit ici les 3 variables qui constituent la pile
    //int size = 12;
    //int* stack=create_stack(size);
    //int top = 0;
    //=>
    IntStack st(12);

    st.print(); // affiche [ [
    st.push(-17);
    st.print(); // affiche [ -17 [

    // on affiche l'élément en haut de pile
    std::cout << st.pop() << std::endl; // affiche -17

    st.push(28);
    st.push(62);

    st.print(); // affiche [ 28 62 [

    int e = st.pop();
    std::cout << e << std::endl; // affiche 62

    st.print();                         // affiche [ 28 [
    std::cout << st.pop() << std::endl; // affiche 28
    st.pop();                           // affiche cannot pop, the stack is empty
    // à partir d'ici la stack n'est plus correcte :
    //    l'utilisateur croit avoir un élément à dépiler or il n'en a pas...
    //    on verra les exceptions qui avertissent l'utilisateur d'un problème
    return 0;
}