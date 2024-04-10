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
}

/*** TEMPLATE CODE ENDS HERE */

struct edge
{
    int trg;
    int len;
};

struct pqitem
{
    int pos;
    int mask;
    int dist;

    bool operator<(const pqitem &other) const
    {
        return dist > other.dist;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<pii> a, b;
    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        if (c == A)
            a.emplace_back(u, v);
        else
            b.emplace_back(u, v);
    }

    vector<vector<bool>> reach(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
        reach[i][i] = true;
    for (const pii &e : a)
        reach[e.first][e.second] = reach[e.second][e.first] = true;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (reach[x][y])
                for (int z = 0; z < N; z++)
                    reach[x][z] = reach[x][z] || reach[y][z];

    vi label(N, -1);
    int L = 0;
    for (int i = 0; i < N; i++)
    {
        if (label[i] == -1)
        {
            vi comp;
            for (int j = 0; j < N; j++)
                if (reach[i][j])
                    comp.push_back(j);
            int lbl = 0;
            if (SZ(comp) >= 4)
            {
                lbl = 1 << L;
                L++;
            }
            for (int v : comp)
                label[v] = lbl;
        }
    }

    vector<vector<edge>> edges(N);
    for (const pii &e : a)
    {
        edges[e.first].push_back(edge{e.second, A});
        edges[e.second].push_back(edge{e.first, A});
    }
    for (const pii &e : b)
        if (!reach[e.first][e.second])
        {
            edges[e.first].push_back(edge{e.second, B});
            edges[e.second].push_back(edge{e.first, B});
        }

    vector<vi> prio(N, vi(1 << L, INT_MAX / 2));
    prio[0][label[0]] = 0;
    priority_queue<pqitem> q;
    q.push(pqitem{0, label[0], 0});
    while (!q.empty())
    {
        int pos = q.top().pos;
        int mask = q.top().mask;
        int dist = q.top().dist;
        q.pop();
        if (dist > prio[pos][mask])
            continue;
        for (const edge &e : edges[pos])
        {
            if (e.len == B && (mask & label[e.trg]))
                continue;
            int mask2 = mask | label[e.trg];
            int dist2 = dist + e.len;
            if (dist2 < prio[e.trg][mask2])
            {
                prio[e.trg][mask2] = dist2;
                q.push(pqitem{e.trg, mask2, dist2});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int ans = *min_element(RA(prio[i]));
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}