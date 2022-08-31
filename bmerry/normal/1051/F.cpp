//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
#pragma GCC target("avx,avx2")
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

struct node
{
    ll w;
    int parent;
    int size = 0;
    int depth;
    int hchild;
    int hidx;
    int hpos;
    std::vector<int> ch;
};

struct path
{
    std::vector<int> nodes;
    int parent;
};

struct edge
{
    int trg;
    ll cost;
};

struct hltree
{
private:
    std::vector<node> nodes;
    std::vector<path> paths;

    void build_nodes(const std::vector<std::vector<edge>> &edges, int cur, int parent, int depth, ll w);
    void build_paths(int top, int up);

public:
    std::vector<tuple<int, int, ll>> jumps;

    explicit hltree(const std::vector<std::vector<edge>> &edges);

    std::size_t size() const { return nodes.size(); }
    node &operator[](std::size_t idx) { return nodes[idx]; }
    const node &operator[](std::size_t idx) const { return nodes[idx]; }

    int ancestor(int x, int k) const;
    int lca(int u, int v) const;
};

void hltree::build_nodes(const std::vector<std::vector<edge>> &edges, int cur, int parent, int depth, ll w)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.size = 1;
    n.depth = depth;
    n.w = w;
    n.ch.reserve(parent == -1 ? edges[cur].size() : edges[cur].size() - 1);
    n.hchild = -1;
    int big = -1;
    for (const auto &e : edges[cur])
        if (e.trg != parent)
        {
            if (nodes[e.trg].size > 0)
            {
                if (nodes[e.trg].w < nodes[cur].w)
                    jumps.emplace_back(cur, e.trg, e.cost);
            }
            else
            {
                build_nodes(edges, e.trg, cur, depth + 1, w + e.cost);
                n.ch.push_back(e.trg);
                int s = nodes[e.trg].size;
                n.size += s;
                if (s > big)
                {
                    big = s;
                    n.hchild = e.trg;
                }
            }
        }
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

hltree::hltree(const std::vector<std::vector<edge>> &edges)
{
    std::size_t N = edges.size();
    nodes.resize(N);
    build_nodes(edges, 0, -1, 0, 0);
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


static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        u--;
        v--;
        edges[u].push_back(edge{v, d});
        edges[v].push_back(edge{u, d});
    }
    hltree tree(edges);

    auto get_dist = [&](int x, int y)
    {
        int lca = tree.lca(x, y);
        return tree[x].w + tree[y].w - 2 * tree[lca].w;
    };

    int Q;
    cin >> Q;
    array<array<ll, 50>, 50> dists;
    int V = tree.jumps.size() * 2;
    vi verts(V);
    for (int i = 0; i < SZ(tree.jumps); i++)
    {
        verts[2 * i + 0] = get<0>(tree.jumps[i]);
        verts[2 * i + 1] = get<1>(tree.jumps[i]);
    }
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dists[i][j] = get_dist(verts[i], verts[j]);
    for (int i = 0; i < V; i += 2)
    {
        dists[i][i + 1] = min(dists[i][i + 1], get<2>(tree.jumps[i / 2]));
        dists[i + 1][i] = dists[i][i + 1];
    }
    for (int y = 0; y < V; y++)
        for (int x = 0; x < V; x++)
            for (int z = 0; z < V; z++)
                dists[x][z] = min(dists[x][z], dists[x][y] + dists[y][z]);

    vll qdists[2];
    qdists[0].resize(V);
    qdists[1].resize(V);
    for (int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        for (int j = 0; j < V; j++)
        {
            qdists[0][j] = get_dist(u, verts[j]);
            qdists[1][j] = get_dist(v, verts[j]);
        }
        ll ans = get_dist(u, v);
        for (int p = 0; p < V; p++)
            for (int q = 0; q < V; q++)
                ans = min(ans, qdists[0][p] + qdists[1][q] + dists[p][q]);
        cout << ans << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}