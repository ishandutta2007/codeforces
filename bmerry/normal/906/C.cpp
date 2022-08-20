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

static inline void setbit(int &v, int b)
{
    v |= 1 << b;
}

static inline bool getbit(int v, int b)
{
    return v & (1 << b);
}

typedef array<int, 22> table;

static int N;
static int best;

static void recurse(const table &t, int pos, int mask)
{
    if (pos == N)
    {
        if (count(RA(t), (1 << N) - 1) == N
            && __builtin_popcount(mask) < __builtin_popcount(best))
                best = mask;
    }
    else
    {
        recurse(t, pos + 1, mask);
        table t2 = t;
        for (int i = 0; i < N; i++)
            if (getbit(t[pos], i))
                t2[i] |= t[pos];
        recurse(t2, pos + 1, mask | (1 << pos));
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int M;
    cin >> N >> M;
    table orig{{}};
    for (int i = 0; i < N; i++)
        setbit(orig[i], i);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        setbit(orig[u], v);
        setbit(orig[v], u);
    }
    best = (1 << N) - 1;
    recurse(orig, 0, 0);
    cout << __builtin_popcount(best) << '\n';
    for (int i = 0; i < N; i++)
        if (getbit(best, i))
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}