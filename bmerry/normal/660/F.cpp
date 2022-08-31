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

static __int128 ccw(const pll &a, const pll &b, const pll &c)
{
    __int128 dx1 = b.first - a.first;
    __int128 dy1 = b.second - a.second;
    __int128 dx2 = c.first - a.first;
    __int128 dy2 = c.second - a.second;
    return dx1 * dy2 - dx2 * dy1;
}

static void solve()
{
    int N;
    cin >> N;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    ll c0 = 0, c1 = 0;
    vector<pll> hull{{0, 0}};
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        c0 += (i + 1) * a[i];
        c1 -= a[i];
        pll next(i + 1, -(c0 + (i + 1) * c1));
        while (SZ(hull) >= 2 && ccw(hull[SZ(hull) - 2], hull.back(), next) >= 0)
            hull.pop_back();
        hull.push_back(next);
        int L = -1;
        int R = SZ(hull) - 1;
        while (R - L > 1)
        {
            int mid = (L + R) / 2;
            ll u = hull[mid].second + c1 * hull[mid].first;
            ll v = hull[mid + 1].second + c1 * hull[mid + 1].first;
            if (u < v)
                L = mid;
            else
                R = mid;
        }
        ans = max(ans, c0 + c1 * hull[R].first + hull[R].second);
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}