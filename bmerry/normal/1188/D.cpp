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

static inline void decr(int &x, int y)
{
    if (y < x)
        x = y;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> a2(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vi dp(N + 1, INT_MAX / 2);
    vi dp2(N + 1);
    dp[N] = 0;
    for (int b = 0; b < 59; b++)
    {
        fill(RA(dp2), INT_MAX / 2);
        int lz = 0, lo = 0;
        int uz = 0, uo = 0;
        ll mask = 1LL << b;
        for (ll v : a)
            if (v & mask)
                uo++;
        uz = N - uo;
        int nxto = uz;
        for (int c = 0; c <= N; c++)
        {
            decr(dp2[lz], dp[c] + lo + uz);
            decr(dp2[N - uo], dp[c] + lz + uo);
            if (c < N)
            {
                if (a[c] & mask)
                {
                    a2[nxto++] = a[c];
                    lo++;
                    uo--;
                }
                else
                {
                    a2[lz] = a[c];
                    lz++;
                    uz--;
                }
            }
        }
        swap(dp, dp2);
        swap(a, a2);
    }
    cout << dp[N] << '\n';

    return 0;
}