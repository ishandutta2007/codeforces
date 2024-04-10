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
int head[3005], nxt[5005], e[5005], cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int dis[3005][3005];

typedef pair<int, int> pi;
priority_queue <pi, vector<pi>, greater <pi> > q; 
bitset <3005> vis;
inline void Dijkstra(int s){
    vis &= 0;
    dis[s][s] = 0;q.push(make_pair(0, s));
    while(!q.empty()){
        pi tp = q.top();q.pop();
        int x = tp.second;
        if(vis[x]) continue;
        vis[x] = 1;
        for (register int i = head[x];i;i = nxt[i]){
            if(dis[s][e[i]] > dis[s][x] + 1){
                dis[s][e[i]] = dis[s][x] + 1;
                q.push(make_pair(dis[s][e[i]], e[i]));
            }
        }
    }
}

int pre[5][3005], succ[5][3005];

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= n;j ++){
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    while (m --){
        int u, v;read(u);read(v);
        add(u, v);
    }
    for (register int i = 1;i <= n;i ++) Dijkstra(i);
    int a = 0, b = 0, c = 0, d = 0;
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= n;j ++){
            if(dis[i][j] == 0x3f3f3f3f) dis[i][j] = -0x3f3f3f3f;
            if(dis[j][i] == 0x3f3f3f3f) dis[j][i] = -0x3f3f3f3f;
            if(dis[i][j] > dis[i][succ[1][i]]) {
                succ[3][i] = succ[2][i];
                succ[2][i] = succ[1][i];
                succ[1][i] = j;
            }
            else{
                if(dis[i][j] > dis[i][succ[2][i]]){
                    succ[3][i] = succ[2][i];
                    succ[2][i] = j;
                }
                else{
                    if(dis[i][j] > dis[i][succ[3][i]]){
                        succ[3][i] = j;
                    }
                }
            }
            if(dis[j][i] > dis[pre[1][i]][i]) {
                pre[3][i] = pre[2][i];
                pre[2][i] = pre[1][i];
                pre[1][i] = j;
            }
            else{
                if(dis[j][i] > dis[pre[2][i]][i]){
                    pre[3][i] = pre[2][i];
                    pre[2][i] = j;
                }
                else{
                    if(dis[j][i] > dis[pre[3][i]][i]){
                        pre[3][i] = j;
                    }
                }
            }
        }
    }
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= n;j ++){
            if(dis[i][j] < 0) continue;
            for (register int k1 = 1;k1 <= 3;k1 ++){
                for (register int k2 = 1;k2 <= 3;k2 ++){
                    if(!pre[k1][i] || !succ[k2][j]) continue;
                    if((i ^ j) && (i ^ pre[k1][i]) && (i ^ succ[k2][j]) && (j ^ pre[k1][i]) && (j ^ succ[k2][j]) && (pre[k1][i] ^ succ[k2][j])){
                        if(dis[i][j] + dis[pre[k1][i]][i] + dis[j][succ[k2][j]] > dis[a][b] + dis[b][c] + dis[c][d]){
                            a = pre[k1][i];
                            b = i;
                            c = j;
                            d = succ[k2][j];
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}