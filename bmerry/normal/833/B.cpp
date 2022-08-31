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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<int> prev(N);
    vector<int> nxt(N + 1, N);
    vector<int> last(N + 1, -1);
    vector<int> dp(N + 1);
    for (int i = 0; i < N; i++)
    {
        dp[i + 1] = dp[i] + (last[a[i]] == -1);
        prev[i] = last[a[i]];
        if (prev[i] != -1)
            nxt[prev[i]] = i;
        last[a[i]] = i;
    }

    for (int pass = 1; pass < K; pass++)
    {
        vector<int> dp2(N + 1, INT_MAX);
        vector<int> dpi(N + 1);
        vector<int> dpl(N + 1);
        dp2[0] = 0;
        dpi[0] = 0;
        dpl[0] = 0;
        dpi[N] = N;
        int step = 1;
        while (step < N)
            step *= 2;
        for (; step >= 1; step /= 2)
        {
            for (int i = step; i <= N; i += 2 * step)
            {
                int lo = dpi[i - step];
                int hi = dpi[min(i + step, N)];
                hi = min(hi, i);
                int best = -1;
                int bestj = -1;
                int bestu = -1;
                int u = dpl[i - step];
                for (int j = i - step; j < i; j++)
                    if (prev[j] < lo)
                        u++;
                for (int j = lo; j <= hi; j++)
                {
                    int score = dp[j] + u;
                    if (score > best)
                    {
                        best = score;
                        bestj = j;
                        bestu = u;
                    }
                    if (nxt[j] >= i)
                        u--;
                }
                dp2[i] = best;
                dpi[i] = bestj;
                dpl[i] = bestu;
            }
        }
        dp = move(dp2);
    }
    cout << dp[N] << '\n';

    return 0;
}