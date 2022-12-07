#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Trie {
    Trie* bit[2];
    int cnt = 0;
    int data = -1;
    Trie* parent; 
    int b;
};
Trie* root;

void insert(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n>>(30-i)) & 1;
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
            temp->bit[b]->parent = temp;
            temp->bit[b]->b = b;
        }
        temp->cnt++;
        temp = temp->bit[b];
    }
    temp->cnt++;
    temp->data = n;
}

void erase(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n>>(30-i)) & 1;
        temp = temp->bit[b];
    }
    Trie* par = root;
    while(temp!=root) {
        temp->cnt--;
        par = temp->parent;
        if(temp->cnt == 0) {
            par->bit[temp->b] = nullptr;
        }
        temp = par;
    }
    temp->cnt--;
}

int max_xor(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n>>(30 - i)) & 1;
        if(!temp->bit[!b]) {
            temp = temp->bit[b];
        }
        else temp = temp->bit[!b];
    }
    return n^(temp->data);
}

int main() {
    root = new Trie();
    root->parent = root;
    insert(0);
    int n; 
    char a; int x;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        scanf("%c%d\n", &a, &x);
        if(a=='+') insert(x);
        if(a=='-') erase(x);
        if(a=='?') printf("%d\n", max_xor(x));
    }
    return 0;
}