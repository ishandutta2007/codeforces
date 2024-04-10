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

typedef std::complex<ll> pnt;

template<typename T>
static inline T dot(const std::complex<T> &a, const std::complex<T> &b)
{
    return real(conj(a) * b);
}

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b)
{
    return imag(conj(a) * b);
}

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b, const std::complex<T> &c)
{
    return cross(b - a, c - a);
}


static void solve()
{
    int N;
    cin >> N;
    vector<pnt> pnts(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
    }
    if (N <= 4)
    {
        cout << "YES\n";
        return;
    }
    int z = 2;
    while (z < N && cross(pnts[0], pnts[1], pnts[z]) == 0)
        z++;
    if (z == N)
    {
        cout << "YES\n";
        return;
    }
    swap(pnts[2], pnts[z]);
    for (int i = 0; i < 3; i++)
    {
        vector<pnt> extra;
        for (int i = 2; i < N; i++)
            if (cross(pnts[0], pnts[1], pnts[i]) != 0)
                extra.push_back(pnts[i]);
        bool good = true;
        for (int i = 2; i < SZ(extra); i++)
            if (cross(extra[0], extra[1], extra[i]) != 0)
                good = false;
        if (good)
        {
            cout << "YES\n";
            return;
        }
        rotate(pnts.begin(), pnts.begin() + 1, pnts.begin() + 3);
    }
    cout << "NO\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}