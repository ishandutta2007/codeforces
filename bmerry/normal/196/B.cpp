// WRONG: doesn't handle N = 1 or M = 1 correctly

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

static int mod(int x, int m)
{
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M;
    cin >> N >> M;
    vs grid(N);
    int sr, sc;
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < M; j++)
            if (grid[i][j] == 'S')
            {
                grid[i][j] = '.';
                sr = i;
                sc = j;
            }
    }

    vector<vector<pii> > phase(N, vector<pii>(M, pii(INT_MAX, INT_MAX)));
    queue<pii> q;
    q.push(pii(sr, sc));
    phase[sr][sc] = pii(0, 0);
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        pii ph = phase[r][c];
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int r2 = mod(r + dr[d], N);
            int c2 = mod(c + dc[d], M);
            pii ph2 = ph;
            if (r == N - 1 && d == 2) ph2.first++;
            if (r == 0 && d == 0) ph2.first--;
            if (c == M - 1 && d == 3) ph2.second++;
            if (c == 0 && d == 1) ph2.second--;
            if (grid[r2][c2] != '#' && phase[r2][c2] != ph2)
            {
                if (phase[r2][c2].first != INT_MAX)
                    goto found;
                phase[r2][c2] = ph2;
                q.push(pii(r2, c2));
            }
        }
    }
    cout << "No\n";
    return 0;

found:
    cout << "Yes\n";
    return 0;
}