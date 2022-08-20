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

static void solve()
{
    int N;
    ll K;
    cin >> N >> K;
    vector<__int128> a(N);
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
    }
    reverse(RA(a));
    while (a.back() == 0)
        a.pop_back();
    reverse(RA(a));
    N = SZ(a);

    if (*max_element(RA(a)) >= K)
    {
        cout << "0\n";
        return;
    }
    K -= a.back();
    a.back() = 0;
    if (N >= 4)
    {
        ll idx = 0;
        while (a.back() < K)
        {
            partial_sum(RA(a), a.begin());
            idx++;
        }
        cout << idx << '\n';
    }
    else if (N == 3)
    {
        ll lo = 0;
        ll hi = min(K, 10000000000LL);
        while (hi - lo > 1)
        {
            __int128 mid = (lo + hi) / 2;
            __int128 s = mid * a[1] + (mid * (mid + 1) / 2) * a[0];
            if (s >= K)
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << '\n';
    }
    else
    {
        assert(N == 2);
        ll ans = (K + a[0] - 1) / a[0];
        cout << ans << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}