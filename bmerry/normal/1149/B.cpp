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

static int dp[251][251][251];

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    string W;
    cin >> N >> Q >> W;
    array<vi, 26> pos;
    for (int i = 0; i < N; i++)
        pos[W[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++)
        pos[i].push_back(N);

    auto nextc = [&](int p, char c)
    {
        if (p >= N)
            return N + 1;
        return *lower_bound(RA(pos[c - 'a']), p) + 1;
    };

    array<string, 3> b;
    dp[0][0][0] = 0;
    for (int q = 0; q < Q; q++)
    {
        char t;
        int r;
        char c;
        cin >> t >> r;
        r--;
        if (t == '+')
        {
            cin >> c;
            b[r] += c;
            array<int, 3> low, high;
            for (int i = 0; i < 3; i++)
            {
                low[i] = 0;
                high[i] = SZ(b[i]);
            }
            low[r] = SZ(b[r]);
            for (int i = low[0]; i <= high[0]; i++)
                for (int j = low[1]; j <= high[1]; j++)
                    for (int k = low[2]; k <= high[2]; k++)
                    {
                        int v = N + 1;
                        if (i > 0)
                            v = min(v, nextc(dp[i - 1][j][k], b[0][i - 1]));
                        if (j > 0)
                            v = min(v, nextc(dp[i][j - 1][k], b[1][j - 1]));
                        if (k > 0)
                            v = min(v, nextc(dp[i][j][k - 1], b[2][k - 1]));
                        dp[i][j][k] = v;
                    }
        }
        else
            b[r].pop_back();
        cout << (dp[SZ(b[0])][SZ(b[1])][SZ(b[2])] <= N ? "YES\n" : "NO\n");
    }

    return 0;
}