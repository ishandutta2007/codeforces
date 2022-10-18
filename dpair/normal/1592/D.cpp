#include <cstdio>
#include <vector>
#include <cstring>

const int MAXN = 1e3 + 5;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }

int id[MAXN << 1], tot, n;

bool vis[MAXN];

inline int ask(int l, int r) {
    memset(vis, 0, sizeof(vis)); std::vector < int > v;
    for (int i = l;i <= r;++ i) if(!vis[id[i]]) v.push_back(id[i]), vis[id[i]] = 1;
    printf("? %lu", v.size()); for (auto it : v) printf(" %d", it);
    printf("\n"); fflush(stdout); int x; scanf("%d", &x); return x;
}

void dfs(int x, int pre) {
    id[++ tot] = x;
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dfs(e[i], x); id[++ tot] = x;
    }
}

int main() {
    scanf("%d", &n); for (int i = 1;i < n;++ i) {
        int u, v; scanf("%d%d", &u, &v);
        link(u, v);
    }
    dfs(1, 0); const int t = ask(1, tot);

    int l = 1, r = tot - 1, ans = tot;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ask(l, mid + 1) == t) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("! %d %d\n", id[ans], id[ans + 1]); fflush(stdout);
}
/*


*/