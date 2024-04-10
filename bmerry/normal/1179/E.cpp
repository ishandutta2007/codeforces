// DOES NOT WORK
// Needs too many queries (~600K)

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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static map<pll, ll> cache;

static ll query(ll idx, ll pos)
{
    pll key(idx, pos);
    if (cache.count(key))
        return cache[key];
    cout << "? " << idx + 1 << ' ' << pos << endl;
    ll ans;
    cin >> ans;
    cache[key] = ans;
    return ans;
}

static ll rev(int idx, ll trg, ll A, ll B)
{
    while (B - A > 1)
    {
        ll M = (A + B) / 2;
        if (query(idx, M) >= trg)
            B = M;
        else
            A = M;
    }
    return B;
}

static mt19937 engine;
static constexpr ll BIG = 1000000000000000000LL;

static void recurse(vi &funcs, vector<pll> &ranges, ll lo, ll hi, ll P, ll Q)
{
    if (SZ(funcs) == 1)
    {
        ranges[funcs[0]] = pll(lo, hi);
        return;
    }

    ll N = SZ(funcs);
    ll N0 = N / 2;
    ll trg = P + (Q - P) / N * N0;
    int A = 0;
    int B = N;
    ll pos;
    while (true)
    {
        int M = uniform_int_distribution<int>(A, B - 1)(engine);
        swap(funcs[M], funcs[B - 1]);
        pos = rev(funcs[B - 1], trg, lo, hi);
        int g2 = partition(funcs.begin() + A, funcs.begin() + (B - 1),
                           [&](int i) { return query(i, pos) >= trg; }) - funcs.begin();
        swap(funcs[B - 1], funcs[g2]);
        int g1 = g2;
        while (g1 > A && query(funcs[g1 - 1], pos - 1) == trg - 1)
        {
            g1--;
            //assert(query(funcs[g1], pos) == trg);
        }
        if (g2 < N0)
            A = g2 + 1;
        else if (g1 > N0)
            B = g1;
        else
            break;
    }
    vi f0(funcs.begin(), funcs.begin() + N0);
    vi f1(funcs.begin() + N0, funcs.end());
    recurse(f0, ranges, lo, pos, P, trg);
    recurse(f1, ranges, pos, hi, trg, Q);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll L;
    cin >> N >> L;
    vi funcs;
    vector<pll> ranges(N);
    for (int i = 0; i < N; i++)
        funcs.push_back(i);
    recurse(funcs, ranges, 0, BIG, 0, L);
    cout << "!" << endl;
    for (int i = 0; i < N; i++)
    {
        assert(ranges[i].first < ranges[i].second);
        cout << ranges[i].first << ' ' << ranges[i].second << endl;
    }

    return 0;
}