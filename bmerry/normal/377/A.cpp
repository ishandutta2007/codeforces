#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    ios::sync_with_stdio(false);
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

static int ids[501][501];

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static void dfs(const vs &grid, int r, int c, vector<pii> &idlist)
{
    const int R = grid.size();
    const int C = grid[0].size();
    if (ids[r][c] == -1)
    {
        ids[r][c] = idlist.size();
        idlist.emplace_back(r, c);
        for (int d = 0; d < 4; d++)
        {
            int r2 = r + dr[d];
            int c2 = c + dc[d];
            if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] == '.')
                dfs(grid, r2, c2, idlist);
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C, K;
    cin >> R >> C >> K;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    memset(ids, -1, sizeof(ids));
    vector<pii> idlist;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '.')
            {
                dfs(grid, i, j, idlist);
                goto found;
            }

found:
    for (int k = 0; k < K; k++)
    {
        auto p = idlist.back();
        idlist.pop_back();
        grid[p.first][p.second] = 'X';
    }
    for (int i = 0; i < R; i++)
        cout << grid[i] << '\n';

    return 0;
}