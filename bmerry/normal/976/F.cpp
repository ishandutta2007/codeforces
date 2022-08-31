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

template<typename T = int>
struct MFEdge
{
    typedef T flow_type;

    int trg;
    T flow;
    T cap;
    int dual;
    int idx;

    MFEdge() {}
    MFEdge(int trg, T cap, int dual, int idx) : trg(trg), flow(0), cap(cap), dual(dual), idx(idx) {}
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

    void add(int a, int b, T cap, T rcap, int idx)
    {
        assert(a >= 0 && a < this->size() && b >= 0 && b < this->size());
        if (a == b)
            return; // no use in network flow, and complicates this function
        int da = this->size(a);
        int db = this->size(b);
        this->nodes[a].edges.push_back(Edge(b, cap, db, idx));
        this->nodes[b].edges.push_back(Edge(a, rcap, da, idx));
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

static void solve()
{
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    int V = N1 + N2 + 2;
    int src = V - 2;
    int sink = V - 1;
    MFGraph<> g(V);
    vi deg1(N1), deg2(N2);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add(u, v + N1, 1, 0, i + 1);
        deg1[u]++;
        deg2[v]++;
    }
    int min_degree = min(*min_element(RA(deg1)), *min_element(RA(deg2)));
    for (int i = 0; i < N1; i++)
        g.add(src, i, deg1[i] - min_degree, 0, -1);
    for (int i = 0; i < N2; i++)
        g.add(i + N1, sink, deg2[i] - min_degree, 0, -1);

    vector<vi> ans(min_degree + 1);
    g.make_flow(src, sink);
    for (int k = min_degree; k >= 0; k--)
    {
        for (int i = 0; i < N1; i++)
            for (const auto &e : g[i].edges)
                if (e.idx != -1 && e.flow == 0)
                    ans[k].push_back(e.idx);
        for (auto &e : g[src].edges)
            e.cap++;
        for (int i = N1; i < N1 + N2; i++)
            for (auto &e : g[i].edges)
                if (e.trg == sink)
                    e.cap++;
        int up;
        while ((up = g.augment(src, sink)) != 0)
            ;
    }
    for (int i = 0; i <= min_degree; i++)
    {
        cout << SZ(ans[i]);
        for (int v : ans[i])
            cout << ' ' << v;
        cout << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}