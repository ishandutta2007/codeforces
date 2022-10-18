#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

int Q;
#define TOT 28
int Trie[3000005][2], tot;
int f[3000005];
inline void modify(int x, int val){
    int rt = 0;
    for (int i = TOT;i >= 0;i --){
        int num = (1 << i);bool ck = (num & x);
        if(!Trie[rt][ck]) Trie[rt][ck] = ++ tot;
        rt = Trie[rt][ck];
        f[rt] += val;
        // printf("rt = %d, i = %d, ck = %d\n", rt, i, ck);
    }
}

inline int query(int x, int tar){
    int rt = 0, ret = 0;
    for (int i = TOT;i >= 0;i --){
        int num = (1 << i);bool ck1 = (num & x), ck2 = (num & tar);
        if(ck2) ret += f[Trie[rt][ck1]];
        if(!Trie[rt][ck1 ^ ck2]) break;
        rt = Trie[rt][ck1 ^ ck2];
        // printf("i = %d, ck1 = %d, ck2 = %d, rt = %d\n", i, ck1, ck2, rt);
    }
    return ret;
}

int main(){
    read(Q);
    while(Q --){
        int opt, x, y;
        read(opt);
        if(opt == 1) read(x), modify(x, 1);
        if(opt == 2) read(x), modify(x, -1);
        if(opt == 3) read(x), read(y), fprint(query(x, y), 10);
    }
}