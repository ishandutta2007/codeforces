#include <cstdio>
#include <functional>
#include <map>
#include <queue>
#include <utility>
#include <vector>
typedef long long int64;
static const int64 INF64 = (1LL << 62);
static const int MAXN = 1e5 + 6;
static const int MAXV = 2e5 + 12;
static const int MAXM = 8e5 + 6;

int n, l;
std::map<int, int> keypts;
int x[MAXN], d[MAXN], t[MAXN], p[MAXN];

int v;
int head[MAXV], dest[MAXM], len[MAXM], tag[MAXM], next[MAXM];
inline void add_edge(int u, int v, int w, int t) {
    static int m = 0;
    dest[m] = v; len[m] = w; tag[m] = t; next[m] = head[u]; head[u] = m++;
}

std::vector<int> path_tags;
int64 dijkstra(int src, int dst)
{
    static int64 dis[MAXV];
    static int last_v[MAXV], last_e[MAXV];
    typedef std::pair<int64, int> vert_info;
    std::priority_queue<
        vert_info, std::vector<vert_info>, std::greater<vert_info>
    > q;

    for (int i = 0; i < v; ++i) dis[i] = INF64, last_v[i] = last_e[i] = -1;
    dis[src] = 0; q.push(vert_info(0, src));
    static vert_info r;
    while (!q.empty()) {
        do { r = q.top(); q.pop(); } while (!q.empty() && dis[r.second] != r.first);
        if (dis[r.second] != r.first) break;
        for (int w = head[r.second]; w != -1; w = next[w])
            if (dis[dest[w]] > r.first + len[w]) {
                dis[dest[w]] = r.first + len[w];
                last_v[dest[w]] = r.second;
                last_e[dest[w]] = w;
                q.push(vert_info(dis[dest[w]], dest[w]));
            }
    }

    // assert(dis[dst] != INF64);
    // Recover the path to find ramps used
    for (int u = dst; u != src; u = last_v[u]) {
        if (tag[last_e[u]] != -1) path_tags.push_back(tag[last_e[u]]);
    }

    return dis[dst];
}

int main()
{
    scanf("%d%d", &n, &l);
    keypts.insert(std::make_pair(0, -1));
    keypts.insert(std::make_pair(l, -1));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &x[i], &d[i], &t[i], &p[i]);
        keypts.insert(std::make_pair(x[i] - p[i], -1));
        keypts.insert(std::make_pair(x[i] + d[i], -1));
    }

    int u = 0;
    for (std::map<int, int>::iterator i = keypts.begin(); i != keypts.end(); ++i, ++u) i->second = u;
    for (int i = 0; i < n; ++i) {
        t[i] += p[i];
        p[i] = keypts[x[i] - p[i]];
        d[i] = keypts[x[i] + d[i]];
    }
    // t[i]: distance
    // p[i]: origin
    // d[i]: destination

    v = (int)keypts.size();
    for (int i = 0; i < v; ++i) head[i] = -1;
    int src = keypts[0], dst = keypts[l], last = 0;
    for (int i = 0; i < n; ++i) if (p[i] >= src) add_edge(p[i], d[i], t[i], i);
    std::map<int, int>::iterator i = keypts.begin();
    for (++i, u = 1; i != keypts.end(); ++i, ++u) if (u - 1 >= src) {
        add_edge(u - 1, u, i->first - last, -1);
        add_edge(u, u - 1, i->first - last, -1);
        last = i->first;
    }

    printf("%I64d\n", dijkstra(src, dst));
    printf("%d\n", (int)path_tags.size());
    for (std::vector<int>::reverse_iterator i = path_tags.rbegin(); i != path_tags.rend(); ++i)
        printf("%d%c", *i + 1, (i + 1 == path_tags.rend()) ? '\n' : ' ');

    return 0;
}