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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vs grid(R);
    int sr = -1, sc = -1, er = -1, ec = -1;
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
        auto p = grid[i].find('S');
        if (p != string::npos)
        {
            sr = i;
            sc = p;
        }
        p = grid[i].find('E');
        if (p != string::npos)
        {
            er = i;
            ec = p;
        }
    }
    string inst;
    cin >> inst;

    array<int, 4> dmap{{0, 1, 2, 3}};
    int ans = 0;
    do
    {
        int r = sr;
        int c = sc;
        bool good = false;
        for (char ch : inst)
        {
            int d = dmap[ch - '0'];
            int r2 = r + dr[d];
            int c2 = c + dc[d];
            if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C || grid[r2][c2] == '#')
                break;
            if (r2 == er && c2 == ec)
            {
                good = true;
                break;
            }
            r = r2;
            c = c2;
        }
        ans += good;
    } while (next_permutation(RA(dmap)));
    cout << ans << '\n';

    return 0;
}