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

struct pqitem
{
    int r, c;
    int d;

    bool operator<(const pqitem &other) const
    {
        return d > other.d;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    vector<vector<bool>> reach(R, vector<bool>(C));
    for (int i = R - 1; i >= 0; i--)
        for (int j = C - 1; j >= 0; j--)
        {
            if (grid[i][j] == '.')
            {
                bool right = j < C - 1 && reach[i][j + 1];
                bool down = i < R - 1 && reach[i + 1][j];
                reach[i][j] = right || down || (i == R - 1 && j == C - 1);
            }
        }

    if (!reach[0][0])
    {
        cout << "0\n";
        return 0;
    }

    int r = 0, c = 0;
    while (r != R - 1 || c != C - 1)
    {
        assert(reach[r][c]);
        reach[r][c] = false;
        if (c < C - 1 && reach[r][c + 1])
            c++;
        else
            r++;
    }

    reach[0][0] = true;
    r = c = 0;
    while (r != R - 1 || c != C - 1)
    {
        assert(reach[r][c]);
        if (r < R - 1 && reach[r + 1][c])
            r++;
        else if (c < C - 1 && reach[r][c + 1])
            c++;
        else
        {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}