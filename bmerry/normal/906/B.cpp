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

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static bool valid(const vector<vector<pii>> &grid)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            auto v = grid[i][j];
            assert(v.first >= 0 && v.first < R);
            assert(v.second >= 0 && v.second < C);
            for (int d = 0; d < 4; d++)
            {
                int i2 = i + dr[d];
                int j2 = j + dc[d];
                if (i2 >= 0 && i2 < R && j2 >= 0 && j2 < C)
                {
                    auto w = grid[i2][j2];
                    int delta = abs(v.first - w.first) + abs(v.second - w.second);
                    if (delta == 1)
                        return false;
                }
            }
        }
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    bool swapped = false;
    if (R > C)
    {
        swap(R, C);
        swapped = true;
    }
    vector<vector<pii>> grid(R, vector<pii>(C));
    if ((R == 1 && (C == 2 || C == 3))
        || (R == 2 && C <= 3))
    {
        cout << "NO\n";
    }
    else
    {
        if (R == 1)
        {
            int p = 0;
            for (int i = 1; i < C; i += 2)
                grid[0][p++] = pii(0, i);
            for (int i = 0; i < C; i += 2)
                grid[0][p++] = pii(0, i);
        }
        else if (R * C <= 9)
        {
            vector<int> perm(R * C);
            for (int i = 0; i < R * C; i++)
                perm[i] = i;
            do
            {
                for (int i = 0; i < R; i++)
                    for (int j = 0; j < C; j++)
                    {
                        int idx = i * C + j;
                        int v = perm[idx];
                        grid[i][j].first = v / C;
                        grid[i][j].second = v % C;
                    }
                if (valid(grid))
                    break;
            } while (next_permutation(RA(perm)));
            if (!valid(grid))
            {
                cout << "NO\n";
                return 0;
            }
        }
        else
        {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                {
                    int r = i, c = j;
                    if (r & 1)
                        c = (c + 2) % C;
                    if (c & 1)
                        r = (r + 1) % R;
                    grid[r][c] = pii(i, j);
                }
        }
        if (swapped)
        {
            vector<vector<pii>> grid2(C, vector<pii>(R));
            for (int i = 0; i < C; i++)
                for (int j = 0; j < R; j++)
                    grid2[i][j] = pii(grid[j][i].second, grid[j][i].first);
            swap(R, C);
            grid = move(grid2);
        }
        cout << "YES\n";
        vector<bool> seen(R * C);
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                auto v = grid[i][j];
                assert(v.first >= 0 && v.first < R);
                assert(v.second >= 0 && v.second < C);
                for (int d = 0; d < 4; d++)
                {
                    int i2 = i + dr[d];
                    int j2 = j + dc[d];
                    if (i2 >= 0 && i2 < R && j2 >= 0 && j2 < C)
                    {
                        auto w = grid[i2][j2];
                        int delta = abs(v.first - w.first) + abs(v.second - w.second);
                        assert(delta != 1);
                    }
                }
            }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                int v = grid[i][j].first * C + grid[i][j].second;
                assert(!seen[v]);
                seen[v] = true;
                cout << v + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}