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


template<typename Traits, typename SizeType = unsigned int>
class FFT
{
public:
    typedef SizeType size_type;
    typedef typename Traits::type type;

private:
    std::vector<std::vector<type>> roots, rroots;
    std::vector<size_type> butterfly;
    type inv_size;

    void permute(std::vector<type> &a) const
    {
        const size_type S = size();
        assert(a.size() == S);
        for (size_type i = 0; i < S; i++)
        {
            size_type other = butterfly[i];
            if (i < other)
                std::swap(a[i], a[other]);
        }
    }

    void transform(std::vector<type> &a, bool invert) const
    {
        const std::vector<std::vector<type>> &allr = invert ? rroots : roots;
        const size_type S = size();

        permute(a);
        for (std::size_t i = 1; i < allr.size(); i++)
        {
            const std::vector<type> &r = allr[i];
            size_type outer = size_type(1) << i;
            size_type inner = outer / 2;
            for (size_type j = 0; j < S; j += outer)
                for (size_type k = 0; k < inner; k++)
                {
                    type x = a[j + k];
                    type y = a[j + k + inner] * r[k];
                    a[j + k] = x + y;
                    a[j + k + inner] = x - y;
                }
        }
    }

    void init_roots(size_type len, type g)
    {
        if (len == 1)
        {
            roots.emplace_back();
            roots.back().push_back(1);
            rroots.push_back(roots.back());
        }
        else
        {
            init_roots(len >> 1, g * g);
            std::vector<type> new_roots;
            new_roots.reserve(len);
            for (auto &r : roots.back())
            {
                new_roots.push_back(r);
                new_roots.push_back(g * r);
            }
            std::vector<type> new_rroots;
            new_rroots.reserve(len);
            new_rroots.push_back(new_roots[0]);
            new_rroots.insert(new_rroots.end(), new_roots.rbegin(), new_roots.rend() - 1);
            roots.push_back(std::move(new_roots));
            rroots.push_back(std::move(new_rroots));
        }
    }

    void init_butterfly(size_type len)
    {
        butterfly.resize(len);
        for (size_type i = 1; i < len; i <<= 1)
            for (size_type j = 0; j < i; j++)
            {
                butterfly[j] <<= 1;
                butterfly[i + j] = butterfly[j] + 1;
            }
    }

public:
    size_type size() const { return butterfly.size(); }

    FFT(size_type len)
    {
        assert(len > 0 && (len & (len - 1)) == 0);
        init_roots(len, Traits::generator(len));
        init_butterfly(len);
        inv_size = Traits::inverse(len);
    }

    void fft(std::vector<type> &a) const
    {
        transform(a, false);
    }

    void rfft(std::vector<type> &a) const
    {
        transform(a, true);
        for (type &v : a)
            v *= inv_size;
    }

    template<typename U>
    std::vector<type> convolve(const std::vector<U> &a, const std::vector<U> &b) const
    {
        assert(!a.empty());
        assert(!b.empty());

        std::vector<type> pa(size()), pb(size());
        std::copy(a.begin(), a.end(), pa.begin());
        std::copy(b.begin(), b.end(), pb.begin());
        transform(pa, false);
        transform(pb, false);
        for (size_type i = 0; i < size(); i++)
            pa[i] *= pb[i];
        transform(pa, true);
        pa.resize(a.size() + b.size() - 1);
        for (type &v : pa)
            v *= inv_size;
        return pa;
    }
};

template<typename Plan>
static void fft(std::vector<typename Plan::type> &a)
{
    Plan plan(a.size());
    plan.fft(a);
}

template<typename Plan>
static void rfft(std::vector<typename Plan::type> &a)
{
    Plan plan(a.size());
    plan.rfft(a);
}

template<typename Plan, typename U>
static std::vector<typename Plan::type>
convolve(const std::vector<U> &a, const std::vector<U> &b)
{
    typename Plan::size_type S = 1;
    while (S < max(a.size(), b.size()))
        S *= 2;
    Plan plan(S);
    return plan.convolve(a, b);
}

template<typename T>
static constexpr T find_gen(typename T::value_type len, T start = 2)
{
    return power(start, len / 2) == -1 ? start : find_gen<T>(len, start + 1);
}

/* These must satisfy:
 * - len is a power of 2
 * - mod is a prime
 * - len divides mod - 1
 */
template<typename T, typename C, T mod, T len>
class fft_traits_mod
{
public:
    typedef MR<T, C, mod> type;

    static type inverse(type value)
    {
        return value.inverse();
    }

    static type generator(T S)
    {
        static constexpr type gen = find_gen<type>(len);
        assert(len % S == 0);
        type g = gen;
        // compute 2^(len / S)
        T s = S;
        for (; s < len; s <<= 1)
            g *= g;
        return g;
    }
};

typedef FFT<fft_traits_mod<int, ll, 998244353, 8388608> > FFT2p23;
typedef FFT2p23::type mr;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    array<int, 26> p;
    for (int i = 0; i < 26; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    string s, t;
    cin >> s >> t;

    int S = SZ(s);
    int T = SZ(t);
    vector<mr> sp(26 * S), tp(26 * T);
    mr one = 1;
    for (int i = 0; i < T; i++)
        tp[26 * i + (t[i] - 'a')] = one;
    for (int i = 0; i < S; i++)
    {
        sp[26 * i + (s[i] - 'a')] = one;
        sp[26 * i + p[s[i] - 'a']] = one;
    }
    reverse(RA(sp));

    auto cp = convolve<FFT2p23>(sp, tp);
    string out(T - S + 1, '0');
    for (int i = 0; i < T - S + 1; i++)
    {
        if (cp[26 * S - 1 + 26 * i].get() == S)
            out[i] = '1';
    }
    cout << out << '\n';

    return 0;
}