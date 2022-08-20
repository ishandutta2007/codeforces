#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

// Various simple graph types

#ifndef GRAPH_TYPES_CPP
#define GRAPH_TYPES_CPP

#include <vector>
#include <cassert>

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

#endif /* GRAPH_TYPES_CPP */

/* Min-cost max flow */

#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
#include <limits>

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

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> room(N, vi(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    MCMFGraph<> g(N * M + 2);
    int src = N * M;
    int sink = src + 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            const int dr[4] = {0, -1, 0, 1};
            const int dc[4] = {-1, 0, 1, 0};
            int id = i * M + j;
            if ((i ^ j) & 1)
                g.add(id, sink, 0, 1, 0);
            else
            {
                g.add(src, id, 0, 1, 0);
                for (int d = 0; d < 4; d++)
                {
                    int r = i + dr[d];
                    int c = j + dc[d];
                    if (r >= 0 && r < N && c >= 0 && c < M)
                    {
                        int id2 = r * M + c;
                        g.add(id, id2, room[r][c] == room[i][j] ? 0 : 1, 1, 0);
                    }
                }
            }
        }

    pair<ll, ll> flowcost = g.make_flow(src, sink);
    cout << flowcost.second << '\n';

    return 0;
}