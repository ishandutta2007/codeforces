// TOO SLOW

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

static void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<edge>> edges(N);
    vector<bool> marked(N);
    list<int> low, med, high;
    vector<list<int>::iterator> pos(N);
    vi cands;

    auto owner = [&](int x) -> list<int> &
    {
        return SZ(edges[x]) < K - 1 ? low : SZ(edges[x]) == K - 1 ? med : high;
    };

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(edge{v, SZ(edges[v])});
        edges[v].push_back(edge{u, SZ(edges[u]) - 1});
    }
    int live = N;
    for (int i = 0; i < N; i++)
    {
        list<int> &s = owner(i);
        pos[i] = s.insert(s.end(), i);
    }

    while (live > 0)
    {
        int x;
        if (!low.empty())
            x = low.front();
        else if (!med.empty())
            x = med.front();
        else
        {
            cout << "1 " << live << '\n';
            for (int i = 0; i < N; i++)
                if (!marked[i])
                    cout << i + 1 << ' ';
            cout << '\n';
            return;
        }
        bool can_clique = (ll) K * (K - 1) / 2 <= M;
        if (can_clique && SZ(edges[x]) == K - 1)
            cands.push_back(x);
        for (auto &e : edges[x])
        {
            int y = e.trg;
            owner(y).erase(pos[y]);
            edges[y][e.dual] = edges[y].back();
            edges[y].pop_back();
            if (e.dual < SZ(edges[y]))
            {
                const edge &e2 = edges[y][e.dual];
                edges[e2.trg][e2.dual].dual = e.dual;
            }
            auto &s = owner(y);
            pos[y] = s.insert(s.end(), y);
            M--;
        }
        owner(x).erase(pos[x]);
        live--;
        marked[x] = true;
    }

    vi label(N);
    int nonce = 0;
    for (int x : cands)
    {
        nonce++;
        for (const auto &e : edges[x])
            label[e.trg] = nonce;
        int hits = 0;
        for (const auto &e : edges[x])
        {
            int y = e.trg;
            for (const auto &f : edges[y])
                if (label[f.trg] == nonce)
                    hits++;
        }
        if (hits != (K - 1) * (K - 2) / 2)
            continue;
        cout << "2\n" << x + 1 << ' ';
        for (const auto &e : edges[x])
            cout << e.trg + 1 << ' ';
        cout << '\n';
        return;
    }

    cout << "-1\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}