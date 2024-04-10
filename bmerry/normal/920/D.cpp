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

static int div_up(int a, int b)
{
    return (a + b - 1) / b;
}

static void solve()
{
    int N, K, V;
    cin >> N >> K >> V;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<vector<bool>> use(N + 1, vector<bool>(K));
    vector<bool> dp(K, false);
    dp[0] = true;
    for (int n = 0; n < N; n++)
    {
        ll r = a[n] % K;
        auto dp2 = dp;
        for (int i = 0; i < K; i++)
        {
            if (!dp[i])
                continue;
            int s = i + r;
            if (s >= K)
                s -= K;
            dp2[s] = true;
            use[n][s] = true;
        }
        dp = move(dp2);
    }

    if (!dp[V % K])
    {
        cout << "NO\n";
        return;
    }

    vi t;
    vi excl;
    int s = V % K;
    for (int i = N - 1; i >= 0; i--)
        if (use[i][s])
        {
            t.push_back(i);
            s -= a[i] % K;
            if (s < 0)
                s += K;
        }
        else
            excl.push_back(i);

    using mover = array<int, 3>;
    vector<mover> moves;

    auto do_move = [&](int c, int src, int trg)
    {
        assert(c >= 0);
        if (c == 0)
            return;
        moves.push_back(mover{c, src, trg});
        int w = min(a[src], ll(c) * K);
        a[trg] += w;
        a[src] -= w;
    };

    auto do_move_all = [&] (int src, int trg)
    {
        do_move(div_up(a[src], K), src, trg);
    };

    if (t.empty())
    {
        do_move_all(0, 1);
        t.push_back(0);
        excl.pop_back();
    }

    for (int i = 1; i < SZ(t); i++)
        do_move_all(t[i], t[0]);

    if (!excl.empty())
    {
        for (int i = 1; i < SZ(excl); i++)
            do_move_all(excl[i], excl[0]);
        if (a[t[0]] < V)
        {
            int u = (V - a[t[0]]) / K;
            do_move(u, excl[0], t[0]);
        }
    }

    if (a[t[0]] > V)
    {
        int trg = (t[0] + 1) % N;
        int u = (a[t[0]] - V) / K;
        do_move(u, t[0], trg);
    }
    if (a[t[0]] == V)
    {
        cout << "YES\n";
        for (const auto m : moves)
            cout << m[0] << ' ' << m[1] + 1 << ' ' << m[2] + 1 << '\n';
    }
    else
        cout << "NO\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}