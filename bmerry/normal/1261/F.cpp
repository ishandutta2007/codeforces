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

// Undefined sign for negative inputs
template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }
template<typename T> static constexpr T sqr(T a) { return a * a; }
// m must be positive
template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T>
static constexpr T inverse2(T a, T m) { return a <= 1 ? a : mod((1 - inverse2(m % a, a) * m) / a, m); }

// a must be relatively prime to m, m > 0
template<typename T>
static constexpr T inverse(T a, T m) { return inverse2(mod(a, m), m); }

template<typename T, typename P>
static constexpr T power(T a, P b) { return b == 0 ? T(1) : (b % 2) ? power(a, b - 1) * a : sqr(power(a, b / 2)); }

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

    static constexpr T reduce(T value, tag_plus)
    {
        return value >= Modulus ? value - Modulus : value;
    }

    static constexpr T reduce(T value, tag_minus)
    {
        return value < 0 ? value + Modulus : value;
    }

    static constexpr T reduce(T value, tag_good) { return value; }

public:
    typedef T value_type;
    typedef C compute_type;
    static constexpr T modulus = Modulus;

    constexpr MR() : value(0) {}
    constexpr MR(C value) : value(reduce(value % Modulus, tag_minus())) {}
    template<typename tag_t>
    constexpr MR(T value, tag_t tag) : value(reduce(value, tag)) {}

    MR &operator=(C value) { this->value = reduce(value % Modulus, tag_minus()); return *this; }

    constexpr MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
    constexpr MR operator -(MR b) const { return MR(value - b.value, tag_minus()); }
    constexpr MR operator *(MR b) const { return MR(C(value) * C(b.value) % Modulus, tag_good()); }
    constexpr MR operator -() const { return MR(-value, tag_minus()); }

    MR &operator +=(MR b) { value = reduce(value + b.value, tag_plus()); return *this; }
    MR &operator -=(MR b) { value = reduce(value - b.value, tag_minus()); return *this; }
    MR &operator *=(MR b) { value = C(value) * C(b.value) % Modulus; return *this; }

    constexpr bool operator==(MR b) const { return value == b.value; }
    constexpr bool operator!=(MR b) const { return value != b.value; }

    constexpr T get() const { return value; }

    // These are only valid if the dividend is relatively prime to the modulus
    constexpr MR inverse() const
    {
        return MR(::inverse(C(value), C(Modulus)), tag_good());
    }
    constexpr MR operator /(MR b) const { return *this * b.inverse(); }
    MR &operator /=(MR b) { return *this *= b.inverse(); }
};

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
    return o << mr.get();
}

typedef MR<int, ll, 998244353> mr;


struct chunk
{
    ll prefix;
    ll sbits;

    bool operator<(const chunk &other) const
    {
        return make_pair(prefix, -sbits) < make_pair(other.prefix, -other.sbits);
    }

    bool operator==(const chunk &other) const
    {
        return prefix == other.prefix && sbits == other.sbits;
    }

    chunk parent() const
    {
        ll mask = (2LL << sbits) - 1;
        return chunk{prefix & ~mask, sbits + 1};
    }
};

struct chunk_group
{
    array<vector<chunk>, 61> real, aux;
};

void add_cg(chunk_group &a, const chunk_group &b)
{
    for (int i = 0; i <= 60; i++)
    {
        a.real[i].insert(a.real[i].end(), RA(b.real[i]));
        a.aux[i].insert(a.aux[i].end(), RA(b.aux[i]));
    }
}

static chunk operator^(const chunk &a, const chunk &b)
{
    chunk out;
    out.sbits = max(a.sbits, b.sbits);
    ll mask = (1LL << out.sbits) - 1;
    out.prefix = (a.prefix ^ b.prefix) & ~mask;
    return out;
}

static chunk_group make_chunks(ll L, ll R)
{
    chunk_group out;
    for (ll i = 0; L < R; i++)
    {
        ll mask = 1LL << i;
        if (L & mask)
        {
            out.real[i].push_back(chunk{L, i});
            L += mask;
        }
        if (R & mask)
        {
            R -= mask;
            out.real[i].push_back(chunk{R, i});
        }
    }
    for (int i = 0; i < 60; i++)
    {
        for (const chunk &c : out.real[i])
        {
            chunk p = c.parent();
            if (!count(RA(out.aux[i + 1]), p))
                out.aux[i + 1].push_back(p);
        }
        for (const chunk &c : out.aux[i])
        {
            chunk p = c.parent();
            if (!count(RA(out.aux[i + 1]), p))
                out.aux[i + 1].push_back(p);
        }
    }
    return out;
}

static chunk_group load_cg()
{
    int N;
    cin >> N;
    chunk_group out;
    for (int i = 0; i < N; i++)
    {
        ll L, R;
        cin >> L >> R;
        auto cg = make_chunks(L, R + 1);
        add_cg(out, cg);
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    chunk_group ag = load_cg();
    chunk_group bg = load_cg();

    vector<chunk> cs;
    for (int i = 0; i < 60; i++)
    {
        for (const chunk &a : ag.real[i])
            for (const chunk &b : bg.aux[i])
                cs.push_back(a ^ b);
        for (const chunk &a : ag.aux[i])
            for (const chunk &b : bg.real[i])
                cs.push_back(a ^ b);
        for (const chunk &a : ag.real[i])
            for (const chunk &b : bg.real[i])
                cs.push_back(a ^ b);
    }
    sort(RA(cs));

    chunk last{LLONG_MAX, 0};
    mr ans = 0;
    constexpr mr half = mr(1) / mr(2);
    for (const chunk &c : cs)
    {
        ll lmask = (1LL << last.sbits) - 1;
        if (c.sbits <= last.sbits && (c.prefix & ~lmask) == last.prefix)
            continue;
        ll p = c.prefix;
        ll q = c.prefix + (1LL << c.sbits) - 1;
        ans += mr(p + q) * mr(q - p + 1) * half;
        last = c;
    }

    cout << ans << '\n';

    return 0;
}