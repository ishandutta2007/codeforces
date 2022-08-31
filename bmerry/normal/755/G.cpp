// STILL TOO SLOW - needs a faster FFT :-(

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
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

template<typename Traits>
class FFT
{
public:
    typedef typename Traits::type type;

private:
    template<typename It>
    static It fft_r(It first, It last, It tmp_first, It tmp_last, type g)
    {
        std::size_t S = last - first;
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
            *(odd + i) = *(first + 2 * i + 1);
        }
        type g2 = g * g;
        even = fft_r(even, odd, first, first + H, g2);
        odd = fft_r(odd, tmp_last, first, first + H, g2);
        if (&*even == &*first)
        {
            swap(first, tmp_first);
            swap(last, tmp_last);
        }
        type p = 1;
        for (std::size_t i = 0; i < H; i++)
        {
            type q = even[i];
            type r = p * odd[i];
            *(first + i) = q + r;
            *(first + i + H) = q - r;
            p *= g;
        }
        return first;
    }

public:
    static std::vector<type> fft_core(std::vector<type> a, type g, bool scale)
    {
        std::size_t S = a.size();
        assert(S > 0 && (S & (S - 1)) == 0); // power of 2
        std::vector<type> tmp(S);
        auto pos = fft_r(a.begin(), a.end(), tmp.begin(), tmp.end(), g);
        if (&*pos == &*tmp.begin())
            a.swap(tmp);
        if (scale)
        {
            type iS = Traits::inverse(S);
            for (std::size_t i = 0; i < S; i++)
                a[i] *= iS;
        }
        return a;
    }

    static std::vector<type> fft(std::vector<type> a)
    {
        std::size_t S = a.size();
        return fft_core(std::move(a), Traits::generator(S, true), false);
    }

    static std::vector<type> rfft(std::vector<type> a)
    {
        std::size_t S = a.size();
        return fft_core(std::move(a), Traits::generator(S, false), true);
    }

    static std::vector<type> convolve(const std::vector<type> &a, const std::vector<type> &b)
    {
        assert(!a.empty());
        assert(!b.empty());
        std::size_t S = 1;
        while (S < a.size() + b.size() - 1)
            S *= 2;

        type g = Traits::generator(S, true);
        type ig = Traits::inverse(g);
        std::vector<type> pa(S), pb(S);
        std::copy(a.begin(), a.end(), pa.begin());
        std::copy(b.begin(), b.end(), pb.begin());
        std::vector<type> A = fft_core(std::move(pa), g, false);
        std::vector<type> B = fft_core(std::move(pb), g, false);
        for (std::size_t i = 0; i < S; i++)
            A[i] *= B[i];
        pa = fft_core(A, ig, true);
        pa.resize(a.size() + b.size() - 1);
        return pa;
    }
};

/* These must satisfy:
 * - len is a power of 2
 * - mod is a prime
 * - len divides mod - 1
 * - gen has order len modulo mod
 */
template<typename T, typename C, T mod, T len, T gen>
class fft_traits_mod
{
public:
    typedef MR<T, C, mod> type;

    static type inverse(type value)
    {
        return value.inverse();
    }

    static type generator(std::size_t S, bool invert)
    {
        assert(len % S == 0);
        type g = gen;
        // compute 2^(len / S)
        T s = S;
        for (; s < len; s <<= 1)
            g *= g;
        if (invert)
            g = g.inverse();
        return g;
    }
};

typedef FFT<fft_traits_mod<int, ll, 998244353, 65536, 256364169> > myFFT;

template<typename T>
static T power(const T &a, ll b)
{
    if (b == 0)
        return T(1);
    else if (b & 1)
        return power(a, b - 1) * a;
    else
    {
        T t = power(a, b / 2);
        return t * t;
    }
}

typedef myFFT::type mr;

static map<ll, vector<mr>> cache;

static const vector<mr> &solve(ll N, ll K)
{
    if (cache.count(N))
        return cache[N];
    else
    {
        auto &ans = cache[N];
        ll S = min(K, N) + 1;
        ans.resize(S);
        for (int d = 0; d < 2; d++)
        {
            if (N < 2 * d)
                continue;
            const vector<mr> &lft = solve(N / 2 - d, K);
            const vector<mr> &rgt = solve(N - N / 2 - d, K);
            vector<mr> comb = myFFT::convolve(lft, rgt);
            for (int i = 0; i < min(SZ(comb), S - d); i++)
                ans[i + d] += comb[i];
        }
        return ans;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, K;
    cin >> N >> K;
    cache[0].resize(1);
    cache[0][0] = 1;
    cache[1].resize(2);
    cache[1][0] = 1;
    cache[1][1] = 1;
    vector<mr> ans = solve(N, K);
    ans.resize(K + 1);
    for (int i = 1; i <= K; i++)
    {
        cout << ans[i];
        if (i < K)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}