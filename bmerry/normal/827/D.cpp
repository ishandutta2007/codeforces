#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
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

struct edge
{
    int trg;
    int w;
    int idx;
};

struct node
{
    int parent = -1;
    int pedge = -1;
    int depth = 0;
    vector<edge> edges;
    vector<edge> children;
    vector<pair<int, int>> anc;
    vector<int> add, remove;
    multiset<int> cross;
};

struct pqitem
{
    int trg;
    int parent;
    int pedge;
    int w;

    bool operator<(const pqitem &other) const
    {
        return w > other.w;
    }
};

static void make_tree(vector<node> &nodes, int cur, vector<int> &order)
{
    node &n = nodes[cur];
    order.push_back(cur);

    if (n.parent != -1)
    {
        node &p = nodes[n.parent];
        n.depth = p.depth + 1;
        n.anc.emplace_back(n.parent, p.edges[n.pedge].w);
        for (int i = 0; i <= 20; i++)
        {
            const auto &prev = n.anc[i];
            const auto &up = nodes[prev.first].anc[i];
            n.anc.emplace_back(up.first, max(prev.second, up.second));
        }
    }
    else
    {
        for (int i = 0; i <= 21; i++)
            n.anc.emplace_back(cur, 0);
    }
    for (const auto &ch : n.children)
        make_tree(nodes, ch.trg, order);
}

static pair<int, int> goup(const vector<node> &nodes, int a, int k)
{
    int lo = 0;
    for (int i = 0; i <= 20; i++)
        if (k & (1 << i))
        {
            auto up = nodes[a].anc[i];
            lo = max(lo, up.second);
            a = up.first;
        }
    return make_pair(a, lo);
}

static pair<int, int> lca(const vector<node> &nodes, int a, int b)
{
    int ans = 0;
    if (nodes[a].depth > nodes[b].depth)
    {
        auto na = goup(nodes, a, nodes[a].depth - nodes[b].depth);
        a = na.first;
        ans = max(ans, na.second);
    }
    else
    {
        auto nb = goup(nodes, b, nodes[b].depth - nodes[a].depth);
        b = nb.first;
        ans = max(ans, nb.second);
    }
    for (int i = 20; i >= 0; i--)
    {
        auto na = nodes[a].anc[i];
        auto nb = nodes[b].anc[i];
        if (na.first != nb.first)
        {
            ans = max(ans, max(na.second, nb.second));
            a = na.first;
            b = nb.first;
        }
    }
    if (a != b)
    {
        ans = max(ans, nodes[a].anc[0].second);
        ans = max(ans, nodes[b].anc[0].second);
        a = nodes[a].parent;
        b = nodes[b].parent;
    }
    assert(a == b);
    return make_pair(a, ans);
}

enum event_type
{
    QUERY, START, STOP
};

static multiset<int> combine(multiset<int> &&a, multiset<int> &&b)
{
    if (a.size() < b.size())
        swap(a, b);
    for (int x : b)
        a.insert(x);
    return move(a);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<node> nodes(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        nodes[a].edges.push_back(edge{b, w, i});
        nodes[b].edges.push_back(edge{a, w, i});
    }

    priority_queue<pqitem> q;
    vector<bool> in_tree(M);
    vector<bool> done(N);
    vector<int> prio(N, INT_MAX);
    q.push(pqitem{0, -1, -1, 0});
    prio[0] = 0;
    nodes[0].parent = -1;
    while (!q.empty())
    {
        pqitem cur = q.top();
        q.pop();
        if (done[cur.trg])
            continue;
        done[cur.trg] = true;
        if (cur.parent != -1)
        {
            const edge &e = nodes[cur.parent].edges[cur.pedge];
            nodes[cur.parent].children.push_back(e);
            nodes[cur.trg].parent = cur.parent;
            nodes[cur.trg].pedge = cur.pedge;
            in_tree[e.idx] = true;
        }
        for (int i = 0; i < SZ(nodes[cur.trg].edges); i++)
        {
            const edge &e = nodes[cur.trg].edges[i];
            if (!done[e.trg] && e.w < prio[e.trg])
            {
                q.push(pqitem{e.trg, cur.trg, i, e.w});
                prio[e.trg] = e.w;
            }
        }
    }

    vector<int> order;
    make_tree(nodes, 0, order);
    vector<int> ans(M, -2);

    for (int i = 0; i < N; i++)
    {
        for (const edge &e : nodes[i].edges)
        {
            if (e.trg > i && !in_tree[e.idx])
            {
                auto c = lca(nodes, i, e.trg);
                ans[e.idx] = c.second - 1;
                nodes[i].add.push_back(e.w);
                nodes[e.trg].add.push_back(e.w);
                nodes[c.first].remove.push_back(e.w);
            }
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        int cur = order[i];
        node &n = nodes[cur];
        for (const auto &e : n.children)
            n.cross = combine(move(n.cross), move(nodes[e.trg].cross));
        for (int x : n.add)
            n.cross.insert(x);
        for (int x : n.remove)
        {
            n.cross.erase(n.cross.find(x));
            n.cross.erase(n.cross.find(x));
        }
        int aidx = nodes[n.parent].edges[n.pedge].idx;
        if (n.cross.empty())
            ans[aidx] = -1;
        else
            ans[aidx] = *n.cross.begin() - 1;
    }

    for (int i = 0; i < M; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}