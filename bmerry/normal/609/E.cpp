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
    int cost;
};

struct pqitem
{
    int trg;
    int up;
    int prio;

    bool operator<(const pqitem &other) const
    {
        return prio > other.prio;
    }
};

static ll prim(const vector<vector<edge>> &edges, vi &parent, vi &pcost)
{
    int N = SZ(edges);
    parent.clear();
    parent.resize(N, -2);
    pcost.clear();
    pcost.resize(N);
    priority_queue<pqitem> q;
    q.push(pqitem{0, -1, 0});
    ll total = 0;
    while (!q.empty())
    {
        int cur = q.top().trg;
        int p = q.top().prio;
        int up = q.top().up;
        q.pop();
        if (parent[cur] != -2)
            continue;
        parent[cur] = up;
        pcost[cur] = p;
        total += p;
        for (const auto &e : edges[cur])
            if (parent[e.trg] == -2)
                q.push(pqitem{e.trg, cur, e.cost});
    }
    return total;
}

struct node
{
    int depth = -1;
    vi anc;
    vi acost;
};

static int get_depth(vector<node> &nodes, int x)
{
    if (nodes[x].depth == -1)
    {
        int p = nodes[x].anc[0];
        nodes[x].depth = get_depth(nodes, p) + 1;
    }
    return nodes[x].depth;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> elist(M);
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        elist[i][0] = u;
        elist[i][1] = v;
        elist[i][2] = w;
        edges[u].push_back(edge{v, w});
        edges[v].push_back(edge{u, w});
    }

    vi parent;
    vi pcost;
    ll base = prim(edges, parent, pcost);

    vector<node> nodes(N);
    nodes[0].depth = 0;
    for (int i = 0; i < N; i++)
    {
        nodes[i].anc.push_back(i ? parent[i] : 0);
        nodes[i].acost.push_back(pcost[i]);
    }
    for (int i = 0; i < N; i++)
        get_depth(nodes, i);
    for (int s = 1; s <= 18; s++)
        for (int i = 0; i < N; i++)
        {
            int c = nodes[i].acost[s - 1];
            int m = nodes[i].anc[s - 1];
            c = max(c, nodes[m].acost[s - 1]);
            m = nodes[m].anc[s - 1];
            nodes[i].anc.push_back(m);
            nodes[i].acost.push_back(c);
        }

    for (int i = 0; i < M; i++)
    {
        int u = elist[i][0];
        int v = elist[i][1];
        while (nodes[u].depth > nodes[v].depth)
            swap(u, v);
        int ddepth = nodes[v].depth - nodes[u].depth;
        int ans = 0;
        for (int s = 0; ddepth > 0; s++)
            if (ddepth & (1 << s))
            {
                ans = max(ans, nodes[v].acost[s]);
                v = nodes[v].anc[s];
                ddepth = nodes[v].depth - nodes[u].depth;
            }

        for (int s = 18; s >= 0; s--)
        {
            if (nodes[u].anc[s] == nodes[v].anc[s])
                continue;
            ans = max(ans, nodes[u].acost[s]);
            ans = max(ans, nodes[v].acost[s]);
            u = nodes[u].anc[s];
            v = nodes[v].anc[s];
        }
        if (u != v)
        {
            assert(nodes[u].anc[0] == nodes[v].anc[0]);
            ans = max(ans, nodes[u].acost[0]);
            ans = max(ans, nodes[v].acost[0]);
        }

        cout << base - ans + elist[i][2] << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}