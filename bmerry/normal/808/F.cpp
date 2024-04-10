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

    explicit MFGraph(std::size_t size = 0) : GraphBase<MFEdge<T> >(size) {}
};

static std::vector<bool> sieve(int n)
{
    std::vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

static vector<bool> is_prime;

struct card
{
    int p, c, l;
};

static int max_power_no1(const vector<card> &cards)
{
    vector<card> odd, even;
    int tpower = 0;
    for (const card &c : cards)
    {
        tpower += c.p;
        if (c.c % 2)
            odd.push_back(c);
        else
            even.push_back(c);
    }

    int A = SZ(odd);
    int B = SZ(even);
    int src = A + B;
    int sink = src + 1;
    MFGraph<ll> g(A + B + 2);
    for (int i = 0; i < A; i++)
        g.add(src, i, odd[i].p, 0);
    for (int i = 0; i < B; i++)
        g.add(i + A, sink, even[i].p, 0);
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            if (is_prime[odd[i].c + even[j].c])
                g.add(i, j + A, INT_MAX, 0);
    return tpower - g.make_flow(src, sink);
}

static int max_power(const vector<card> &cards)
{
    int max1 = 0;
    for (const card &c : cards)
        if (c.c == 1)
            max1 = max(max1, c.p);
    int ans = 0;
    if (max1 > 0)
    {
        vector<card> no1;
        for (const card &c : cards)
            if (c.c != 1)
                no1.push_back(c);
        ans = max_power_no1(no1);

        no1.clear();
        for (const card &c : cards)
            if (c.c != 1 && !is_prime[c.c + 1])
                no1.push_back(c);
        ans = max(ans, max_power_no1(no1) + max1);
    }
    else
        ans = max_power_no1(cards);
    return ans;
}

static void solve()
{
    is_prime = sieve(200001);
    int N, K;
    cin >> N >> K;
    vector<card> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i].p >> cards[i].c >> cards[i].l;
    int L = 0;
    int R = N + 1;
    while (R - L > 1)
    {
        int mid = (L + R) / 2;
        vector<card> sub;
        for (const card &c : cards)
            if (c.l <= mid)
                sub.push_back(c);
        if (max_power(sub) >= K)
            R = mid;
        else
            L = mid;
    }
    if (R == N + 1)
        cout << "-1\n";
    else
        cout << R << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}