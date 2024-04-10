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
}

/*** TEMPLATE CODE ENDS HERE */

static int rerank(const vi &row, vi &out)
{
    vi u = row;
    sort(RA(u));
    u.resize(unique(RA(u)) - u.begin());
    for (int i = 0; i < SZ(row); i++)
        out[i] = lower_bound(RA(u), row[i]) - u.begin();
    return SZ(u);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vector<vi> grid(R, vi(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    vi freqr(R), freqc(C);
    vector<vi> rankr(R, vi(C)), rankc(R, vi(C));
    for (int i = 0; i < R; i++)
        freqr[i] = rerank(grid[i], rankr[i]);
    for (int i = 0; i < C; i++)
    {
        vi tmp(R);
        for (int j = 0; j < R; j++)
            tmp[j] = grid[j][i];
        vi trank(R);
        freqc[i] = rerank(tmp, trank);
        for (int j = 0; j < R; j++)
            rankc[j][i] = trank[j];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int s = max(rankr[i][j], rankc[i][j])
                + max(freqr[i] - rankr[i][j], freqc[j] - rankc[i][j]);
            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}