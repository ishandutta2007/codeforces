//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

static constexpr int ROOK = 0;
static constexpr int KNIGHT = 1;
static constexpr int BISHOP = 2;

static const int drk[8] = {2, 1, -1, -2, -2, -1, 1, 2};
static const int dck[8] = {1, 2, 2, 1, -1, -2, -2, -1};

static void solve()
{
    int N;
    cin >> N;

    auto pos = [N](int r, int c) { return r * N + c; };

    vector<vi> board(N, vi(N));
    vi loc(N * N + 1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            loc[board[i][j]] = pos(i, j);
        }

    vector<vi> dist[3];
    for (int i = 0; i < 3; i++)
    {
        dist[i].resize(N * N, vi(N * N, INT_MAX / 4));
        for (int j = 0; j < N * N; j++)
            dist[i][j][j] = 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                if (j != k)
                    dist[ROOK][pos(i, j)][pos(i, k)] = 1;
                if (i != k)
                    dist[ROOK][pos(i, j)][pos(k, j)] = 1;
            }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < N; l++)
                    if ((i + j == k + l || i - j == k - l) && (i != k || j != l))
                        dist[BISHOP][pos(i, j)][pos(k, l)] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int d = 0; d < 8; d++)
            {
                int r = i + drk[d];
                int c = j + dck[d];
                if (r >= 0 && r < N && c >= 0 && c < N)
                    dist[KNIGHT][pos(i, j)][pos(r, c)] = 1;
            }

    for (int p = 0; p < 3; p++)
        for (int y = 0; y < N * N; y++)
            for (int x = 0; x < N * N; x++)
                for (int z = 0; z < N * N; z++)
                    dist[p][x][z] = min(dist[p][x][z], dist[p][x][y] + dist[p][y][z]);

    array<pii, 3> dp = {}, dp2;
    for (int i = N * N - 1; i > 0; i--)
    {
        int x = loc[i];
        int y = loc[i + 1];
        for (int p = 0; p < 3; p++)
        {
            dp2[p] = pii(dp[p].first + dist[p][x][y], dp[p].second);
            for (int q = 0; q < 3; q++)
                for (int j = 0; j < N * N; j++)
                {
                    dp2[p] = min(dp2[p], pii(dp[q].first + dist[p][x][j] + dist[q][j][y] + 1,
                                             dp[q].second + 1));
                }
        }
        dp = dp2;
    }
    pii best = *min_element(RA(dp));
    cout << best.first << ' ' << best.second << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}