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

constexpr int MAXA = 5032108;
static vi factor(MAXA + 1);

static void init()
{
    for (int i = 2; i <= MAXA; i++)
        if (factor[i] == 0)
        {
            for (int j = i; j <= MAXA; j += i)
                factor[j] = i;
        }
}

static vi factorise(int x)
{
    vi out;
    while (x > 1)
    {
        int p = factor[x];
        int pp = p * p;
        while (x % pp == 0)
            x /= pp;
        if (x % p == 0)
        {
            out.push_back(p);
            x /= p;
        }
    }
    return out;
}

static vector<pii> factors(const vi &primes)
{
    int P = SZ(primes);
    vector<pii> out;
    out.reserve(1 << P);
    out.emplace_back(1, 0);
    for (int p : primes)
    {
        int N = SZ(out);
        for (int j = 0; j < N; j++)
            out.emplace_back(out[j].first * p, out[j].second + 1);
    }
    return out;
}

struct query
{
    int l, r;
    int idx;
    int ans;
};

template<typename T>
static void up(T &x, T y)
{
    if (y > x)
        x = y;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    init();

    int N, Q;
    cin >> N >> Q;
    vi a(N);
    vector<query> q(Q);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < Q; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
        q[i].l--;
    }
    sort(RA(q), [](const query &a, const query &b) { return a.r < b.r; });

    vi nearest(15, -1);
    vector<array<int, 8>> dnearest(MAXA + 1);
    for (int i = 0; i <= MAXA; i++)
        for (int j = 0; j < 8; j++)
            dnearest[i][j] = -1;

    int qp = 0;
    for (int i = 0; i < N; i++)
    {
        vi primes = factorise(a[i]);
        auto fact = factors(primes);
        for (const auto &item : fact)
        {
            int f = item.first;
            int d = SZ(primes) - item.second;
            for (int j = 0; j < 8; j++)
                up(nearest[d + j], dnearest[f][j]);
            up(dnearest[f][d], i);
        }

        while (qp < Q && q[qp].r == i + 1)
        {
            int ans = 100;
            for (int i = 14; i >= 0; i--)
                if (nearest[i] >= q[qp].l)
                    ans = i;
            q[qp].ans = ans;
            qp++;
        }
    }

    sort(RA(q), [](const query &a, const query &b) { return a.idx < b.idx; });
    for (const auto &c : q)
        cout << c.ans << '\n';

    return 0;
}