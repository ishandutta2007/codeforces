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

template<typename T, typename Op = std::plus<T> >
class BIT
{
private:
    std::vector<T> values;
    Op op;
    T identity;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    explicit BIT(size_type size = 0, Op op = Op(), T identity = T())
        : values(size + 1, identity), op(op), identity(identity) {}

    size_type size() const { return values.size() - 1; }

    void add(size_type idx, T delta)
    {
        assert(idx < size());
        idx++;
        while (idx < values.size())
        {
            values[idx] = op(values[idx], delta);
            idx += idx & ~(idx - 1);
        }
    }

    // Sum of values up to and including idx
    T sum(size_type idx) const
    {
        assert(idx < size());
        T ans = identity;
        idx++;
        while (idx > 0)
        {
            ans = op(ans, values[idx]);
            idx &= idx - 1;
        }
        return ans;
    }
};

struct node
{
    int depth;
    int idx;
    int end;
};

static vector<node> nodes;

struct change
{
    int start;
    int end;
    ll x;
};

static void build(const vector<vi> &edges, int cur, int parent, int depth, int &pool)
{
    node &n = nodes[cur];
    n.depth = depth;
    n.idx = pool++;
    for (int y : edges[cur])
        if (y != parent)
            build(edges, y, cur, depth + 1, pool);
    n.end = pool;
}

static void solve()
{
    int N;
    cin >> N;
    vector<vi> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    nodes.resize(N);
    int pool = 0;
    build(edges, 0, -1, 0, pool);

    vector<vi> by_depth(N);
    for (int i = 0; i < N; i++)
        by_depth[nodes[i].depth].push_back(i);

    vector<vector<change>> changes(N + 1);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int v, d;
        ll x;
        cin >> v >> d >> x;
        v--;
        const node &n = nodes[v];
        changes[n.depth].push_back(change{n.idx, n.end, x});
        changes[min(N, n.depth + d + 1)].push_back(change{n.idx, n.end, -x});
    }

    BIT<ll> bit(N + 1);
    vll ans(N);
    for (int i = 0; i < N; i++)
    {
        for (const change &c : changes[i])
        {
            bit.add(c.start, c.x);
            bit.add(c.end, -c.x);
        }
        for (int v : by_depth[i])
            ans[v] = bit.sum(nodes[v].idx);
    }

    for (ll a : ans)
        cout << a << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}