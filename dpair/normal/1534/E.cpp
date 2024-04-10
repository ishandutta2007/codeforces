#include <cstring>
#include <cstdio>
#include <queue>
int ans = 0, n, k;
const int MAXN = 505;
struct DPair {int val, id; DPair(int val, int id) : val(val), id(id) {} inline bool operator< (const DPair &tmp) const{return val > tmp.val;}};
std::priority_queue < DPair > q;
const int INF = 0x3f3f3f3f;
int head[MAXN], e[MAXN * MAXN], nxt[MAXN * MAXN], cnt, dis[MAXN], pre[MAXN];
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
bool vis[MAXN];
inline void Dijkstra() {
    for(int i = 1;i <= n;++ i) dis[i] = INF;
    q.push(DPair(0, 0));
    while(!q.empty()) {
        const int x = q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x] = 1; for (int i = head[x];i;i = nxt[i]) {
            if(dis[e[i]] > dis[x] + 1) {
                dis[e[i]] = dis[x] + 1; pre[e[i]] = x;
                q.push(DPair(dis[e[i]], e[i]));
            }
        }
    }
}
inline int mx(int x, int y) {return x > y? x : y;}
inline void init() {
    scanf("%d%d", &n, &k);
    for (int i = 0;i <= n;++ i) {
        for (int j = mx(0, k + i - n);j <= k && j <= i;++ j) {
            const int v = i - j + (k - j);
            if(v <= n && !vis[v]) { vis[v] = 1; add(i, v); }
        } memset(vis, 0, sizeof(vis));
    }
}
inline int abs(int x) {return x < 0? -x : x;}
void output(int x) {
    if(!x) return ;
    const int y = pre[x]; int r1 = (k + x - y) >> 1, r2 = k - r1;
    printf("?");
    for (int i = 1;i <= n;++ i) {
        if(vis[i] && r1) {
            printf(" %d", i);
            vis[i] = 0; -- r1;
        } else if(!vis[i] && r2) {
            printf(" %d", i);
            vis[i] = 1; -- r2;
        }
    } printf("\n"); fflush(stdout); int r;
    scanf("%d", &r); ans ^= r; output(y);
}

int main() { init(); Dijkstra();
    if(dis[n] == INF) {
        printf("-1\n"); fflush(stdout);
        return 0;
    } memset(vis, 1, sizeof(vis));
    output(n); printf("! %d\n", ans); fflush(stdout);
}