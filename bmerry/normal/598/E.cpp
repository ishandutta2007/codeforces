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

static int dp[31][31][51] = {};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    for (int R = 1; R <= 30; R++)
        for (int C = 1; C <= 30; C++)
            for (int K = 0; K <= min(50, R * C); K++)
            {
                if (C < R)
                {
                    dp[R][C][K] = dp[C][R][K];
                    continue;
                }
                if (K == 0 || K == R * C)
                {
                    dp[R][C][K] = 0;
                    continue;
                }
                int ans = INT_MAX;
                for (int i = 1; i < R; i++)
                {
                    for (int p = max(0, K - (R - i) * C); p <= min(K, i * C); p++)
                        ans = min(ans, dp[i][C][p] + dp[R - i][C][K - p] + C * C);
                }
                for (int i = 1; i < C; i++)
                    for (int p = max(0, K - (C - i) * R); p <= min(K, i * R); p++)
                        ans = min(ans, dp[R][i][p] + dp[R][C - i][K - p] + R * R);
                dp[R][C][K] = ans;
            }

    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N, M, K;
        cin >> N >> M >> K;
        cout << dp[N][M][K] << '\n';
    }

    return 0;
}