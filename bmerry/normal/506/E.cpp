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

typedef MR<int, ll, 10007> mr;

template<typename T>
struct polynomial_product_simple
{
    std::vector<T> operator()(const std::vector<T> &a, const std::vector<T> &b) const
    {
        std::vector<T> out(a.size() + b.size() - 1);
        for (std::size_t i = 0; i < a.size(); i++)
            for (std::size_t j = 0; j < b.size(); j++)
                out[i + j] += a[i] * b[j];
        return out;
    }
};

template<typename T, typename Product = polynomial_product_simple<T>>
class polynomial
{
private:
    std::vector<T> coeff;

    void prune()
    {
        while (!coeff.empty() && coeff.back() == T())
            coeff.pop_back();
    }

public:
    typedef T value_type;
    typedef Product product_type;

    polynomial() = default;
    explicit polynomial(const T &c) : coeff{c}
    {
        prune();
    }

    polynomial(std::initializer_list<T> c) : coeff(std::move(c))
    {
        prune();
    }

    template<typename It>
    polynomial(It first, It last) : coeff(first, last)
    {
        prune();
    }

    static polynomial xk(std::size_t k)
    {
        polynomial p;
        p.coeff.resize(k + 1);
        p.coeff[k] = 1;
        return p;
    }

    void set(std::size_t idx, const T &value)
    {
        if (value != T())
        {
            if (idx >= coeff.size())
                coeff.resize(idx + 1);
            coeff[idx] = value;
        }
        else if (idx < coeff.size())
        {
            coeff[idx] = value;
            prune();
        }
    }

    T operator[](std::size_t idx) const
    {
        return idx < coeff.size() ? coeff[idx] : T();
    }

    T operator()(const T &x) const
    {
        T ans{};
        for (std::size_t i = coeff.size(); i > 0; i--)
            ans = ans * x + coeff[i - 1];
        return ans;
    }

    std::size_t size() const { return coeff.size(); }
    std::size_t degree() const { return coeff.empty() ? 0 : coeff.size() - 1; }

    explicit operator bool() const { return !coeff.empty(); }
    bool operator!() const { return coeff.empty(); }
    bool operator==(const polynomial &other) const { return coeff == other.coeff; }
    bool operator!=(const polynomial &other) const { return coeff != other.coeff; }

    polynomial operator+(const polynomial &other) const
    {
        polynomial out;
        out.coeff.resize(std::max(size(), other.size()));
        for (std::size_t i = 0; i < out.size(); i++)
            out.coeff[i] = (*this)[i] + other[i];
        out.prune();
        return out;
    }

    polynomial operator-(const polynomial &other) const
    {
        polynomial out;
        out.coeff.resize(std::max(size(), other.size()));
        for (std::size_t i = 0; i < out.size(); i++)
            out.coeff[i] = (*this)[i] - other[i];
        out.prune();
        return out;
    }

    polynomial operator-() const
    {
        polynomial out;
        out.coeff.resize(size());
        for (std::size_t i = 0; i < size(); i++)
            out.coeff[i] = -coeff[i];
        return out;
    }

    polynomial operator*(const T &m) const
    {
        polynomial out;
        if (m != T())
        {
            out.coeff.resize(size());
            for (std::size_t i = 0; i < size(); i++)
                out.coeff[i] = coeff[i] * m;
            out.prune();
        }
        return out;
    }

    polynomial &operator+=(const polynomial &other)
    {
        if (other.size() > size())
            coeff.resize(other.size());
        for (std::size_t i = 0; i < other.size(); i++)
            coeff[i] += other.coeff[i];
        prune();
        return *this;
    }

    polynomial &operator-=(const polynomial &other)
    {
        if (other.size() > size())
            coeff.resize(other.size());
        for (std::size_t i = 0; i < other.size(); i++)
            coeff[i] -= other.coeff[i];
        prune();
        return *this;
    }

