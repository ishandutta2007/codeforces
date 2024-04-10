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

static void down(int &v, int u)
{
    if (u < v)
        v = u;
}

static bool solve()
{
    string s, t;
    cin >> s >> t;
    int L = SZ(s);
    vector<array<int, 26>> next(L + 1);
    array<int, 26> last;
    for (int i = 0; i < 26; i++)
        last[i] = L;
    next[L] = last;
    for (int i = L - 1; i >= 0; i--)
    {
        last[s[i] - 'a'] = i;
        next[i] = last;
    }
    for (int M = 0; M < SZ(t); M++)
    {
        int R = SZ(t) - M;
        vector<vi> dp(M + 1, vi(R + 1, L + 1));
        dp[0][0] = 0;
        for (int i = 0; i <= M; i++)
            for (int j = 0; j <= R; j++)
            {
                int d = dp[i][j];
                if (d > L)
                    continue;
                if (i < M)
                    down(dp[i + 1][j], next[d][t[i] - 'a'] + 1);
                if (j < R)
                    down(dp[i][j + 1], next[d][t[M + j] - 'a'] + 1);
            }
        if (dp[M][R] <= L)
            return true;
    }
    return false;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        bool ans = solve();
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}