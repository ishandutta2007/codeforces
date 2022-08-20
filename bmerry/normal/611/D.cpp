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

static const int MOD = 1000000007;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    string digits;
    cin >> N >> digits;
    vector<vi> eq(N, vi(N + 1, 0));
    for (int d = 1; d < N; d++)
    {
        for (int i = N - d - 1; i >= 0; i--)
        {
            if (digits[i] == digits[i + d])
                eq[i][i + d] = eq[i + 1][i + d + 1] + 1;
        }
    }

    vector<vi> dp(N + 1, vi(N + 1));
    for (int i = N - 1; i >= 0; i--)
    {
        if (digits[i] == '0')
            continue;
        dp[i][N] = 1;
        for (int j = N - 1; j > i; j--)
        {
            ll v = dp[i][j + 1];
            int e = eq[i][j];
            bool incr = (e < j - i) && digits[i + e] < digits[j + e];
            int step = j + (j - i) + !incr;
            if (step <= N)
                v += dp[j][step];
            dp[i][j] = v % MOD;
        }
    }
    cout << dp[0][1] << '\n';

    return 0;
}