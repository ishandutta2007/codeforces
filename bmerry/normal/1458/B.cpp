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

static inline void up(int &x, int y)
{
    if (y > x)
        x = y;
}

static void solve()
{
    int N;
    cin >> N;
    vi a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];
    int T = accumulate(RA(b), 0);
    vector<vi> dp(N + 1, vi(100 * N + 1, INT_MIN / 2));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        int A = a[i];
        int B = b[i];
        for (int j = i; j >= 0; j--)
            for (int k = 0; k <= 100 * i; k++)
                up(dp[j + 1][k + B], dp[j][k] + A);
    }
    for (int i = 1; i <= N; i++)
    {
        int ans = 0;
        for (int j = 0; j <= 100 * i; j++)
            up(ans, min(j + T, 2 * dp[i][j]));
        cout << 0.5 * ans << ' ';
    }
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}