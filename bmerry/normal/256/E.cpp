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

static int count_levels(int N)
{
    int lvls = 1;
    while (N > 1)
    {
        lvls++;
        N = (N + 1) / 2;
    }
    return lvls;
}

#define MOD 777777777

struct node
{
    int paths[3][3];
};

static int mul(ll x, ll y)
{
    return (x * y) % MOD;
}

static int N, L;
static int lucky[3][3] = {{}};
static vector<vector<node> > levels;

static void fix(int lvl, int idx)
{
    node &cur = levels[lvl][idx];
    int a = 2 * idx;
    int b = a + 1;
    if (b >= SZ(levels[lvl - 1]))
        cur = levels[lvl - 1][a];
    else
    {
        const node &sa = levels[lvl - 1][a];
        const node &sb = levels[lvl - 1][b];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                ll sum = 0;
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++)
                        if (lucky[k][l])
                            sum += mul(sa.paths[i][k], sb.paths[l][j]);
                cur.paths[i][j] = sum % MOD;
            }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int M;
    cin >> N >> M;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> lucky[i][j];
        }

    L = count_levels(N);
    levels.resize(L);
    for (int i = 0; i < L; i++)
    {
        int mask = (1 << i);
        int sz = (N + mask - 1) >> i;
        levels[i].resize(sz);
    }
    for (int j = 0; j < N; j++)
        for (int k = 0; k < 3; k++)
            for (int l = 0; l < 3; l++)
                levels[0][j].paths[k][l] = (k == l);

    for (int i = 1; i < L; i++)
        for (int j = 0; j < SZ(levels[i]); j++)
        {
            fix(i, j);
        }

    for (int i = 0; i < M; i++)
    {
        int v, t;
        cin >> v >> t;
        v--; t--;
        for (int k = 0; k < 3; k++)
            levels[0][v].paths[k][k] = (t == -1 || t == k);
        for (int j = 1; j < L; j++)
        {
            fix(j, v >> j);
        }

        ll sum = 0;
        for (int k = 0; k < 3; k++)
            for (int l = 0; l < 3; l++)
                sum += levels[L - 1][0].paths[k][l];
        sum %= MOD;
        cout << sum << '\n';
    }

    return 0;
}