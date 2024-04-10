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
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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

struct walk
{
    int x0, y0, x1, y1;

    walk() {}
    walk(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
};

static vector<pii> make_ranges(const set<int> &k)
{
    vector<pii> ranges;
    vi kv(k.begin(), k.end());
    ranges.push_back(pii(INT_MIN / 2, kv[0]));
    for (int i = 0; i < SZ(kv) - 1; i++)
    {
        ranges.push_back(pii(kv[i], kv[i] + 1));
        if (kv[i + 1] > kv[i] + 1)
            ranges.push_back(pii(kv[i] + 1, kv[i + 1]));
    }
    ranges.push_back(pii(kv.back(), kv.back() + 1));
    ranges.push_back(pii(kv.back() + 1, INT_MAX / 2));
    return ranges;
}

static int locate(const vector<pii> &ranges, int x)
{
    return lower_bound(ranges.begin(), ranges.end(), pii(x, INT_MIN)) - ranges.begin();
}

static const int ddr[4] = {-1, 0, 1, 0};
static const int ddc[4] = {0, -1, 0, 1};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    map<char, int> dr;
    map<char, int> dc;
    dr['L'] = 0; dr['R'] = 0; dr['U'] = -1; dr['D'] = 1;
    dc['L'] = -1; dc['R'] = 1; dc['U'] = 0; dc['D'] = 0;

    int N;
    cin >> N;
    int x = 0;
    int y = 0;
    set<int> kx, ky;
    kx.insert(0);
    ky.insert(0);
    vector<walk> walks;
    for (int i = 0; i < N; i++)
    {
        char dir;
        int len;
        cin >> ws >> dir >> len;
        int x1 = x + dr[dir] * len;
        int y1 = y + dc[dir] * len;
        kx.insert(x1);
        ky.insert(y1);
        walks.push_back(walk(x, y, x1, y1));
        x = x1;
        y = y1;
    }

    vector<pii> xr = make_ranges(kx);
    vector<pii> yr = make_ranges(ky);
    int R = SZ(xr);
    int C = SZ(yr);
    typedef int grid_type;
    vector<vector<grid_type> > grid(R, vector<grid_type>(C));
    for (int i = 0; i < N; i++)
    {
        walk &w = walks[i];
        w.x0 = locate(xr, w.x0);
        w.x1 = locate(xr, w.x1);
        w.y0 = locate(yr, w.y0);
        w.y1 = locate(yr, w.y1);
        for (int x = min(w.x0, w.x1); x <= max(w.x0, w.x1); x++)
            for (int y = min(w.y0, w.y1); y <= max(w.y0, w.y1); y++)
                grid[x][y] = 2;
    }

    queue<pii> q;
    q.push(pii(0, 0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + ddr[i];
            int y2 = y + ddc[i];
            if (x2 >= 0 && x2 < R && y2 >= 0 && y2 < C && grid[x2][y2] == 0)
            {
                grid[x2][y2] = 1;
                q.push(pii(x2, y2));
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] != 1)
            {
                ll w = xr[i].second - xr[i].first;
                ll h = yr[j].second - yr[j].first;
                ans += w * h;
            }
    cout << ans << '\n';

    return 0;
}