// Appears to be correct, but uses too much memory (and may be too slow)

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

template<typename Node>
class SegmentTree
{
public:
    typedef std::size_t size_type;
    typedef Node node;

private:
    size_type N;
    size_type offset;
    mutable std::vector<node> nodes;

    void push_down(size_type idx, int L, int R) const
    {
        if (idx < offset)
            nodes[idx].push_down(L, R, nodes[2 * idx], nodes[2 * idx + 1]);
    }

    template<typename Op>
    auto query(size_type cur, size_type L, size_type R, size_type A, size_type B, const Op &op) const
        -> decltype(nodes[0].query(L, R, op))
    {
        assert(A < R && B > L && A < B);
        if (A <= L && B >= R)
            return nodes[cur].query(L, R, op);
        else
        {
            size_type M = (L + R) / 2;
            push_down(cur, L, R);
            if (B <= M)
                return query(2 * cur, L, M, A, B, op);
            else if (A >= M)
                return query(2 * cur + 1, M, R, A, B, op);
            else
            {
                auto left = query(2 * cur, L, M, A, B, op);
                auto right = query(2 * cur + 1, M, R, A, B, op);
                return op(left, right);
            }
        }
    }

    template<typename T, typename Op>
    void apply(size_type cur, size_type L, size_type R, size_type A, size_type B, const T &value,
               const Op &op)
    {
        assert(A < R && B > L && A < B);
        push_down(cur, L, R);
        if (A <= L && B >= R)
            nodes[cur].apply(L, R, value, op);
        else
        {
            size_type M = (L + R) / 2;
            if (A < M)
                apply(2 * cur, L, M, A, B, value, op);
            if (B > M)
                apply(2 * cur + 1, M, R, A, B, value, op);
            nodes[cur].update(L, R, nodes[2 * cur], nodes[2 * cur + 1]);
        }
    }

    void prepare(size_type N)
    {
        this->N = N;
        offset = 1;
        while (offset < N)
            offset *= 2;
        nodes.resize(2 * offset);
    }

    void pull_up()
    {
        for (size_type step = 2; step <= offset; step <<= 1)
        {
            int base = offset / step;
            for (int i = base; i < base * 2; i++)
                nodes[i].update(i * step, (i + 1) * step, nodes[2 * i], nodes[2 * i + 1]);
        }
    }

public:
    explicit SegmentTree(size_type N)
    {
        prepare(N);
        pull_up();
    }

    template<typename ForwardIterator>
    SegmentTree(ForwardIterator first, ForwardIterator last)
    {
        prepare(std::distance(first, last));
        for (size_type i = 0; i < N; i++)
            nodes[i + offset] = node(*first++);
        pull_up();
    }

    size_type size() const { return N; }

    template<typename Op>
    auto query(size_type a, size_type b, const Op &op = Op()) const
        -> decltype(query(1, 0, offset, a, b, op))
    {
        assert(a < b && b <= N);
        return query(1, 0, offset, a, b, op);
    }

    template<typename T, typename Op>
    void apply(size_type a, size_type b, const T &value, const Op &op = Op())
    {
        assert(a <= b && b <= N);
        if (a < b)
            apply(1, 0, offset, a, b, value, op);
    }
};

class op_query
{
public:
    typedef array<int, 2> result_type;
    result_type operator()(const result_type &a, const result_type &b) const
    {
        return {{max(a[0], b[0]), max(a[1], b[1])}};
    };
};

class op_flip
{
};

struct node
{
    array<int, 2> deep;
    bool flip = false;

    void push_down(size_t L, size_t R, node &left, node &right)
    {
        if (flip)
        {
            swap(left.deep[0], left.deep[1]);
            swap(right.deep[0], right.deep[1]);
            left.flip = !left.flip;
            right.flip = !right.flip;
            flip = false;
        }
    }

    void update(size_t L, size_t R, const node &left, const node &right)
    {
        assert(!flip);
        deep = op_query()(left.deep, right.deep);
    }

    void apply(size_t L, size_t R, int, const op_flip &)
    {
        swap(deep[0], deep[1]);
        flip = !flip;
    }

    array<int, 2> query(size_t L, size_t R, const op_query &) const { return deep; }

    node() = default;
    explicit node(int depth) : deep{{depth, -1}} {}
};

typedef SegmentTree<node> segtree;


struct edge
{
    int u, v, t;
};

struct ctree
{
    vector<int> vmap;
    vector<int> end;
    segtree segs{0};
};

struct vertex
{
    vi edges;
    int size;
    int depth;
};

static vector<vertex> vertices;

static int dfs_size(int x, int p)
{
    vertices[x].size = 1;
    for (int y : vertices[x].edges)
        if (y != p)
            vertices[x].size += dfs_size(y, x);
    return vertices[x].size;
}

static void dfs_depth(int x, int p, int d)
{
    vertices[x].depth = d;
    for (int y : vertices[x].edges)
        if (y != p)
            dfs_depth(y, x, d + 1);
}

static void dfs_number(ctree &tree, int x, int p, int &pool, int depth, vi &depths)
{
    int id = pool++;
    tree.vmap[x] = id;
    depths[id] = depth;
    for (int y : vertices[x].edges)
        if (y != p)
            dfs_number(tree, y, x, pool, depth + 1, depths);
    tree.end[id] = pool;
}

static void make_tree(ctree &tree, int start)
{
    int N = vertices.size();

    tree.vmap.resize(N);
    tree.end.resize(N);
    int pool = 0;
    vi depths(N);
    dfs_number(tree, start, -1, pool, 0, depths);
    tree.segs = segtree(depths.begin(), depths.end());
}

static void tree_flip_edge(ctree &tree, int u, int v)
{
    u = tree.vmap[u];
    v = tree.vmap[v];
    if (u > v)
        swap(u, v);
    tree.segs.apply(v, tree.end[v], 1, op_flip());
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vertices.resize(N);
    vector<edge> edges(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        vertices[u].edges.push_back(v);
        vertices[v].edges.push_back(u);
        edges[i] = edge{u, v, t};
    }

    dfs_depth(0, -1, 0);
    int A = 0;
    for (int i = 0; i < N; i++)
        if (vertices[i].depth > vertices[A].depth)
            A = i;
    dfs_depth(A, -1, 0);
    int B = 0;
    for (int i = 0; i < N; i++)
        if (vertices[i].depth > vertices[B].depth)
            B = i;

    ctree tA, tB;
    make_tree(tA, A);
    make_tree(tB, B);

    for (int i = 0; i < N - 1; i++)
    {
        if (edges[i].t)
        {
            tree_flip_edge(tA, edges[i].u, edges[i].v);
            tree_flip_edge(tB, edges[i].u, edges[i].v);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int eid;
        cin >> eid;
        eid--;
        tree_flip_edge(tA, edges[eid].u, edges[eid].v);
        tree_flip_edge(tB, edges[eid].u, edges[eid].v);
        int dA = tA.segs.query(0, N, op_query())[0];
        int dB = tB.segs.query(0, N, op_query())[0];
        cout << max(dA, dB) << '\n';
    }

    return 0;
}