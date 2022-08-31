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

static ll choose[501][501];

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, P;
    cin >> N >> M >> P;
    for (int i = 0; i <= N; i++)
    {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % P;
    }

    vector<ll> dp1(N + 1);
    vector<ll> dpw(N + 1);
    dp1[0] = 0;
    dpw[0] = 1;
    for (int m = 1; m <= M; m++)
    {
        for (int i = 0; i < m; i++)
        {
            ll w = dpw[i] * dpw[m - 1 - i] % P;
            w = w * choose[m - 1][i] % P;
            dpw[m] = (dpw[m] + w * (m + 1) % P) % P;

            ll s1 = dp1[i] * dpw[m - 1 - i] % P;
            ll s2 = dp1[m - 1 - i] * dpw[i] % P;
            ll add = (s1 + s2) % P * (m + 1) % P * choose[m - 1][i] % P;
            add += w * ((i * (i + 1) + (m - 1 - i) * (m - i)) / 2) % P;
            dp1[m] = (dp1[m] + add) % P;
        }
    }

    vector<vll> dp(N + 1, vll(N + 1)), dps(N + 1, vll(N + 1));
    dps[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][i] = dp1[i];
        dps[i][i] = dpw[i];
        dps[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            dps[i][j] = dps[i - 1][j];
            for (int k = 1; k <= j; k++)
            {
                dps[i][j] = (dps[i][j] + dpw[k] * dps[i - k - 1][j - k] % P * choose[j][k]) % P;
                ll add = (dp[i - k - 1][j - k] * dpw[k] % P + dps[i - k - 1][j - k] * dp1[k]) % P;
                dp[i][j] = (dp[i][j] + add * choose[j][k] % P) % P;
            }
        }
    }
    cout << dp[N][M] << '\n';

    return 0;
}