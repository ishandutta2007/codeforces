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
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

struct edge_info
{
    int d;
    int start;
};

struct link
{
    int up;
    int d;
};

struct ulink
{
    int x;
    int sz;
};

struct edge
{
    int x, y, d;
    ulink ul;
    int cpos = -1;
};

static vector<link> parent;

static pii find(int x)
{
    int d = 0;
    while (parent[x].up >= 0)
    {
        d ^= parent[x].d;
        x = parent[x].up;
    }
    return pii(x, d);
}

static ulink merge(int x, int y, int d)
{
    pii dx = find(x);
    pii dy = find(y);
    x = dx.first;
    y = dy.first;
    if (x == y)
        return ulink{-1, -1};
    if (-parent[x].up > -parent[y].up)
        swap(x, y);
    ulink ul = {x, -parent[x].up};
    parent[y].up += parent[x].up;
    parent[x].up = y;
    parent[x].d = dx.second ^ dy.second ^ d;
    return ul;
}

static void unmerge(const ulink &ul)
{
    int x = ul.x;
    int y = parent[x].up;
    parent[y].up += ul.sz;
    parent[x].up = -ul.sz;
    parent[x].d = 0;
}

typedef vector<edge> node;

static vector<node> nodes;
static int offset;
static vector<pii> queries;
static vi gauss(30);

static void add_edge1(int x, int y, int d, int a)
{
    node &n = nodes[a];
    n.push_back(edge{x, y, d});
}

static void add_edge(int x, int y, int d, int a, int b)
{
    a += offset;
    b += offset;
    while (a < b)
    {
        if (a & 1)
            add_edge1(x, y, d, a++);
        if (b & 1)
            add_edge1(x, y, d, --b);
        a >>= 1;
        b >>= 1;
    }
}

static void recurse(int p)
{
    for (edge &e : nodes[p])
    {
        e.ul = merge(e.x, e.y, e.d);
        if (e.ul.x == -1)
        {
            pii dx = find(e.x);
            pii dy = find(e.y);
            int d = dx.second ^ dy.second ^ e.d;
            for (int i = 29; i >= 0; i--)
                if (d & (1 << i))
                    d ^= gauss[i];
            if (d != 0)
            {
                int k = 31 - __builtin_clz(d);
                e.cpos = k;
                gauss[k] = d;
            }
        }
    }
    if (p < offset)
    {
        recurse(2 * p);
        recurse(2 * p + 1);
    }
    else
    {
        int q = p - offset;
        if (q < SZ(queries))
        {
            int d = find(queries[q].first).second ^ find(queries[q].second).second;
            for (int i = 29; i >= 0; i--)
                if (d & (1 << i))
                    d ^= gauss[i];
            cout << d << '\n';
        }
    }

    for (auto epos = nodes[p].rbegin(); epos != nodes[p].rend(); ++epos)
    {
        const edge &e = *epos;
        if (e.cpos != -1)
            gauss[e.cpos] = 0;
        if (e.ul.x >= 0)
            unmerge(e.ul);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    offset = 1;

    parent.resize(N, link{-1, 0});
    map<pii, edge_info> edge_infos;
    for (int i = 0; i < M; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        if (x > y)
            swap(x, y);
        edge_infos[pii(x, y)] = edge_info{d, 0};
    }
    int Q;
    cin >> Q;
    while (offset <= Q)
        offset *= 2;
    nodes.resize(2 * offset);
    for (int i = 0; i < Q; i++)
    {
        int t, x, y, d;
        cin >> t >> x >> y;
        x--;
        y--;
        if (x > y)
            swap(x, y);
        switch (t)
        {
        case 1:
            cin >> d;
            edge_infos[pii(x, y)] = edge_info{d, SZ(queries)};
            break;
        case 2:
            {
                const auto &e = edge_infos[pii(x, y)];
                add_edge(x, y, e.d, e.start, SZ(queries));
                edge_infos.erase(pii(x, y));
            }
            break;
        case 3:
            queries.emplace_back(x, y);
            break;
        }
    }
    for (const auto &ei : edge_infos)
    {
        const auto &e = ei.second;
        add_edge(ei.first.first, ei.first.second, e.d, e.start, SZ(queries));
    }
    recurse(1);

    return 0;
}