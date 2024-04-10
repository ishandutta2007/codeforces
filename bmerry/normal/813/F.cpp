#pragma GCC optimize("O3")
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

static constexpr int BLOCK = 300;

struct jump
{
    int trg = -1;
    int parity = 0;
};

jump operator+(const jump &a, const jump &b)
{
    return jump{b.trg, a.parity ^ b.parity};
}

class UnionFind
{
private:
    std::vector<jump> parent;
    std::vector<pair<int, jump>> unwind;
    bool is_bipartite = true;
    bool was_bipartite = true;

public:
    explicit UnionFind(int size = 0) : parent(size) {}

    int size() const { return parent.size(); }

    jump find(int x) const
    {
        assert(x >= 0 && x < size());
        jump y{x, 0};
        while (parent[y.trg].trg >= 0)
            y = y + parent[y.trg];
        return y;
    }

    bool merge(int x, int y)
    {
        jump xj = find(x);
        jump yj = find(y);
        if (xj.trg == yj.trg)
        {
            if (xj.parity == yj.parity)
                is_bipartite = false;
            return false;
        }
        if (-parent[xj.trg].trg > -parent[yj.trg].trg)
            std::swap(xj, yj);
        unwind.emplace_back(xj.trg, parent[xj.trg]);
        unwind.emplace_back(yj.trg, parent[yj.trg]);
        parent[yj.trg].trg += parent[xj.trg].trg;
        parent[xj.trg].trg = yj.trg;
        parent[xj.trg].parity = xj.parity ^ yj.parity ^ 1;
        return true;
    }

    void freeze()
    {
        unwind.clear();
        was_bipartite = is_bipartite;
    }

    void reset()
    {
        for (auto it = unwind.rbegin(); it != unwind.rend(); ++it)
            parent[it->first] = it->second;
        is_bipartite = was_bipartite;
    }

    bool bipartite() const
    {
        return is_bipartite;
    }
};

static void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<pii> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        queries[i] = pii(x, y);
    }

    set<pii> edges;
    for (int bs = 0; bs < Q; bs += BLOCK)
    {
        int be = min(bs + BLOCK, Q);
        set<pii> flip;

        for (int i = bs; i < be; i++)
            flip.insert(queries[i]);

        UnionFind uf(N);
        set<pii> extra;
        for (const auto &e : edges)
        {
            if (!flip.count(e))
                uf.merge(e.first, e.second);
            else
                extra.insert(e);
        }
        uf.freeze();

        for (int i = bs; i < be; i++)
        {
            if (edges.count(queries[i]))
            {
                edges.erase(queries[i]);
                extra.erase(queries[i]);
            }
            else
            {
                edges.insert(queries[i]);
                extra.insert(queries[i]);
            }
            for (const auto &e : extra)
                uf.merge(e.first, e.second);
            cout << (uf.bipartite() ? "YES\n" : "NO\n");
            uf.reset();
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}