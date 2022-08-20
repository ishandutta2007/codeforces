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

static void roll(vector<vector<int>> &grid, int k)
{
    int C = SZ(grid[0]);
    for (int r = 0; r < SZ(grid); r++)
    {
        deque<pair<int, int>> st;
        for (int c = 0; c < C; c++)
        {
            while (!st.empty() && st.front().first <= c - k)
                st.pop_front();
            int h = grid[r][c];
            while (!st.empty() && st.back().second <= h)
                st.pop_back();
            st.emplace_back(c, h);
            grid[r][c] = st[0].second;
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C, K, Q;
    cin >> R >> C >> K >> Q;
    vector<vector<int>> grid(R, vector<int>(C, INT_MAX));
    for (int i = 0; i < Q; i++)
    {
        int r, c, t;
        cin >> r >> c >> t;
        r--;
        c--;
        grid[r][c] = t;
    }

    roll(grid, K);
    vector<vector<int>> grid2(C, vector<int>(R));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grid2[j][i] = grid[i][j];
    roll(grid2, K);

    int ans = INT_MAX;
    for (int j = K - 1; j < C; j++)
        for (int i = K - 1; i < R; i++)
            ans = min(ans, grid2[j][i]);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}