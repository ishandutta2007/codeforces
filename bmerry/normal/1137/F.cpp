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

    // Sum of values up to but excluding idx
    T sum_exclusive(size_type idx) const
    {
        return (idx == 0) ? identity : sum(idx - 1);
    }
};

struct node
{
    int size = 1;
    int depth = 0;
    int parent = -1;
    vi edges;
    int hid = -1;
    int hpos = -1;
};

struct segment
{
    int start;
    int stop;
    int label;

    segment() = default;
    segment(int start, int stop, int label) : start(start), stop(stop), label(label) {}
    bool operator<(const segment &other) const { return start < other.start; }
};

struct path
{
    vi idx;
    set<segment> segs;
};

static vector<node> nodes;
static vector<path> heavy;
static vector<int> prior;
static BIT<int> bit;

static void build_tree(int cur, int parent, int depth)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.depth = depth;
    for (int y : n.edges)
        if (y != parent)
        {
            const node &s = nodes[y];
            build_tree(y, cur, depth + 1);
            n.size += s.size;
        }
}

static void build_hl(int cur)
{
    node &n = nodes[cur];
    if (n.parent == -1 || n.size * 2 < nodes[n.parent].size)
    {
        int c = cur;
        int hid = heavy.size();
        path chain;
        while (true)
        {
            nodes[c].hid = hid;
            nodes[c].hpos = chain.idx.size();
            chain.idx.push_back(c);

            int hchild = -1;
            for (int y : nodes[c].edges)
                if (y != nodes[c].parent)
                    if (nodes[y].size * 2 >= nodes[c].size)
                    {
                        hchild = y;
                        break;
                    }
            if (hchild == -1)
                break;
            c = hchild;
        }
        chain.segs.emplace(0, chain.idx.size(), -1);
        heavy.push_back(move(chain));
    }

    for (int y : nodes[cur].edges)
        if (y != nodes[cur].parent)
            build_hl(y);
}

static int lca(int a, int b)
{
    while (nodes[a].hid != nodes[b].hid)
    {
        if (nodes[a].depth - nodes[a].hpos > nodes[b].depth - nodes[b].hpos)
            swap(a, b);
        b = heavy[nodes[b].hid].idx[0];
        b = nodes[b].parent;
    }
    return nodes[a].depth < nodes[b].depth ? a : b;
}

static void adjust(int label, int delta)
{
    if (label >= 0)
    {
        //cerr << "Adjust " << label << " " << delta << '\n';
        bit.add(label, delta);
    }
}

static void paint1(path &chain, int a, int b, int label)   // a <= b, excludes b
{
    auto pos = chain.segs.lower_bound(segment(a, b, label));
    while (pos != chain.segs.end() && pos->stop <= b)
    {
        auto nxt = next(pos);
        adjust(pos->label, pos->start - pos->stop);
        chain.segs.erase(pos);
        pos = nxt;
    }
    if (pos != chain.segs.end())
    {
        assert(pos->start <= b);
        if (pos->start < b)
        {
            adjust(pos->label, pos->start - b);
            segment replace{b, pos->stop, pos->label};
            chain.segs.erase(pos);
            pos = chain.segs.insert(replace).first;
        }
    }
    if (pos != chain.segs.begin())
    {
        --pos;
        assert(pos->start < a);
        if (pos->stop > a)
        {
            adjust(pos->label, a - pos->stop);
            segment replace{pos->start, a, pos->label};
            chain.segs.erase(pos);
            pos = chain.segs.insert(replace).first;
        }
    }
    adjust(label, b - a);
    chain.segs.emplace(a, b, label);
}

static void paint(int a, int b, int label)   // a below b, includes both
{
    while (nodes[a].hid != nodes[b].hid)
    {
        auto &chain = heavy[nodes[a].hid];
        paint1(chain, 0, nodes[a].hpos + 1, label);
        a = nodes[chain.idx[0]].parent;
    }
    auto &chain = heavy[nodes[a].hid];
    paint1(chain, nodes[b].hpos, nodes[a].hpos + 1, label);
}

static void up(int v, int prev, int label)
{
    prior.push_back(prev);
    int L = lca(v, prev);
    paint(prev, L, label);
    paint(v, L, label);
}

static int when(int v)
{
    const path &chain = heavy[nodes[v].hid];
    int a = nodes[v].hpos;
    auto pos = prev(chain.segs.upper_bound(segment{a, 0, 0}));
    int label = pos->label;
    int below = bit.sum_exclusive(label);
    int p = prior[label];
    int L = lca(v, p);
    int dist = nodes[v].depth + nodes[p].depth - 2 * nodes[L].depth;
    return below + dist;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    cin >> N >> Q;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    bit = BIT<int>(N + Q);
    build_tree(0, -1, 0);
    build_hl(0);
    int prev = N - 1;
    int label = 0;
    for (int i = 0; i < N; i++)
    {
        up(i, prev, label++);
        prev = i;
    }
    for (int i = 0; i < Q; i++)
    {
        char type[10];
        cin >> type;
        if (type[0] == 'u')
        {
            int v;
            cin >> v;
            up(v - 1, prev, label++);
            prev = v - 1;
        }
        else if (type[0] == 'w')
        {
            int v;
            cin >> v;
            int t = when(v - 1);
            cout << t + 1 << '\n';
        }
        else
        {
            int v, u;
            cin >> v >> u;
            int tv = when(v - 1);
            int tu = when(u - 1);
            cout << (tv < tu ? v : u) << '\n';
        }
    }

    return 0;
}