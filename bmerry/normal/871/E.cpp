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

static void no()
{
    cout << "-1\n";
    exit(0);
}

static void check_dist(const vi &dist, const vector<vi> &edges, int cur, int parent, int depth)
{
    if (dist[cur] != depth)
        no();
    for (int v : edges[cur])
        if (v != parent)
            check_dist(dist, edges, v, cur, depth + 1);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vector<vi> dist(K, vi(N));

    vi opos(K, -1);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> dist[i][j];
            if (dist[i][j] == 0)
                opos[i] = j;
        }
    if (count(RA(opos), -1))
        no();
    int root = opos[0];

    // 2979ms
    vector<int> parent(N, -1);
    parent[root] = -2;
    vector<vi> order(K);
    for (int i = 1; i < K; i++)
    {
        if (dist[i][root] == 0)
            no();
        order[i].resize(dist[i][root] + 1, -1);
        for (int j = 0; j < N; j++)
            if (dist[i][j] + dist[0][j] == dist[i][root])
                order[i][dist[0][j]] = j;
        if (order[i][0] != root)
            no();
        for (int j = 1; j < SZ(order[i]); j++)
        {
            int v = order[i][j];
            if (v == -1)
                no();
            if (parent[v] != -1 && parent[v] != order[i][j - 1])
                no();
            parent[v] = order[i][j - 1];
        }
    }

    // 2916 ms
    vector<vector<pii>> down(N);
    for (int i = 0; i < N; i++)
        if (parent[i] == -1)
        {
            int hi = -1;
            int v = root;
            int d = dist[0][i];
            pii best(0, 0);
            for (int j = 1; j < K; j++)
            {
                int a = dist[0][i] + dist[j][root] - dist[j][i];
                if (a < 0 || a > 2 * dist[j][root] || (a & 1))
                    no();
                a /= 2;
                if (a > hi)
                {
                    hi = a;
                    v = order[j][a];
                    d = dist[0][i] - a;
                }
            }
            down[v].emplace_back(d, i);
        }

    // 2995ms
    vi lvl;
    for (int i = 0; i < N; i++)
    {
        if (down[i].empty())
            continue;
        sort(RA(down[i]));
        lvl.clear();
        lvl.push_back(i);
        for (const auto &entry : down[i])
        {
            int d = entry.first;
            int v = entry.second;
            if (d > SZ(lvl))
                no();
            else
            {
                parent[v] = lvl[d - 1];
                if (d == SZ(lvl))
                    lvl.push_back(v);
            }
        }
    }

    vector<vi> edges(N);
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1)
            no();
        else if (parent[i] >= 0)
        {
            edges[parent[i]].push_back(i);
            edges[i].push_back(parent[i]);
        }
    }

    for (int i = 0; i < K; i++)
        check_dist(dist[i], edges, opos[i], -1, 0);

    for (int i = 0; i < N; i++)
        if (parent[i] >= 0)
            cout << i + 1 << ' ' << parent[i] + 1 << '\n';

    return 0;
}