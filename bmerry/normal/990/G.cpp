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

static vector<vi> factors(200001);

struct node
{
    int a;
    vi edges;
    vi paths;
};

static void recurse(vector<node> &nodes, int cur, int parent, vll &ans)
{
    node &n = nodes[cur];
    n.paths.resize(SZ(factors[n.a]), 1);
    for (int x : factors[n.a])
        ans[x]++;
    for (int y : n.edges)
        if (y != parent)
        {
            recurse(nodes, y, cur, ans);
            vi sub(SZ(factors[n.a]));
            int b = nodes[y].a;
            int p = 0;
            for (int i = 0; i < SZ(factors[b]); i++)
            {
                int f = factors[b][i];
                while (p < SZ(factors[n.a]) && factors[n.a][p] < f)
                    p++;
                if (p < SZ(factors[n.a]) && factors[n.a][p] == f)
                    sub[p] += nodes[y].paths[i];
            }
            for (int i = 0; i < SZ(n.paths); i++)
            {
                ans[factors[n.a][i]] += (ll) n.paths[i] * sub[i];
                n.paths[i] += sub[i];
            }
            nodes[y].paths.clear();
            nodes[y].paths.shrink_to_fit();
        }
}

static void solve()
{
    for (int i = 1; i <= 200000; i++)
        for (int j = i; j <= 200000; j += i)
            factors[j].push_back(i);

    int N;
    cin >> N;
    vector<node> nodes(N);
    for (int i = 0; i < N; i++)
        cin >> nodes[i].a;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].edges.push_back(y);
        nodes[y].edges.push_back(x);
    }
    vll ans(200001);
    recurse(nodes, 0, -1, ans);
    for (int i = 200000; i >= 1; i--)
        for (int j = 2 * i; j <= 200000; j += i)
            ans[i] -= ans[j];

    for (int i = 1; i <= 200000; i++)
        if (ans[i])
            cout << i << ' ' << ans[i] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}