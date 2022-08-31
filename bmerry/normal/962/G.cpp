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

template<typename T>
static inline T dot(const std::complex<T> &a, const std::complex<T> &b)
{
    return real(conj(a) * b);
}

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b)
{
    return imag(conj(a) * b);
}

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b, const std::complex<T> &c)
{
    return cross(b - a, c - a);
}

class CompareX
{
public:
    template<typename T>
    bool operator()(const std::complex<T> &a, const std::complex<T> &b) const
    {
        if (a.real() != b.real())
            return a.real() < b.real();
        else
            return a.imag() < b.imag();
    }
};

class UnionFind
{
private:
    mutable std::vector<int> parent;

public:
    explicit UnionFind(int size = 0) : parent(size, -1) {}

    int size() const { return parent.size(); }

    int find(int x) const
    {
        assert(x >= 0 && x < size());
        int y = x;
        while (parent[y] >= 0)
            y = parent[y];
        while (parent[x] >= 0)
        {
            int nxt = parent[x];
            parent[x] = y;
            x = nxt;
        }
        return y;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (-parent[x] > -parent[y])
            std::swap(x, y);
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }
};

static void clip(vector<pair<pnt, pnt>> &edges, const pnt &p, const pnt &q)
{
    vector<pair<pnt, pnt>> out;
    vector<pnt> cuts;
    for (const auto &e : edges)
    {
        ll c1 = cross(p, q, e.first);
        ll c2 = cross(p, q, e.second);
        if (c1 > 0 && c2 > 0)
            out.push_back(e);
        else if (c1 > 0 || c2 > 0)
        {
            pnt cut = (e.first * c2 - e.second * c1) / (c2 - c1);
            if (c1 > 0)
                out.emplace_back(e.first, cut);
            else
                out.emplace_back(cut, e.second);
            cuts.push_back(cut);
        }
    }
    sort(RA(cuts), [&](const pnt &a, const pnt &b) { return dot(q - p, b - a) > 0; });
    for (int i = 0; i + 1 < SZ(cuts); i += 2)
        out.emplace_back(cuts[i], cuts[i + 1]);
    edges = move(out);
}

static void solve()
{
    int N;
    ll x1, y1, x2, y2;
    cin >> x1 >> y2 >> x2 >> y1;
    cin >> N;
    vector<pnt> pnts(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
    }
    vector<pair<pnt, pnt>> edges(N);
    for (int i = 0; i < N; i++)
        edges[i] = make_pair(pnts[i], pnts[(i + 1) % N]);

    clip(edges, pnt(100000, y2), pnt(-1, y2));
    clip(edges, pnt(x1, 100000), pnt(x1, -1));
    clip(edges, pnt(-1, y1), pnt(100000, y1));
    clip(edges, pnt(x2, -1), pnt(x2, 100000));

    map<pnt, int, CompareX> ids;
    int M = 0;
    for (const auto &e : edges)
    {
        if (!ids.count(e.first))
            ids[e.first] = M++;
        if (!ids.count(e.second))
            ids[e.second] = M++;
    }

    UnionFind uf(M);
    int C = M;
    for (const auto &e : edges)
        if (uf.merge(ids[e.first], ids[e.second]))
            C--;
    cout << C << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}