//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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
    int dual;
};

static void push2(array<pii, 2> &ldists, int d, int v)
{
    pii x(d, v);
    if (x > ldists[0])
    {
        ldists[1] = ldists[0];
        ldists[0] = x;
    }
    else if (x > ldists[1])
        ldists[1] = x;
}

static pair<pii, int> dfs(const vector<vector<edge>> &edges, const vector<array<pii, 2>> &ldists, int cur, int parent, int depth)
{
    pair<pii, int> ans;
    if (SZ(edges[cur]) == 1 && parent != -1)
    {
        ans.first = pii(depth, ldists[cur][0].first + ldists[cur][1].first);
        ans.second = cur;
    }
    else
    {
        for (const edge &e : edges[cur])
            if (e.trg != parent)
                ans = max(ans, dfs(edges, ldists, e.trg, cur, depth + 1));
    }
    return ans;
}

static void solve()
{
    int N;
    cin >> N;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(edge{v, SZ(edges[v])});
        edges[v].push_back(edge{u, SZ(edges[u]) - 1});
    }

    vi odeg(N);
    for (int i = 0; i < N; i++)
        odeg[i] = SZ(edges[i]);

    vector<array<pii, 2>> ldists(N);
    stack<int> leaves;
    vector<bool> dead(N);
    for (int i = 0; i < N; i++)
    {
        ldists[i][0] = pii(0, -1);
        ldists[i][1] = pii(0, -1);
        if (odeg[i] == 1)
        {
            leaves.push(i);
            ldists[i][0] = pii(0, i);
        }
    }
    while (!leaves.empty())
    {
        int cur = leaves.top();
        leaves.pop();
        dead[cur] = true;
        assert(SZ(edges[cur]) == 1);
        edge e = edges[cur][0];
        edge &nd = edges[e.trg][e.dual];
        nd = edges[e.trg].back();
        edges[nd.trg][nd.dual].dual = e.dual;
        edges[e.trg].pop_back();
        push2(ldists[e.trg], ldists[cur][0].first + 1, ldists[cur][0].second);
        if (odeg[e.trg] == 2 && SZ(edges[e.trg]) == 1)
            leaves.push(e.trg);
        edges[cur].clear();
    }

    int root = 0;
    while (dead[root])
        root++;
    auto [score, deep] = dfs(edges, ldists, root, -1, 0);
    auto [score2, deep2] = dfs(edges, ldists, deep, -1, 0);
    int ex = score2.second + ldists[deep][0].first + ldists[deep][1].first;
    //cerr << score2.first << " + " << ex << '\n';
    for (int i = 0; i < 2; i++)
        cout << ldists[deep][i].second + 1 << ' ' << ldists[deep2][i].second + 1 << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}