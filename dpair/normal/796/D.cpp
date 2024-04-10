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

int n, k, d;
int col[300005], head[300005], nxt[600005], e[600005], cnt;

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

typedef pair <int, int> pi;
queue <pi> q;
int u[300005], v[300005];
int main(){
    read(n);read(k);read(d);
    for (register int i = 1;i <= k;i ++){
        int x;read(x);col[x] = i;
        q.push(make_pair(x, 0));
    }
    for (register int i = 1;i < n;i ++){
        read(u[i]);read(v[i]);
        add(u[i], v[i]);add(v[i], u[i]);
    }
    while(!q.empty()){
        int x = q.front().first, dis = q.front().second;
        q.pop();
        if(dis == d) continue;
        for (register int i = head[x];i;i = nxt[i]){
            if(col[e[i]]) continue;
            col[e[i]] = col[x];
            q.push(make_pair(e[i], dis + 1));
        }
    }
    int ans = 0;
    for (register  int i = 1;i < n;i ++){
        if(col[u[i]] ^ col[v[i]]) ans ++;
    }
    fprint(ans, 10);
    for (register int i = 1;i < n;i ++){
        if(col[u[i]] ^ col[v[i]]) fprint(i, 32);
    }
    putchar(10);
}