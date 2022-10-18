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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
#define MAXN 100005
int n;
const int block = 1302;
int head[MAXN], nxt[MAXN << 1], e[MAXN << 1], cnt;
int ans[MAXN];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int dep[MAXN], res;
void dfs(int x, int &val){
    int fst = 0, sec = 0;
    for (register int i = head[x];i;i = nxt[i]){
        // if(e[i] == pre) continue;
        dfs(e[i], val);
        if(dep[e[i]] > fst){
            sec = fst;
            fst = dep[e[i]];
        } 
        else if(dep[e[i]] > sec){
            sec = dep[e[i]];
        }
    }
    if(fst + sec + 1 >= val){
        res ++;
        dep[x] = 0;
        return ;
    }
    dep[x] = fst + 1;
}
int mem[MAXN];
inline int getans(int x){
    if(~mem[x]) return mem[x];
    res = 0;
    dfs(1, x);
    return mem[x] = res;
}
vector <int> dd[MAXN];
void init(int x, int pre){
    for (register int i = 0;i < dd[x].size();i ++){
        if(dd[x][i] == pre) continue;
        add(x, dd[x][i]);
        init(dd[x][i], x);
    }
}

int main(){
    memset(mem, -1, sizeof(mem));
    read(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        dd[u].push_back(v);
        dd[v].push_back(u);
    }
    init(1, 0);
    for (register int i = 1;i <= block;i ++) ans[i] = getans(i);
    int L = block + 1;
    while(L <= n){
        int num = getans(L);
        if(!num) break;
        int l = L, r = n, R = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getans(mid) == num) R = mid, l = mid + 1;
            else r = mid - 1;
        }
        for (register int i = L;i <= R;i ++) ans[i] = num;
        L = R + 1;
    }
    for (register int i = 1;i <= n;i ++) fprint(ans[i], 10);
}