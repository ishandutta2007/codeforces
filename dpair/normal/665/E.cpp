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

int Trie[40000005][2], tot, k;
int val[40000005];
inline void ins(int x){
    int rt = 0;
    for (register int i = 30;i >= 0;i --){
        int num = (1 << i);bool ch = num & x;
        if(!Trie[rt][ch]) Trie[rt][ch] = ++ tot;
        rt = Trie[rt][ch];
        val[rt] ++;
    }
}
long long ans = 0;
inline int query(int x){
    int rt = 0, ret = 0, bruh = 0;
    for (register int i = 30;i >= -1;i --){
        if(!~i) {bruh = 1;break;}
        int num = (1 << i);bool ch = num & x, ck = num & k;
        // printf("i = %d, rt = %d, ch = %d, ck = %d, ret = %d\n", i, rt, (int)ch, (int)ck, ret);
        if(!ck){
            ret += val[Trie[rt][ch ^ 1]];
            if(!Trie[rt][ch]) break;
            rt = Trie[rt][ch];
        }
        else{
            if(!Trie[rt][ch ^ 1]) break;
            rt = Trie[rt][ch ^ 1];
        }
    }
    // printf("ret = %d, rt = %d, val[rt] = %d\n", ret, rt, val[rt]);
    return ret + val[rt] * bruh;
}
int n, a, pre;
int main(){
    read(n);read(k);
    ins(0);
    for (register int i = 1;i <= n;i ++){
        int x;read(x);x ^= pre;
        ans += query(x);ins(x);
        pre = x;
        // fprint(ans, 10);
    }
    fprint(ans, 10);
    return 0;
}