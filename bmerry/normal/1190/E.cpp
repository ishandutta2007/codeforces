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

static inline double dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline double cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline double cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

class CompareAngle
{
public:
    bool operator()(const pnt &a, const pnt &b) const
    {
        const pnt da = a;
        const pnt db = b;
        bool fa = da.imag() > 0 || (da.imag() == 0 && da.real() >= 0);
        bool fb = db.imag() > 0 || (db.imag() == 0 && db.real() >= 0);
        if (fa != fb)
            return fa;
        else
        {
            double c = cross(da, db);
            if (c != 0)
                return c > 0;
            else
                return dot(da, da) < dot(db, db);
        }
    }
};

static vi combine(const vi &a, const vi &b)
{
    int N = SZ(a);
    vi out(N);
    for (int i = 0; i < N; i++)
    {
        int jmp = a[i];
        int y = (i + jmp) % N;
        out[i] = min(N, jmp + b[y]);
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cout << fixed << setprecision(9);
    int N, M;
    cin >> N >> M;
    vector<pnt> pnts(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x, y);
    }
    sort(RA(pnts), CompareAngle());
    double hi = HUGE_VAL;
    for (const auto &p : pnts)
        hi = min(hi, abs(p));
    double lo = 0.0;
    if (hi == 0.0 || N == M)
    {
        cout << hi << '\n';
        return 0;
    }

    vector<double> args(N), angu(N), angd(N);
    for (int i = 0; i < N; i++)
    {
        args[i] = arg(pnts[i]);
        if (args[i] < 0.0)
            args[i] += 2 * M_PI;
    }

    while (hi - lo > 1e-10 * max(1.0, lo))
    {
        double dist = (lo + hi) * 0.5;
        vi jump(N);
        int jmp = 0;
        multiset<double> upper, lower;
        for (int i = 0; i < N; i++)
        {
            double t = acos(min(1.0, dist / abs(pnts[i])));
            angu[i] = args[i] + t;
            angd[i] = args[i] - t;
        }

        for (int i = 0; i < N; i++)
        {
            jmp--;
            jmp = max(jmp, 0);
            int y = (i + jmp) % N;
            while (jmp < N)
            {
                if (jmp > 0 && min(angu[y], *upper.begin()) < max(angd[y], *lower.rbegin()))
                    break;
                upper.insert(angu[y]);
                lower.insert(angd[y]);
                jmp++;
                if (++y == N)
                    y = 0;
            }
            jump[i] = jmp;
            upper.erase(upper.find(angu[i]));
            lower.erase(lower.find(angd[i]));
            angu[i] += 2 * M_PI;
            angd[i] += 2 * M_PI;
        }
        vi p2 = jump;
        vi comb(N);
        for (int i = 1; i <= M; i *= 2)
        {
            if (M & i)
                comb = combine(comb, p2);
            p2 = combine(p2, p2);
        }
        if (*max_element(RA(comb)) >= N)
            lo = dist;
        else
            hi = dist;
    }
    cout << hi << '\n';

    return 0;
}