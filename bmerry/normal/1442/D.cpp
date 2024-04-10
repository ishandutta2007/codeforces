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

static ll recurse(int A, int B, const vll &dp, const vector<vll> &pref)
{
    ll ans = 0;
    int K = SZ(dp) - 1;
    if (B - A == 1)
    {
        for (int i = 0; i < SZ(pref[A]); i++)
            ans = max(ans, pref[A][i] + dp[K - i]);
    }
    else
    {
        int M = (A + B) / 2;
        vll dp2 = dp;
        for (int i = M; i < B; i++)
        {
            int s = SZ(pref[i]) - 1;
            ll w = pref[i].back();
            for (int j = K; j >= s; j--)
                dp2[j] = max(dp2[j], dp2[j - s] + w);
        }
        ans = max(ans, recurse(A, M, dp2, pref));

        dp2 = dp;
        for (int i = A; i < M; i++)
        {
            int s = SZ(pref[i]) - 1;
            ll w = pref[i].back();
            for (int j = K; j >= s; j--)
                dp2[j] = max(dp2[j], dp2[j - s] + w);
        }
        ans = max(ans, recurse(M, B, dp2, pref));
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vector<vll> pref(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        pref[i].resize(t + 1);
        for (int j = 0; j < t; j++)
        {
            ll x;
            cin >> x;
            pref[i][j + 1] = pref[i][j] + x;
        }
        if (t > K)
            pref[i].resize(K + 1);
    }

    vll dp(K + 1);
    ll ans = recurse(0, N, dp, pref);
    cout << ans << '\n';

    return 0;
}