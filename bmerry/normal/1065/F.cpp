//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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
    int parent = -1;
    vi ch;
    int depth = 0;
    int up_depth = -1;
    vi ch_fixed;
    int direct_leaves = 0;
    int dp = 0;
};

static vector<node> nodes;

static void recurse1(int cur, int K)
{
    node &n = nodes[cur];
    n.up_depth = n.depth;
    if (n.ch.empty())
    {
        n.up_depth = max(0, n.depth - K);
        n.direct_leaves = 1;
    }
    for (int y : n.ch)
    {
        nodes[y].depth = n.depth + 1;
        recurse1(y, K);
        n.up_depth = min(n.up_depth, nodes[y].up_depth);
    }
    if (n.up_depth < n.depth)
    {
        node &p = nodes[n.parent];
        p.direct_leaves += n.direct_leaves;
        n.direct_leaves = 0;
    }
}

static void recurse2(int cur)
{
    node &n = nodes[cur];
    for (int y : n.ch)
    {
        recurse2(y);
        n.dp = max(n.dp, nodes[y].dp);
    }
    n.dp += n.direct_leaves;
}

static void solve()
{
    int N, K;
    cin >> N >> K;
    nodes.resize(N);
    for (int i = 1; i < N; i++)
    {
        int p;
        cin >> p;
        p--;
        nodes[i].parent = p;
        nodes[p].ch.push_back(i);
    }
    recurse1(0, K);
    recurse2(0);
    cout << nodes[0].dp << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}