    polynomial &operator*=(const T &m)
    {
        if (m == T())
            coeff = std::vector<T>();
        else
        {
            for (T &v : coeff)
                v *= m;
            prune();
        }
        return *this;
    }

    polynomial operator*(const polynomial &other) const
    {
        if (coeff.empty() || other.coeff.empty())
            return polynomial{};
        polynomial out;
        out.coeff = Product()(coeff, other.coeff);
        out.prune();
        return out;
    }

    polynomial &operator*=(const polynomial &other)
    {
        return *this = *this * other;
    }

    polynomial reversed(std::size_t degree) const
    {
        assert(degree >= this->degree());
        polynomial out;
        out.coeff.resize(degree + 1);
        for (std::size_t i = 0; i < this->size(); i++)
            out.coeff[degree - i] = coeff[i];
        out.prune();
        return out;
    }

    polynomial reversed() const { return reversed(degree()); }

    // p % x^k
    polynomial mod_xk(std::size_t k) const
    {
        if (degree() < k)
            return *this;
        polynomial out;
        out.coeff = std::vector<T>(coeff.begin(), coeff.begin() + k);
        out.prune();
        return out;
    }

    // Below requires T to be a field

    polynomial &operator%=(const polynomial &q)
    {
        assert(q.size() > 0);
        if (q.coeff.back() != T(-1))
        {
            T scale = T(-1) / q.coeff.back();
            return *this %= q * scale;
        }
        while (size() >= q.size())
        {
            T s = coeff.back();
            std::size_t offset = size() - q.size();
            for (std::size_t i = 0; i + 1 < q.size(); i++)
                coeff[offset + i] += s * q[i];
            coeff.pop_back();
            prune();
        }
        return *this;
    }

    polynomial operator%(const polynomial &q) const
    {
        polynomial tmp = *this;
        return tmp %= q;
    }

    // Inverse of p modulo x^k
    polynomial inverse(std::size_t k) const
    {
        assert(!coeff.empty());
        if (k == 0)
            return polynomial{};
        else if (k == 1)
            return polynomial(T(1) / coeff[0]);
        else
        {
            std::size_t u = (k + 1) / 2;
            polynomial a0 = inverse(u);
            polynomial a = mod_xk(k);
            return ((polynomial(2) - a * a0) * a0).mod_xk(k);
        }
    }
};

// Fast polynomial modulus, precomputed for a given dividend
// Algorithm from http://docplayer.net/25594945-Lecture-4-polynomial-algorithms.html
// NB: only use if Polynomial has an FFT multiplication, otherwise it's a slowdown.
template<typename Polynomial>
class polymod
{
public:
    typedef typename Polynomial::value_type value_type;
    typedef Polynomial polynomial_type;

private:
    std::size_t N;
    polynomial_type b, br;
    // TODO: precompute inverse up to 2*N to speed it up

public:
    polymod(const polynomial_type &poly) : N(poly.degree()), b(poly), br(poly.reversed())
    {
        assert(poly);
    }

    polynomial_type operator()(const polynomial_type &a) const
    {
        std::size_t M = a.degree();
        if (M < N)
            return a;
        std::size_t D = M + 1 - N;
        auto bri = br.inverse(D);
        auto dr = (a.reversed() * br.inverse(D)).mod_xk(D);
        auto d = dr.reversed(D - 1);  // quotient
        return a - d * b;
    }
};

template<typename S, typename T, typename Product>
polynomial<T> operator*(const S &a, const polynomial<T, Product> &b)
{
    return b * a;
}

template<typename T, typename Product>
std::ostream &operator<<(std::ostream &o, const polynomial<T, Product> &p)
{
    if (!p)
        return o << "0";
    else
    {
        std::size_t D = p.degree();
        o << p[D] << "x^" << D;
        for (std::size_t i = D; i > 0; i--)
            if (p[i - 1] != T())
                o << " + " << p[i - 1] << "x^" << i - 1;
        return o;
    }
}

// Fast evaluation of a linear recurrence relation
template<typename T, typename Product = polynomial_product_simple<T>>
class recurrence
{
public:
    typedef T value_type;

private:
    polymod<polynomial<T, Product>> f;
    std::vector<T> a;

