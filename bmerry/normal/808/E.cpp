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
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

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

static void solve()
{
    int N, W;
    cin >> N >> W;
    vi cost[4];
    vll csum[4];
    for (int i = 0; i < N; i++)
    {
        int w, c;
        cin >> w >> c;
        cost[w].push_back(c);
    }
    for (int i = 1; i <= 3; i++)
    {
        sort(RA(cost[i]), greater<>());
        int M = SZ(cost[i]);
        csum[i].resize(M + 1);
        for (int j = 0; j < M; j++)
            csum[i][j + 1] = csum[i][j] + cost[i][j];
    }

    ll ans = 0;
    for (int i = 0; i < SZ(csum[3]); i++)
    {
        int rem = W - 3 * i;
        if (rem < 0)
            break;
        int L = -1;
        int R = SZ(cost[2]);
        while (R - L > 1)
        {
            int mid = (L + R) / 2;
            int rem2 = rem - 2 * mid;
            if (rem2 < 2)
                R = mid;
            else
            {
                ll score1 = csum[2][mid] + csum[1][min(SZ(cost[1]), rem2)];
                ll score2 = csum[2][mid + 1] + csum[1][min(SZ(cost[1]), rem2 - 2)];
                if (score1 < score2)
                    L = mid;
                else
                    R = mid;
            }
        }
        ll score = csum[3][i] + csum[2][R] + csum[1][min(SZ(cost[1]), rem - 2 * R)];
        ans = max(ans, score);
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}