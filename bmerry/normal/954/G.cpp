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

static bool protect(vll a, int R, ll def, ll K)
{
    int N = SZ(a);
    ll cur = 0;
    for (int i = 0; i <= min(N - 1, R); i++)
        cur += a[i];
    for (int i = 0; i < N; i++)
    {
        if (cur < def)
        {
            ll extra = def - cur;
            if (extra > K)
                return false;
            K -= extra;
            int pos = min(N - 1, i + R);
            a[pos] += extra;
            cur += extra;
        }
        if (i >= R)
            cur -= a[i - R];
        if (i + R + 1 < N)
            cur += a[i + R + 1];
    }
    return K >= 0;
}

static void solve()
{
    int N, R;
    ll K;
    cin >> N >> R >> K;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    ll lo = 0;
    ll hi = 2000000000000000000LL;
    while (hi - lo > 1)
    {
        ll mid = (lo + hi) / 2;
        if (protect(a, R, mid, K))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}