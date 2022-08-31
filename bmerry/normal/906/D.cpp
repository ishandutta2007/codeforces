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

static ll phi(ll M)
{
    ll P = 1;
    for (ll i = 2; i < 32767; i++)
        if (M % i == 0)
        {
            P *= i - 1;
            M /= i;
            while (M % i == 0)
            {
                P *= i;
                M /= i;
            }
        }
    if (M > 1)
        P *= M - 1;
    return P;
}

static ll reduce(ll a, ll m, ll h)
{
    if (a < h)
        return a;
    else
    {
        a %= m;
        while (a < h)
            a += m;
        return a;
    }
}

static ll pmod(ll a, ll b, ll m, ll h)
{
    if (b == 0)
        return reduce(1, m, h);
    else if (b & 1)
        return reduce(a * pmod(a, b - 1, m, h), m, h);
    else
    {
        ll t = pmod(a, b / 2, m, h);
        return reduce(t * t, m, h);
    }
}

template<typename It>
static ll query(const vector<ll> &w, int L, int R, It Ms0, It Ms1, ll H)
{
    ll M = *Ms0;
    if (L == R || w[L] == 1 || Ms1 - Ms0 == 1)
        return reduce(1, M, H);
    else
    {
        ll sub = query(w, L + 1, R, next(Ms0), Ms1, H);
        return pmod(w[L], sub, M, H);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<ll> w(N);
    for (int i = 0; i < N; i++)
        cin >> w[i];
    vector<ll> Ms;
    Ms.push_back(M);
    while (Ms.back() > 1)
        Ms.push_back(phi(Ms.back()));
    for (int i = 0; i < 8; i++)
        Ms.push_back(1);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        int ans = query(w, L, R, RA(Ms), 64) % M;
        cout << ans << '\n';
    }

    return 0;
}