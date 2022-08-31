#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

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

static const int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
static const int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct state
{
    unsigned char level;
    unsigned char dir;

    bool operator==(const state &other) const
    {
        return level == other.level && dir == other.dir;
    }
};

namespace std
{

template<>
struct hash<state>
{
    size_t operator()(const state &s) const
    {
        return (s.level << 8) | s.dir;
    }
};

}

static bool grid[320][320];
static unordered_set<state> seen[320][320];
static int N;
static int t[32];

static void recurse(int r, int c, const state &s)
{
    if (!seen[r][c].insert(s).second)
        return;
    grid[r][c] = true;
    for (int i = 1; i < t[s.level]; i++)
    {
        r += dr[s.dir];
        c += dc[s.dir];
        grid[r][c] = true;
    }
    if (s.level < N - 1)
    {
        int d1 = (s.dir - 1) & 7;
        int d2 = (s.dir + 1) & 7;
        int r1 = r + dr[d1];
        int c1 = c + dc[d1];
        int r2 = r + dr[d2];
        int c2 = c + dc[d2];
        state s1 = {s.level + 1, d1};
        state s2 = {s.level + 1, d2};
        recurse(r1, c1, s1);
        recurse(r2, c2, s2);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> t[i];

    state start = {0, 0};
    recurse(160, 160, start);
    int ans = 0;
    for (int i = 0; i < 320; i++)
        for (int j = 0; j < 320; j++)
            ans += int(grid[i][j]);
    cout << ans << '\n';
    return 0;
}