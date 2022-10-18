#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

int n, fa[200005], rt;
vector <int> son[200005];

int sz[200005];

void build(int x){
    sz[x] = 1;
    for (register int i = 0;i < son[x].size();i ++){
        int e = son[x][i];
        build(e);
        sz[x] += sz[e];
    }
}

void destory(int x){
    for (register int i = 0;i < son[x].size();i ++){
        int e = son[x][i];
        if(!(sz[e] & 1)) destory(e);
    }
    fprint(x, 10);
    for (register int i = 0;i < son[x].size();i ++){
        int e = son[x][i];
        if(sz[e] & 1) destory(e);
    }
}

int main(){
    read(n);
    if(!(n & 1)) return printf("NO\n"), 0;
    printf("YES\n");
    for (register int i = 1;i <= n;i ++){
        read(fa[i]);
        if(!fa[i]) rt = i;
        else son[fa[i]].push_back(i);
    }
    build(rt);
    destory(rt);
}