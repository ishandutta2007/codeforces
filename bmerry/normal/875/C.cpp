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

template<typename EdgeType, typename NodeType>
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
template<typename NodeType>
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

template<typename EdgeType>
struct SccNode
{
    typedef EdgeType Edge;
    int id;
    int link;
    std::vector<Edge> edges;
};

template<typename Graph>
int sccs_r(Graph &g, int root, int &pool, std::vector<std::vector<int> > &ans, std::stack<int> &active)
{
    typename Graph::Node &r = g[root];
    if (r.id != -1)
        return g[root].link;
    active.push(root);

    r.id = pool++;
    r.link = r.id;
    for (std::size_t i = 0; i < r.edges.size(); i++)
    {
        int trg = r.edges[i].trg;
        r.link = std::min(r.link, sccs_r(g, trg, pool, ans, active));
    }
    if (r.link == r.id)
    {
        ans.push_back(std::vector<int>());
        do
        {
            g[active.top()].link = INT_MAX;
            ans.back().push_back(active.top());
            active.pop();
        } while (ans.back().back() != root);
    }
    return r.link;
}

// Modifies the id and link elements of the graph
template<typename Graph>
std::vector<std::vector<int> > sccs(Graph &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        g[i].id = -1;
        g[i].link = -1;
    }

    int pool = 0;
    std::vector<std::vector<int> > ans;
    std::stack<int> st;
    for (int i = 0; i < g.size(); i++)
        sccs_r(g, i, pool, ans, st);
    return ans;
}

class Twosat
{
private:
    UGGraph<SccNode<SimpleEdge>> g;

public:
    explicit Twosat(int N) : g(2 * N) {}

    void implies(int a, bool at, int b, int bt)
    {
        g.add1(2 * a + at, 2 * b + bt);
        g.add1(2 * b + !bt, 2 * a + !at);
    }

    void set(int a, bool at)
    {
        implies(a, !at, a, at);
    }

    // Returns assignments, or empty vector if impossible
    std::vector<bool> solve()
    {
        std::vector<bool> hit(g.size());
        std::stack<int> st;
        for (const auto &sc : sccs(g))
            for (int v : sc)
            {
                if (!hit[v] && !hit[v ^ 1])
                {
                    hit[v] = true;
                    st.push(v);
                    while (!st.empty())
                    {
                        int cur = st.top();
                        st.pop();
                        for (const auto &edge : g[cur].edges)
                            if (!hit[edge.trg])
                            {
                                hit[edge.trg] = true;
                                st.push(edge.trg);
                            }
                    }
                }
            }
        std::vector<bool> ans(g.size() / 2);
        for (int i = 0; i < g.size(); i += 2)
        {
            if (hit[i] && hit[i + 1])
                return {};
            ans[i / 2] = hit[i + 1];
        }
        return ans;
    }
};

void no()
{
    cout << "No\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> words(N);
    for (int i = 0; i < N; i++)
    {
        int L;
        cin >> L;
        words[i].resize(L);
        for (int j = 0; j < L; j++)
        {
            cin >> words[i][j];
            words[i][j]--;
        }
    }

    Twosat ts(M);
    for (int i = 0; i < N - 1; i++)
    {
        int p = 0;
        const vi &a = words[i];
        const vi &b = words[i + 1];
        while (p < min(SZ(a), SZ(b)) && a[p] == b[p])
            p++;
        if (p != SZ(a))
        {
            if (p == SZ(b))
                no();
            else if (a[p] < b[p])
                ts.implies(b[p], true, a[p], true);
            else
            {
                ts.set(a[p], true);
                ts.set(b[p], false);
            }
        }
    }

    auto ans = ts.solve();
    if (ans.empty())
        no();
    vi up;
    for (int i = 0; i < M; i++)
        if (ans[i])
            up.push_back(i + 1);
    cout << "Yes\n" << SZ(up) << '\n';
    for (int v : up)
        cout << v << ' ';
    cout << '\n';

    return 0;
}