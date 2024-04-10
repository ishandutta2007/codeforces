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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

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
            auto c = cross(da, db);
            if (c != 0)
                return c > 0;
            else
                return dot(da, da) > dot(db, db);
        }
    }
};

class CompareDamage
{
public:
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() > b.imag();
        else
            return a.real() < b.real();
    }
};

static void solve()
{
    int Q;
    ll M;
    cin >> Q >> M;

    int last_pos = 0;
    set<pnt, CompareAngle> hull;
    set<pnt, CompareDamage> hull_by_dmg;
    hull.insert(pnt(1, 0));
    for (int i = 0; i < Q; i++)
    {
        int k;
        ll a, b;
        cin >> k >> a >> b;
        a = (a + last_pos) % 1000000 + 1;
        b = (b + last_pos) % 1000000 + 1;
        if (k == 1)
        {
            pnt p(b, a);
            auto [ptr, added] = hull.insert(p);
            if (!added)
                continue;
            hull_by_dmg.insert(p);
            if (ptr != hull.begin() && next(ptr) != hull.end()
                && cross(*prev(ptr), p, *next(ptr)) <= 0)
            {
                hull.erase(ptr);
                hull_by_dmg.erase(p);
                continue;
            }

            decltype(ptr) x1, x2;
            while (ptr != hull.begin() && (x1 = prev(ptr)) != hull.begin()
                   && cross(*prev(x1), *x1, p) <= 0)
            {
                hull_by_dmg.erase(*x1);
                hull.erase(x1);
            }
            while ((x1 = next(ptr)) != hull.end() && (x2 = next(x1)) != hull.end()
                   && cross(p, *x1, *x2) <= 0)
            {
                hull_by_dmg.erase(*x1);
                hull.erase(x1);
            }

            while (SZ(hull) >= 2 && cross(*prev(hull.end()), *prev(prev(hull.end()))) == 0)
            {
                auto prv = prev(hull.end());
                hull_by_dmg.erase(*prv);
                hull.erase(prv);
            }
        }
        else
        {
            ll t = a;
            ll h = b;
            ll min_y = (h + t - 1) / t;
            pnt p(M, h);
            auto ptr = hull.lower_bound(p);
            if (ptr != hull.begin() && cross(*prev(ptr), p) == 0)
                --ptr;
            bool good = false;
            if (ptr != hull.end())
            {
                if (ptr->imag() >= min_y)
                    good = true;
                else if (ptr != hull.begin())
                {
                    auto prv = prev(ptr);
                    ll cr1 = cross(p, *ptr);
                    ll cr2 = cross(p, *prv);
                    ll yn = (prv->imag() * cr1 - ptr->imag() * cr2);
                    ll yd = cr1 - cr2;
                    assert(yd > 0);
                    if (__int128(yn) * t >= __int128(h) * yd)
                        good = true;
                }
            }
            if (!good && !hull_by_dmg.empty() && hull_by_dmg.begin()->imag() >= min_y
                && cross(p, *hull_by_dmg.begin()) >= 0)
                good = true;
            if (good)
            {
                cout << "YES\n";
                last_pos = i + 1;
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}