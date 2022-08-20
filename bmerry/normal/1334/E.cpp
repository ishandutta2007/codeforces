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

static ll powermod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return __int128(a) * powermod(a, b - 1, m) % m;
    else
    {
        ll t = powermod(a, b / 2, m);
        return __int128(t) * t % m;
    }
}

static bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    else if (n < 64)
        return (0x28208a20a08a28acULL >> n) & 1;
    else if (n % 2 == 0)
        return false;
    else if (n < 1000000)
    {
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
    else
    {
        // Rabin-Miller
        ll d = n - 1;
        int r = 0;
        while (!(d & 1))
        {
            d >>= 1;
            r++;
        }
        for (ll a = 2; a <= 37; a++)
            if (is_prime(a))
            {
                ll x = powermod(a, d, n);
                if (x == 1 || x == n - 1)
                    continue;
                int i;
                for (i = 0; i < r - 1; i++)
                {
                    x = __int128(x) * x % n;
                    if (x == n - 1)
                        break;
                }
                if (i == r - 1)
                    return false;
            }
        return true;
    }
}

// Finds a factor of n (which *must* be composite and > 1)
static ll pollard_rho(ll n)
{
    std::mt19937_64 engine;
    std::uniform_int_distribution<ll> pick(2, n - 2);
    while (true)
    {
        ll a, b, s;
        a = b = pick(engine);
        s = pick(engine);
        while (true)
        {
            a = (__int128(a) * a + s) % n;
            b = (__int128(b) * b + s) % n;
            b = (__int128(b) * b + s) % n;
            if (a == b)
                break;
            ll g = gcd(llabs(a - b), n);
            if (g > 1)
                return g;
        }
    }
}

static std::vector<std::pair<ll, int>> factorise(ll n)
{
    std::vector<std::pair<ll, int>> out;
    if (n < 1000000)   // NB: match with is_prime
    {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
            {
                n /= i;
                int r = 1;
                while (n % i == 0)
                {
                    n /= i;
                    r++;
                }
                out.emplace_back(i, r);
            }
        if (n > 1)
            out.emplace_back(n, 1);
    }
    else if (is_prime(n))
    {
        out.emplace_back(n, 1);
    }
    else
    {
        ll a = pollard_rho(n);
        auto fa = factorise(a);
        auto fb = factorise(n / a);
        auto pa = fa.begin();
        auto pb = fb.begin();
        while (pa != fa.end() && pb != fb.end())
        {
            if (pa->first == pb->first)
            {
                out.emplace_back(pa->first, pa->second + pb->second);
                ++pa;
                ++pb;
            }
            else if (pa->first < pb->first)
                out.push_back(*pa++);
            else
                out.push_back(*pb++);
        }
        std::copy(pa, fa.end(), std::back_inserter(out));
        std::copy(pb, fb.end(), std::back_inserter(out));
    }
    return out;
}


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


static vector<mr> fact(64), ifact(64);

static mr multinomial(const vi &m)
{
    mr ans = 1;
    int sum = 0;
    for (int x : m)
    {
        ans *= ifact[x];
        sum += x;
    }
    ans *= fact[sum];
    return ans;
}


int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll D;
    cin >> D;

    fact[0] = 1;
    ifact[0] = 1;
    for (int i = 1; i < 64; i++)
    {
        fact[i] = fact[i - 1] * i;
        ifact[i] = ifact[i - 1] / i;
    }

    auto factors = factorise(D);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        vi lft, rgt;
        ll u, v;
        cin >> u >> v;
        for (const auto &f : factors)
        {
            ll p = f.first;
            int x = 0;
            while (u % p == 0)
            {
                x++;
                u /= p;
            }
            while (v % p == 0)
            {
                x--;
                v /= p;
            }
            if (x > 0)
                lft.push_back(x);
            else if (x < 0)
                rgt.push_back(-x);
        }

        mr ans = multinomial(lft) * multinomial(rgt);
        cout << ans << '\n';
    }

    return 0;
}