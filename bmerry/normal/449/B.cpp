#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
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
    ll cost;
};

struct pqitem
{
    int trg;
    ll prio;
    bool operator<(const pqitem &b) const
    {
        return prio > b.prio;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> T(N, LLONG_MAX);
    T[0] = 0;
    priority_queue<pqitem> q;
    vector<vector<edge> > edges(N);
    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        edges[u].push_back(edge{v, x});
        edges[v].push_back(edge{u, x});
    }
    for (int i = 0; i < K; i++)
    {
        int s, y;
        cin >> s >> y;
        s--;
        if (T[s] != LLONG_MAX)
            ans++;
        T[s] = min(T[s], ll(y));
    }

    vector<bool> kill(N);

    vector<ll> prio = T;
    q.push(pqitem{0, 0});
    for (int i = 1; i < N; i++)
        if (T[i] < LLONG_MAX)
            q.push(pqitem{i, prio[i]});

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
            if (p2 <= T[e.trg])
                kill[e.trg] = true;
            if (p2 < prio[e.trg])
            {
                prio[e.trg] = p2;
                q.push(pqitem{e.trg, p2});
            }
        }
    }

    for (int i = 1; i < N; i++)
        if (kill[i] && T[i] != LLONG_MAX)
            ans++;
    cout << ans << '\n';

    return 0;
}