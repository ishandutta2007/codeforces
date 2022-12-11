#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 131072 + 4;
static const int MAXQ = 1e5 + 4;
static const int MAXV = MAXN * 3;

struct edge { int dest, len; edge(int dest = -1, int len = 0) : dest(dest), len(len) { } };
int n, q, s;
int v;
std::vector<edge> e[MAXV];
int lch[MAXV], rch[MAXV];

int ql, qr;
void get_range_nodes(std::vector<int> &out, int idx, int l, int r) {
    if (ql <= l && qr >= r) { out.push_back(idx); return; }
    int r_lch = (l + r) >> 1;
    if (ql <= r_lch) get_range_nodes(out, lch[idx], l, r_lch);
    if (qr >  r_lch) get_range_nodes(out, rch[idx], r_lch + 1, r);
}
inline std::vector<int> get_range_nodes(int root, int l, int r) {
    ql = l, qr = r;
    std::vector<int> ret; get_range_nodes(ret, root, 1, n); return ret;
}

int64 dist[MAXN];
inline void dijkstra(int source)
{
    for (int i = 0; i < v; ++i) dist[i] = INF64;
    dist[source] = 0;

    typedef std::pair<int64, int> node_info;
    typedef std::priority_queue< node_info, std::vector<node_info>, std::greater<node_info> > node_ctr;
    node_ctr q;
    q.push(node_info(0, source));

    while (!q.empty()) {
        node_info r;
        do { r = q.top(); q.pop(); } while (!q.empty() && dist[r.second] != r.first);
        if (dist[r.second] != r.first) break;
        for (std::vector<edge>::iterator i = e[r.second].begin(); i != e[r.second].end(); ++i) {
            if (dist[i->dest] > r.first + i->len) {
                dist[i->dest] = r.first + i->len;
                q.push(node_info(dist[i->dest], i->dest));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &q, &s);
    int _n = n;
    n = (1 << (8 * sizeof(n) - __builtin_clz(n - 1)));

    // Build the tree
    v = n * 3;
    for (int i = 1; i < n; ++i) {
        int idx = n + i, lch = n + i * 2, rch = n + i * 2 + 1;
        if (i >= n / 2) lch -= (n * 2 - 1), rch -= (n * 2 - 1);
        ::lch[idx] = lch, ::rch[idx] = rch;
        e[idx].push_back(edge(lch, 0));
        e[idx].push_back(edge(rch, 0));
    }
    for (int i = 1; i < n; ++i) {
        int idx = n * 2 + i, lch = n * 2 + i * 2, rch = n * 2 + i * 2 + 1;
        if (i >= n / 2) lch -= (n * 3 - 1), rch -= (n * 3 - 1);
        ::lch[idx] = lch, ::rch[idx] = rch;
        e[lch].push_back(edge(idx, 0));
        e[rch].push_back(edge(idx, 0));
    }

    // Process plans
    int ty, arg1, arg2, arg3, arg4;
    std::vector<int> t;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &ty, &arg1, &arg2, &arg3);
        switch (ty) {
            case 1:
                e[arg1].push_back(edge(arg2, arg3));
                break;
            case 2:
                scanf("%d", &arg4);
                t = get_range_nodes(n + 1, arg2, arg3);
                for (std::vector<int>::iterator i = t.begin(); i != t.end(); ++i)
                    e[arg1].push_back(edge(*i, arg4));
                break;
            case 3:
                scanf("%d", &arg4);
                t = get_range_nodes(n * 2 + 1, arg2, arg3);
                for (std::vector<int>::iterator i = t.begin(); i != t.end(); ++i)
                    e[*i].push_back(edge(arg1, arg4));
                break;
            default: puts("> <");
        }
    }

    // SSSP
    dijkstra(s);
    for (int i = 1; i <= _n; ++i) printf("%I64d%c", dist[i] == INF64 ? -1LL : dist[i], i == _n ? '\n' : ' ');
    return 0;
}