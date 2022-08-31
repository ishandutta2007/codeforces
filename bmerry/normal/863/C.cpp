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

static void solve()
{
    ll K;
    int a, b;
    cin >> K >> a >> b;
    a--;
    b--;
    array<array<int, 3>, 3> A, B;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
            A[i][j]--;
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> B[i][j];
            B[i][j]--;
        }

    array<array<int, 3>, 3> last;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            last[i][j] = -1;

    vector<array<int, 2>> pnts;
    pnts.push_back(array<int, 2>{0, 0});
    while (last[a][b] == -1)
    {
        last[a][b] = SZ(pnts) - 1;
        pnts.push_back(pnts.back());
        if (a == (b + 1) % 3)
            pnts.back()[0]++;
        else if (b == (a + 1) % 3)
            pnts.back()[1]++;
        int na = A[a][b];
        int nb = B[a][b];
        a = na;
        b = nb;
    }
    ll R = SZ(pnts) - 1;
    ll ea = 0, eb = 0;
    if (K > R)
    {
        ll L = last[a][b];
        ll period = R - L;
        ll reps = (K - L) / period;
        K -= reps * period;
        ea = (pnts[R][0] - pnts[L][0]) * reps;
        eb = (pnts[R][1] - pnts[L][1]) * reps;
    }
    cout << pnts[K][0] + ea << ' ' << pnts[K][1] + eb << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}