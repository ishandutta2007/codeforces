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

static pair<ll, ll> fnext(ll k, ll m)
{
    ll first = k * (k + 1) / 2;
    if (m <= first)
        return pair(first, 0);

    ll base = (m - first) / k + 1;
    auto [gap, pos] = fnext(k, base);
    if (gap == base)
        base--;
    ll bpos = base - 1 - pos;
    ll step = k - bpos % k;
    if (step == k)
        step = 0;
    bpos += step;
    base += step;
    if (base >= gap)
        base++;

    ll red = base * k + k * (k - 1) / 2;
    if (base <= gap && gap < base + k)
        red += base + k - gap;
    if (red < m)
    {
        bpos += k;
        if (base < gap && base + k >= gap)
            base++;
        base += k;
        red = base * k + k * (k - 1) / 2;
        if (base <= gap && gap < base + k)
            red += base + k - gap;
    }

    assert(red >= m);
    return pair(red, bpos / k);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        ll n, k;
        cin >> n >> k;
        auto [gap, pos] = fnext(k, n);
        ll ans;
        if (gap == n)
            ans = (k + 1) * pos + k;
        else
        {
            ll green = n - 1 - pos;
            ans = green + green / k;
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}