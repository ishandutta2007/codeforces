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
typedef unsigned long long ull;
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

static vector<string> fibs;

static ll addc(ll x, ll y)
{
    ull sum = ull(x) + ull(y);
    return min(sum, ull(LLONG_MAX));
}

struct state
{
    vector<bool> prefs, suffs;
    ll internal;
};

static state operator+(const state &a, const state &b)
{
    int L = a.prefs.size() - 1;
    state out;
    out.prefs = a.prefs;
    out.suffs = b.suffs;
    out.internal = addc(a.internal, b.internal);
    for (int i = 1; i < L; i++)
        if (a.suffs[i] && b.prefs[L - i])
            out.internal = addc(out.internal, 1);
    return out;
}

static ll count_sub(const string_view &a, const string_view &b)
{
    ll ans = 0;
    for (int i = 0; i <= SZ(a) - SZ(b); i++)
        if (a.substr(i, SZ(b)) == b)
            ans++;
    return ans;
}

static state make_state(const string_view &a, const string_view &s)
{
    assert(a.size() >= s.size());
    state out;
    out.internal = count_sub(a, s);
    out.prefs.resize(s.size() + 1);
    out.suffs.resize(s.size() + 1);
    for (int i = 1; i <= SZ(s); i++)
    {
        out.prefs[i] = a.substr(0, i) == s.substr(SZ(s) - i);
        out.suffs[i] = a.substr(SZ(a) - i) == s.substr(0, i);
    }
    return out;
}

static state occurs(int N, const string_view &s)
{
    vector<string> fib;
    if (N < SZ(fibs))
        return make_state(fibs[N], s);

    int c = SZ(fibs) - 1;
    state st[2];
    st[0] = make_state(fibs[c - 1], s);
    st[1] = make_state(fibs[c], s);
    while (c < N)
    {
        state nxt = st[0] + st[1];
        st[0] = move(st[1]);
        st[1] = move(nxt);
        c++;
    }
    return st[1];
}

static void solve()
{
    int N, M;
    ll K;
    cin >> N >> K >> M;
    K--;
    fibs.push_back("0"s);
    fibs.push_back("1"s);
    while (fibs.back().size() < 600)
        fibs.push_back(fibs[SZ(fibs) - 2] + fibs.back());

    string cur = "";
    while (SZ(cur) < M)
    {
        if (!cur.empty() && occurs(N, cur).suffs.back())
        {
            if (K == 0)
                break;
            K--;
        }
        cur += '0';
        ll z = occurs(N, cur).internal;
        if (z <= K)
        {
            K -= z;
            cur.back() = '1';
        }
    }
    cout << cur << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}