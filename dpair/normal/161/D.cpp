#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 50005

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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
int n, m, ans;
int head[MAXN], cnt, nxt[MAXN << 1], e[MAXN << 1];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
bool vis[MAXN];
int sz[MAXN], SZ[MAXN];

void get_size(int x, int pre){
    sz[x] = 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre || vis[e[i]]) continue;
        get_size(e[i], x);
        sz[x] += sz[e[i]];
    }
}
int root = 0;

void get_root(int x, int pre, int rt){
    SZ[x] = 0;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre || vis[e[i]]) continue;
        get_root(e[i], x, rt);
        chmax(SZ[x], sz[e[i]]);
    }
    chmax(SZ[x], sz[rt] - sz[x]);
    if(!root || SZ[x] < SZ[root]) root = x;
}

int dis[MAXN];
stack <int> stk, mem, ss;
void get_dis(int x, int pre){
    if(dis[x] <= m) stk.push(dis[x]);
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre || vis[e[i]]) continue;
        dis[e[i]] = dis[x] + 1;
        get_dis(e[i], x);
    }
}
int app[505];
int q[MAXN];
inline void calc(int x){
    for (register int i = head[x];i;i = nxt[i]){
        if(vis[e[i]]) continue;
        dis[e[i]] = 1;
        get_dis(e[i], x);
        while(!stk.empty()){
            int tp = stk.top();
            mem.push(tp);
            if(m < tp) continue;
            if(m == tp) ans ++;
            ans += app[m - tp];
            ss.push(tp);
            stk.pop();
        }
        while(!ss.empty()) app[ss.top()] ++, ss.pop();
    }
    while(!mem.empty()) app[mem.top()] --, mem.pop();
}

void dfz(int x){
    vis[x] = 1;calc(x);
    for (register int i = head[x];i;i = nxt[i]){
        if(vis[e[i]]) continue;
        get_size(e[i], x);
        root = 0;
        get_root(e[i], x, e[i]);
        dfz(root);
    }
}

int main(){
    read(n);read(m);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    get_size(1, 0);
    root = 0;
    get_root(1, 0, 1);
    dfz(root);
    fprint(ans, 10);
    return 0;
}