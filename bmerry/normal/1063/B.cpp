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
    int R, C, sr, sc, x, y;
    cin >> R >> C >> sr >> sc >> x >> y;
    sr--;
    sc--;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];
    vector<vi> dist(R, vi(C, INT_MAX / 4));
    vector<vector<bool>> done(R, vector<bool>(C));
    dist[sr][sc] = 0;
    deque<pii> q;
    q.emplace_back(sr, sc);
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop_front();
        if (done[r][c])
            continue;
        done[r][c] = true;
        for (int dr = -1; dr <= 1; dr += 2)
        {
            int r2 = r + dr;
            if (r2 >= 0 && r2 < R && grid[r2][c] == '.' && dist[r2][c] > dist[r][c])
            {
                dist[r2][c] = dist[r][c];
                q.emplace_front(r2, c);
            }
        }
        for (int dc = -1; dc <= 1; dc += 2)
        {
            int c2 = c + dc;
            if (c2 >= 0 && c2 < C && grid[r][c2] == '.' && dist[r][c2] > dist[r][c] + 1)
            {
                dist[r][c2] = dist[r][c] + 1;
                q.emplace_back(r, c2);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (dist[i][j] >= INT_MAX / 4)
                continue;
            int L = max(0, sc - j);
            int R = max(0, j - sc);
            int ex = (dist[i][j] - L - R) / 2;
            L += ex;
            R += ex;
            if (L <= x && R <= y)
                ans++;
        }
    cout << ans << '\n';

    return 0;
}