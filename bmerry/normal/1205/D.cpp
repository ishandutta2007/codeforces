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

struct node
{
    vi edges;
    int size;
    int label;
    int parent;
};

static vector<node> nodes;

static int find_centroid(int cur, int parent, int thresh)
{
    node &n = nodes[cur];
    n.size = 1;
    n.parent = parent;
    int mx = 0;
    int ans = -1;
    for (int y : n.edges)
        if (y != parent)
        {
            ans = max(ans, find_centroid(y, cur, thresh));
            int c = nodes[y].size;
            n.size += c;
            mx = max(mx, c);
        }
    if (n.size > thresh && mx <= thresh)
        ans = cur;
    return ans;
}

static void label(int cur, int &pool, int step)
{
    node &n = nodes[cur];
    pool += step;
    n.label = pool;
    for (int y : n.edges)
        if (y != n.parent)
            label(y, pool, step);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }

    int root = find_centroid(0, -1, (N - 1) / 2);
    assert(root != -1);
    find_centroid(root, -1, N + 1);
    array<vi, 2> groups;
    int gsize[2] = {0, 0};
    sort(RA(nodes[root].edges), [&](int a, int b) { return nodes[a].size > nodes[b].size; });
    for (int y : nodes[root].edges)
    {
        int side = gsize[0] < gsize[1] ? 0 : 1;
        gsize[side] += nodes[y].size;
        groups[side].push_back(y);
    }

    nodes[root].label = 0;
    int pool = 0;
    for (int y : groups[0])
        label(y, pool, 1);
    pool = 0;
    for (int y : groups[1])
        label(y, pool, gsize[0] + 1);

    for (int i = 0; i < N; i++)
        if (i != root)
        {
            int p = nodes[i].parent;
            cout << i + 1 << ' ' << p + 1 << ' ' << nodes[i].label - nodes[p].label << '\n';
        }

    return 0;
}