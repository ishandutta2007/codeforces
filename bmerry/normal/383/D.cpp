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

static void add(int &o, int v)
{
    o = (o + v) % MOD;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> ways(1);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        vector<int> dp(SZ(ways) + a[i]);
        for (int j = 0; j < SZ(ways); j++)
        {
            add(dp[j + a[i]], ways[j]);
            if (j == a[i])
                add(dp[0], 2 * ways[j]);
            else if (j > 0)
                add(dp[abs(j - a[i])], ways[j]);
        }
        add(dp[a[i]], 1);
        ways = move(dp);
        add(ans, ways[0]);
    }
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';

    return 0;
}