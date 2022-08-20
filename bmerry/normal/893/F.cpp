// Time limit exceeded

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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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

struct node
{
    int idx;
    int end;
    int depth;
};

static void recurse(vector<node> &nodes, int cur, int parent, int depth,
                    const vector<vector<int>> &edges, int &pool)
{
    node &n = nodes[cur];
    n.idx = pool++;
    n.depth = depth;
    for (int v : edges[cur])
        if (v != parent)
        {
            recurse(nodes, v, cur, depth + 1, edges, pool);
        }
    n.end = pool;
}

template<typename T>
struct mini
{
    T operator()(const T &a, const T &b) const
    {
        return min(a, b);
    }
};

template<typename T, typename Op = mini<T>>
class SegTree
{
    typedef std::size_t size_type;

    T identity{std::numeric_limits<T>::max()};
    Op op;
    std::vector<T> nodes;

public:
    explicit SegTree(std::size_t n = 0)
        : nodes(2 * n, this->identity)
    {
        for (int i = n - 1; i > 0; i--)
            nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
    }

    template<typename Iterator>
    SegTree(Iterator first, Iterator last)
    {
        size_type n = std::distance(first, last);
        nodes.reserve(2 * n);
        nodes.resize(n, this->identity);
        nodes.insert(nodes.end(), first, last);
        for (int i = n - 1; i > 0; i--)
            nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
    }

    size_type size() const { return nodes.size() / 2;}

    void set(size_type idx, T value)
    {
        assert(0 <= idx && idx < size());
        idx += size();
        nodes[idx] = std::move(value);
        while (idx > 0)
        {
            idx /= 2;
            nodes[idx] = op(nodes[2 * idx], nodes[2 * idx + 1]);
        }
    }

    const T &operator[](size_type idx) const
    {
        assert(0 <= idx && idx < size());
        return nodes[idx + size()];
    }

    T query(size_type a, size_type b) const
    {
        assert(0 <= a && a <= size());
        assert(0 <= b && b <= size());
        a += size();
        b += size();
        T left = identity, right = identity;
        while (a < b)
        {
            if (a & 1)
                left = op(left, nodes[a++]);
            if (b & 1)
                right = op(nodes[--b], right);
            a /= 2;
            b /= 2;
        }
        return op(left, right);
    }
};

class SegTree1D
{
    vector<pair<int, int>> pre;
    vector<int> coords;
    SegTree<int> seg;

public:
    void add(int x, int v) { pre.emplace_back(x, v); }

    void prepare()
    {
        vector<int> vals;
        sort(RA(pre));
        for (const auto &entry : pre)
        {
            coords.push_back(entry.first);
            vals.push_back(entry.second);
        }
        pre.clear();
        pre.shrink_to_fit();
        seg = decltype(seg)(RA(vals));
    }

    int query(int L, int R) const
    {
        int l = lower_bound(RA(coords), L) - coords.begin();
        int r = lower_bound(RA(coords), R) - coords.begin();
        return seg.query(l, r);
    }
};

class SegTree2D
{
    typedef int T;
    typedef std::size_t size_type;

    std::vector<SegTree1D> nodes;

public:
    explicit SegTree2D(std::size_t n = 0)
        : nodes(2 * n)
    {
    }

    size_type size() const { return nodes.size() / 2;}

    const SegTree1D &operator[](size_type idx) const
    {
        assert(0 <= idx && idx < size());
        return nodes[idx + size()];
    }

    SegTree1D &operator[](size_type idx)
    {
        assert(0 <= idx && idx < size());
        return nodes[idx + size()];
    }

    int query(size_type a, size_type b, size_type u, size_type v) const
    {
        assert(0 <= a && a <= size());
        assert(0 <= b && b <= size());
        a += size();
        b += size();
        T left = INT_MAX, right = INT_MAX;
        while (a < b)
        {
            if (a & 1)
                left = min(left, nodes[a++].query(u, v));
            if (b & 1)
                right = min(nodes[--b].query(u, v), right);
            a /= 2;
            b /= 2;
        }
        return min(left, right);
    }

    void add(size_type idx, size_type u, int value)
    {
        assert(0 <= idx && idx < size());
        idx += size();
        while (idx > 0)
        {
            nodes[idx].add(u, value);
            idx /= 2;
        }
    }

    void prepare()
    {
        for (size_type i = 1; i < nodes.size(); i++)
            nodes[i].prepare();
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, root;
    cin >> N >> root;
    root--;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<node> nodes(N);
    int pool = 0;
    recurse(nodes, root, -1, 0, edges, pool);
    SegTree2D st(N);
    for (int i = 0; i < N; i++)
        st.add(nodes[i].depth, nodes[i].idx, a[i]);
    st.prepare();

    int Q;
    cin >> Q;
    int last = 0;
    for (int i = 0; i < Q; i++)
    {
        int x, k;
        cin >> x >> k;
        x = (x + last) % N;
        k = (k + last) % N;
        last = st.query(nodes[x].depth, min(nodes[x].depth + k + 1, N),
                        nodes[x].idx, nodes[x].end);
        cout << last << '\n';
    }

    return 0;
}