//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K, N;
    cin >> K >> N;
    vector<int> t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];
    sort(RA(t));
    vector<pii> tt(N - 1);
    for (int i = 0; i < N - 1; i++)
        tt[i] = pii(t[i], t[i + 1]);
    sort(RA(tt), [](const pii &a, const pii &b) { return a.second - a.first < b.second - b.first; });
    if (3 * K < N)
        tt.resize(3 * K);
    sort(RA(tt));

    vi dp(K + 1, INT_MAX / 2);
    dp[0] = 0;
    vi dpp(K + 1, INT_MAX / 2);
    for (int i = 1; i <= SZ(tt); i++)
    {
        int d = tt[i - 1].second - tt[i - 1].first;
        bool p = (i == 1 || tt[i - 2].second < tt[i - 1].first);
        vi dp2 = dp;
        for (int j = K; j > 0; j--)
            dp2[j] = min(dp2[j], (p ? dp[j - 1] : dpp[j - 1]) + d);
        dpp = move(dp);
        dp = move(dp2);
    }
    cout << dp[K] << '\n';

    return 0;
}