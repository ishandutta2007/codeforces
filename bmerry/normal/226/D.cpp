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

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int rsum[100] = {}, csum[100] = {};
    int grid[100][100];
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            rsum[i] += grid[i][j];
            csum[j] += grid[i][j];
        }

    bool rflip[100] = {}, cflip[100] = {};
    bool rinq[100] = {}, cinq[100] = {};
    queue<int> q;
    for (int i = 0; i < R; i++)
        if (rsum[i] < 0)
        {
            q.push(i);
            rinq[i] = true;
        }
    for (int i = 0; i < C; i++)
        if (csum[i] < 0)
        {
            q.push(-1 - i);
            cinq[i] = true;
        }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur < 0)
        {
            int c = -1 - cur;
            cinq[c] = false;
            if (csum[c] >= 0)
                continue;
            cflip[c] = !cflip[c];
            csum[c] = -csum[c];
            for (int i = 0; i < R; i++)
            {
                grid[i][c] = -grid[i][c];
                rsum[i] += 2 * grid[i][c];
                if (rsum[i] < 0 && !rinq[i])
                {
                    rinq[i] = true;
                    q.push(i);
                }
            }
        }
        else
        {
            int r = cur;
            rinq[r] = false;
            if (rsum[r] >= 0)
                continue;
            rflip[r] = !rflip[r];
            rsum[r] = -rsum[r];
            for (int i = 0; i < C; i++)
            {
                grid[r][i] = -grid[r][i];
                csum[i] += 2 * grid[r][i];
                if (csum[i] < 0 && !cinq[i])
                {
                    cinq[i] = true;
                    q.push(-1 - i);
                }
            }
        }
    }

    cout << count(rflip, rflip + R, true);
    for (int i = 0; i < R; i++)
        if (rflip[i])
            cout << ' ' << i + 1;
    cout << '\n';
    cout << count(cflip, cflip + C, true);
    for (int i = 0; i < C; i++)
        if (cflip[i])
            cout << ' ' << i + 1;
    cout << '\n';

    return 0;
}