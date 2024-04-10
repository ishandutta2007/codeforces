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

static ll make_bit(ll b)
{
    return 1LL << b;
}

static bool has_bit(ll x, ll b)
{
    return x & (1LL << b);
}

static void dfs(const vector<vi> &edges, vi &depth, int root, int parent, int d, int &ans)
{
    depth[root] = d;
    for (int y : edges[root])
        if (y != parent)
        {
            if (depth[y] != -1)
            {
                if (depth[y] < d)
                    ans = min(ans, d + 1 - depth[y]);
            }
            else
                dfs(edges, depth, y, root, d + 1, ans);
        }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vll a(N);
    array<int, 60> freq{};
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 60; j++)
            if (has_bit(a[i], j))
                freq[j]++;
    }
    if (*max_element(RA(freq)) > 2)
    {
        cout << "3\n";
        return 0;
    }

    array<vi, 60> link{};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 60; j++)
            if (has_bit(a[i], j))
                link[j].push_back(i);

    vector<vi> edges(N);
    set<int> good;
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < SZ(link[i]); j++)
            for (int k = j + 1; k < SZ(link[i]); k++)
            {
                int u = link[i][j];
                int v = link[i][k];
                ll common = a[u] & a[v];
                if ((common & ~(common - 1)) != make_bit(i))
                    continue;
                edges[u].push_back(v);
                edges[v].push_back(u);
                good.insert(u);
                good.insert(v);
            }

    int ans = INT_MAX;
    vi depth(N);
    for (int start : good)
    {
        queue<int> q;
        q.push(start);
        fill(RA(depth), -1);
        depth[start] = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int y : edges[cur])
            {
                if (depth[y] == -1)
                {
                    depth[y] = depth[cur] + 1;
                    q.push(y);
                }
                else if (depth[y] >= depth[cur])
                {
                    ans = min(ans, depth[y] + depth[cur] + 1);
                    goto found;
                }
            }
        }
found:;
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}