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

static bool good(const vs &grid)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    if (R % 3 != 0)
        return false;
    set<char> seen;
    for (int i = 0; i < 3; i++)
    {
        int r0 = R / 3 * i;
        int r1 = R / 3 * (i + 1);
        for (int r = r0; r < r1; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] != grid[r0][0])
                    return false;
        seen.insert(grid[r0][0]);
    }
    return seen.size() == 3;
}

static void solve()
{
    int R, C;
    cin >> R >> C;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];
    if (good(grid))
    {
        cout << "YES\n";
        return;
    }
    vs rot(C, string(R, '?'));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            rot[j][i] = grid[i][j];
    if (good(rot))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}