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

struct edge
{
    int trg;
    int w;
};

static void dfs(const vector<vector<edge>> &edges, int cur, vi &label, vi &loops)
{
    for (const edge &e : edges[cur])
        if (label[e.trg] == -1)
        {
            label[e.trg] = label[cur] ^ e.w;
            dfs(edges, e.trg, label, loops);
        }
        else
        {
            int x = label[cur] ^ e.w ^ label[e.trg];
            if (x)
                loops.push_back(x);
        }
}

static constexpr int bit(int x)
{
    return 1 << x;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        edges[x].push_back(edge{y, w});
        if (x != y)
            edges[y].push_back(edge{x, w});
    }
    vector<int> label(N, -1);
    vector<int> loops;
    label[0] = 0;
    dfs(edges, 0, label, loops);

    int R = SZ(loops);
    int r = 0;
    vi toggle(30, -1);
    for (int i = 29; i >= 0; i--)
    {
        int p = r;
        while (p < R && !(loops[p] & bit(i)))
            p++;
        if (p == R)
            continue;
        swap(loops[r], loops[p]);
        for (p = r + 1; p < R; p++)
            if (loops[p] & bit(i))
                loops[p] ^= loops[r];
        toggle[i] = loops[r];
        r++;
    }

    int ans = label[N - 1];
    for (int i = 29; i >= 0; i--)
        if ((ans & bit(i)) && toggle[i] != -1)
            ans ^= toggle[i];
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}