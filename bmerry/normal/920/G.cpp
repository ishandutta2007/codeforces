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

static ll rpu(ll x, const vll fs)
{
    ll ans = 0;
    for (int m = 0; m < (1 << SZ(fs)); m++)
    {
        ll b = 1;
        int sign = 1;
        for (int i = 0; i < SZ(fs); i++)
            if (m & (1 << i))
            {
                b *= fs[i];
                sign = -sign;
            }
        ans += sign * (x / b);
    }
    return ans;
}

constexpr int MAX = 1000000;
static vll factor(MAX + 1);

static void solve()
{
    ll x, p, k;
    cin >> x >> p >> k;

    vll fs;
    ll tmp = p;
    while (tmp > 1)
    {
        ll f = factor[tmp];
        while (factor[tmp] == f)
            tmp /= f;
        fs.push_back(f);
    }

    k += rpu(x, fs);
    ll lo = 0;
    ll hi = 1000000000;
    while (hi - lo > 1)
    {
        ll mid = (lo + hi) / 2;
        if (rpu(mid, fs) < k)
            lo = mid;
        else
            hi = mid;
    }
    cout << hi << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    for (int i = 2; i <= MAX; i++)
        if (factor[i] == 0)
        {
            for (int j = i; j <= MAX; j += i)
                factor[j] = i;
        }

    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}