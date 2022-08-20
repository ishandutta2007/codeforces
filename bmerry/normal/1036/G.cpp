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

enum State
{
    NEW, ACTIVE, DONE
};

static void dfs(int cur, const vector<vi> &edges, vector<State> &state, vi &reach)
{
    state[cur] = ACTIVE;
    for (int y : edges[cur])
    {
        if (state[y] == NEW)
            dfs(y, edges, state, reach);
        reach[cur] |= reach[y];
    }
    state[cur] = DONE;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> edges(N);
    vi indeg(N);
    vi outdeg(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }
    vi sources, sinks;
    for (int i = 0; i < N; i++)
    {
        if (indeg[i] == 0)
            sources.push_back(i);
        if (outdeg[i] == 0)
            sinks.push_back(i);
    }
    int S = SZ(sources);
    assert(S == SZ(sinks));

    vector<State> state(N, NEW);
    vi fullreach(N);
    vi reach(S);
    for (int i = 0; i < S; i++)
        fullreach[sinks[i]] = 1 << i;
    for (int i = 0; i < S; i++)
    {
        dfs(sources[i], edges, state, fullreach);
        reach[i] = fullreach[sources[i]];
    }

    for (int m = 1; m < (1 << S) - 1; m++)
    {
        int r = 0;
        for (int i = 0; i < S; i++)
            if (m & (1 << i))
                r |= reach[i];
        if (__builtin_popcount(r) <= __builtin_popcount(m))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}