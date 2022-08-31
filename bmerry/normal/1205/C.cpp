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

static bool query(int r1, int c1, int r2, int c2)
{
    cout << "? " << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
    int ret;
    cin >> ret;
    if (ret == -1)
        exit(0);
    return ret;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vi> grid(N, vi(N, -1));
    grid[0][0] = 1;
    grid[N - 1][N - 1] = 0;
    grid[0][1] = 0;
    grid[1][2] = !query(0, 1, 1, 2);
    grid[1][0] = grid[1][2] ^ !query(1, 0, 1, 2);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        {
            if (grid[r][c] != -1)
                continue;
            int r1, c1;
            if (r > 0 && c > 0)
                r1 = r - 1, c1 = c - 1;
            else if (r >= 2)
                r1 = r - 2, c1 = c;
            else
            {
                assert(c >= 2);
                r1 = r, c1 = c - 2;
            }
            grid[r][c] = grid[r1][c1] ^ !query(r1, c1, r, c);
        }

    const int step[2][4] = {{0, 1, 2, 2}, {0, 0, 0, 1}};
    bool flip = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int d = 0; d < 2; d++)
            {
                int r = i + step[d][3];
                int c = j + step[!d][3];
                if (r >= N || c >= N)
                    continue;
                int x = 0;
                for (int k = 0; k < 4; k++)
                    x ^= grid[i + step[d][k]][j + step[!d][k]];
                if (x == 0)
                {
                    flip = (grid[i][j] == grid[r][c]) ^ query(i, j, r, c);
                    goto found;
                }
            }

    abort();

found:
    for (int i = 0; i < N; i++)
        for (int j = !(i & 1); j < N; j += 2)
            grid[i][j] ^= flip;

    cout << "!\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j];
        cout << '\n';
    }
    cout << flush;

    return 0;
}