#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

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

int head[MAXN], cnt, nxt[MAXN << 1], e[MAXN << 1];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int val[MAXN], sz[MAXN], n, ans = -0x3f3f3f3f, res;
char a[MAXN];
int Trie[MAXN][31];

inline int merge(int u, int v){
    if(!Trie[u][a[v] - 'a']) {
        Trie[u][a[v] - 'a'] = v;
        return 0;
    }
    else{
        int ret = 1;
        for (register int i = 0;i < 26;i ++){
            if(Trie[v][i]) ret += merge(Trie[u][a[v] - 'a'], Trie[v][i]);
        }
        return ret;
    }
}

void dfs(int x, int pre){
    sz[x] = 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
        sz[x] += sz[e[i]];
        sz[x] -= merge(x, e[i]);
    }
    if(sz[x] + val[x] > ans){
        ans = sz[x] + val[x];
        res = 1;
    }
    else{
        if(sz[x] + val[x] == ans){
            res ++;
        }
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(val[i]);
    scanf("%s", a + 1);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    fprint(ans, 10);fprint(res, 10);
}