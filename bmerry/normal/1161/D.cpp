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

#define MOD 998244353

struct edge
{
    int trg;
    bool flip;
};

static bool dfs(const vector<vector<edge>> &edges, vector<bool> &seen, vector<bool> &f, int x)
{
    for (const auto &e : edges[x])
    {
        int y = e.trg;
        bool g = f[x] ^ e.flip;
        if (seen[y])
        {
            if (f[y] != g)
                return false;
        }
        else
        {
            f[y] = g;
            seen[y] = true;
            if (!dfs(edges, seen, f, y))
                return false;
        }
    }
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string S;
    cin >> S;
    reverse(RA(S));
    int N = SZ(S);
    int ans = 0;
    for (int d = 1; d < N; d++)
    {
        int A = (d + 1) / 2;
        int B = (N + 1) / 2;
        int V = A + B + 1;
        int z = V - 1;
        vector<vector<edge>> edges(V);
        auto add_edge = [&](int u, int v, bool flip) {
            edges[u].push_back(edge{v, flip});
            edges[v].push_back(edge{u, flip});
        };
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '?')
                continue;
            int a = min(i, d - 1 - i);
            int b = min(i, N - 1 - i) + A;
            if (i >= d)
                add_edge(z, b, S[i] == '1');
            else
                add_edge(a, b, S[i] == '1');
        }
        add_edge(0, z, true);
        add_edge(A, z, true);

        vector<bool> f(V);
        vector<bool> seen(V);
        int comps = 0;
        int ways = 1;
        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                seen[i] = true;
                if (!dfs(edges, seen, f, i))
                    goto bad;
                comps++;
            }
        }
        for (int i = 1; i < comps; i++)
        {
            ways *= 2;
            if (ways >= MOD)
                ways -= MOD;
        }

        ans += ways;
        if (ans >= MOD)
            ans -= MOD;

bad:;
    }
    cout << ans << '\n';

    return 0;
}