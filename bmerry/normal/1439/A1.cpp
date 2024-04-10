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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static void solve()
{
    int R, C;
    cin >> R >> C;
    vs grid(R);

    using op = array<int, 6>;
    vector<op> ops;

    auto apply = [&](int r0, int c0, int r1, int c1, int r2, int c2)
    {
        assert(r0 >= 0 && r0 < R && c0 >= 0 && c0 < C);
        assert(r1 >= 0 && r1 < R && c1 >= 0 && c1 < C);
        assert(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C);
        grid[r0][c0] ^= 1;
        grid[r1][c1] ^= 1;
        grid[r2][c2] ^= 1;
        ops.push_back(op{{r0, c0, r1, c1, r2, c2}});
    };

    for (int i = 0; i < R; i++)
        cin >> grid[i];
    for (int r = 0; r < R - 2; r++)
    {
        for (int c = 0; c < C - 1; c++)
            if (grid[r][c] == '1')
                apply(r, c, r, c + 1, r + 1, c);
        if (grid[r][C - 1] == '1')
            apply(r, C - 1, r + 1, C - 2, r + 1, C - 1);
    }
    for (int c = 0; c < C - 2; c++)
    {
        int x = grid[R - 2][c] - '0';
        int y = grid[R - 1][c] - '0';
        switch (y * 2 + x)
        {
        case 0: break;
        case 1: apply(R - 2, c, R - 2, c + 1, R - 1, c + 1); break;
        case 2: apply(R - 1, c, R - 2, c + 1, R - 1, c + 1); break;
        case 3: apply(R - 1, c, R - 2, c, R - 1, c + 1); break;
        }
    }

    bool a[4] = {
        grid[R - 2][C - 2] == '1',
        grid[R - 2][C - 1] == '1',
        grid[R - 1][C - 2] == '1',
        grid[R - 1][C - 1] == '1'
    };
    bool par = a[0] ^ a[1] ^ a[2] ^ a[3];
    if (par)
    {
        for (int i = 0; i < 4; i++)
            a[i] = !a[i];
    }
    if (a[0])
        apply(R - 2, C - 1, R - 1, C - 2, R - 1, C - 1);
    if (a[1])
        apply(R - 2, C - 2, R - 1, C - 2, R - 1, C - 1);
    if (a[2])
        apply(R - 2, C - 2, R - 2, C - 1, R - 1, C - 1);
    if (a[3])
        apply(R - 2, C - 2, R - 2, C - 1, R - 1, C - 2);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            assert(grid[i][j] == '0');

    cout << ops.size() << '\n';
    for (auto &x : ops)
    {
        for (int i = 0; i < 6; i++)
            cout << x[i] + 1 << ' ';
        cout << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}