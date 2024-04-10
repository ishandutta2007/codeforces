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

// Returns vector of IDs in topological order if possible, otherwise empty vector
template<typename Graph>
std::vector<int> topological_sort(const Graph &g)
{
    int N = g.nodes.size();
    std::vector<int> deg(N);
    std::stack<int> st;
    std::vector<int> ans;
    ans.reserve(N);
    for (int i = 0; i < N; i++)
        for (std::size_t j = 0; j < g.nodes[i].edges.size(); j++)
            deg[g.nodes[i].edges[j].trg]++;
    for (int i = 0; i < N; i++)
        if (deg[i] == 0)
            st.push(i);
    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        ans.push_back(cur);
        for (size_t j = 0; j < g.nodes[cur].edges.size(); j++)
        {
            int trg = g.nodes[cur].edges[j].trg;
            if (--deg[trg] == 0)
                st.push(trg);
        }
    }
    if (ans.size() != (size_t) N)
        std::vector<int>().swap(ans); // resets ans and reclaims memory
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vi up(N), tom(N, -1), yes(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> up[i];
        up[i]--;
    }
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        assert(yes[y] == -1);
        assert(tom[x] == -1);
        yes[y] = x;
        tom[x] = y;
    }

    UGraph g(N);

    vi chain_id(N, -1);
    for (int i = 0; i < N; i++)
    {
        if (up[i] != -1)
            g.add1(up[i], i);
        if (yes[i] == -1)
        {
            chain_id[i] = i;
            for (int y = tom[i]; y != -1; y = tom[y])
            {
                if (up[y] != -1 && chain_id[up[y]] != i)
                    g.add1(up[y], i);
                chain_id[y] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
        if (yes[i] != -1)
            g.add1(yes[i], i);

    auto order = topological_sort(g);
    if (order.empty())
        cout << "0\n";
    else
    {
        for (int v : order)
            cout << v + 1 << ' ';
        cout << '\n';
    }

    return 0;
}