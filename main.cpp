#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

struct nod {
    struct nod *left;
    char data;
    struct nod *right;
};

typedef struct nod NOD;
typedef NOD TREE;

NOD *NewNode(char item) {
    NOD *n;
    n = (NOD*) malloc(sizeof(NOD));
    if(n != NULL) {
        n->data = item;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void BuildTree(TREE **T) {
    *T = NULL;
}

typedef enum {FALSE = 0, TRUE = 1} BOOL;

BOOL EmptyTree(TREE *T) {
    return ((BOOL) (T == NULL));
}

void AddNode(NOD **p, char item) {
    NOD *n;
    n = NewNode(item);
    *p = n;
}

void PreOrder(TREE *T) {
    if(!EmptyTree(T)) {
        printf(" %c ", T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(TREE *T) {
    if(!EmptyTree(T)) {
        InOrder(T->left);
        printf(" %c ", T->data);
        InOrder(T->right);
    }
}

void PostOrder(TREE *T) {
    if(!EmptyTree(T)) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf(" %c ", T->data);
    }
}

int main()
{
    TREE *kelapa;
    char buah;
    BuildTree(&kelapa);
    AddNode(&kelapa, buah = 'A');
    AddNode(&kelapa->left, buah = 'B');
        AddNode(&kelapa->left->left, buah = 'D');
            //AddNode(&kelapa->left->left->left, 'H');
            //AddNode(&kelapa->left->left->right, 'I');
        AddNode(&kelapa->left->right, buah = 'E');
            //AddNode(&kelapa->left->right->left, 'J');
            //AddNode(&kelapa->left->right->right, 'K');
    AddNode(&kelapa->right, 'C');
        AddNode(&kelapa->right->left, 'F');
        AddNode(&kelapa->right->right, buah = 'G');
    printf("Urutan secara PreOrder : ");
    PreOrder(kelapa);
    printf("\nUrutan secara InOrder : ");
    InOrder(kelapa);
    printf("\nUrutan secara PostOrder : ");
    PostOrder(kelapa);
    return 0;
}
