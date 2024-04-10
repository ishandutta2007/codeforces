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

struct ant
{
    int id;
    ll s;
    ll stop;
    char d;
};

static ll mod(ll a, ll M)
{
    a %= M;
    if (a < 0)
        a += M;
    return a;
}

static ll passes(const ant &a, const ant &b, ll M, ll T)
{
    if (a.d == b.d)
        return 0;
    if (a.d == 'L')
        return -passes(b, a, M, T);
    ll x = mod(b.s - a.s, M) / 2;
    if (T <= x)
        return 0;
    else
        return (T - x - 1) / (M / 2) + 1;
}

static void solve()
{
    int N;
    ll M, T;
    cin >> N >> M >> T;
    M *= 6;
    T = T * 6 - 1;
    vector<ant> ants(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ants[i].s >> ants[i].d;
        ants[i].s--;
        ants[i].s *= 6;
        ants[i].id = i;
    }
    sort(RA(ants), [](const ant &a, const ant &b) { return a.s < b.s; });

    int pass = 0;
    vector<ll> fin(N);
    for (int i = 0; i < N; i++)
    {
        pass = mod(pass + passes(ants[0], ants[i], M, T), N);
        ants[i].stop = mod(ants[i].s + (ants[i].d == 'R' ? T : -T), M);
        fin[i] = ants[i].stop;
    }
    sort(RA(fin));
    int pend = find(RA(fin), ants[0].stop) - fin.begin();
    assert(pend < N);
    int add = mod(pend - pass, N);
    vi ans(N);
    for (int i = 0; i < N; i++)
    {
        ll pos = fin[(i + add) % N];
        ans[ants[i].id] = (pos + 1) % M / 6;
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}