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

struct solution
{
    ll cost = 0;
    bool winner = false;
    int uses = -1;
    vector<solution *> ptr;
};

struct node
{
    ll cost;
    int size = 1;
    int parent;
    vi edges;
    bool winner = false;
    solution *buy1;
    solution *inherit;
    solution *no_inherit;
};

static vector<node> nodes;

static solution *best(solution *a, solution *b)
{
    ll c = min(a->cost, b->cost);
    solution *out = new solution;
    out->cost = c;
    if (a->cost == c)
        out->ptr.push_back(a);
    if (b->cost == c)
        out->ptr.push_back(b);
    return out;
}

static solution *sum(solution *a, solution *b)
{
    solution *out = new solution;
    out->cost = a->cost + b->cost;
    out->ptr.reserve(2);
    out->ptr.push_back(a);
    out->ptr.push_back(b);
    return out;
}

static solution *single(int cost, int uses)
{
    solution *out = new solution;
    out->cost = cost;
    out->uses = uses;
    return out;
}

static void make_tree(int cur, int parent)
{
    node &n = nodes[cur];
    n.parent = parent;
    if (parent != -1)
        n.edges.erase(find(RA(n.edges), parent));
    for (int y : n.edges)
    {
        make_tree(y, cur);
        n.size += nodes[y].size;
    }
    sort(RA(n.edges), [](int a, int b) { return nodes[a].size > nodes[b].size; });
    n.buy1 = single(n.cost, cur);

    if (n.edges.empty())
    {
        n.no_inherit = n.buy1;
        n.inherit = new solution;
    }
    else
    {
        solution *buy = n.buy1;
        solution *sub = new solution;
        n.inherit = new solution;

        for (int y : n.edges)
        {
            node &m = nodes[y];
            solution *inherit1 = sum(sub, m.inherit);
            solution *inherit2 = sum(n.inherit, m.no_inherit);
            solution *buy1 = sum(inherit1, n.buy1);
            solution *buy2 = sum(buy, m.no_inherit);
            buy = best(buy1, buy2);
            n.inherit = best(inherit1, inherit2);
            sub = sum(sub, m.no_inherit);
        }
        n.no_inherit = best(buy, sub);
    }
}

static void mark(solution *s)
{
    if (s->winner)
        return;
    s->winner = true;
    if (s->uses >= 0)
        nodes[s->uses].winner = true;
    for (solution *p : s->ptr)
        mark(p);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nodes[i].cost;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    make_tree(0, -1);
    mark(nodes[0].no_inherit);
    for (int i = 0; i < N; i++)
        if (nodes[i].cost == 0)
            nodes[i].winner = true;
    int k = 0;
    for (int i = 0; i < N; i++)
        k += nodes[i].winner;
    cout << nodes[0].no_inherit->cost << ' ' << k << '\n';
    for (int i = 0; i < N; i++)
        if (nodes[i].winner)
            cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}