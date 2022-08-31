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

struct subtree
{
    vi da;
    int dom = -1;
    int base = 0;
};

struct node
{
    vi edges;
    int depth;
    subtree sub;
};

static void merge(subtree &a, subtree &b)
{
    if (a.da.size() < b.da.size())
    {
        swap(a.da, b.da);
        a.dom = b.dom;
    }
    a.base = min(a.base, b.base);
    for (int i = a.base; i < SZ(b.da); i++)
    {
        a.da[i] += b.da[i];
        if (a.da[i] > a.da[a.dom] || (a.da[i] == a.da[a.dom] && i < a.dom))
            a.dom = i;
    }
    b.da.clear();
    b.da.shrink_to_fit();
}

static void recurse(vector<node> &nodes, int cur, int parent, int depth)
{
    node &n = nodes[cur];
    n.depth = depth;
    for (int y : n.edges)
        if (y != parent)
        {
            recurse(nodes, y, cur, depth + 1);
            if (n.sub.da.empty())
            {
                n.sub = move(nodes[y].sub);
                n.sub.da[depth] = 1;
                n.sub.base = depth;
                if (n.sub.da[n.sub.dom] == 1)
                    n.sub.dom = depth;
            }
            else
            {
                merge(n.sub, nodes[y].sub);
            }
        }
    if (n.sub.da.empty())
    {
        n.sub.base = depth;
        n.sub.da.resize(depth + 1);
        n.sub.da[depth] = 1;
        n.sub.dom = depth;
    }
}

static void solve()
{
    int N;
    cin >> N;
    vector<node> nodes(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].edges.push_back(y);
        nodes[y].edges.push_back(x);
    }

    recurse(nodes, 0, -1, 0);
    for (int i = 0; i < N; i++)
        cout << nodes[i].sub.dom - nodes[i].depth << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}