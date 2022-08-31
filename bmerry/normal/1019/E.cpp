//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

struct path
{
    ll a, b;

    bool operator<(const path &other) const
    {
        return tie(a, b) < tie(other.a, other.b);
    }
    path operator+(const path &other) const
    {
        return path{a + other.a, b + other.b};
    }
    path operator-(const path &other) const
    {
        return path{a - other.a, b - other.b};
    }
};

static ll cross(const path &u, const path &v)
{
    return u.a * v.b - u.b * v.a;
}

static ll cross(const path &x, const path &y, const path &z)
{
    return cross(y - x, z - x);
}

struct edge
{
    int trg;
    int dual;
    path p;
};

struct node
{
    vector<edge> edges;
    int size;
};

static vector<node> nodes;

static void delete_hedge(int src, int src_idx)
{
    node &n = nodes[src];
    if (src_idx + 1 < SZ(n.edges))
    {
        edge e = n.edges.back();
        n.edges[src_idx] = e;
        nodes[e.trg].edges[e.dual].dual = src_idx;
    }
    n.edges.pop_back();
}

static void delete_edge(int src, int src_idx)
{
    edge e = nodes[src].edges[src_idx];
    delete_hedge(src, src_idx);
    delete_hedge(e.trg, e.dual);
}

static int tree_size(int cur, int parent)
{
    int size = 1;
    for (const edge &e : nodes[cur].edges)
    {
        if (e.trg == parent)
            continue;
        size += tree_size(e.trg, cur);
    }
    return size;
}

static int centroid(int cur, int parent, int N)
{
    const node &n = nodes[cur];
    int size = 1;
    for (const edge &e : n.edges)
    {
        if (e.trg == parent)
            continue;
        int sub = centroid(e.trg, cur, N);
        if (sub >= 0)
            return sub;
        size += -1 - sub;
    }
    if (size * 2 >= N)
        return cur;
    else
        return -1 - size;
}

static void dfs(int cur, int parent, const path &cpath, vector<path> &out)
{
    int s = 0;
    const node &n = nodes[cur];
    for (const edge &e : n.edges)
    {
        if (e.trg == parent)
            continue;
        dfs(e.trg, cur, cpath + e.p, out);
        s++;
    }
    if (!s)
        out.push_back(cpath);
}

static void hull_append(vector<path> &out, const path &p)
{
    while (!out.empty() && p.b >= out.back().b)
        out.pop_back();
    while (SZ(out) >= 2 && cross(out[SZ(out) - 2], out.back(), p) >= 0)
        out.pop_back();
    out.push_back(p);
}

static vector<path> hull(const vector<path> &orig)
{
    vector<path> out;
    for (const path &p : orig)
        hull_append(out, p);
    return out;
}

static vector<path> merge(const vector<path> &a, const vector<path> &b)
{
    vector<path> out;
    merge(RA(a), RA(b), back_inserter(out));
    return hull(out);
}

static vector<path> add(const vector<path> &a, const vector<path> &b)
{
    auto p = a.begin();
    auto q = b.begin();
    vector<path> out;
    while (true)
    {
        out.push_back(*p + *q);
        auto p2 = next(p);
        auto q2 = next(q);
        if (p2 == a.end() && q2 == b.end())
            break;
        else if (p2 == a.end())
            q = q2;
        else if (q2 == b.end())
            p = p2;
        else if (cross(*p2 - *p, *q2 - *q) >= 0)
            q = q2;
        else
            p = p2;
    }
    return hull(out);
}

static vector<vector<path>> cands;

static void recurse1(int start)
{
    int N = tree_size(start, -1);
    int root = centroid(start, -1, N);
    node &n = nodes[root];
    const vector<edge> &ch = n.edges;
    int C = SZ(ch);

    vector<vector<path>> paths(1);
    paths[0].push_back(path{0, 0});
    for (int i = 0; i < C; i++)
    {
        vector<path> orig;
        dfs(ch[i].trg, root, ch[i].p, orig);
        sort(RA(orig));
        paths.push_back(hull(orig));
    }

    while (SZ(paths) > 1)
    {
        vector<vector<path>> npaths;
        for (int i = 0; i + 1 < SZ(paths); i += 2)
        {
            cands.push_back(add(paths[i], paths[i + 1]));
            npaths.push_back(merge(paths[i], paths[i + 1]));
        }
        if (SZ(paths) & 1)
            npaths.push_back(move(paths.back()));
        paths = move(npaths);
    }

    // Centroid decomposition recursion
    vi next;
    for (const auto &edge : ch)
        next.push_back(edge.trg);
    for (int i = SZ(ch) - 1; i >= 0; i--)
        delete_edge(root, i);
    for (int nxt : next)
        recurse1(nxt);
}

static ll eval(ll t, const path &p)
{
    return t * p.a + p.b;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        path p;
        cin >> u >> v >> p.a >> p.b;
        u--;
        v--;
        int ud = SZ(nodes[v].edges);
        int vd = SZ(nodes[u].edges);
        nodes[u].edges.push_back(edge{v, ud, p});
        nodes[v].edges.push_back(edge{u, vd, p});
    }
    recurse1(0);

    cands.push_back(vector<path>{path{0, 0}});
    while (SZ(cands) > 1)
    {
        vector<vector<path>> ncands;
        for (int i = 0; i + 1 < SZ(cands); i += 2)
            ncands.push_back(merge(cands[i], cands[i + 1]));
        if (SZ(cands) & 1)
            ncands.push_back(move(cands.back()));
        cands = move(ncands);
    }
    auto cand = cands[0];
    int pos = 0;
    for (ll t = 0; t < M; t++)
    {
        while (pos + 1 < SZ(cand)
               && eval(t, cand[pos + 1]) > eval(t, cand[pos]))
            pos++;
        cout << eval(t, cand[pos]) << ' ';
    }
    cout << '\n';

    return 0;
}