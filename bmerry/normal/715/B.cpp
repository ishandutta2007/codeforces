// WRONG ANSWER

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
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
    ll weight;
    int id;
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

static ll dijkstra(const vector<vector<edge>> &edges, int S, int T, int cut,
                   vector<int> &prev, vector<int> &preve, vector<ll> &prio)
{
    fill(RA(prev), -1);
    fill(RA(prio), LLONG_MAX / 2);
    prio[S] = 0;
    prev[S] = -2;
    priority_queue<pqitem> q;
    q.push(pqitem{S, 0});
    while (!q.empty())
    {
        int cur = q.top().trg;
        ll p = q.top().prio;
        q.pop();
        if (p != prio[cur])
            continue;
        for (int i = 0; i < SZ(edges[cur]); i++)
        {
            const edge &e = edges[cur][i];
            ll w = e.weight ? e.weight : e.id < cut ? INT_MAX : 1;
            ll p2 = p + w;
            if (p2 < prio[e.trg])
            {
                q.push(pqitem{e.trg, p2});
                prio[e.trg] = p2;
                prev[e.trg] = cur;
                preve[e.trg] = i;
            }
        }
    }
    return prio[T];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;

    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(edge{v, w, i});
        edges[v].push_back(edge{u, w, i});
    }

    vector<int> prev(N);
    vector<int> preve(N);
    vector<ll> prio(N);
    ll old = dijkstra(edges, S, T, M, prev, preve, prio);
    if (old < L || old == LLONG_MAX / 2)
    {
        cout << "NO\n";
        return 0;
    }
    ll dlow = dijkstra(edges, S, T, 0, prev, preve, prio);
    if (dlow > L)
    {
        cout << "NO\n";
        return 0;
    }

    int lo = 0;
    int hi = M;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        ll d = dijkstra(edges, S, T, mid, prev, preve, prio);
        if (d < L)
        {
            lo = mid;
            dlow = d;
        }
        else
            hi = mid;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
        for (const edge &e : edges[i])
        {
            if (e.trg < i)
                continue;
            ll w = e.weight;
            if (w == 0)
            {
                if (e.id < lo)
                    w = INT_MAX / 2;
                else if (e.id == lo)
                    w = L - dlow + 1;
                else
                    w = 1;
            }
            cout << i << ' ' << e.trg << ' ' << w << '\n';
        }

    return 0;
}