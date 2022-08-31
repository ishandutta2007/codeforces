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

template<typename EdgeType>
struct SimpleNode
{
    typedef EdgeType Edge;
    std::vector<Edge> edges;
};

struct SimpleEdge
{
    int trg;

    SimpleEdge() {}
    explicit SimpleEdge(int trg) : trg(trg) {}
};

template<typename T = int>
struct WeightedEdge
{
    typedef T weight_type;

    int trg;
    T weight;
    WeightedEdge() {}
    WeightedEdge(int trg, T weight) : trg(trg), weight(weight) {}
};

template<typename EdgeType, typename NodeType = SimpleNode<EdgeType> >
class GraphBase
{
public:
    typedef EdgeType Edge;
    typedef NodeType Node;

    std::vector<Node> nodes;

    int size() const { return nodes.size(); }

    int size(int id) const
    {
        assert(0 <= id && id < size());
        return nodes[id].edges.size();
    }

    NodeType &operator[](int id)
    {
        assert(0 <= id && id < size());
        return nodes[id];
    }

    const NodeType &operator[](int id) const
    {
        assert(0 <= id && id < size());
        return nodes[id];
    }

    explicit GraphBase(std::size_t size = 0) : nodes(size) {}
};

// Unweighted graph with arbitrary node type
template<typename NodeType = SimpleNode<SimpleEdge> >
class UGGraph : public GraphBase<SimpleEdge, NodeType>
{
public:
    // Add unidirectional edge
    void add1(int a, int b)
    {
        assert(0 <= a && a < this->size());
        assert(0 <= b && b < this->size());
        this->nodes[a].edges.push_back(SimpleEdge(b));
    }

    // Add bidirected edge
    void add2(int a, int b)
    {
        add1(a, b);
        add1(b, a);
    }

    explicit UGGraph(std::size_t size = 0) : GraphBase<SimpleEdge, NodeType>(size) {}
};

// Unweighted graph
typedef UGGraph<> UGraph;

// Weighted graph
template<typename T = int, typename NodeType = SimpleNode<WeightedEdge<T> > >
class WGraph : public GraphBase<WeightedEdge<T>, NodeType>
{
public:
    typedef typename GraphBase<WeightedEdge<T>, NodeType>::Edge::weight_type weight_type;
    typedef typename GraphBase<WeightedEdge<T>, NodeType>::Edge Edge;
    typedef typename GraphBase<WeightedEdge<T>, NodeType>::Node Node;

    // Add unidirectional edge
    void add1(int a, int b, T weight)
    {
        assert(0 <= a && a < this->size());
        assert(0 <= b && b < this->size());
        this->nodes[a].edges.push_back(Edge(b, weight));
    }

    // Add bidirectional edge
    void add2(int a, int b, T weight)
    {
        add1(a, b, weight);
        add1(b, a, weight);
    }

    explicit WGraph(std::size_t size = 0) : GraphBase<WeightedEdge<T>, NodeType>(size) {}
};

template<typename T = int>
struct MFEdge
{
    typedef T flow_type;

    int trg;
    T flow;
    T cap;
    int dual;

    MFEdge() {}
    MFEdge(int trg, T cap, int dual) : trg(trg), flow(0), cap(cap), dual(dual) {}
};

template<typename T = int>
class MFGraph : public GraphBase<MFEdge<T> >
{
private:
    struct pqitem
    {
        int trg;
        T prio;

        pqitem() {}
        pqitem(int trg, T prio) : trg(trg), prio(prio) {}

        bool operator<(const pqitem &b) const
        {
            return prio < b.prio;
        }
    };
public:
    typedef typename MFEdge<T>::flow_type flow_type;
    typedef typename GraphBase<MFEdge<T> >::Edge Edge;
    typedef typename GraphBase<MFEdge<T> >::Node Node;

    void add(int a, int b, T cap, T rcap)
    {
        assert(a >= 0 && a < this->size() && b >= 0 && b < this->size());
        if (a == b)
            return; // no use in network flow, and complicates this function
        int da = this->size(a);
        int db = this->size(b);
        this->nodes[a].edges.push_back(Edge(b, cap, db));
        this->nodes[b].edges.push_back(Edge(a, rcap, da));
    }

