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

int n;
bitset <1000005> f, ans;
int lc[1000005], rc[1000005], t[1000005];// and 1, or 2, xor 3, not 4, in 5
char ch[15];

void dfs1(int x){
    if(~lc[x]) dfs1(lc[x]);
    if(~rc[x]) dfs1(rc[x]);
    if(t[x] == 5) return ;
    if(t[x] == 1) f[x] = f[lc[x]] && f[rc[x]];
    if(t[x] == 2) f[x] = f[lc[x]] || f[rc[x]];
    if(t[x] == 3) f[x] = f[lc[x]] ^ f[rc[x]];
    if(t[x] == 4) f[x] = !f[lc[x]];
}

void dfs2(int x){
    if(t[x] == 5) {ans[x] = 1;return ;}
    if(t[x] == 1){
        if((f[lc[x]] && f[rc[x]]) ^ ((!f[lc[x]]) && f[rc[x]])) dfs2(lc[x]);
        if((f[lc[x]] && f[rc[x]]) ^ ((!f[rc[x]]) && f[lc[x]])) dfs2(rc[x]);
    }
    if(t[x] == 2){
        if((f[lc[x]] || f[rc[x]]) ^ ((!f[lc[x]]) || f[rc[x]])) dfs2(lc[x]);
        if((f[lc[x]] || f[rc[x]]) ^ ((!f[rc[x]]) || f[lc[x]])) dfs2(rc[x]);
    }
    if(t[x] == 3){dfs2(lc[x]);dfs2(rc[x]);}
    if(t[x] == 4){dfs2(lc[x]);}
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        scanf("%s", ch);
        lc[i] = rc[i] = -1;
        if(ch[0] == 'A'){
            t[i] = 1;
            read(lc[i]);read(rc[i]);
        }
        if(ch[0] == 'O'){
            t[i] = 2;
            read(lc[i]);read(rc[i]);
        }
        if(ch[0] == 'X'){
            t[i] = 3;
            read(lc[i]);read(rc[i]);
        }
        if(ch[0] == 'N'){
            t[i] = 4;
            read(lc[i]);
        }
        if(ch[0] == 'I'){
            t[i] = 5;int x;read(x);f[i] = x;
        }
    }
    dfs1(1);dfs2(1);
    for (register int i = 1;i <= n;i ++){
        if(t[i] == 5){
            fprint(ans[i] ^ f[1]);
        }
    }
    putchar(10);
}