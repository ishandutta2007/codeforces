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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

struct node
{
    int a;
    vi edges;
    int dp[2];
};

static int recurse(vector<node> &nodes, int cur, int parent)
{
    node &n = nodes[cur];
    int big[2][2] = {};
    int ans = -1;
    for (int y : n.edges)
        if (y != parent)
        {
            ans = max(ans, recurse(nodes, y, cur));
            const node &c = nodes[y];
            for (int i = 0; i < 2; i++)
            {
                if (c.dp[i] > big[i][0])
                {
                    big[i][1] = big[i][0];
                    big[i][0] = c.dp[i];
                }
                else if (c.dp[i] > big[i][1])
                    big[i][1] = c.dp[i];
            }
        }

    int top = INT_MAX;
    n.dp[0] = n.dp[1] = INT_MAX;
    for (int m = 0; m < 2; m++)
    {
        if (n.a != 2 && n.a != m)
            continue;
        top = min(top, big[m][0] + big[m][1] + 1);

        for (int u = 0; u < 2; u++)
            n.dp[u] = min(n.dp[u], big[m][0] + (u != m));
    }
    ans = max(ans, top);
    return ans;
}

static void solve()
{
    int N;
    cin >> N;
    vector<node> nodes(N);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        nodes[i].a = 2 - a;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }

    int chain = recurse(nodes, 0, -1);
    cout << chain / 2 + 1 << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        solve();
    }

    return 0;
}