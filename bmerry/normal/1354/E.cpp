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

struct odd_cycle : public exception
{
};

static void dfs(const vector<vi> &edges, int x, vi &comp, int C)
{
    if (comp[x] == -C)
        throw odd_cycle();
    else if (comp[x] == C)
        return;
    assert(comp[x] == 0);
    comp[x] = C;
    for (int y : edges[x])
        dfs(edges, y, comp, -C);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    array<int, 3> szs;
    for (int i = 0; i < 3; i++)
        cin >> szs[i];
    vector<vi> edges(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    try
    {
        vi comp(N);
        int C = 1;
        for (int i = 0; i < N; i++)
            if (comp[i] == 0)
            {
                dfs(edges, i, comp, C);
                C++;
            }
        vector<array<int, 2>> freq(C);
        for (int c : comp)
            freq[abs(c)][c > 0]++;
        vector<vector<bool>> dp(C, vector<bool>(szs[1] + 1));
        dp[0][0] = true;
        for (int i = 1; i < C; i++)
        {
            for (int s : freq[i])
            {
                for (int j = s; j <= szs[1]; j++)
                    if (dp[i - 1][j - s])
                        dp[i][j] = true;
            }
        }

        if (dp[C - 1][szs[1]])
        {
            int k = szs[1];
            vi side(C);
            for (int i = C - 1; i >= 1; i--)
            {
                side[i] = (k >= freq[i][0] && dp[i - 1][k - freq[i][0]]) ? 0 : 1;
                k -= freq[i][side[i]];
            }
            string s(N, '?');
            for (int i = 0; i < N; i++)
            {
                if (side[abs(comp[i])] == (comp[i] > 0))
                    s[i] = '2';
                else if (szs[0] > 0)
                {
                    s[i] = '1';
                    szs[0]--;
                }
                else
                    s[i] = '3';
            }
            cout << "YES\n" << s << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
    catch (odd_cycle &e)
    {
        cout << "NO\n";
    }

    return 0;
}