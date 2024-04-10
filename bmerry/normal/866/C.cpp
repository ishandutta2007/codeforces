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

struct level
{
    int F;
    int S;
    double p;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, R;
    cin >> N >> R;
    vector<level> lvls(N);
    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> lvls[i].F >> lvls[i].S >> P;
        lvls[i].p = P / 100.0;
    }
    double lo = 0.0;
    double hi = 1e12;
    for (int pass = 0; pass < 100; pass++)
    {
        double mid = (lo + hi) / 2;
        vector<double> dp(R + 1);
        for (int i = N - 1; i >= 0; i--)
        {
            vector<double> dp2(R + 1, mid);
            for (int r = lvls[i].F; r <= R; r++)
            {
                double s;
                if (lvls[i].S <= r)
                    s = dp[r - lvls[i].S];
                else
                    s = mid;
                double d = lvls[i].p * (lvls[i].F + dp[r - lvls[i].F])
                    + (1.0 - lvls[i].p) * (lvls[i].S + s);
                if (d < mid)
                    dp2[r] = d;
            }
            dp = move(dp2);
        }
        if (dp[R] < mid)
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(12) << lo << '\n';

    return 0;
}