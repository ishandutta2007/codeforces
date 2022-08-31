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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vs grid(R + 2);
    for (int i = 1; i <= R; i++)
    {
        string s;
        cin >> s;
        grid[i] = '.' + s + '.';
    }
    grid[0] = grid[R + 1] = string(C + 2, '.');
    R += 2;
    C += 2;

    vector<vi> dist(R, vi(C, INT_MAX));
    queue<pii> q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '.')
            {
                dist[i][j] = -1;
                q.emplace(i, j);
            }

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
            {
                int r2 = r + dr;
                int c2 = c + dc;
                if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] == 'X'
                    && dist[r2][c2] == INT_MAX)
                {
                    dist[r2][c2] = dist[r][c] + 1;
                    q.emplace(r2, c2);
                }
            }
    }

    int lo = 0;
    int hi = max(R, C) + 2;
    while (hi - lo > 1)
    {
        int T = (lo + hi) / 2;
        vector<vi> delt(R + 1, vi(C + 1, 0));
        for (int i = 1; i < R - 1; i++)
            for (int j = 1; j < C - 1; j++)
                if (dist[i][j] >= T)
                {
                    int r1 = max(0, i - T);
                    int r2 = min(R, i + T + 1);
                    int c1 = max(0, j - T);
                    int c2 = min(C, j + T + 1);
                    delt[r1][c1]++;
                    delt[r1][c2]--;
                    delt[r2][c1]--;
                    delt[r2][c2]++;
                }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                if (i > 0)
                    delt[i][j] += delt[i - 1][j];
                if (j > 0)
                    delt[i][j] += delt[i][j - 1];
                if (i > 0 && j > 0)
                    delt[i][j] -= delt[i - 1][j - 1];
                char expect = (delt[i][j] > 0) ? 'X' : '.';
                if (grid[i][j] != expect)
                    goto bad;
            }
        lo = T;
        continue;
bad:
        hi = T;
    }

    cout << lo << '\n';
    for (int i = 1; i < R - 1; i++)
    {
        string out(C - 2, '.');
        for (int j = 1; j < C - 1; j++)
            if (dist[i][j] >= lo)
                out[j - 1] = 'X';
        cout << out << '\n';
    }

    return 0;
}