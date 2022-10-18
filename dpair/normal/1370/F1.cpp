#include <cstdio>
#include <cstring>

const int MAXN = 1e3 + 5;
int n, root, len;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }

int dep[MAXN], fa[MAXN]; 
#include <vector>
std::vector < int > v[MAXN];
int mxd; bool vis[MAXN];
void dfs(int x, int pre) {
    fa[x] = pre;
    v[dep[x]].push_back(x); mxd = std::max(mxd, dep[x]);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + 1;
        dfs(e[i], x);
    }
}

inline void ask(int t, int &x, int &d) {
    printf("? %lu", v[t].size()); for (auto it : v[t]) printf(" %d", it);
    putchar(10); fflush(stdout);
    scanf("%d%d", &x, &d);
}
inline void init() { cnt = 0; memset(head, 0, sizeof(head)); memset(vis, 0, sizeof(vis)); }


inline void work() {
    scanf("%d", &n); init();
    for (int i = 2;i <= n;++ i) {
        int u, v; scanf("%d%d", &u, &v);
        link(u, v);
    }

    mxd = 0;
    printf("? %d", n); for (int i = 1;i <= n;++ i) printf(" %d", i);
    putchar(10); fflush(stdout);

    scanf("%d%d", &root, &len); dep[root] = 0; dfs(root, 0);

    int l = ((len - 1) >> 1) + 1, r = std::min(mxd, len), ans = l, U = root;
    while(l <= r) {
        int mid = (l + r) >> 1, x, d; ask(mid, x, d);
        if(d == len) ans = mid, l = mid + 1, U = x;
        else r = mid - 1;
    }
    int tmp = U; while(tmp != root) vis[tmp] = 1, tmp = fa[tmp];
    int V, d;
    printf("? %lu", v[len - ans].size() - ((len - ans) && len - ans <= ans));
    for (auto it : v[len - ans]) if(!vis[it]) printf(" %d", it);
    putchar(10); fflush(stdout);
    scanf("%d%d", &V, &d);
    printf("! %d %d\n", U, V); fflush(stdout);
    for (int i = 0;i <= mxd;++ i) v[i].clear();

    char ssssss[20]; scanf("%s", ssssss); 
}

int main() {
    int T; scanf("%d", &T);
    while(T --) work();
}