//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

struct edge
{
    int trg;
    ll w;
};

struct node
{
    int parent;
    int size;
    int depth;
    int hchild;
    int hidx;
    int hpos;
    std::vector<int> ch;

    ll pw = 0;
    ll a;
    ll vdepth;
    ll edepth;
    ll rt_down;
    ll rt_down_sum;
    ll rt_up;
};

struct path
{
    std::vector<int> nodes;
    int parent;
};

struct hltree
{
private:
    std::vector<node> nodes;
    std::vector<path> paths;

    void build_nodes(const std::vector<std::vector<edge>> &edges, int cur, int parent, int depth, ll vdepth, ll edepth);
    void build_paths(int top, int up);
    void build_rt_down_sum(int cur, ll above);
    void build_rt_up(int cur);
    ll step(int v) const;

public:
    explicit hltree(const std::vector<std::vector<edge>> &edges, const vll &a);

    std::size_t size() const { return nodes.size(); }
    node &operator[](std::size_t idx) { return nodes[idx]; }
    const node &operator[](std::size_t idx) const { return nodes[idx]; }

    int ancestor(int x, int k) const;
    int lca(int u, int v) const;

    ll query(int u, int v) const;
};

ll hltree::step(int v) const
{
    const node &n = nodes[v];
    return max(0LL, n.rt_down + n.a - 2 * n.pw);
}

void hltree::build_nodes(const std::vector<std::vector<edge>> &edges, int cur, int parent, int depth, ll vdepth, ll edepth)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.size = 1;
    n.depth = depth;
    vdepth += n.a;
    n.vdepth = vdepth;
    n.edepth = edepth;
    n.ch.reserve(parent == -1 ? edges[cur].size() : edges[cur].size() - 1);
    n.hchild = -1;
    n.rt_down = 0;
    int big = -1;
    for (const edge &e : edges[cur])
    {
        int y = e.trg;
        if (y != parent)
        {
            nodes[y].pw = e.w;
            build_nodes(edges, y, cur, depth + 1, vdepth, edepth + e.w);
            n.ch.push_back(y);
            int s = nodes[y].size;
            n.size += s;
            if (s > big)
            {
                big = s;
                n.hchild = y;
            }
            n.rt_down += step(y);
        }
    }
}

void hltree::build_rt_down_sum(int cur, ll above)
{
    node &n = nodes[cur];
    n.rt_down_sum = above;
    for (int y : n.ch)
        build_rt_down_sum(y, above + (n.rt_down - step(y)));
}

void hltree::build_rt_up(int cur)
{
    node &n = nodes[cur];
    n.rt_up = 0;
    if (n.parent != -1)
    {
        const node &p = nodes[n.parent];
        n.rt_up = max(0LL, p.rt_down + p.rt_up - step(cur) + p.a - 2 * n.pw);
    }
    for (int y : n.ch)
        build_rt_up(y);
}

void hltree::build_paths(int top, int up)
{
    int idx = paths.size();
    paths.emplace_back();
    path &p = paths.back();
    p.parent = up;
    for (int x = top, pos = 0; x != -1; x = nodes[x].hchild, pos++)
    {
        node &n = nodes[x];
        n.hidx = idx;
        n.hpos = pos;
        p.nodes.push_back(x);
    }
    for (int x : p.nodes)
    {
        const node &n = nodes[x];
        for (int y : n.ch)
            if (y != n.hchild)
                build_paths(y, x);
    }
}

hltree::hltree(const std::vector<std::vector<edge>> &edges, const std::vector<ll> &a)
{
    std::size_t N = edges.size();
    nodes.resize(N);
    for (size_t i = 0; i < N; i++)
        nodes[i].a = a[i];
    build_nodes(edges, 0, -1, 0, 0, 0);
    build_rt_down_sum(0, 0);
    build_rt_up(0);
    build_paths(0, -1);
}

int hltree::ancestor(int x, int k) const
{
    while (k > nodes[x].hpos)
    {
        k -= nodes[x].hpos + 1;
        x = paths[nodes[x].hidx].parent;
    }
    return paths[nodes[x].hidx].nodes[nodes[x].hpos - k];
}

int hltree::lca(int u, int v) const
{
    while (nodes[u].hidx != nodes[v].hidx)
    {
        int du = nodes[u].depth - nodes[u].hpos;
        int dv = nodes[v].depth - nodes[v].hpos;
        if (du < dv)
            v = paths[nodes[v].hidx].parent;
        else
            u = paths[nodes[u].hidx].parent;
    }
    return nodes[u].depth < nodes[v].depth ? u : v;
}

ll hltree::query(int u, int v) const
{
    int m = lca(u, v);
    // sum(a_v) on the simple path
    ll ans = nodes[u].vdepth + nodes[v].vdepth - 2 * nodes[m].vdepth + nodes[m].a;
    // sum(w) on the simple path
    ans -= nodes[u].edepth + nodes[v].edepth - 2 * nodes[m].edepth;
    // round trips below the path, excluding those from the endpoints
    ans += nodes[u].rt_down_sum + nodes[v].rt_down_sum - 2 * nodes[m].rt_down_sum - nodes[m].rt_down;
    // round trips down, from the endpoints
    ans += nodes[u].rt_down + nodes[v].rt_down;
    // round trips up, from the LCA
    ans += nodes[m].rt_up;
    return ans;
}

static void solve()
{
    int N, Q;
    cin >> N >> Q;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<vector<edge>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back(edge{v, w});
        edges[v].push_back(edge{u, w});
    }
    hltree tree(edges, a);
    for (int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << tree.query(u, v) << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}