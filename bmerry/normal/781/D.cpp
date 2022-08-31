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

typedef bitset<500> bs;
typedef array<array<bs, 2>, 61> journ;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<journ> J(N);
    for (int i = 0; i < M; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        J[x][0][t].set(y);
    }
    for (int s = 1; s <= 60; s++)
    {
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                for (int p = 0; p < 2; p++)
                    if (J[x][s - 1][p][y])
                        J[x][s][p] |= J[y][s - 1][!p];
    }
    vector<vector<array<ll, 2>>> lng(N, vector<array<ll, 2>>(61));
    for (int s = 1; s <= 60; s++)
    {
        for (int i = 0; i < N; i++)
            for (int p = 0; p < 2; p++)
            {
                ll best = lng[i][s - 1][p];
                for (int j = 0; j < N; j++)
                {
                    if (J[i][s - 1][p][j])
                        best = max(best, lng[j][s - 1][!p] + (1LL << (s - 1)));
                }
                lng[i][s][p] = best;
            }
    }
    ll ans = lng[0][60][0];
    if (ans > 1000000000000000000LL)
        ans = -1;
    cout << ans << '\n';

    return 0;
}