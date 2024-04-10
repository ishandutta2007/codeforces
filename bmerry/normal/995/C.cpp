//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

typedef std::complex<ll> pnt;

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

struct lpnt
{
    pnt pos;
    int idx;
};

class CompareAngle
{
public:
    bool operator()(const lpnt &a, const lpnt &b) const
    {
        ll c = cross(a.pos, b.pos);
        if (c != 0)
            return c > 0;
        else
            return a.idx < b.idx;
    }
};

static bool below(const pnt &p)
{
    return p.imag() < 0 || (p.imag() == 0 && p.real() < 0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    set<lpnt, CompareAngle> pnts;
    vector<pnt> orig(N);
    vector<unsigned char> flip(N);
    vector<int> parent(N, -1);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnt p(x, y);
        orig[i] = p;
        if (below(p))
        {
            p = -p;
            flip[i] = true;
        }
        pnts.insert(lpnt{p, i});
    }
    while (SZ(pnts) > 1)
    {
        for (auto u = pnts.begin(); u != pnts.end(); ++u)
        {
            auto v = next(u);
            if (v == pnts.end())
                v = pnts.begin();
            ll du = dot(u->pos, u->pos);
            ll dv = dot(v->pos, v->pos);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                {
                    pnt sum = (i ? -u->pos : u->pos) + (j ? -v->pos : v->pos);
                    ll ds = dot(sum, sum);
                    if (!below(sum) && (ds <= du || ds <= dv))
                    {
                        int idx = SZ(parent);
                        flip[u->idx] ^= i;
                        flip[v->idx] ^= j;
                        parent[u->idx] = idx;
                        parent[v->idx] = idx;
                        pnts.erase(u);
                        pnts.erase(v);
                        pnts.insert(lpnt{sum, idx});
                        parent.push_back(-1);
                        flip.push_back(false);
                        goto have_found;
                    }
                }
        }
        break;
have_found:;
    }

    if (SZ(pnts) > 1)
    {
        assert(SZ(pnts) == 2);
        auto u = pnts.begin();
        auto v = next(u);
        if (dot(u->pos, v->pos) > 0)
            flip[v->idx] ^= true;
    }

    for (int i = SZ(parent) - 1; i >= 0; i--)
        if (parent[i] != -1)
            flip[i] ^= flip[parent[i]];

    for (int i = 0; i < N; i++)
        cout << (flip[i] ? -1 : 1) << ' ';
    cout << '\n';

#if 0
    pnt total = 0;
    for (int i = 0; i < N; i++)
        total += (flip[i] ? -orig[i] : orig[i]);
    cout << total << '\n';
    assert(dot(total, total) <= 1500000LL * 1500000LL);
#endif

    return 0;
}