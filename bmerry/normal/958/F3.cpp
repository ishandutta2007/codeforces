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

// Undefined sign for negative inputs
template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }
template<typename T> static constexpr T sqr(T a) { return a * a; }
// m must be positive
template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T>
static constexpr T inverse2(T a, T m)
{
    return a <= 1 ? a : mod((1 - inverse2(m % a, a) * m) / a, m);
}

// a must be relatively prime to m, m > 0
template<typename T>
static constexpr T inverse(T a, T m)
{
    return inverse2(mod(a, m), m);
}


template<typename T, typename P>
static constexpr T power(T a, P b)
{
    return b == 0 ? T(1) : (b % 2) ? power(a, b - 1) * a : sqr(power(a, b / 2));
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

template<typename Traits>
class FFT
{
public:
    typedef typename Traits::type type;

private:
    std::vector<type> roots, rroots;
    std::unique_ptr<FFT> next_plan;
    type inv_size;

    template<typename It>
    It transform(It first, It last, It tmp_first, It tmp_last, bool invert) const
    {
        const std::vector<type> &rr = invert ? rroots : roots;
        std::size_t S = size();
        if (S == 1)
            return first;
        else if (S == 2)
        {
            type a = *first;
            type b = *(first + 1);
            *first = a + b;
            *(first + 1) = a - b;
            return first;
        }
        std::size_t H = S / 2;
        It even = tmp_first;
        It odd = tmp_first + H;
        for (std::size_t i = 0; i < H; i++)
        {
            *(even + i) = *(first + 2 * i);
            *(odd + i) = *(first + (2 * i + 1));
        }
        even = next_plan->transform(even, odd, first, first + H, invert);
        odd = next_plan->transform(odd, tmp_last, first, first + H, invert);
        if (&*even == &*first)
        {
            swap(first, tmp_first);
            swap(last, tmp_last);
        }
        for (std::size_t i = 0; i < H; i++)
        {
            type q = even[i];
            type r = rr[i] * odd[i];
            *(first + i) = q + r;
            *(first + i + H) = q - r;
        }
        return first;
    }

    void transform(std::vector<type> &a, bool invert) const
    {
        assert(a.size() == size());
        std::vector<type> tmp(a.size());
        auto pos = transform(a.begin(), a.end(), tmp.begin(), tmp.end(), invert);
        if (&*pos == &*tmp.begin())
            a.swap(tmp);
    }

public:
    std::size_t size() const { return roots.size(); }

    FFT(std::size_t len)
    {
        if (len > 1)
        {
            assert(len % 2 == 0);
            next_plan.reset(new FFT(len / 2));
            roots.reserve(len);
            type g = Traits::generator(len);
            for (const type &r : next_plan->roots)
            {
                roots.push_back(r);
                roots.push_back(g * r);
            }
            rroots.reserve(len);
            rroots.push_back(roots[0]);
            rroots.insert(rroots.end(), roots.rbegin(), roots.rend() - 1);
        }
        else
        {
            roots.push_back(1);
            rroots.push_back(1);
        }
        inv_size = Traits::inverse(len);
    }

    template<typename U>
    std::vector<type> convolve(const std::vector<U> &a, const std::vector<U> &b) const
    {
        assert(!a.empty());
        assert(!b.empty());
        assert(a.size() + b.size() - 1 <= size());

        std::vector<type> pa(size()), pb(size());
        std::copy(a.begin(), a.end(), pa.begin());
        std::copy(b.begin(), b.end(), pb.begin());
        transform(pa, false);
        transform(pb, false);
        for (std::size_t i = 0; i < size(); i++)
            pa[i] *= pb[i];
        transform(pa, true);
        pa.resize(a.size() + b.size() - 1);
        for (type &v : pa)
            v *= inv_size;
        return pa;
    }
};

template<typename Plan, typename U>
static std::vector<typename Plan::type>
convolve(const std::vector<U> &a, const std::vector<U> &b)
{
    std::size_t S = 1;
    while (S < a.size() + b.size() - 1)
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

    static type generator(std::size_t S)
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

static constexpr ll P1 = 786433;
static constexpr ll P2 = 5767169;
static constexpr ll P12 = P1 * P2;
static constexpr ll inv1 = inverse(P1, P2) * P1;
static constexpr ll inv2 = inverse(P2, P1) * P2;
typedef FFT<fft_traits_mod<int, ll, P1, 262144> > FFT1;
typedef FFT<fft_traits_mod<int, ll, P2, 262144> > FFT2;

static vector<pair<FFT1, FFT2>> plans;

static vi convolve1(const vi &a, const vi &b)
{
    size_t S = a.size() + b.size() - 1;
    int p = 0;
    while (plans[p].first.size() < S)
        p++;
    auto c1 = plans[p].first.convolve(a, b);
    auto c2 = plans[p].second.convolve(a, b);
    vi c(SZ(c1));
    for (int i = 0; i < SZ(c); i++)
    {
        ll v = (c1[i].get() * inv2 + c2[i].get() * inv1) % P12;
        c[i] = v % 1009;
    }
    return c;
}

struct compare_len
{
    bool operator()(const vi &a, const vi &b) const
    {
        return a.size() > b.size();
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, K;
    cin >> N >> M >> K;
    priority_queue<vi, vector<vi>, compare_len> q;
    vi freq(M);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        freq[x - 1]++;
    }
    for (int x : freq)
    {
        if (x > 0)
            q.push(vi(x + 1, 1));
    }

    for (int i = 1; i <= 2 * N; i *= 2)
    {
        plans.push_back(make_pair(FFT1(i), FFT2(i)));
    }

    while (SZ(q) >= 2)
    {
        vi a = q.top(); q.pop();
        vi b = q.top(); q.pop();
        q.push(convolve1(a, b));
    }
    vi c = q.top();
    int ans = (K < SZ(c)) ? c[K] : 0;
    if (ans < 0)
        ans += 1009;
    cout << ans << '\n';

    return 0;
}