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

// Sort by Y then by X
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

/* Sorts points by the angle they occupy relative to another point, starting at +X
 * and going ccw. Ties are broken by sorting with increasing distance from the base.
 * The base itself sorts to the front.
 */
class CompareAngle
{
private:
    const pnt base;

public:
    explicit CompareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        const pnt da = a - base;
        const pnt db = b - base;
        bool fa = da.imag() > 0 || (da.imag() == 0 && da.real() >= 0);
        bool fb = db.imag() > 0 || (db.imag() == 0 && db.real() >= 0);
        if (fa != fb)
            return fa;
        else
        {
            ll c = cross(da, db);
            if (c != 0)
                return c > 0;
            else
                return dot(da, da) < dot(db, db);
        }
    }
};

struct shipbase
{
    pnt pos;
    int idx;
    int type;
};

static vi ans;

static vector<shipbase> extract(const vector<shipbase> &items, int head, int tail)
{
    vector<shipbase> out;
    while (head != tail)
    {
        out.push_back(items[head]);
        if (++head == SZ(items))
            head = 0;
    }
    assert(!out.empty());
    return out;
}

static bool internal(const pnt &a, const pnt &b)
{
    ll c = cross(a, b);
    if (c != 0)
        return c > 0;
    else
        return !CompareY()(b, a);
}

static void solve(const vector<shipbase> &oitems)
{
    int N = SZ(oitems);
    if (N == 2)
    {
        if (oitems[0].type == 1)
            ans[oitems[0].idx] = oitems[1].idx;
        else
            ans[oitems[1].idx] = oitems[0].idx;
        return;
    }

    auto items = oitems;
    pnt mid = 0;
    for (int i = 0; i < N; i++)
        mid += items[i].pos;
    for (int i = 0; i < N; i++)
        items[i].pos = items[i].pos * ll(N) - mid;

    sort(RA(items), [](const shipbase &a, const shipbase &b)
    {
        return CompareAngle(pnt(0))(a.pos, b.pos);
    });
    int tail = 0;
    int sum = 0;
    for (int head = 0; head < N; head++)
    {
        while (internal(items[head].pos, items[tail].pos))
        {
            sum += items[tail].type;
            if (++tail == N)
                tail = 0;
        }
        if (sum == 0)
        {
            for (auto &item : items)
            {
                item.pos += mid;
                item.pos = pnt(item.pos.real() / N, item.pos.imag() / N);
            }
            solve(extract(items, head, tail));
            solve(extract(items, tail, head));
            return;
        }
        sum -= items[head].type;
    }
    assert(false);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<shipbase> items(2 * N);
    pnt mid;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        items[i].pos = pnt(x, y);
        items[i].idx = i;
        items[i].type = 1;
    }
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        items[i + N].pos = pnt(x, y);
        items[i + N].idx = i;
        items[i + N].type = -1;
    }

    ans.resize(N);
    solve(items);
    for (int i = 0; i < N; i++)
        cout << ans[i] + 1 << '\n';

    return 0;
}