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

static ll dot(const pnt &a, const pnt &b) { return real(conj(a) * b); }

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

class CompareY
{
public:
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pnt> pnts(N);
    vector<pnt> cpnts(N);
    pnt middle = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
        middle += pnts[i];
    }
    set<pnt, CompareY> spnts;
    for (int i = 0; i < N; i++)
    {
        cpnts[i] = pnts[i] * ll(N) - middle;
        spnts.insert(cpnts[i]);
    }

    int i = 0;
    while (i < N && spnts.count(-cpnts[i]))
        i++;
    if (i == N)
    {
        cout << "-1\n";
        return 0;
    }

    set<pnt, CompareY> ans;
    for (int j = 0; j < N; j++)
    {
        pnt L = cpnts[i] + cpnts[j];
        L *= pnt(0, 1);

        vector<ll> pos(N);
        for (int k = 0; k < N; k++)
            pos[k] = dot(L, pnts[k]);
        sort(RA(pos));
        ll s = pos[0] + pos.back();
        bool good = true;
        for (int i = 1; i <= N / 2 && good; i++)
            if (pos[i] + pos[N - 1 - i] != s)
                good = false;
        if (good)
        {
            ll g = gcd(L.real(), L.imag());
            L /= g;
            if (L.imag() < 0 || (L.imag() == 0 && L.real() < 0))
                L = -L;
            ans.insert(L);
        }
    }
    cout << SZ(ans) << '\n';

    return 0;
}