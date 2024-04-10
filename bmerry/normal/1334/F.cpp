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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi a(N);
    vll p(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> p[i];
    int M;
    cin >> M;
    vi b(M + 2);
    for (int i = 0; i < M; i++)
        cin >> b[i + 1];
    b[M + 1] = N + 1;

    vll cull(N + 1);
    vll csum(M + 2);
    vll negsum(N + 1);
    for (int i = 0; i < N; i++)
    {
        int idx = lower_bound(RA(b), a[i]) - b.begin();
        if (b[idx] == a[i])
            cull[i] = csum[idx];
        if (p[i] >= 0)
            csum[idx] += p[i];
        negsum[i + 1] = negsum[i] + min(0LL, p[i]);
    }
    cull[N] = csum[M + 1];

    vi last(M + 2, N);
    vll dp(M + 2, LLONG_MAX);
    dp[M + 1] = cull[N];
    ll ans = LLONG_MAX;
    for (int i = N - 1; i >= 0; i--)
    {
        int idx = lower_bound(RA(b), a[i]) - b.begin();
        if (b[idx] == a[i])
        {
            int nxt = last[idx + 1];
            int lvl = last[idx];
            ll d = LLONG_MAX;
            if (dp[idx + 1] != LLONG_MAX)
                d = min(d, dp[idx + 1] + cull[i] + negsum[nxt] - negsum[i + 1]);
            if (dp[idx] != LLONG_MAX)
                d = min(d, dp[idx] + negsum[lvl] - negsum[i]);
            dp[idx] = d;
            if (idx == 1 && d != LLONG_MAX)
                ans = min(ans, d + negsum[i]);
            last[idx] = i;
        }
    }

    if (ans == LLONG_MAX)
        cout << "NO\n";
    else
        cout << "YES\n" << ans << '\n';

    return 0;
}