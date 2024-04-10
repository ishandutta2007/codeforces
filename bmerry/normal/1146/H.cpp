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
typedef complex<ll> pnt;
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

typedef bitset<300> bs;

static inline ll dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pnt> pnts(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
    }

    vector<vector<bs>> cw(N, vector<bs>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                for (int k = 0; k < N; k++)
                    if (cross(pnts[i], pnts[j], pnts[k]) > 0)
                        cw[i][j].set(k);

    ll tris = 0;
    ll quads = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                for (int k = max(i, j) + 1; k < N; k++)
                    if (cross(pnts[i], pnts[j], pnts[k]) > 0)
                    {
                        bs inside = cw[i][j] & cw[j][k] & cw[k][i];
                        int I = inside.count();
                        tris += I * (I - 1) / 2;

                        int O = (cw[i][j] & cw[j][k]).count() - I;
                        O += (cw[j][k] & cw[k][i]).count() - I;
                        O += (cw[k][i] & cw[i][j]).count() - I;
                        quads += I * O;
                    }

    quads /= 2;
    ll all = ll(N) * (N - 1) * (N - 2) * (N - 3) * (N - 4) / 120;
    ll ans = all - tris - quads;
    cout << ans << '\n';

    return 0;
}