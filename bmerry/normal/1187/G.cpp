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

template<typename T = long long>
struct MCMFEdge
{
    typedef T flow_type;

    int trg;
    T cost;
    T adjcost;
    T flow;
    T cap;
    int dual;

    MCMFEdge() {}
    MCMFEdge(int trg, T cost, T cap, int dual) : trg(trg), cost(cost), adjcost(cost), flow(0), cap(cap), dual(dual) {}
};

template<typename T = long long>
class MCMFGraph : public GraphBase<MCMFEdge<T> >
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
            return prio > b.prio;
        }
    };
public:
    typedef typename MCMFEdge<T>::flow_type flow_type;
    typedef typename GraphBase<MCMFEdge<T> >::Edge Edge;
    typedef typename GraphBase<MCMFEdge<T> >::Node Node;

    void add(int a, int b, T cost, T cap, T rcap)
    {
        assert(a >= 0 && a < this->size() && b >= 0 && b < this->size());
        assert(cap >= 0 && rcap >= 0 && cost >= 0);
        if (a == b)
            return; // no use in network flow, and complicates this function
        if (cap > 0 && rcap > 0)
        {
            add(a, b, cost, cap, 0);
            add(b, a, cost, cap, 0);
        }
        else if (rcap > 0)
        {
            add(b, a, cost, rcap, 0);
        }
        else
        {
            int da = this->size(a);
            int db = this->size(b);
            this->nodes[a].edges.push_back(Edge(b, cost, cap, db));
            this->nodes[b].edges.push_back(Edge(a, -cost, 0, da));
        }
    }

    // Returns change in flow and in cost
    std::pair<T, T> augment(int source, int sink)
    {
        const int N = this->size();
        const T big = std::numeric_limits<T>::max();

        std::vector<T> upby(N);
        std::vector<T> prio(N, big);
        std::vector<int> preve(N);
        std::priority_queue<pqitem> q;

        prio[source] = 0;
        upby[source] = big;
        q.push(pqitem(source, 0));
        while (!q.empty())
        {
            int cur = q.top().trg;
            T p = q.top().prio;
            q.pop();
            if (p != prio[cur])
                continue;
            for (int i = 0; i < this->size(cur); i++)
            {
                const Edge &e = this->nodes[cur].edges[i];
                assert(e.flow == e.cap || e.adjcost >= 0);
                T p2 = p + e.adjcost;
                if (e.flow < e.cap && p2 < prio[e.trg])
                {
                    prio[e.trg] = p2;
                    preve[e.trg] = e.dual;
                    upby[e.trg] = std::min(e.cap - e.flow, upby[cur]);
                    q.push(pqitem(e.trg, p2));
                }
            }
        }

        T up = upby[sink];
        T upcost = 0;
        if (up > 0)
        {
            int cur = sink;
            while (cur != source)
            {
                Edge &ed = this->nodes[cur].edges[preve[cur]];
                Edge &e = this->nodes[ed.trg].edges[ed.dual];
                e.flow += up;
                upcost += e.cost * up;
                ed.flow -= up;
                cur = ed.trg;
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < this->size(i); j++)
                {
                    Edge &e = this->nodes[i].edges[j];
                    if (prio[i] != big && prio[e.trg] != big)
                        e.adjcost += prio[i] - prio[e.trg];
                }
            }
        }
        return std::make_pair(up, upcost);
    }

    // Returns total flow and total cost
    std::pair<T, T> make_flow(int source, int sink)
    {
        for (int i = 0; i < this->size(); i++)
            for (int j = 0; j < this->size(i); j++)
            {
                Edge &e = this->nodes[i].edges[j];
                e.flow = 0;
                e.adjcost = e.cost;
            }

        T flow = 0;
        T cost = 0;
        std::pair<T, T> up;
        while ((up = augment(source, sink)).first != 0)
        {
            flow += up.first;
            cost += up.second;
        }
        return std::make_pair(flow, cost);
    }

    explicit MCMFGraph(std::size_t size = 0) : GraphBase<MCMFEdge<T> >(size) {}
};


int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, K, C, D;
    cin >> N >> M >> K >> C >> D;
    vi a(K);
    vi starts(N);
    for (int i = 0; i < K; i++)
    {
        cin >> a[i];
        a[i]--;
        starts[a[i]]++;
    }

    int maxT = K + N + 1;
    int V = (maxT + 1) * N + 2;
    int src = V - 2;
    int sink = V - 1;
    MCMFGraph<int> g(V);
    for (int i = 0; i < N; i++)
        if (starts[i])
            g.add(src, i, 0, starts[i], 0);
    for (int t = 0; t <= maxT; t++)
        g.add(t * N, sink, 0, K, 0);
    for (int i = 0; i < N; i++)
        for (int t = 0; t < maxT; t++)
            g.add(t * N + i, (t + 1) * N + i, C, K, 0);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        for (int t = 0; t < maxT; t++)
            for (int j = 0; j < K; j++)
            {
                g.add(t * N + u, (t + 1) * N + v, C + (2 * j + 1) * D, 1, 0);
                g.add(t * N + v, (t + 1) * N + u, C + (2 * j + 1) * D, 1, 0);
            }
    }

    auto fc = g.make_flow(src, sink);
    assert(fc.first == K);
    cout << fc.second << '\n';

    return 0;
}