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

struct node
{
    int id = -1;
    int up = INT_MAX;
    vi edges;
};

static void recurse(vector<node> &nodes, int cur, int parent, int &pool, stack<int> &st, vector<vi> &comps)
{
    node &n = nodes[cur];
    n.id = pool++;
    n.up = n.id;
    st.push(cur);
    for (int y : n.edges)
        if (y != parent)
        {
            if (nodes[y].id == -1)
            {
                recurse(nodes, y, cur, pool, st, comps);
                n.up = min(n.up, nodes[y].up);
            }
            else
                n.up = min(n.up, nodes[y].id);
        }
    if (n.up == n.id)
    {
        vi comp{cur};
        while (st.top() != cur)
        {
            comp.push_back(st.top());
            st.pop();
        }
        st.pop();
        comps.push_back(move(comp));
    }
}

static pair<int, int> deepest(const vector<vi> &edges, int cur, int parent, int depth)
{
    int v = cur;
    int d = depth;
    for (int y : edges[cur])
        if (y != parent)
        {
            auto [v2, d2] = deepest(edges, y, cur, depth + 1);
            if (d2 > d)
            {
                v = v2;
                d = d2;
            }
        }
    return {v, d};
}

static int tree_diameter(const vector<vi> &edges)
{
    auto [v, d] = deepest(edges, 0, -1, 0);
    auto [v2, d2] = deepest(edges, v, -1, 0);
    return d2;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<node> nodes(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].edges.push_back(y);
        nodes[y].edges.push_back(x);
    }

    stack<int> st;
    int pool = 0;
    vector<vi> comps;
    recurse(nodes, 0, -1, pool, st, comps);

    int C = SZ(comps);
    vi cid(N);
    for (int i = 0; i < C; i++)
        for (int x : comps[i])
            cid[x] = i;

    vector<vi> edges(C);
    for (int i = 0; i < N; i++)
        for (int y : nodes[i].edges)
            if (cid[i] != cid[y])
                edges[cid[i]].push_back(cid[y]);

    cout << tree_diameter(edges) << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}