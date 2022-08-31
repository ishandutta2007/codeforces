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

static int d, m;
static vi gen;
static vi prefix;

static int sub(int x, int y)
{
    x -= y;
    if (x < 0)
        x += m;
    return x;
}

struct interval
{
    ll mask = 0;

    explicit interval(ll mask = 0) : mask(mask) {}

    interval operator&(const interval &x) const
    {
        return interval(mask & x.mask);
    }

    interval operator-(int shift) const
    {
        ll smask = (1LL << shift) - 1;
        return interval((mask >> shift) | ((mask & smask) << (m - shift)));
    }

    bool contains(int v) const
    {
        return mask & (1LL << v);
    }
};

static interval all;

static unordered_map<ll, vll> memo;

static vll &prepare(ll R)
{
    auto pos = memo.find(R);
    if (pos == memo.end())
    {
        vll &ans = memo[R];
        ans.resize(m);
        if (R <= d)
        {
            for (ll i = 0; i < R; i++)
                ans[gen[i]]++;
        }
        else
        {
            for (int p = 0; p < d; p++)
            {
                ll R1 = (R - p + d - 1) / d;
                const auto &ch = prepare(R1);
                for (int i = 0; i < m; i++)
                    ans[i] += ch[sub(i, gen[p])];
            }
        }
        return ans;
    }
    else
        return pos->second;
}

static inline ll solve0(int v, ll R)
{
    return prepare(R)[v];
}

static ll solve1(const interval &b, ll R)
{
    ll ans = 0;
    for (int i = 0; i < m; i++)
        if (b.contains(i))
            ans += solve0(i, R);
#ifdef PRINT
    cerr << "solve1: " << b.mask << ", " << R << " -> " << ans << '\n';
#endif
    return ans;
}

static ll solve(const vector<interval> &b, ll R)
{
    int N = SZ(b);
    ll ans = 0;
    if (R <= d && N <= d)
    {
        for (int i = 0; i < R; i++)
        {
            bool good = true;
            for (int j = 0; j < N; j++)
                if (!b[j].contains(prefix[i + j]))
                    good = false;
            ans += good;
        }
        return ans;
    }
    else if (N > 1)
    {
        for (int p = 0; p < d; p++)
        {
            int No = (N + p + d - 1) / d;
            vector<interval> c(No);
            int ofs = -p;
            for (int i = 0; i < No; i++)
            {
                interval cur = all;
                for (int j = 0; j < d; j++, ofs++)
                {
                    if (ofs >= 0 && ofs < N)
                        cur = cur & (b[ofs] - gen[j]);
                }
                c[i] = cur;
            }
            ans += solve(c, (R - p + d - 1) / d);
        }
#ifdef PRINT
        cerr << "solve: [";
        for (int i = 0; i < N; i++)
        {
            if (i)
                cerr << ", ";
            cerr << b[i].mask;
        }
        cerr << "], " << R << " -> " << ans << '\n';
#endif
        return ans;
    }
    else
        return solve1(b[0], R);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> d >> m;
    all = interval((1LL << m) - 1);
    gen.resize(d);
    for (int i = 0; i < d; i++)
        cin >> gen[i];
    prefix = gen;
    for (int i = 0; i < d; i++)
        prefix.push_back((gen[i] + gen[1]) % m);
    int N;
    cin >> N;
    vector<interval> b(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        b[i] = interval((2LL << x) - 1);
    }
    ll L, R;
    cin >> L >> R;
    L--;
    R--;
    cout << solve(b, R - N + 2) - solve(b, L) << '\n';

    return 0;
}