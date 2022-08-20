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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string lines[4];
    int C;
    int a[4];
    cin >> C;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> lines[i];
    vector<int> cols(C + 4);
    for (int i = 0; i < C; i++)
    {
        int m = 0;
        for (int j = 0; j < 4; j++)
            if (lines[j][i] == '*')
                m |= 1 << j;
        cols[i] = m;
    }

    int masks[10];
    int costs[10];
    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        int base = (2 << i) - 1;
        int m = 0;
        for (int k = 0; k <= i; k++)
            m |= base << (4 * k);
        for (int j = 0; j < 4 - i; j++)
        {
            masks[idx] = m << j;
            costs[idx] = a[i];
            idx++;
        }
    }
    assert(idx == 10);

    vector<int> dp(1 << 16, INT_MAX / 4);
    dp[0] = 0;
    for (int i = C - 1; i >= 0; i--)
    {
        vector<int> dp2(1 << 16, INT_MAX / 4);
        for (int m = cols[i]; ; m = (m - 1) & cols[i])
        {
            int h = cols[i] ^ m;
            int b = h & ~(h - 1);
            for (int u = h; u < (1 << 16); u += (1 << 4))
            {
                if (h == 0)
                    dp2[u] = dp[(u >> 4) | (cols[i + 4] << 12)];
                else
                {
                    int v = INT_MAX / 4;
                    for (int x = 0; x < 10; x++)
                        if (masks[x] & b)
                            v = min(v, dp2[u & ~masks[x]] + costs[x]);
                    dp2[u] = v;
                }
            }
            if (m == 0)
                break;
        }
        dp = move(dp2);
    }
    int q = 0;
    for (int i = 0; i < 4; i++)
        q |= cols[i] << (4 * i);
    cout << dp[q] << '\n';

    return 0;
}