    template<typename It>
    polynomial<T, Product> make_f(It first, It last)
    {
        typedef polynomial<T, Product> poly;
        poly p(first, last);
        return poly::xk(last - first) - p;
    }

public:
    // First element refers to furthest-back element e.g. for
    // a_i = 3a_{i-2} + 2a_{i-1}, pass {3, 2}
    template<typename It, typename It2>
    recurrence(It cfirst, It clast, It2 afirst, It2 alast)
        : f(make_f(cfirst, clast)), a(afirst, alast)
    {
        assert(clast - cfirst == alast - afirst);
    }

    std::size_t size() const
    {
        return a.size();
    }

    T operator()(ll idx) const
    {
        typedef polynomial<T, Product> poly;
        poly g{1};
        poly p2{0, 1};
        while (idx > 0)
        {
            if (idx & 1)
                g = f(g * p2);
            p2 = f(p2 * p2);
            idx >>= 1;
        }
        T ans{};
        for (std::size_t i = 0; i < a.size(); i++)
            ans += a[i] * g[i];
        return ans;
    }

    // Berlekamp-Massey
    static recurrence from_data(const std::vector<T> &s)
    {
        std::vector<T> C{1};
        std::vector<T> B{1};
        std::size_t x = 1;
        std::size_t L = 0;
        T b{1};
        for (std::size_t N = 0; N < s.size(); N++)
        {
            T d = s[N];
            for (std::size_t i = 1; i <= L; i++)
                d += C[i] * s[N - i];
            if (d == 0)
                x++;
            else
            {
                std::vector<T> tmp = C;
                T scale = d / b;
                if (B.size() + x > C.size())
                    C.resize(B.size() + x);
                for (std::size_t i = 0; i < B.size(); i++)
                    C[i + x] -= scale * B[i];
                if (2 * L > N)
                    x++;
                else
                {
                    L = N + 1 - L;
                    B = std::move(tmp);
                    b = d;
                    x = 1;
                }
                assert(C.size() == L + 1);
            }
        }
        for (std::size_t i = 1; i <= L; i++)
            C[i] = -C[i];
        return recurrence(C.rbegin(), C.rend() - 1, s.begin(), s.begin() + L);
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string S;
    int N;
    cin >> S >> N;
    int L = SZ(S);
    int M = 3 * L + 26;
    vector<vector<vector<mr>>> dp(M + 1, vector<vector<mr>>(L, vector<mr>(L + 1)));
    dp[0][0][L] = 1;
    for (int i = 0; i < M; i++)
    {
        dp[i + 1][0][0] += dp[i][0][0] * 26;
        for (int j = 0; j < L; j++)
        {
            dp[i + 1][0][0] += dp[i][j][j + 1];
            dp[i + 1][j][j + 1] += dp[i][j][j + 1] * 25;
            for (int k = j + 2; k <= L; k++)
            {
                if (S[j] == S[k - 1])
                {
                    if (k - j > 2)
                        dp[i + 1][j + 1][k - 1] += dp[i][j][k];
                    else
                        dp[i + 1][0][0] += dp[i][j][k];
                    dp[i + 1][j][k] += dp[i][j][k] * 25;
                }
                else
                {
                    dp[i + 1][j + 1][k] += dp[i][j][k];
                    dp[i + 1][j][k - 1] += dp[i][j][k];
                    dp[i + 1][j][k] += dp[i][j][k] * 24;
                }
            }
        }
    }

    vector<mr> a(2 * M + 2);
    for (int i = 0; i <= M; i++)
    {
        a[2 * i] = dp[i][0][0];
        a[2 * i + 1] += dp[i][0][0] * 26;
        for (int j = 0; j < L; j++)
            a[2 * i + 1] += dp[i][j][j + 1];
    }

    auto r = recurrence<mr>::from_data(a);
    cout << r(N + L) << '\n';

    return 0;
}