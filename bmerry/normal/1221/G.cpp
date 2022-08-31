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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static int N;

static inline ll bit(int x)
{
    return 1LL << x;
}

static inline bool has_bit(ll x, int y)
{
    return x & bit(y);
}

static ll bottom(ll x)
{
    return x & ~(x - 1);
}

static int comps(const vector<ll> &edges)
{
    vector<ll> trans = edges;
    for (int i = 0; i < N; i++)
        trans[i] |= bit(i);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (has_bit(trans[x], y))
                trans[x] |= trans[y];
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += bottom(trans[i]) == bit(i);
    return ans;
}

static bool bipartite(const vector<ll> &edges)
{
    vi side(N, -1);
    for (int i = 0; i < N; i++)
        if (side[i] == -1)
        {
            side[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int y = 0; y < N; y++)
                    if (has_bit(edges[x], y))
                    {
                        if (side[y] == -1)
                        {
                            side[y] = !side[x];
                            q.push(y);
                        }
                        else if (side[y] == side[x])
                            return false;
                    }
            }
        }
    return true;
}

static ll n_valid(const vector<ll> &edges)
{
    int H = N / 2;
    vector<int> mob(1 << H);
    for (int i = 0; i < (1 << H); i++)
    {
        ll bad = 0;
        for (int j = 0; j < H; j++)
            if (has_bit(i, j))
                bad |= edges[j];
        mob[i] = (bad & i) == 0;
    }
    for (int i = 0; i < H; i++)
    {
        int b = 1 << i;
        for (int j = 0; j < (1 << H); j++)
            if (j & b)
                mob[j] += mob[j - b];
    }

    ll step = bit(H);
    ll ans = 0;
    for (ll m = 0; m < bit(N); m += step)
    {
        ll bad = 0;
        for (int i = H; i < N; i++)
            if (has_bit(m, i))
                bad |= edges[i];
        if (bad & m)
            continue;
        ll good = (bit(H) - 1) & ~bad;
        ans += mob[good];
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int M;
    cin >> N >> M;
    vector<ll> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x] |= bit(y);
        edges[y] |= bit(x);
    }

    int single = 0;
    for (int i = 0; i < N; i++)
        single += !edges[i];

    ll c = comps(edges);
    ll all = bit(N);
    ll no0 = n_valid(edges);
    ll no1 = bit(c);
    ll no2 = no0;
    ll no01 = bit(single);
    ll no12 = no01;
    ll no02 = bipartite(edges) ? no1 : 0;
    ll no012 = (single == N) ? no1 : 0;

    ll ans = all - no0 - no1 - no2 + no01 + no12 + no02 - no012;
    cout << ans << '\n';

    return 0;
}