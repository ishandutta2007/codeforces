#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int UI;
typedef pair <int, int> pi;

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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, m;

int head[100005], nxt[200005], e[200005], cnt;
LL val[200005];

inline void add(int u, int v, LL w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
}

LL dis[100005];
int pre[100005];
bitset <100005> vis;

priority_queue <pi, vector <pi>, greater <pi> > q;

inline void Dijkstra(){
    memset(dis, 63, sizeof(dis));
    dis[1] = 0;q.push(make_pair(0, 1));
    while(!q.empty()){
        pi tp = q.top();q.pop();
        int x = tp.second;
        if(vis[x]) continue;
        vis[x] = 1;
        for (register int i = head[x];i;i = nxt[i]){
            if(dis[e[i]] > dis[x] + val[i]){
                pre[e[i]] =  x;
                dis[e[i]] = dis[x] + val[i];
                q.push(make_pair(dis[e[i]], e[i]));
            }
        }
    }
}

void output(int x){
    if(pre[x]) output(pre[x]);
    fprint(x, 32);
}

int main(){
    read(n);read(m);
    while(m --){
        int u, v;LL w;read(u);read(v);read(w);
        add(u, v, w);add(v, u, w);
    }
    Dijkstra();
    if(dis[n] == dis[0]) return printf("-1\n"), 0;
    output(n);
    putchar(10);
    return 0;
}