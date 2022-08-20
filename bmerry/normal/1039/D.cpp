// WRONG

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

struct compare
{
    bool operator()(const pii &a, const pii &b) const
    {
        return pii(a.first, -a.second) < pii(b.first, -b.second);
    }
};

struct node
{
    int paths, extra;
    vi edges;
};

static vector<node> nodes;
static vi order;

static void make_order(int cur, int parent)
{
    node &n = nodes[cur];
    order.push_back(cur);
    if (parent != -1)
        n.edges.erase(find(RA(n.edges), parent));
    for (int c : n.edges)
        make_order(c, cur);
}

static int solve(int k)
{
    for (int cur : order)
    {
        node &n = nodes[cur];
        int d1 = 0, d2 = 0;
        n.paths = 0;
        for (int ch : n.edges)
        {
            const node &c = nodes[ch];
            n.paths += c.paths;
            if (c.extra > d1)
            {
                d2 = d1;
                d1 = c.extra;
            }
            else if (c.extra > d2)
                d2 = c.extra;
        }
        if (d1 + d2 + 1 >= k)
        {
            n.paths++;
            n.extra = 0;
        }
        else
            n.extra = d1 + 1;
    }
    return nodes[0].paths;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    make_order(0, -1);
    reverse(RA(order));

    int S = min(N, 1000);
    vi ans(N + 1);
    for (int i = 1; i <= S; i++)
        ans[i] = solve(i);
    int prev = S;
    for (int i = ans[S]; i >= 1; i--)
    {
        int lo = prev;
        int hi = N + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (solve(mid) >= i)
                lo = mid;
            else
                hi = mid;
        }
        for (int j = prev + 1; j < hi; j++)
            ans[j] = i;
        prev = lo;
    }
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}