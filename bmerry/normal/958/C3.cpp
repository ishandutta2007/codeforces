//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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
    int N, K, p;
    cin >> N >> K >> p;
    vll a(N + 1);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[i + 1] = a[i] + x;
    }

    vector<vi> by(p);
    for (int i = 0; i <= N; i++)
        by[a[i] % p].push_back(i);

    vi dp{0};
    for (int k = 0; k < K; k++)
    {
        vi dp2;
        for (int i = 0; i < SZ(dp); i++)
            for (int s = 0; s < p; s++)
            {
                int trg = (i + s) % p;
                auto pos = upper_bound(RA(by[trg]), dp[i]);
                if (pos != by[trg].end())
                {
                    if (i + s >= SZ(dp2))
                        dp2.resize(i + s + 1, N + 1);
                    dp2[i + s] = min(dp2[i + s], *pos);
                }
            }
        dp = move(dp2);
    }

    int ans = -1;
    for (int i = a[N] % p; i < SZ(dp); i += p)
        if (dp[i] <= N)
        {
            ans = i;
            break;
        }
    cout << ans << '\n';

    return 0;
}