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

static char chs[4] = {'A', 'C', 'G', 'T'};

static vs transpose(const vs &grid)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    vs out(C, string(R, '?'));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            out[j][i] = grid[i][j];
    return out;
}

static int delta(const string &row1, const string &row2)
{
    int ans = 0;
    for (int i = 0; i < SZ(row1); i++)
        ans += row1[i] != row2[i];
    return ans;
}

static int delta(const vs &grid1, const vs &grid2)
{
    int ans = 0;
    for (int i = 0; i < SZ(grid1); i++)
        ans += delta(grid1[i], grid2[i]);
    return ans;
}

static pair<int, vs> solve(const vs &grid)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    pair<int, vs> ans;
    ans.first = INT_MAX;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            char ch[4];
            ch[0] = chs[i];
            ch[1] = chs[j];
            int k = 0;
            while (k == i || k == j)
                k++;
            ch[2] = chs[k++];
            while (k == i || k == j)
                k++;
            ch[3] = chs[k];

            vs cand(R);
            for (int r = 0; r < R; r++)
            {
                int f = (r & 1) ? 2 : 0;
                string row[2];
                for (int c = 0; c < C; c++)
                {
                    row[0] += ch[f + c % 2];
                    row[1] += ch[f + (c + 1) % 2];
                }
                if (delta(grid[r], row[1]) < delta(grid[r], row[0]))
                    cand[r] = move(row[1]);
                else
                    cand[r] = move(row[0]);
            }
            int score = delta(grid, cand);
            if (score < ans.first)
            {
                ans.first = score;
                ans.second = cand;
            }
        }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    pair<int, vs> ans = solve(grid);
    grid = transpose(grid);
    pair<int, vs> ans2 = solve(grid);
    if (ans2.first < ans.first)
    {
        ans.first = ans2.first;
        ans.second = transpose(ans2.second);
    }
    for (int i = 0; i < R; i++)
        cout << ans.second[i] << '\n';

    return 0;
}