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

struct node
{
    int parent;
    ll depth;
    vi ch;
    bool crit = false;
    int nch = -1;
};

struct edge
{
    int trg;
    ll w;
};

static vector<node> nodes;

static void make_tree(const vector<vector<edge>> &edges, int cur, int parent, ll depth)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.depth = depth;
    for (const auto &e : edges[cur])
        if (e.trg != parent)
        {
            n.ch.push_back(e.trg);
            make_tree(edges, e.trg, cur, depth + e.w);
        }
}

static bool easy_case()
{
    int N = SZ(nodes);
    for (int i = 0; i < N; i++)
    {
        if (nodes[i].crit)
        {
            int k = 0;
            for (int y : nodes[i].ch)
                if (!nodes[y].crit)
                {
                    k++;
                    nodes[i].nch = y;
                }
            if (k > 1)
                return true;
        }
        else
        {
            if (!nodes[i].ch.empty())
                return true;
        }
    }
    return false;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    nodes.resize(N);
    vector<vector<edge>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        edges[x].push_back(edge{y, w});
        edges[y].push_back(edge{x, w});
    }
    vll proj(M);
    for (int i = 0; i < M; i++)
        cin >> proj[i];

    make_tree(edges, 0, -1, 0);
    vi cpath;
    for (int i = N - 1; i != -1; i = nodes[i].parent)
    {
        nodes[i].crit = true;
        cpath.push_back(i);
    }

    vll ans(M, nodes[N - 1].depth);
    ll alt = LLONG_MIN / 2;
    ll lo = LLONG_MIN / 2;
    if (!easy_case())
    {
        for (int i = 0; i < SZ(cpath); i++)
        {
            int v = cpath[i];
            alt = max(alt, lo + nodes[v].depth);
            if (i > 0)
                lo = max(lo, -nodes[cpath[i - 1]].depth);
            int nch = nodes[v].nch;
            if (nch != -1)
            {
                alt = max(alt, lo + nodes[nch].depth);
                lo = max(lo, nodes[nch].depth - 2 * nodes[v].depth);
            }
        }
        for (int i = 0; i < M; i++)
            ans[i] = min(ans[i], nodes[N - 1].depth + alt + proj[i]);
    }
    for (ll v : ans)
        cout << v << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}