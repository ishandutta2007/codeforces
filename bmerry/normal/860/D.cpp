// WRONG

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

struct node
{
    int order = -1;
    int up = -1;
    int depth = -1;
    int parent = -1;
    unordered_set<int> ch;
    vector<int> edges;
};

static vector<node> nodes;
static vector<tuple<int, int, int>> ans;

static int recurse(int cur, int parent, int depth, int &pool)
{
    node &n = nodes[cur];
    n.order = pool++;
    n.depth = depth;
    n.parent = parent;
    vector<int> ups;
    int size = SZ(n.edges);
    for (int y : n.edges)
    {
        if (y == parent)
            continue;
        else if (nodes[y].depth != -1)
        {
            if (nodes[y].order < n.order)
                ups.push_back(y);
        }
        else
        {
            size += recurse(y, cur, depth + 1, pool);
            n.ch.emplace(y);
        }
    }
    if (SZ(ups) & 1)
    {
        n.up = ups.back();
        ups.pop_back();
    }
    for (int i = 0; i < SZ(ups); i += 2)
        ans.emplace_back(ups[i], cur, ups[i + 1]);
    return size;
}

struct leaf
{
    int idx;
    int depth;
    bool up;

    leaf(int idx, int depth, bool up) : idx(idx), depth(depth), up(up) {}

    bool operator<(const leaf &other) const
    {
        return make_tuple(depth, up, idx) > make_tuple(other.depth, other.up, other.idx);
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    nodes.resize(N);
    int pool = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }

    int expect = 0;
    for (int i = 0; i < N; i++)
        if (nodes[i].depth == -1)
        {
            int size = recurse(i, -1, 0, pool);
            expect += size / 4;
        }

    set<leaf> leaves;
    auto tryadd = [&](int idx)
    {
        if (nodes[idx].ch.empty())
            leaves.emplace(idx, nodes[idx].depth, nodes[idx].up != -1);
    };
    auto remove = [&](int idx)
    {
        leaves.erase(leaf(idx, nodes[idx].depth, nodes[idx].up != -1));
        if (nodes[idx].parent != -1)
        {
            auto &pn = nodes[nodes[idx].parent];
            pn.ch.erase(idx);
            tryadd(nodes[idx].parent);
        }
    };
    for (int i = 0; i < N; i++)
        tryadd(i);

    while (!leaves.empty())
    {
        int cur = leaves.begin()->idx;
        remove(cur);
        node &n = nodes[cur];
        if (n.parent == -1)
            continue;
        node &pn = nodes[n.parent];
        if (n.up != -1)
        {
            ans.emplace_back(n.up, cur, n.parent);
            n.up = -1;
        }
        else if (!pn.ch.empty())
        {
            auto pos = pn.ch.begin();
            ans.emplace_back(cur, n.parent, *pos);
            remove(*pos);
        }
        else if (pn.up != -1)
        {
            leaves.erase(leaf(n.parent, pn.depth, true));
            ans.emplace_back(cur, n.parent, pn.up);
            pn.up = -1;
            tryadd(n.parent);
        }
        else if (pn.parent != -1)
        {
            ans.emplace_back(cur, n.parent, pn.parent);
            remove(n.parent);
        }
    }
    cout << SZ(ans) << '\n';
    set<pair<int, int>> seen;
    assert(SZ(ans) == expect);
    for (int i = 0; i < SZ(ans); i++)
    {
        int a = get<0>(ans[i]);
        int b = get<1>(ans[i]);
        int c = get<2>(ans[i]);
        cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
        assert(!seen.count(make_pair(a, b)));
        assert(!seen.count(make_pair(b, a)));
        assert(!seen.count(make_pair(b, c)));
        assert(!seen.count(make_pair(c, b)));
        seen.emplace(a, b);
        seen.emplace(b, c);
    }

    return 0;
}