    T augment(int source, int sink)
    {
        const int N = this->size();
        const T big = std::numeric_limits<T>::max();

        std::vector<T> prio(N);
        std::vector<int> preve(N);
        std::priority_queue<pqitem> q;

        prio[source] = big;
        q.push(pqitem(source, big));
        while (!q.empty())
        {
            int cur = q.top().trg;
            T p = q.top().prio;
            q.pop();
            if (p != prio[cur])
                continue;
            if (cur == sink)
                break;
            for (int i = 0; i < this->size(cur); i++)
            {
                const Edge &e = this->nodes[cur].edges[i];
                T p2 = std::min(p, e.cap - e.flow);
                if (p2 > prio[e.trg])
                {
                    prio[e.trg] = p2;
                    preve[e.trg] = e.dual;
                    q.push(pqitem(e.trg, p2));
                }
            }
        }

        T up = prio[sink];
        if (up > 0)
        {
            int cur = sink;
            while (cur != source)
            {
                Edge &ed = this->nodes[cur].edges[preve[cur]];
                Edge &e = this->nodes[ed.trg].edges[ed.dual];
                e.flow += up;
                ed.flow -= up;
                cur = ed.trg;
            }
        }
        return up;
    }

    T make_flow(int source, int sink)
    {
        for (int i = 0; i < this->size(); i++)
            for (int j = 0; j < this->size(i); j++)
                this->nodes[i].edges[j].flow = 0;

        T flow = 0;
        T up;
        while ((up = augment(source, sink)) != 0)
            flow += up;
        return flow;
    }

    // Returns all vertices on the source side of the cut. Call this
    // immediately after make_flow
    std::set<int> cut_vertices(int source) const
    {
        std::stack<int> st;
        st.push(source);
        std::set<int> reach;
        reach.insert(source);
        while (!st.empty())
        {
            int cur = st.top();
            st.pop();
            for (int i = 0; i < this->size(cur); i++)
            {
                const Edge &e = this->nodes[cur].edges[i];
                if (e.flow != e.cap && !reach.count(e.trg))
                {
                    st.push(e.trg);
                    reach.insert(e.trg);
                }
            }
        }
        return reach;
    }

    explicit MFGraph(std::size_t size = 0) : GraphBase<MFEdge<T> >(size) {}
};


typedef array<array<int, 2>, 2> rect;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    map<int, int> xs, ys;
    xs[0] = 0;
    xs[N] = 0;
    ys = xs;
    vector<rect> rects(M);
    for (int i = 0; i < M; i++)
    {
        cin >> rects[i][0][0] >> rects[i][0][1] >> rects[i][1][0] >> rects[i][1][1];
        rects[i][0][0]--;
        rects[i][0][1]--;
        for (int j = 0; j < 2; j++)
        {
            xs[rects[i][j][0]] = 0;
            ys[rects[i][j][1]] = 0;
        }
    }

    int id = 0;
    vi xv;
    for (auto &e : xs)
    {
        xv.push_back(e.first);
        e.second = id++;
    }
    int X = id - 1;

    id = 0;
    vi yv;
    for (auto &e : ys)
    {
        yv.push_back(e.first);
        e.second = id++;
    }
    int Y = id - 1;

    vs grid(Y, string(X, '.'));
    for (int i = 0; i < M; i++)
    {
        rect &r = rects[i];
        for (int j = 0; j < 2; j++)
        {
            r[j][0] = xs[r[j][0]];
            r[j][1] = ys[r[j][1]];
        }
        for (int y = r[0][1]; y < r[1][1]; y++)
            for (int x = r[0][0]; x < r[1][0]; x++)
                grid[y][x] = '#';
    }

    int V = X + Y + 2;
    MFGraph<ll> g(V);
    int src = V - 2;
    int sink = V - 1;
    for (int i = 0; i < X; i++)
        g.add(src, i, xv[i + 1] - xv[i], 0);
    for (int i = 0; i < Y; i++)
        g.add(i + X, sink, yv[i + 1] - yv[i], 0);
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            if (grid[y][x] == '#')
                g.add(x, y + X, LLONG_MAX / 4, 0);
    ll flow = g.make_flow(src, sink);
    cout << flow << '\n';

    return 0;
}