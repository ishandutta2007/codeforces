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

struct query
{
    int l, r;
    int idx;

    bool operator<(const query &other) const
    {
        return r < other.r;
    }
};

static constexpr ll MOD = 1000000007;
static constexpr ll BIG = 2 * MOD;

// Undefined sign for negative inputs
template<typename T>
static T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

template<typename T, typename C, T Modulus>
class MR
{
private:
    struct tag_plus {}; // indicates value is in range [0, 2 * Modulus)
    struct tag_minus {}; // indicates value is in range (-Modulus, Modulus)
    struct tag_good {}; // indicates value is in range

    T value;

    static_assert(std::numeric_limits<C>::max() / Modulus / Modulus > 0, "compute type is too small");
    static_assert(Modulus < std::numeric_limits<T>::max() / 2, "storage type is too small");

    void reduce(tag_plus)
    {
        if (value >= Modulus)
            value -= Modulus;
    }

    void reduce(tag_minus)
    {
        if (value < 0)
            value += Modulus;
    }

    void reduce(tag_good) {}

public:
    typedef T value_type;
    typedef C compute_type;
    static const T modulus = Modulus;

    MR() : value(0) {}
    MR(C value) : value(value % Modulus) { reduce(tag_minus()); }
    template<typename tag_t>
    MR(T value, tag_t tag) : value(value) { reduce(tag); }

    MR &operator=(C value) { this->value = value % Modulus; reduce(tag_minus()); return *this; }

    MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
    MR operator -(MR b) const { return MR(value - b.value, tag_minus()); }
    MR operator *(MR b) const { return MR(C(value) * C(b.value) % Modulus, tag_good()); }
    MR operator -() const { return MR(-value, tag_minus()); }

    MR &operator +=(MR b) { value += b.value; reduce(tag_plus()); return *this; }
    MR &operator -=(MR b) { value -= b.value; reduce(tag_minus()); return *this; }
    MR &operator *=(MR b) { value = C(value) * C(b.value) % Modulus; return *this; }

    bool operator==(MR b) const { return value == b.value; }
    bool operator!=(MR b) const { return value != b.value; }

    T get() const { return value; }

    // These are only valid if the Modulus is prime, or at least if
    // the dividend is relatively prime to the modulus
    MR inverse() const
    {
        assert(value);
        return MR(::inverse(C(value), C(Modulus)), tag_good());
    }
    MR operator /(MR b) const { return *this * b.inverse(); }
    MR &operator /=(MR b) { return *this *= b.inverse(); }
};

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
    return o << mr.get();
}

typedef MR<int, ll, int(MOD)> mr;

static vector<mr> p2, ip2;

static ll reduce(ll v)
{
    if (v >= BIG)
        return v % MOD + BIG;
    else if (v <= -BIG)
        return v % MOD - BIG;
    else
        return v;
}

static ll shl(ll v, int d)
{
    assert(v > 0);
    if (d <= 30)
        return reduce(v << d);
    else
        return v * p2[d].get() % MOD + BIG;
}

struct group
{
    int start, end;
    ll total;

    int len() const { return end - start; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    vector<query> queries(Q);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(RA(queries));
    vector<mr> ans(Q);

    p2.resize(N + 1);
    ip2.resize(N + 1);
    p2[0] = 1;
    ip2[0] = 1;
    mr inv2 = mr(2).inverse();
    for (int i = 1; i <= N; i++)
    {
        p2[i] = p2[i - 1] + p2[i - 1];
        ip2[i] = inv2 * ip2[i - 1];
    }

    vector<mr> prefix(N + 1);
    vector<group> groups;
    int q = 0;
    for (int i = 0; i < N; i++)
    {
        group ng;
        ng.start = i;
        ng.end = i + 1;
        ng.total = reduce(a[i]);
        int fix = i;
        while (!groups.empty() && ng.total > 0)
        {
            fix = ng.start;
            ng.start = groups.back().start;
            ng.total = reduce(groups.back().total + shl(ng.total, groups.back().len()));
            groups.pop_back();
        }
        groups.push_back(ng);
        for (int j = fix; j <= i; j++)
            prefix[j + 1] = prefix[j] + p2[j - ng.start] * a[j];

        while (q < Q && queries[q].r == i + 1)
        {
            int lo = 0;
            int hi = SZ(groups);
            int l = queries[q].l;
            while (hi - lo > 1)
            {
                int mid = (lo + hi) / 2;
                if (groups[mid].start <= l)
                    lo = mid;
                else
                    hi = mid;
            }
            const group &g = groups[lo];
            mr part = mr(g.total) - (prefix[l] - prefix[g.start]);
            part *= ip2[l - g.start];
            part += (prefix[i + 1] - prefix[g.end]);
            ans[queries[q].idx] = part * 2 + a[l - 1];
            q++;
        }
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}