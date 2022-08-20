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

struct node
{
    int size;
    vector<double> dp;
    vi edges;
};

static vector<node> nodes;
static double choose[51][51];

static void recurse(int root, int parent)
{
    node &n = nodes[root];
    n.size = 1;
    n.dp.clear();
    n.dp.push_back(1.0);
    for (int ch : n.edges)
    {
        if (ch == parent)
            continue;
        const node &c = nodes[ch];
        recurse(ch, root);

        vector<double> dpc(c.size + 1);
        for (int s = 0; s <= c.size; s++)
        {
            for (int i = 0; i < c.size; i++)
            {
                double sp = 1.0 / c.size;
                if (i < s)
                    dpc[s] += sp * c.dp[s - 1];
                else
                    dpc[s] += 0.5 * sp * c.dp[i];
            }
        }

        vector<double> dp2(n.dp.size() + c.size);
        for (int a = 0; a < n.size; a++)
            for (int b = 0; b <= c.size; b++)
            {
                int safe = a + b;
                double sp = choose[n.size - 1][a] * choose[c.size][b] / choose[n.size + c.size - 1][safe];
                dp2[safe] += sp * n.dp[a] * dpc[b];
            }
        n.size += c.size;
        n.dp = move(dp2);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);

    for (int i = 0; i <= 50; i++)
    {
        choose[i][0] = choose[i][i] = 1.0;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
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

    for (int i = 0; i < N; i++)
    {
        recurse(i, -1);
        cout << fixed << setprecision(10) << nodes[i].dp[0] << '\n';
    }

    return 0;
}