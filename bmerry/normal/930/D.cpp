//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

static ll solve(vector<pii> &pnts)
{
    ll ans = 0;
    sort(RA(pnts), [](const pii &a, const pii &b) { return a.second < b.second; });
    ll prev = INT_MIN / 2;
    multiset<ll> ux, dx;
    for (int i = 0; i < SZ(pnts); i++)
        ux.insert(pnts[i].first);
    for (int i = 0; i < SZ(pnts); i++)
    {
        ll x = pnts[i].first;
        ll y = pnts[i].second;
        if (!dx.empty() && !ux.empty())
        {
            ll x0 = max(*dx.begin(), *ux.begin());
            ll x1 = min(*dx.rbegin(), *ux.rbegin());
            if (x0 < x1)
                ans += (x1 - x0) / 2 * (y - prev) / 2;
        }
        ux.erase(ux.find(x));
        dx.insert(x);
        prev = y;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pii> even, odd;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1)
            odd.emplace_back(x + y, x - y);
        else
            even.emplace_back(x + y + 1, x - y - 1);
    }
    ll ae = solve(even);
    ll ao = solve(odd);
    cout << ae + ao << '\n';

    return 0;
}