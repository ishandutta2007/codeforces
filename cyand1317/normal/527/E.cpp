// We've come a long way from where we began.
// Let's rewrite this.
#include <cstdio>
#include <list>
static const int MAXN = 1e5 + 5;
static const int MAXM = 1e6 + 5;

int n, m;
int head[MAXN], dest[MAXM], last[MAXM], next[MAXM];
int deg[MAXN] = { 0 };

inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; last[w] = -1;
    if (head[u] != -1) last[head[u]] = w;
    head[u] = w++; ++deg[u];
    dest[w] = u; next[w] = head[v]; last[w] = -1;
    if (head[v] != -1) last[head[v]] = w;
    head[v] = w++; ++deg[v];
}
inline void remove_edge(int u, int w) {
    if (next[w] != -1) last[next[w]] = last[w];
    if (last[w] == -1) head[u] = next[w];
    else next[last[w]] = next[w];
}

std::list<int> dfs_euler(int u)
{
    std::list<int> ret;
    if (head[u] == -1) return ret;
    int v = u, w;
    do {
        ret.push_back(v);
        w = head[v];
        remove_edge(v, w);
        remove_edge(dest[w], w ^ 1);
        v = dest[w];
    } while (v != u || head[u] != -1);

    std::list<int>::iterator i = ret.begin();
    for (++i; i != ret.end(); ++i) {
        std::list<int> r = dfs_euler(*i);
        ret.splice(i, r);
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
    }

    int last_odd = -1;
    for (int i = 0; i < n; ++i) if (deg[i] % 2 == 1) {
        if (last_odd == -1) last_odd = i;
        else { ++m; add_edge(last_odd, i); last_odd = -1; }
    }
    if (m % 2 == 1) { ++m; add_edge(0, 0); }

    std::list<int> cir = dfs_euler(0);
    cir.push_back(0);

    printf("%lu\n", cir.size() - 1);
    bool flag = false;
    for (std::list<int>::iterator i = cir.begin(); i != cir.end(); flag ^= 1) {
        u = *i + 1;
        if (++i == cir.end()) break;
        v = *i + 1;
        if (flag) printf("%d %d\n", u, v);
        else printf("%d %d\n", v, u);
    }

    return 0;
}