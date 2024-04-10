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
    int w;
};

typedef tuple<int, int, int, int> state;

static int N, S;
static vector<vector<edge>> edges;
static vector<int> crim;
static map<state, ll> cache;

static ll recurse(int cur, int prev, int w, int out, int in)
{
    state key(cur, prev, out, in);
    if (cache.count(key))
    {
        ll ans = cache[key];
        assert(ans != -1);
        return ans;
    }
    ll &ans = cache[key];
    ans = -1;
    int nup = int(prev != -1);
    bool empty = SZ(edges[cur]) == nup || in == 0;
    if (out == 0 && empty)
        return ans = 0;
    else if (empty)
        return ans = recurse(prev, cur, w, 0, out) + w;

    vector<ll> dp;
    for (const edge &e : edges[cur])
    {
        if (e.trg != prev)
        {
            vector<ll> sub(in + 1);
            for (int i = 1; i <= in; i++)
                sub[i] = recurse(e.trg, cur, e.w, out + in - i, i) + e.w;
            sub[0] = LLONG_MAX / 4;
            if (dp.empty())
                dp = move(sub);
            else
            {
                for (int i = in; i >= 0; i--)
                {
                    for (int j = 0; j <= i; j++)
                        dp[i] = max(dp[i], min(dp[i - j], sub[j]));
                }
            }
        }
    }
    return ans = dp[in];
}

static int stc(int cur, int parent)
{
    int ans = crim[cur];
    for (const auto &e : edges[cur])
        if (e.trg != parent)
            ans += stc(e.trg, cur);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N;
    edges.resize(N);
    crim.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges[a].push_back(edge{b, w});
        edges[b].push_back(edge{a, w});
    }
    int M;
    cin >> S >> M;
    S--;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        x--;
        crim[x]++;
    }
    if (N == 1)
    {
        cout << "0\n";
        return 0;
    }

    ll ans = LLONG_MAX;
    for (const auto &e : edges[S])
    {
        int in = stc(e.trg, S);
        ll score = recurse(e.trg, S, e.w, M - in, in) + e.w;
        ans = min(ans, score);
    }
    cout << ans << '\n';

    return 0;
}