#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
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
    ios::sync_with_stdio(false);
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

template<typename T, typename Op = std::plus<T> >
class BIT
{
private:
    std::vector<T> values;
    Op op;
    T identity;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    explicit BIT(size_type size = 0, Op op = Op(), T identity = T())
        : values(size + 1, identity), op(op), identity(identity) {}

    size_type size() const { return values.size() - 1; }

    void add(size_type idx, T delta)
    {
        assert(idx < size());
        idx++;
        while (idx < values.size())
        {
            values[idx] = op(values[idx], delta);
            idx += idx & ~(idx - 1);
        }
    }

    // Sum of values up to and including idx
    T sum(size_type idx) const
    {
        assert(idx < size());
        T ans = identity;
        idx++;
        while (idx > 0)
        {
            ans = op(ans, values[idx]);
            idx &= idx - 1;
        }
        return ans;
    }

    // Sum of values up to but excluding idx
    T sum_exclusive(size_type idx) const
    {
        return (idx == 0) ? identity : sum(idx - 1);
    }
};

/*** TEMPLATE CODE ENDS HERE */

struct node
{
    vector<int> edges;
    vector<int> children;
    char ch;
    int C;
    int id;
    int end;
    int tid;
};

struct tnode
{
    char ch = '\0';
    int sib = -1;
    int child = -1;
    int prev = -1;
};

static vector<node> nodes;
static vector<tnode> tnodes;
static BIT<int> uniq;

static int trie_child(int id, char ch)
{
    int *cur = &tnodes[id].child;
    while (*cur != -1 && tnodes[*cur].ch < ch)
        cur = &tnodes[*cur].sib;
    if (*cur != -1 && tnodes[*cur].ch == ch)
        return *cur;
    else
    {
        int ans = tnodes.size();
        tnodes.emplace_back();
        tnodes.back().sib = *cur;
        tnodes.back().ch = ch;
        *cur = ans;
        return ans;
    }
}

static void build_tree(int root, int parent, int tparent, int &pool)
{
    node &n = nodes[root];
    n.id = pool++;
    n.tid = trie_child(tparent, n.ch);
    int prev = tnodes[n.tid].prev;
    if (prev >= 0)
        uniq.add(prev, -1);
    uniq.add(n.id, 1);
    tnodes[n.tid].prev = n.id;
    for (int e : n.edges)
    {
        if (e == parent)
            continue;
        n.children.push_back(e);
        build_tree(e, root, n.tid, pool);
    }
    n.edges.clear();
    n.end = pool;
    n.C += uniq.sum_exclusive(pool) - uniq.sum_exclusive(n.id);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nodes[i].C;
    string labels;
    cin >> labels;
    for (int i = 0; i < N; i++)
        nodes[i].ch = labels[i];
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    int pool = 0;
    tnodes.reserve(N + 1);
    tnodes.emplace_back();
    uniq = BIT<int>(N);
    build_tree(0, -1, 0, pool);
    int best = -1;
    int nbest = 0;
    for (int i = 0; i < N; i++)
    {
        if (nodes[i].C > best)
            nbest = 0;
        if (nodes[i].C >= best)
        {
            best = nodes[i].C;
            nbest++;
        }
    }
    cout << best << '\n' << nbest << '\n';

    return 0;
}