// WRONG ANSWER

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
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

static ll dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static ll hvdist(const pnt &a, const pnt &b)
{
    assert(a.real() == b.real() || a.imag() == b.imag());
    return llabs(a.real() - b.real()) + llabs(a.imag() - b.imag());
}

static pnt hvdir(const pnt &a, const pnt &b)
{
    assert(a.real() == b.real() || a.imag() == b.imag());
    int x = (a.real() < b.real()) ? 1 : (a.real() > b.real()) ? -1 : 0;
    int y = (a.imag() < b.imag()) ? 1 : (a.imag() > b.imag()) ? -1 : 0;
    return pnt(x, y);
}

struct walker
{
    const vector<ll> &plen;
    const vector<pnt> &pnts;
    int base = 0;
    ll bdist = 0;

    walker(const vector<ll> &plen, const vector<pnt> &pnts)
        : plen(plen), pnts(pnts) {}

    pnt pos_at(ll t)
    {
        int N = SZ(plen) - 1;
        while (bdist + plen[base + 1] - plen[base] <= t)
        {
            bdist += plen[base + 1] - plen[base];
            base++;
            if (base == N)
                base = 0;
        }
        ll extra = t - bdist;
        pnt dir = hvdir(pnts[base], pnts[base + 1]);
        return pnts[base] + dir * extra;
    }
};

static array<double, 2> rngtime(const pnt &p, const pnt &v, double r)
{
    double vv = dot(v, v);
    double pp = dot(p, p);
    double rr = r * r;
    if (vv == 0)
    {
        if (pp <= rr)
            return {{-HUGE_VAL, HUGE_VAL}};
        else
            return {{HUGE_VAL, -HUGE_VAL}};
    }
    else
    {
        double a = vv;
        double b = 2 * dot(v, p);
        double c = pp - rr;
        double det = b * b - 4 * a * c;
        if (det < 0)
            return {{HUGE_VAL, -HUGE_VAL}};
        det = sqrt(det);
        return {{(-b - det) / (2 * a), (-b + det) / (2 * a)}};
    }
}

struct event
{
    double t;
    int delta;

    event(double t, int delta) : t(t), delta(delta) {}

    bool operator<(const event &other) const
    {
        if (t != other.t)
            return t < other.t;
        else
            return delta < other.delta;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<pnt> pnts(N + 1);
    vector<ll> plen(N + 1);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts[i] = pnt(x * M, y * M);
        if (i > 0)
            plen[i] = plen[i - 1] + hvdist(pnts[i - 1], pnts[i]);
    }
    pnts[N] = pnts[0];
    plen[N] = plen[N - 1] + hvdist(pnts[N - 1], pnts[N]);
    assert(plen[N] % M == 0);
    ll sep = plen[N] / M;

    vector<ll> special;
    for (int i = 0; i < N; i++)
    {
        special.push_back(plen[i]);
        ll s = plen[i + 1] - sep;
        if (s < 0)
            s += plen[N];
        special.push_back(s);
    }
    for (ll i = 0; i <= M; i++)
        special.push_back(i * sep);
    sort(RA(special));
    special.resize(unique(RA(special)) - special.begin());
    assert(special[0] == 0);
    assert(special.back() == plen[N]);

    double lo = 0.0;
    double hi = 4000.0 * M;
    for (int pass = 0; pass < 50; pass++)
    {
        double R = (lo + hi) * 0.5;
        walker wa(plen, pnts), wb(plen, pnts);
        pnt pa, pb;
        ll ps = -1;
        vector<event> events;
        for (ll s : special)
        {
            pnt a = wa.pos_at(s);
            pnt b = wb.pos_at(s + sep);
            if (ps >= 0)
            {
                pnt va = hvdir(pa, a);
                pnt vb = hvdir(pb, b);
                pnt v = vb - va;
                pnt p = pb - pa;
                array<double, 2> times = rngtime(p, v, R);
                times[0] = max(times[0], 0.0);
                times[1] = min(times[1], double(s - ps));
                if (times[0] <= times[1])
                {
                    times[0] += ps % sep;
                    times[1] += ps % sep;
                    events.emplace_back(times[0], 1);
                    events.emplace_back(times[1], -1);
                }
            }
            pa = a;
            pb = b;
            ps = s;
        }

        sort(RA(events));
        int cur = 0;
        bool good = false;
        for (const event &e : events)
        {
            cur += e.delta;
            if (cur >= M)
                good = true;
        }
        if (good)
            hi = R;
        else
            lo = R;
    }
    cout << fixed << setprecision(9) << hi / M << '\n';

    return 0;
}