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

struct edge
{
    int trg;
    ll cost;
};

struct pqitem
{
    int trg;
    ll prio;

    bool operator<(const pqitem &other) const
    {
        return prio > other.prio;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int V, E;
    cin >> V >> E;
    vector<vector<edge>> edges(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back(edge{v, 2 * w});
        edges[v].push_back(edge{u, 2 * w});
    }
    for (int i = 0; i < V; i++)
    {
        ll a;
        cin >> a;
        edges[V].push_back(edge{i, a});
    }

    priority_queue<pqitem> q;
    q.push(pqitem{V, 0});
    vll prio(V + 1, LLONG_MAX);
    prio[V] = 0;
    while (!q.empty())
    {
        int cur = q.top().trg;
        ll p = q.top().prio;
        q.pop();
        if (p != prio[cur])
            continue;
        for (const edge &e : edges[cur])
        {
            ll p2 = p + e.cost;
            if (p2 < prio[e.trg])
            {
                prio[e.trg] = p2;
                q.push(pqitem{e.trg, p2});
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << prio[i] << ' ';
    cout << '\n';

    return 0;
}