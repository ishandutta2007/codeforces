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

static ll gethi(int q, ll lo)
{
    if (q == 0)
        return lo - 1;
    else if (q == 1)
    {
        return lo + min(lo, 10000LL) - 1;
    }
    else if (lo >= 10000)
    {
        ll c = 0;
        for (int i = 0; i < q; i++)
            c = c * 10001LL + 10000;
        return c + lo - 1;
    }
    else
    {
        int k = min(lo, 10000LL);
        for (int i = 0; i <= k; i++)
        {
            ll h = gethi(q - 1, lo);
            lo = h + 2;
        }
        return lo - 2;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int q = 5;
    ll lo = 1;
    const ll M = 10004205361450474;
    ll hi = M;
    cerr << gethi(5, 1) << '\n';
    while (true)
    {
        vector<ll> guess;
        int k = min(lo, 10000LL);
        ll s = lo;
        for (int i = 0; i < k; i++)
        {
            ll h = gethi(q - 1, s) + 1;
            if (h > M)
                break;
            guess.push_back(h);
            s = h + 1;
        }
        k = SZ(guess);
        cout << k;
        for (ll v : guess)
            cout << ' ' << v;
        cout << endl;

        int ret;
        cin >> ret;
        if (ret < 0)
            break;
        if (ret > 0)
            lo = guess[ret - 1] + 1;
        if (ret < k)
            hi = guess[ret] - 1;
        q--;
    }

    return 0;
}