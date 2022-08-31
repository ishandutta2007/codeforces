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
}

/*** TEMPLATE CODE ENDS HERE */

static vll w;
static vi level;

struct edge
{
    int trg;
    int idx;
};

static void dfs(const vector<vector<edge>> &edges, vll &c, int cur, int parent, int pe, int depth)
{
    level[cur] = depth;
    for (const edge &e : edges[cur])
        if (level[e.trg] == -1)
            dfs(edges, c, e.trg, cur, e.idx, depth + 1);
    if (pe != -1)
    {
        w[pe] += c[cur];
        c[parent] -= c[cur];
        c[cur] = 0;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> edges(N);
    vll c(N);
    w.resize(M);
    level.resize(N, -1);
    for (int i = 0; i < N; i++)
        cin >> c[i];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(edge{b, i});
        edges[b].push_back(edge{a, i});
    }
    dfs(edges, c, 0, -1, -1, 0);
    if (c[0] != 0)
    {
        int ei = -1, a = -1, b = -1;
        if (c[0] % 2 == 0)
        {
            for (int i = 0; i < N; i++)
                for (const edge &e : edges[i])
                    if (level[i] % 2 == level[e.trg] % 2)
                    {
                        ei = e.idx;
                        a = i;
                        b = e.trg;
                    }
        }
        if (ei == -1)
        {
            cout << "NO\n";
            return 0;
        }
        int adj = c[0] / 2;
        if (level[a] & 1)
            adj = -adj;
        w[ei] += adj;
        c[a] -= adj;
        c[b] -= adj;
        fill(RA(level), -1);
        dfs(edges, c, 0, -1, -1, 0);
    }
    cout << "YES\n";
    for (int i = 0; i < M; i++)
        cout << w[i] << '\n';

    return 0;
}