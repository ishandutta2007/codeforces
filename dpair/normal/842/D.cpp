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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

#define MAXN 300005

int n, q, t;
int a[MAXN], vis[MAXN];

int Trie[MAXN * 33][2], tot, val[MAXN * 33];

inline void ins(int x){
    int rt = 0;
    // printf("ins x = %d\n", x);
    for (register int i = 20;i >= 0;i --){
        int num = (1 << i);bool ck = num & x;
        if(!Trie[rt][ck]) Trie[rt][ck] = ++ tot;
        rt = Trie[rt][ck];
        val[rt] ++;
        // printf("i = %d, rt = %d, val ++\n", i, rt);
    }
}

inline int query(){
    int rt = 0, res = 0;
    for (register int i = 20;i >= 0;i --){
        int num = (1 << i);bool ck = num & t;
        // printf("i = %d, rt = %d, ck = %d, res = %d\n", i, rt, ck, res);
        if(val[Trie[rt][ck]] < (1 << i)){
            rt = Trie[rt][ck];
            if(!rt) return res;
        }
        else{
            rt = Trie[rt][ck ^ 1];
            res |= (1 << i);
            if(!rt) return res;
        }
    }
    return res;
}

int main(){
    read(n);read(q);
    for (register int i = 1;i <= n;i ++) {
        read(a[i]);
        if(vis[a[i]]) continue;
        vis[a[i]] = 1;
        ins(a[i]);
    }
    while(q --){
        int x;read(x);
        t ^= x;
        fprint(query(), 10);
    }
}