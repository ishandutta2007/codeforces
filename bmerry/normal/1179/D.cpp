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
typedef complex<ll> pnt;
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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static int N;

struct state
{
    ll size{1};
    ll dp{LLONG_MAX};
    ll ans{LLONG_MAX};
};

static ll c2(ll x)
{
    return x * (x - 1) / 2;
}

static inline ll dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

static state recurse(const vector<vi> &edges, int cur, int parent)
{
    state s;
    vector<state> sub;
    for (int y : edges[cur])
        if (y != parent)
        {
            state t = recurse(edges, y, cur);
            s.size += t.size;
            sub.push_back(t);
        }

    s.dp = c2(s.size);
    for (auto &t : sub)
    {
        s.dp = min(s.dp, t.dp + c2(s.size - t.size));
        s.ans = min(s.ans, t.dp + c2(N - t.size));
        s.ans = min(s.ans, t.ans);
    }

    sort(RA(sub), [](const state &a, const state &b) { return a.size < b.size; });

    deque<pnt> pnts;
    for (const state &t : sub)
    {
        ll x = t.size;
        ll extra = c2(x + 1) + t.dp;
        auto score = [&](const pnt &prev)
        {
            return x * prev.real() + prev.imag() + extra;
        };
        while (SZ(pnts) >= 2 && score(pnts[1]) < score(pnts[0]))
            pnts.pop_front();
        if (!pnts.empty())
            s.ans = min(s.ans, score(pnts[0]));
        pnt next(x - N, t.dp + c2(N - x));
        while (SZ(pnts) >= 2 && cross(pnts[SZ(pnts) - 2], pnts.back(), next) <= 0)
            pnts.pop_back();
        pnts.push_back(next);
    }
    return s;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N;
    vector<vi> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    state s = recurse(edges, 0, -1);
    ll paths = 2 * c2(N) - s.ans;
    cout << paths << '\n';

    return 0;
}