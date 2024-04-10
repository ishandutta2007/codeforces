//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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
    cin >> N;
    vll sum(N + 1);

    map<ll, ll, greater<ll>> pareto;
    pareto[0] = N;
    ll cur = N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        ll s = sum[i] + a;
        sum[i + 1] = s;
        auto pos = pareto.upper_bound(s);
        ll nxt = LLONG_MIN / 2;
        if (pos != pareto.end())
            nxt = pos->second;
        if (a == 0)
            nxt = max(nxt, cur - 1);
        else if (a < 0)
            nxt = max(nxt, cur - 2);

        cur = nxt;
        if (pos == pareto.end() || cur > pos->second)
        {
            decltype(pos) ptr;
            if (pos != pareto.begin() && prev(pos)->first == s)
            {
                ptr = prev(pos);
                ptr->second = max(ptr->second, cur);
            }
            else
                ptr = pareto.insert(pair(s, cur)).first;
            while (ptr != pareto.begin() && prev(ptr)->second < cur)
                pareto.erase(prev(ptr));
        }
    }
    cout << cur << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}