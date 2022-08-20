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

static vector<vll> chooset;

static ll choose(int n, int r)
{
    assert(n <= SZ(chooset));
    if (r < 0 || r > n)
        return 0;
    else
        return chooset[n][r];
}

static int R, C;

static ll bit(int x)
{
    return 1LL << x;
}

static void recurse(int L, int N, int a, int na, ll req, ll excl, ll cur, vll &sums)
{
    if (na > N - L)
        return;
    else if (L == N)
    {
        sums.push_back(cur);
        return;
    }

    ll mask = bit(L);
    if (!(req & mask))
        recurse(L + 1, N, a, na, req, excl, cur, sums);
    if (na > 0 && !(excl & mask))
    {
        ll nxt = cur + choose(a, R - 1) * choose(L - a, R);
        recurse(L + 1, N, a + 1, na - 1, req, excl, nxt, sums);
    }
}

static pll solve(const string &pattern)
{
    int N = SZ(pattern);
    ll base = 0;
    for (int i = 0; i < R + C; i++)
        base += choose(i, R - 1) * choose(N - i - 1, R);
    ll unfair = LLONG_MAX;
    ll trg = 2 * base - choose(N, 2 * R);

    ll req = 0, excl = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (pattern[i] == 'A')
            req |= bit(i);
        else if (pattern[i] == 'B')
            excl |= bit(i);
    }

    vector<vll> dp(R + C + 1, vll(R + C + 1));
    dp[0][0] = 1;
    for (int j = 0; j <= R + C; j++)
        for (int k = 0; k <= R + C; k++)
        {
            if (j >= R - 1 && k >= R)
                break;
            if (j < R + C && pattern[j + k] != 'B')
                dp[j + 1][k] += dp[j][k];
            if (k < R + C && pattern[j + k] != 'A')
                dp[j][k + 1] += dp[j][k];
        }

    int M = N - C;
    vector<vll> asums2(R + C + 1);
    for (int al = R - 1; al <= R + C; al++)
    {
        recurse(M, N, al, R + C - al, req, excl, 0, asums2[al]);
        sort(RA(asums2[al]), greater<ll>());
    }
    for (int a = R - 1; a <= R + C; a++)
        for (int b = R; b <= R + C; b++)
        {
            if (a > R - 1 && b > R)
                continue;
            if (dp[a][b] == 0)
                continue;
            int L = a + b;
            for (int l = 0; l <= M - L; l++)
            {
                int r = R + C - a - l;
                if (r > N - M || r < 0)
                    continue;
                vll sums1;
                recurse(L, M, a, l, req, excl, 0, sums1);
                auto &sums2 = asums2[a + l];
                sort(RA(sums1));
                int p = 0, q = 0;
                int p2 = 0, q2 = 0;
                while (p < SZ(sums1) && q < SZ(sums2))
                {
                    while (p2 < SZ(sums1) && sums1[p2] == sums1[p])
                        p2++;
                    while (q2 < SZ(sums2) && sums2[q2] == sums2[q])
                        q2++;
                    ll total = 2 * (sums1[p] + sums2[q]);
                    ll diff = llabs(total - trg);
                    if (diff < unfair)
                    {
                        unfair = diff;
                        ans = 0;
                    }
                    if (diff == unfair)
                        ans += ll(p2 - p) * ll(q2 - q) * dp[a][b];
                    if (total > trg)
                        q = q2;
                    else
                        p = p2;
                }
            }
        }
    return pll(unfair, ans);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string pattern;
    cin >> R >> C >> pattern;
    int N = 2 * (R + C);
    chooset.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        chooset[i].resize(i + 1);
        chooset[i][0] = chooset[i][i] = 1;
        for (int j = 1; j < i; j++)
            chooset[i][j] = chooset[i - 1][j - 1] + chooset[i - 1][j];
    }

    pll opt = solve(string(N, '?'));
    pll score = solve(pattern);
    // cerr << opt.first << ' ' << opt.second << ' ' << score.first << ' ' << score.second << '\n';
    if (score.first == opt.first)
        cout << score.second << '\n';
    else
        cout << "0\n";
    return 0;
}