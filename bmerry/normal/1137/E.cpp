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

static ll ccw(const pll &a, const pll &b, const pll &c)
{
    ll dx1 = b.first - a.first;
    ll dx2 = c.first - a.first;
    ll dy1 = b.second - a.second;
    ll dy2 = c.second - a.second;
    typedef long double ld;
    ld cc = ld(dx1) * ld(dy2) - ld(dx2) * ld(dy1);
    if (fabsl(cc) > 1e16)
        return cc > 0 ? 1 : -1;
    else
        return dx1 * dy2 - dx2 * dy1;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll b = 0, s = 0, x = 0;
    ll N, Q;
    cin >> N >> Q;
    deque<pll> hull;
    hull.emplace_back(0, 0);

    auto eval = [&](const pll &v) { return v.second + b + s * (v.first + x); };

    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            {
                ll k;
                cin >> k;
                x += k;
                b -= k * s;
                pll n(-x, -b);
                N += k;
                while (hull.size() >= 2 && ccw(n, hull[0], hull[1]) <= 0)
                    hull.pop_front();
                hull.push_front(n);
            }
            break;
        case 2:
            {
                ll k;
                cin >> k;
                pll n(N - x, -(N * s + b));
                N += k;
                while (hull.size() >= 2 && ccw(hull[SZ(hull) - 2], hull.back(), n) <= 0)
                    hull.pop_back();
                hull.push_back(n);
            }
            break;
        case 3:
            {
                ll nb, ns;
                cin >> nb >> ns;
                b += nb;
                s += ns;
            }
            break;
        }
        while (hull.size() >= 2 && eval(hull[SZ(hull) - 2]) <= eval(hull.back()))
            hull.pop_back();

        cout << hull.back().first + x + 1 << ' ' << eval(hull.back()) << '\n';
    }

    return 0;
}