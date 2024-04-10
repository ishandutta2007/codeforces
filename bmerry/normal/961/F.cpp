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

typedef int64_t u64;

static constexpr u64 P = 37;
static constexpr u64 iP = 621621626;
static constexpr u64 MOD = 1000000007;

template<typename T> static constexpr T sqr(T a) { return a * a; }
template<typename T, typename P>
static constexpr T power(T a, P b) { return b == 0 ? T(1) : (b % 2) ? power(a, b - 1) * a % MOD : sqr(power(a, b / 2)) % MOD; }

static u64 rad_hash(const vector<u64> &hash, int mid, int rad)
{
    u64 ans = (hash[mid + rad + 1] - hash[mid - rad]) * power(iP, mid - rad) % MOD;
    if (ans < 0)
        ans += MOD;
    return ans;
}

static void solve()
{
    int N;
    string s;
    cin >> N >> s;
    vector<u64> hash(N + 1);
    u64 r = 1;
    for (int i = 0; i < N; i++)
    {
        hash[i + 1] = (hash[i] + r * s[i]) % MOD;
        r = r * P % MOD;
    }
    int best = N + 1;
    vi ans((N + 1) / 2, -1);
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        int ri = N - 1 - i;
        int d = max(0, i - best);
        if (rad_hash(hash, i, d) == rad_hash(hash, ri, d))
        {
            while (d < i && rad_hash(hash, i, d + 1) == rad_hash(hash, ri, d + 1))
                d++;
            if (i - d < best)
            {
                best = i - d;
                ans[i - d] = 2 * d + 1;
            }
        }
    }
    for (int i = 1; i < SZ(ans); i++)
        ans[i] = max(ans[i], ans[i - 1] - 2);
    if (ans[0] != -1)
    {
        // assert(rad_hash(hash, ans[0] / 2, ans[0] / 2)
        //        == rad_hash(hash, N - 1 - ans[0] / 2, ans[0] / 2));
        //assert(s.substr(0, ans[0]) == s.substr(N - ans[0]));
    }
    for (int v : ans)
        cout << v << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}