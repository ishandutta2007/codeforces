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

vector<vi> dp_side(const vi &side)
{
    int K = SZ(side);
    vector<vi> ans(K + 1);
    for (int k = 0; k <= K; k++)
    {
        int top = (K - 1) * k - k * (k - 1) / 2;
        ans[k].resize(top + 1, INT_MAX / 4);
    }
    ans[0][0] = 0;
    for (int i = 0; i < K; i++)
    {
        int v = side[i];
        for (int k = i + 1; k > 0; k--)
        {
            int top = i * k - k * (k - 1) / 2;
            for (int r = i; r <= top; r++)
            {
                int prev = ans[k - 1][r - i];
                if (prev != INT_MAX / 4)
                {
                    int test = prev + v;
                    if (test < ans[k][r])
                        ans[k][r] = test;
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K, S;
    cin >> N >> K >> S;
    S = min(S, N * N);
    vector<int> sides[2];
    int old = 0;
    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        sides[0].push_back(-x);
        old += x;
    }
    for (int i = K; i < N; i++)
    {
        int x;
        cin >> x;
        sides[1].push_back(x);
    }
    reverse(RA(sides[0]));

    vector<vi> dp[2];
    dp[0] = dp_side(sides[0]);
    dp[1] = dp_side(sides[1]);
    int ans = INT_MAX;
    for (int k = 0; k <= min(K, N - K); k++)
    {
        int budget = S - k;
        for (int i = 1; i < SZ(dp[1][k]); i++)
            dp[1][k][i] = min(dp[1][k][i], dp[1][k][i - 1]);
        for (int i = 0; i < min(budget + 1, SZ(dp[0][k])); i++)
        {
            int other = min(SZ(dp[1][k]) - 1, budget - i);
            ans = min(ans, dp[0][k][i] + dp[1][k][other]);
        }
    }
    cout << ans + old << '\n';

    return 0;
}