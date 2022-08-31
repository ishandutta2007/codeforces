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

template<typename EdgeType>
struct SccNode
{
    typedef EdgeType Edge;
    int id;
    int link;
    std::vector<Edge> edges;
};

class SccGraph : public GraphBase<SimpleEdge, SccNode<SimpleEdge> >
{
public:
    void add1(int a, int b)
    {
        assert(0 <= a && a < this->size());
        assert(0 <= b && b < this->size());
        this->nodes[a].edges.push_back(SimpleEdge(b));
    }

    explicit SccGraph(std::size_t size = 0) : GraphBase<SimpleEdge, SccNode<SimpleEdge>>(size) {}
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
std::vector<std::vector<int> > calc_sccs(Graph &g)
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, D;
    cin >> N >> M >> D;
    SccGraph g(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add1(u, v);
    }
    vector<string> open(N);
    for (int i = 0; i < N; i++)
        cin >> open[i];

    auto sccs = calc_sccs(g);
    int C = SZ(sccs);
    vi sccid(N);
    for (int i = 0; i < C; i++)
        for (int v : sccs[i])
            sccid[v] = i;

    vi period(C);
    vi depth(N, -1);
    for (int i = 0; i < C; i++)
    {
        reverse(RA(sccs[i]));
        depth[sccs[i][0]] = 0;
        int G = D;
        for (int x : sccs[i])
        {
            assert(depth[x] != -1);
            for (const auto &e : g[x].edges)
            {
                int y = e.trg;
                if (sccid[y] == i)
                {
                    if (depth[y] == -1)
                        depth[y] = depth[x] + 1;
                    else
                        G = gcd(G, abs(depth[x] + 1 - depth[y]));
                }
            }
        }
        period[i] = G;
        for (int x : sccs[i])
            depth[x] %= G;
    }

    vector<vi> dp(C);
    for (int i = 0; i < C; i++)
    {
        vi &best = dp[i];
        best.resize(period[i]);
        for (int x : sccs[i])
            for (const auto &e : g[x].edges)
            {
                int y = e.trg;
                if (sccid[y] != i)
                {
                    int j = sccid[y];
                    int r = gcd(period[i], period[j]);
                    int shift = (depth[x] - depth[y] + 1) % r;
                    if (shift < r)
                        shift += r;
                    vi fold(r);
                    for (int p = 0; p < r; p++)
                        for (int q = (p + shift) % r; q < period[j]; q += r)
                            fold[p] = max(fold[p], dp[j][q]);
                    for (int p = 0; p < r; p++)
                        for (int q = p; q < period[i]; q += r)
                            best[q] = max(best[q], fold[p]);
                }
            }

        for (int p = 0; p < period[i]; p++)
        {
            for (int x : sccs[i])
            {
                int q = (p + depth[x]) % period[i];
                bool good = false;
                for (int r = q; r < D; r += period[i])
                    good |= open[x][r] == '1';
                best[p] += good;
            }
        }
    }

    assert(sccs[sccid[0]][0] == 0);

    cout << dp[sccid[0]][0] << '\n';
    return 0;
}