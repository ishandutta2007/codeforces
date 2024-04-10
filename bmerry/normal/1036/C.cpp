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

static ll choose(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
        ans = ans * (n - i) / (i + 1);
    return ans;
}

static ll ways(int n, int r)
{
    ll p9 = 1;
    ll ans = 0;
    for (int i = 0; i <= r; i++)
    {
        ans += choose(n, i) * p9;
        p9 *= 9;
    }
    return ans;
}

static ll count_classy(const string &R, int nz)
{
    int D = SZ(R);
    if (nz == 0 || R == "")
        return 1;
    int c = R[0] - '0';
    ll ans = 0;
    if (c == 0)
        return count_classy(R.substr(1), nz);
    ans += ways(D - 1, nz);
    ans += (c - 1) * ways(D - 1, nz - 1);
    ans += count_classy(R.substr(1), nz - 1);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        ll L, R;
        cin >> L >> R;
        ll aR = count_classy(to_string(R), 3);
        ll aL = count_classy(to_string(L - 1), 3);
        cout << aR - aL << '\n';
    }

    return 0;
}