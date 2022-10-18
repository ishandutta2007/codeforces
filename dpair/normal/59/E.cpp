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

typedef pair <int, int> pi;
typedef pair <int, pi> pii;

set <pii> h;
set <pi> inq;

inline pi mk(int x, int y){return make_pair(x, y);}
inline pii mkk(int x, int y, int z){return make_pair(x, make_pair(y, z));}

int n, m, k;

int head[3005], nxt[40005], e[40005], cnt;
int dis[3005][3005], pre[3005][3005];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

queue <pi> q;

inline void ins(pi x){
    if(inq.find(x) == inq.end()){
        inq.insert(x);
        q.push(x);
    }
}

inline void SPFA(){
    memset(dis, 31, sizeof(dis));
    dis[1][0] = 0;
    ins(mk(1, 0));
    while(!q.empty()){
        pi tp = q.front();q.pop();
        inq.erase(tp);
        int x = tp.first, pree = tp.second;
        for (register int i = head[x];i;i = nxt[i]){
            if(h.find(mkk(tp.second, tp.first, e[i])) != h.end()) continue;
            if(dis[e[i]][x] > dis[x][pree] + 1){
                dis[e[i]][x] = dis[x][pree] + 1;
                pre[e[i]][x] = pree;
                ins(mk(e[i], x));
            }
        }
    }
}

void output(int x, int y){
    if(pre[x][y]) output(y, pre[x][y]), fprint(x, 32);
    else fprint(y, 32), fprint(x, 32);
}

int main(){
    read(n);read(m);read(k);
    while(m --){
        int u, v;
        read(u);read(v);
        add(u, v);add(v, u);
    }
    while(k --){
        int u, v, w;
        read(u);read(v);read(w);
        h.insert(mkk(u, v, w));
    }
    SPFA();
    int num = 0;
    for (register int i = 1;i <= n;i ++){
        if(dis[n][num] > dis[n][i]){
            num = i;
        }
    }
    if(!num) fprint(-1, 10);
    else fprint(dis[n][num], 10), output(n, num), putchar(10);
}