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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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
}

/*** TEMPLATE CODE ENDS HERE */

struct edge
{
    int trg;
    int val;
    int dual;
    int leaf = -1;
};

struct op
{
    int u, v;
    int x;
};

static int find_leaf(vector<vector<edge>> &edges, int cur, edge &e)
{
    if (e.leaf != -1)
        return e.leaf;
    if (SZ(edges[e.trg]) == 1)
        return e.leaf = e.trg;
    for (edge &y : edges[e.trg])
        if (y.trg != cur)
            return e.leaf = find_leaf(edges, e.trg, y);
    abort();
}

static array<int, 2> find_leaves(vector<vector<edge>> &edges, int cur, int excl)
{
    array<int, 2> out;
    int pos = 0;
    for (edge &y : edges[cur])
        if (y.trg != excl)
        {
            out[pos++] = find_leaf(edges, cur, y);
            if (pos == 2)
                return out;
        }
    abort();
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, val;
        cin >> u >> v >> val;
        u--;
        v--;
        int su = SZ(edges[u]);
        int sv = SZ(edges[v]);
        edges[u].push_back(edge{v, val, sv});
        edges[v].push_back(edge{u, val, su});
    }

    vi cut;
    for (int i = 0; i < N; i++)
        if (SZ(edges[i]) == 2)
        {
            if (edges[i][0].val != edges[i][1].val)
            {
                cout << "NO\n";
                return 0;
            }
            cut.push_back(i);
        }
    for (int v : cut)
    {
        edge a = edges[v][0];
        edge b = edges[v][1];
        edges[a.trg][a.dual].trg = b.trg;
        edges[a.trg][a.dual].dual = b.dual;
        edges[b.trg][b.dual].trg = a.trg;
        edges[b.trg][b.dual].dual = a.dual;
        edges[v].clear();
    }

    vector<op> ops;
    for (int i = 0; i < N; i++)
        for (edge &e : edges[i])
        {
            if (e.trg < i)
                continue;
            int u = i;
            int v = e.trg;
            int x = e.val;
            if (SZ(edges[v]) == 1)
                swap(u, v);
            if (SZ(edges[v]) == 1)
                ops.push_back(op{u, v, x});
            else if (SZ(edges[u]) == 1)
            {
                array<int, 2> leaves = find_leaves(edges, v, u);
                ops.push_back(op{u, leaves[0], x / 2});
                ops.push_back(op{u, leaves[1], x / 2});
                ops.push_back(op{leaves[0], leaves[1], -x / 2});
            }
            else
            {
                array<int, 2> ul = find_leaves(edges, u, v);
                array<int, 2> vl = find_leaves(edges, v, u);
                ops.push_back(op{ul[0], vl[0], x / 2});
                ops.push_back(op{ul[1], vl[1], x / 2});
                ops.push_back(op{ul[0], ul[1], -x / 2});
                ops.push_back(op{vl[0], vl[1], -x / 2});
            }
        }

    cout << "YES\n" << SZ(ops) << '\n';
    for (const auto &o : ops)
        cout << o.u + 1 << ' ' << o.v + 1 << ' ' << o.x << '\n';

    return 0;
}