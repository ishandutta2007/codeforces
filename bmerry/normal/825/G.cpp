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

template<typename T, typename Op = std::plus<T>>
class SegTree
{
    typedef std::size_t size_type;

    T identity;
    Op op;
    std::vector<T> nodes;

public:
    explicit SegTree(std::size_t n = 0, const T &identity = T(), const Op &op = Op())
        : identity(identity), op(op), nodes(2 * n, this->identity)
    {
        for (int i = n - 1; i > 0; i--)
            nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
    }

    size_type size() const { return nodes.size() / 2;}

    void set(size_type idx, T value)
    {
        assert(0 <= idx && idx < size());
        idx += size();
        nodes[idx] = std::move(value);
        while (idx > 0)
        {
            idx /= 2;
            nodes[idx] = op(nodes[2 * idx], nodes[2 * idx + 1]);
        }
    }

    const T &operator[](size_type idx) const
    {
        assert(0 <= idx && idx < size());
        return nodes[idx + size()];
    }

    T query(size_type a, size_type b) const
    {
        assert(0 <= a && a <= size());
        assert(0 <= b && b <= size());
        a += size();
        b += size();
        T left = identity, right = identity;
        while (a < b)
        {
            if (a & 1)
                left = op(left, nodes[a++]);
            if (b & 1)
                right = op(nodes[--b], right);
            a /= 2;
            b /= 2;
        }
        return op(left, right);
    }
};

template<typename T>
class op_min
{
public:
    T operator()(const T &a, const T &b) const { return std::min(a, b); }
};

struct hpath
{
    int top;
    int lo = INT_MAX / 2, hi = -1;
    SegTree<int, op_min<int>> dseg, iseg;

    hpath(int top, int size)
        : top(top), dseg(size, INT_MAX), iseg(size, INT_MAX)
    {
    }
};

struct node
{
    int parent = -1;
    int hl_idx = -1;
    int hl_pos = -1;
    vi ch;
    int size = -1;
    pair<int, int> best[2] = {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};
};

static vector<node> nodes;
static vector<hpath> hpaths;

static void prepare_hpath(int top)
{
    vector<int> path;
    path.push_back(top);
    while (!nodes[path.back()].ch.empty())
        path.push_back(nodes[path.back()].ch[0]);
    int hl_idx = SZ(hpaths);
    hpaths.emplace_back(top, SZ(path));
    for (int i = 0; i < SZ(path); i++)
    {
        nodes[path[i]].hl_idx = hl_idx;
        nodes[path[i]].hl_pos = i;
        hpaths.back().iseg.set(i, path[i]);
    }
}

static void make_tree(vector<vi> &edges, int cur, int parent)
{
    node &n = nodes[cur];
    n.size = 1;
    int hchild = -1;
    if (parent != -1)
        edges[cur].erase(find(RA(edges[cur]), parent));
    n.ch = move(edges[cur]);
    for (int i = 0; i < SZ(n.ch); i++)
    {
        int y = n.ch[i];
        nodes[y].parent = cur;
        make_tree(edges, y, cur);
        n.size += nodes[y].size;
        if (hchild == -1 || nodes[y].size > nodes[n.ch[hchild]].size)
            hchild = i;
    }
    if (hchild != -1)
        swap(n.ch[0], n.ch[hchild]);
    for (int i = 1; i < SZ(n.ch); i++)
        prepare_hpath(n.ch[i]);
}

static int query(int x, int down)
{
    int ans = INT_MAX;
    if (x == -1)
        return ans;
    const node &n = nodes[x];
    if (n.best[0].second != down)
        ans = min(ans, n.best[0].first);
    else
        ans = min(ans, n.best[1].first);
    const hpath &hp = hpaths[n.hl_idx];
    ans = min(ans, hp.dseg.query(n.hl_pos + 1, hp.dseg.size()));
    ans = min(ans, hp.dseg.query(0, n.hl_pos));
    if (hp.hi > n.hl_pos)
        ans = min(ans, hp.iseg.query(n.hl_pos, hp.hi + 1));
    int sub = query(nodes[hp.top].parent, hp.top);
    ans = min(ans, sub);
    int lo = sub == INT_MAX ? hp.lo : 0;
    if (lo < n.hl_pos)
        ans = min(ans, hp.iseg.query(lo, n.hl_pos + 1));
    if (ans != INT_MAX)
        ans = min(ans, x);
    return ans;
}

static void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<vi> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    nodes.resize(N);
    make_tree(edges, 0, -1);
    prepare_hpath(0);

    int last = 0;
    for (int i = 0; i < Q; i++)
    {
        int t, z;
        cin >> t >> z;
        int x = (z + last) % N;
        if (t == 1)
        {
#ifndef ONLINE_JUDGE
            // cerr << "U: " << x << '\n';
#endif
            int down = -2;
            int y = x;
            while (y != -1)
            {
                node &n = nodes[y];
                hpath &hp = hpaths[n.hl_idx];
                if (x < n.best[0].first)
                {
                    if (n.best[0].second != down)
                        n.best[1] = n.best[0];
                    n.best[0] = make_pair(x, down);
                    hp.dseg.set(n.hl_pos, x);
                }
                else if (x < n.best[1].first && down != n.best[0].second)
                    n.best[1] = make_pair(x, down);
                hp.lo = min(hp.lo, nodes[y].hl_pos);
                hp.hi = max(hp.hi, nodes[y].hl_pos);
                down = hp.top;
                y = nodes[down].parent;
            }
        }
        else
        {
#ifndef ONLINE_JUDGE
            // cerr << "Q: " << x << "\n";
#endif
            int ans = query(x, -1);
            assert(ans != INT_MAX);
            cout << ans + 1 << '\n';
            last = ans + 1;
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}