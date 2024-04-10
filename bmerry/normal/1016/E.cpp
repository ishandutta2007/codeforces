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

static double shade_dist(const vector<pll> &fences, const vector<ll> &lsum, double a)
{
    auto p = lower_bound(RA(fences), a, [](const pll &f, double a) { return f.first < a; }) - fences.begin();
    double ans = lsum[p];
    if (p > 0 && a < fences[p - 1].second)
        ans -= fences[p - 1].second - a;
    return ans;
}

static void solve()
{
    ll sy, a, b;
    int N;
    cin >> sy >> a >> b >> N;
    vector<pll> fences(N);
    vector<ll> lsum(N + 1);
    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        fences[i] = pll(L, R);
        lsum[i + 1] = lsum[i] + (R - L);
    }

    int Q;
    cin >> Q;
    cout << fixed << setprecision(12);
    for (int i = 0; i < Q; i++)
    {
        ll x, y;
        cin >> x >> y;
        double a0 = x + (a - x) * double(y) / (y - sy);
        double b0 = x + (b - x) * double(y) / (y - sy);
        double shade_a = shade_dist(fences, lsum, a0);
        double shade_b = shade_dist(fences, lsum, b0);
        double ans = (shade_b - shade_a) / (b0 - a0) * (b - a);
        cout << ans << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}