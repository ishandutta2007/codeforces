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
    int N, K;
    cin >> N >> K;
    vector<int> grid[2];
    grid[0].resize(2 * N);
    grid[1].resize(2 * N);
    for (int i = 0; i < N; i++)
        cin >> grid[0][i];
    for (int i = 0; i < N; i++)
        cin >> grid[1][i];
    for (int i = 0; i < N; i++)
        cin >> grid[1][2 * N - 1 - i];
    for (int i = 0; i < N; i++)
        cin >> grid[0][2 * N - 1 - i];

    vector<tuple<int, int, int>> moves;
    if (K == 2 * N)
    {
        for (int i = 0; i < 2 * N; i++)
        {
            if (grid[0][i] == grid[1][i])
            {
                moves.emplace_back(grid[0][i], 0, i);
                grid[0][i] = grid[1][i] = 0;
                K--;
                break;
            }
        }
        if (K == 2 * N)
        {
            cout << "-1\n";
            return 0;
        }
    }

    while (K > 0)
    {
        int z = find(RA(grid[1]), 0) - grid[1].begin();
        while (true)
        {
            int prev = z - 1;
            if (prev == -1)
                prev += 2 * N;
            int c = grid[1][prev];
            if (c > 0)
                moves.emplace_back(c, 1, z);
            grid[1][z] = c;
            grid[1][prev] = 0;
            if (c > 0 && grid[0][z] == c)
            {
                moves.emplace_back(c, 0, z);
                grid[0][z] = grid[1][z] = 0;
                K--;
                break;
            }
            z = prev;
        }
    }

    cout << SZ(moves) << '\n';
    for (const auto &move : moves)
    {
        int id, r, c;
        tie(id, r, c) = move;
        if (c < N)
            cout << id << ' ' << r + 1 << ' ' << c + 1 << '\n';
        else
            cout << id << ' ' << 4 - r << ' ' << 2 * N - c << '\n';
    }

    return 0;
}