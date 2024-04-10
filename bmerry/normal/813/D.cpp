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

static void up(int &x, int y)
{
    if (y > x)
        x = y;
}

static void solve()
{
    int N;
    cin >> N;
    vi a(N);
    map<int, int> vmap;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        vmap[a[i]] = -1;
    }
    int P = 7;
    for (auto &e : vmap)
        e.second = P++;

    vi prv(N, -1), nxt(N, -1), label(N, -1);
    for (int i = 0; i < N; i++)
    {
        label[i] = vmap[a[i]];
        if (vmap.count(a[i] - 1))
            prv[i] = vmap[a[i] - 1];
        if (vmap.count(a[i] + 1))
            nxt[i] = vmap[a[i] + 1];
    }

    vi last(P, -1);
    vector<vi> dp(N), dpt(N);
    vi dp1(N);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        dp1[i] = 1;
        int cats[3] = {prv[i], nxt[i], a[i] % 7};
        for (int c : cats)
        {
            if (c != -1 && last[c] != -1)
                up(dp1[i], dp1[last[c]] + 1);
        }

        dp[i].resize(i);
        dpt[i].resize(P, INT_MIN / 2);
        for (int j = 0; j < i; j++)
        {
            int d = dp1[j] + 1;
            for (int c : cats)
            {
                if (c == -1)
                    continue;
                if (last[c] > j)
                    up(d, dp[last[c]][j] + 1);
                up(d, dpt[j][c] + 1);
            }
            dp[i][j] = d;
            up(dpt[i][a[j] % 7], d);
            up(dpt[i][label[j]], d);
            up(ans, d);
        }
        last[a[i] % 7] = i;
        last[label[i]] = i;
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}