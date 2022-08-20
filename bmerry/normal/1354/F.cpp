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

struct minion
{
    int a, b;
    int idx;
    bool operator<(const minion &other) const
    {
        return b < other.b;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N, K;
        cin >> N >> K;
        vector<minion> m(N);
        for (int i = 0; i < N; i++)
        {
            cin >> m[i].a >> m[i].b;
            m[i].idx = i + 1;
        }
        sort(RA(m));
        vector<vi> dp(N + 1, vi(K + 1, INT_MIN / 2));
        vector<vi> team(N + 1, vi(K + 1, 0));
        dp[0][0] = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= min(i, K); j++)
                dp[i + 1][j] = dp[i][j] + m[i].b * (K - 1);
            for (int j = 0; j <= min(i, K - 1); j++)
            {
                int score = dp[i][j] + m[i].a + j * m[i].b;
                if (score > dp[i + 1][j + 1])
                {
                    dp[i + 1][j + 1] = score;
                    team[i + 1][j + 1] = 1;
                }
            }
        }
        int n = N;
        int k = K;
        vi in, out;
        while (n > 0)
        {
            int t = team[n][k];
            n--;
            k -= t;
            if (t)
                in.push_back(m[n].idx);
            else
                out.push_back(m[n].idx);
        }
        reverse(RA(in));
        cout << SZ(in) + 2 * SZ(out) << '\n';
        for (int i = 0; i < K - 1; i++)
            cout << in[i] << ' ';
        for (int v : out)
            cout << v << ' ' << -v << ' ';
        cout << in.back() << '\n';
    }

    return 0;
}