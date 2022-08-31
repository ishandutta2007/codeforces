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
    ll w;
    int label;
};

struct pqitem
{
    int trg;
    ll w;

    bool operator<(const pqitem &other) const { return w > other.w; }
};

static void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--;
        y--;
        edges[x].push_back(edge{y, w, i + 1});
        edges[y].push_back(edge{x, w, i + 1});
    }

    vll prio(N, LLONG_MAX);
    vi use(N, -1);
    priority_queue<pqitem> q;
    q.push(pqitem{0, 0});
    prio[0] = 0;
    vi saved;
    while (!q.empty() && K > 0)
    {
        auto cur = q.top();
        q.pop();
        if (cur.w != prio[cur.trg])
            continue;
        if (use[cur.trg] != -1)
        {
            saved.push_back(use[cur.trg]);
            K--;
        }
        for (const edge &e : edges[cur.trg])
        {
            ll w = cur.w + e.w;
            if (w < prio[e.trg])
            {
                q.push(pqitem{e.trg, w});
                prio[e.trg] = w;
                use[e.trg] = e.label;
            }
        }
    }

    cout << SZ(saved) << '\n';
    for (int v : saved)
        cout << v << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}