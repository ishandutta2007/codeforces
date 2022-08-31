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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
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
}

/*** TEMPLATE CODE ENDS HERE */

struct extra
{
    int u, v;
    ll cost;
};

struct node
{
    int depth = -1;
    int parent = -1;
    vector<int> anc;
    vector<ll> up;
    vector<int> ch;
    ll dp = -1;
    vector<extra> extras;
};

static vector<node> nodes;

static void make_tree(const vector<vector<int>> &edges, int cur, int parent, int depth)
{
    node &n = nodes[cur];
    n.depth = depth;
    n.parent = parent;
    n.anc.push_back(parent);
    for (int v : edges[cur])
        if (v != parent)
        {
            n.ch.push_back(v);
            make_tree(edges, v, cur, depth + 1);
        }
}

static int kth_anc(int cur, int k)
{
    for (int i = 0; i < SZ(nodes[cur].anc); i++)
    {
        if (k & (1 << i))
        {
            cur = nodes[cur].anc[i];
            k ^= 1 << i;
        }
        else if (k < (1 << i))
            break;
    }
    assert(k == 0);
    return cur;
}

static int lca(int a, int b)
{
    if (nodes[a].depth > nodes[b].depth)
        a = kth_anc(a, nodes[a].depth - nodes[b].depth);
    else
        b = kth_anc(b, nodes[b].depth - nodes[a].depth);
    for (int i = SZ(nodes[a].anc) - 1; i >= 0; i--)
    {
        int ua = nodes[a].anc[i];
        int ub = nodes[b].anc[i];
        if (ua != ub)
            a = ua, b = ub;
    }
    if (a != b)
        return nodes[a].parent;
    else
        return a;
}

static ll upsum(int cur, int k)
{
    if (k == 0)
        return 0;
    assert(!nodes[cur].up.empty());
    int last = SZ(nodes[cur].up) - 1;
    while (k >= (2 << last))
    {
        nodes[cur].up.push_back(nodes[cur].up.back() + upsum(nodes[cur].anc[last], 1 << last));
        last++;
    }
    while (k < (1 << last))
        last--;
    return nodes[cur].up[last] + upsum(nodes[cur].anc[last], k - (1 << last));
}

static void solve(int cur)
{
    node &n = nodes[cur];
    ll csum = 0;
    for (int v : n.ch)
        csum += nodes[v].dp;
    ll best = csum;
    for (const auto &e : n.extras)
    {
        int u = e.u, v = e.v;
        ll score = csum + e.cost;
#if 0
        while (u != cur)
        {
            score -= nodes[u].delta;
            u = nodes[u].parent;
        }
        while (v != cur)
        {
            score -= nodes[v].delta;
            v = nodes[v].parent;
        }
#else
        score -= upsum(u, nodes[u].depth - n.depth);
        score -= upsum(v, nodes[v].depth - n.depth);
#endif
        best = max(best, score);
    }
    n.dp = best;
    n.up.clear();
    n.up.push_back(best - csum);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    nodes.resize(N);

    vector<vector<int>> edges(N);
    for (int i = 1; i < N; i++)
    {
        int p;
        cin >> p;
        p--;
        edges[p].push_back(i);
        edges[i].push_back(p);
    }

    make_tree(edges, 0, -1, 0);
    for (int i = 1; i < 20; i++)
        for (int j = 0; j < N; j++)
        {
            int h = nodes[j].anc[i - 1];
            nodes[j].anc.push_back(h == -1 ? -1 : nodes[h].anc[i - 1]);
        }

    for (int i = 0; i < M; i++)
    {
        extra e;
        cin >> e.u >> e.v >> e.cost;
        e.u--;
        e.v--;
        int p = lca(e.u, e.v);
        nodes[p].extras.push_back(e);
    }

    for (int i = N - 1; i >= 0; i--)
        solve(i);
    cout << nodes[0].dp << '\n';

    return 0;
}