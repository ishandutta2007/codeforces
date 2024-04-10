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

typedef array<pnt, 2> segment;

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

// a-b and p-q contain their endpoints
bool intersects_inclusive(const pnt &a, const pnt &b, const pnt &p, const pnt &q)
{
    if (std::min(a.real(), b.real()) > std::max(p.real(), q.real()))
        return false;
    if (std::min(p.real(), q.real()) > std::max(a.real(), b.real()))
        return false;
    if (std::min(a.imag(), b.imag()) > std::max(p.imag(), q.imag()))
        return false;
    if (std::min(p.imag(), q.imag()) > std::max(a.imag(), b.imag()))
        return false;

    ll c1 = cross(a, b, p);
    ll c2 = cross(a, b, q);
    if ((c1 > 0 && c2 > 0) || (c1 < 0 && c2 < 0))
        return false;

    ll d1 = cross(p, q, a);
    ll d2 = cross(p, q, b);
    if ((d1 > 0 && d2 > 0) || (d1 < 0 && d2 < 0))
        return false;

    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<segment> segs(N);
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        segs[i][0] = pnt(ax, ay);
        segs[i][1] = pnt(bx, by);
        pnt diff = segs[i][1] - segs[i][0];
        ll g = gcd(diff.real(), diff.imag());
        ans += g + 1;
    }

    map<pii, set<int>> freq;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (intersects_inclusive(segs[i][0], segs[i][1], segs[j][0], segs[j][1]))
            {
                ll u = cross(segs[i][0], segs[i][1], segs[j][0]);
                ll v = cross(segs[i][0], segs[i][1], segs[j][1]);
                ll d = v - u;
                pnt s = segs[j][0] * v - segs[j][1] * u;
                if (s.real() % d == 0 && s.imag() % d == 0)
                {
                    pii cut(s.real() / d, s.imag() / d);
                    freq[cut].insert(i);
                    freq[cut].insert(j);
                }
            }
        }
    for (const auto &item : freq)
        ans -= SZ(item.second) - 1;
    cout << ans << '\n';

    return 0;
}