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

static ll pclamp(ll b, int e)
{
    ll ans = 1;
    for (int i = 0; i < e; i++)
    {
        if (ans >= LLONG_MAX / b)
            return LLONG_MAX;
        ans *= b;
    }
    return ans;
}

template<typename T> static constexpr T sqr(T a) { return a * a; }
template<typename T, typename P>
static constexpr T power(T a, P b) { return b == 0 ? T(1) : (b % 2) ? power(a, b - 1) * a : sqr(power(a, b / 2)); }

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    vll cap(61);
    for (int i = 2; i <= 60; i++)
    {
        ll lo = 1;
        ll hi = power(10LL, 18) + 1;
        while (hi - lo > 1)
        {
            ll mid = (lo + hi) / 2;
            if (pclamp(mid, i) > power(10LL, 18))
                hi = mid;
            else
                lo = mid;
        }
        cap[i] = hi;
    }
    for (int cas = 0; cas < T; cas++)
    {
        ll N;
        cin >> N;
        vll dp(61);
        ll ans = 0;
        for (int i = 60; i >= 2; i--)
        {
            ll lo = 1;
            ll hi = cap[i];
            while (hi - lo > 1)
            {
                ll mid = (lo + hi) / 2;
                if (power(mid, i) > N)
                    hi = mid;
                else
                    lo = mid;
            }
            dp[i] = lo - 1;
            for (int j = 2 * i; j <= 60; j += i)
                dp[i] -= dp[j];
            ans += dp[i];
        }
        cout << N - 1 - ans << '\n';
    }

    return 0;
}