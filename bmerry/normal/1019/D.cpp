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
typedef complex<ll> pnt;
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

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

// Sort by Y then by X
class CompareY
{
public:
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }
};

static void dump(const pnt &a)
{
    cout << a.real() << ' ' << a.imag() << '\n';
}

struct edge
{
    int a;
    int b;
    pnt delta;

    bool operator<(const edge &other) const
    {
        return cross(delta, other.delta) > 0;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll S;
    cin >> N >> S;
    S *= 2;
    vector<pnt> pnts(N);
    vi order(N), rorder(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
        order[i] = i;
        rorder[i] = i;
    }
    sort(RA(pnts), CompareY());

    vector<edge> edges;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            edges.push_back(edge{i, j, pnts[j] - pnts[i]});
    sort(RA(edges));

    for (const edge &e : edges)
    {
        int lo = rorder[e.a];
        int hi = N;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            ll area = cross(e.delta, pnts[order[mid]] - pnts[e.a]);
            if (area <= S)
                lo = mid;
            else
                hi = mid;
        }
        if (cross(e.delta, pnts[order[lo]] - pnts[e.a]) == S)
        {
            cout << "Yes\n";
            dump(pnts[e.a]);
            dump(pnts[e.b]);
            dump(pnts[order[lo]]);
            return 0;
        }
        int &p = rorder[e.a];
        int &q = rorder[e.b];
        assert(q == p + 1);
        swap(order[p], order[q]);
        swap(p, q);
    }

    cout << "No\n";
    return 0;
}