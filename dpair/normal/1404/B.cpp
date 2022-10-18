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
int n, a, b, da, db;
int head[100005], nxt[200005], cnt, e[200005];
int dep[100005];
inline void init(){
    memset(head, 0, sizeof(head));
    cnt = 0;
}
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int depth;

void dfs(int x, int pre){
    if(dep[x] > dep[depth]) depth = x;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + 1;
        dfs(e[i], x);
    }
}

inline void work(){
    init();
    read(n);read(a);read(b);read(da);read(db);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dep[a] = 0;depth = 0;
    dfs(a, 0);
    if(dep[b] <= da){
        printf("Alice\n");
        return ;
    }
    dep[depth] = 0;
    dfs(depth, 0);
    db = min(db, dep[depth]);
    if(db <= (da << 1)) printf("Alice\n");
    else printf("Bob\n");
}

int main(){
    int ___;
    read(___);
    while(___ --) work();
}