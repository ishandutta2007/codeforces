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

static int N;
static vector<vi> edges;
static vi parent;
static vi depth;
static vector<pii> dist;
static vector<bool> diam;
static int D, root, bot;
static vector<pii> cuts;

static void dfs(int cur, int p, int d)
{
    parent[cur] = p;
    depth[cur] = d;
    for (int v : edges[cur])
        if (v != p)
            dfs(v, cur, d + 1);
}

static pii get_dist(int cur)
{
    if (dist[cur].first == -1)
    {
        if (diam[cur])
        {
            if (depth[cur] > D - depth[cur])
                dist[cur] = pii(depth[cur], root);
            else
                dist[cur] = pii(D - depth[cur], bot);
        }
        else
        {
            auto sub = get_dist(parent[cur]);
            sub.first++;
            cuts.emplace_back(sub.second, cur);
            dist[cur] = sub;
        }
    }
    return dist[cur];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N;
    edges.resize(N);
    parent.resize(N);
    depth.resize(N);
    diam.resize(N);
    dist.resize(N, pii(-1, -1));
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1, 0);
    root = max_element(RA(depth)) - depth.begin();
    dfs(root, -1, 0);
    bot = max_element(RA(depth)) - depth.begin();
    D = depth[bot];
    for (int i = bot; i != -1; i = parent[i])
        diam[i] = true;
    ll score = ll(D) * ll(D + 1) / 2;
    for (int i = 0; i < N; i++)
        if (!diam[i])
        {
            auto sub = get_dist(i);
            score += sub.first;
        }
    reverse(RA(cuts));
    for (int i = bot; i != root; i = parent[i])
        cuts.emplace_back(root, i);
    cout << score << '\n';
    for (const auto &c : cuts)
        cout << c.first + 1 << ' ' << c.second + 1 << ' ' << c.second + 1 << '\n';

    return 0;
}