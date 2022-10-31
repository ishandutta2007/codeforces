#include <cstdio>
#include <cstdlib>
#include <iostream>
typedef unsigned long long int ull;
using namespace std;
struct node{
    ull data;
    node *child[2];
    node(){
        data = 0;
        child[0] = child[1] = NULL;
    }
};
ull ary[100010], ans = 0, sum = 0;
node *root;

void insert(node *n, ull num){
    int bit[50];
    node *now = n;
    for(int i = 0; i <= 40; ++i)
        bit[i] = 1 & (num >> i);
    for(int i = 40; i>= 0; --i){
        int x = bit[i];
        if(now->child[x]==NULL)
            now->child[x] = new node;
        now = now-> child[x];
    }
    now->data = num;
}

ull query(node *n, ull num){
    int bit[50];
    node *now = n;
    for(int i = 0; i<=40; ++i)
        bit[i] = 1 & (num >> i);
    for(int i = 40; i>=0; --i){
        int x = bit[i];
        if(now->child[1^x]!=NULL) now = now->child[1^x];
        else now = now->child[x];
    }
    return num^(now->data);
}

int main(){
    root = new node;
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> ary[i];
        sum ^= ary[i];
        ans = max(ans, sum);
        insert(root, sum);
    }
    sum = 0;
    for(int i = n-1; i>=0; --i){
        sum ^= ary[i];
        ans = max(ans, query(root, sum));
    }
    cout << ans << endl;
    return 0;
}