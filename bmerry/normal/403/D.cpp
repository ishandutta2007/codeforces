// FAILED SYSTESTS

#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    ios::sync_with_stdio(false);
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

#define MOD 1000000007
static int dp[1001][1001];
static int dpa[1001][1001];

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    for (int n = 0; n <= 1000; n++)
    {
        dp[0][n] = 1;
        dpa[0][n] = n + 1;
    }
    for (int k = 1; k <= 50; k++)
    {
        for (int n = k * (k + 1) / 2; n <= 1000; n++)
        {
            ll ans = 0;
            for (int gap = 0; gap <= n; gap++)
            {
                int n2 = n - (gap + 1) * k;
                if (n2 >= 0)
                    ans += dpa[k - 1][n2];
            }
            dp[k][n] = ans % MOD;
            dpa[k][n] = (dpa[k][n - 1] + ans) % MOD;
        }
    }

    ll fact = 1;
    for (int k = 1; k <= 50; k++)
    {
        fact = (fact * k) % MOD;
        for (int n = k * (k + 1) / 2; n <= 1000; n++)
            dp[k][n] = (dp[k][n] * fact) % MOD;
    }

    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int n, k;
        cin >> n >> k;
        cout << dp[k][n] << '\n';
    }

    return 0;
}