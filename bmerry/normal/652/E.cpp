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

struct edge
{
    int trg;
    bool art;
};

struct node
{
    int id = -1;
    int parent = -1;
    int up = INT_MAX;
    int comp = -1;
    vector<edge> edges;
};

static void dfs(vector<node> &nodes, int cur, int parent, int &pool, int &cpool, stack<int> &st)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.id = pool++;
    n.up = n.id;
    st.push(cur);
    for (const edge &e : n.edges)
    {
        int y = e.trg;
        if (y != parent)
        {
            if (nodes[y].id == -1)
                dfs(nodes, y, cur, pool, cpool, st);
            n.up = min(n.up, nodes[y].up);
        }
    }
    if (n.up == n.id)
    {
        int v;
        do
        {
            v = st.top();
            st.pop();
            nodes[v].comp = cpool;
        } while (v != cur);
        cpool++;
    }
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<node> nodes(N);
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        nodes[x].edges.push_back(edge{y, bool(z)});
        nodes[y].edges.push_back(edge{x, bool(z)});
    }
    int A, B;
    cin >> A >> B;
    A--;
    B--;

    int pool = 0;
    int cpool = 0;
    stack<int> st;
    dfs(nodes, A, -1, pool, cpool, st);
    if (nodes[B].id == -1)
    {
        cout << "NO\n";
        return;
    }

    vector<bool> gcomps(cpool);
    for (int i = B; i != -1; i = nodes[i].parent)
        if (nodes[i].comp >= 0)
            gcomps[nodes[i].comp] = true;
    for (int i = 0; i < N; i++)
        if (nodes[i].comp >= 0 && gcomps[nodes[i].comp])
            for (const auto &e : nodes[i].edges)
                if (e.art && nodes[e.trg].comp >= 0 && gcomps[nodes[e.trg].comp])
                {
                    cout << "YES\n";
                    return;
                }
    cout << "NO\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}