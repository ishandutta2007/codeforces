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
    int idx;
    bool rev;
};

struct node
{
    ll s;
    ll sum = 0;
    bool seen = false;
    vector<edge> edges;
};

static void recurse(vector<node> &nodes, int cur, vll &ans)
{
    node &n = nodes[cur];
    n.seen = true;
    n.sum = n.s;
    for (const edge &e : n.edges)
        if (!nodes[e.trg].seen)
        {
            recurse(nodes, e.trg, ans);
            n.sum += nodes[e.trg].sum;
            ans[e.idx] = e.rev ? -nodes[e.trg].sum : nodes[e.trg].sum;
        }
}

static void solve()
{
    int N, M;
    cin >> N;
    vector<node> nodes(N);
    ll total = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> nodes[i].s;
        total += nodes[i].s;
    }
    if (total != 0)
    {
        cout << "Impossible\n";
        return;
    }
    cin >> M;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].edges.push_back(edge{y, i, false});
        nodes[y].edges.push_back(edge{x, i, true});
    }

    vll ans(M);
    recurse(nodes, 0, ans);
    cout << "Possible\n";
    for (ll v : ans)
        cout << v << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}