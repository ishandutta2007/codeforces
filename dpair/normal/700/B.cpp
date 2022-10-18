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

int n, m;

int head[200005], nxt[400005], cnt, e[400005];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int b[200005];
typedef long long LL;
LL ans = 0;
void dfs(int x, int pre){
    for (register int i = head[x];i;i = nxt[i]){
        if(pre == e[i]) continue;
        dfs(e[i], x);
        ans = ans + min(b[e[i]], (m << 1) - b[e[i]]);
        b[x] += b[e[i]];
    }
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= m;i ++){
        int x;read(x);b[x] = 1;
        read(x);b[x] = 1;
    }
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    fprint(ans, 10);
    return 0;
}