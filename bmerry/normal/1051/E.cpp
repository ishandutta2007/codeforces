//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

    static constexpr T multiply(T a, T b)
    {
        using UC = typename std::make_unsigned<C>::type;
        return UC(a) * UC(b) % Modulus;
    }

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
    constexpr MR operator *(MR b) const { return MR(multiply(value, b.value), tag_good()); }
    constexpr MR operator -() const { return MR(-value, tag_minus()); }

    MR &operator +=(MR b) { value = reduce(value + b.value, tag_plus()); return *this; }
    MR &operator -=(MR b) { value = reduce(value - b.value, tag_minus()); return *this; }
    MR &operator *=(MR b) { value = multiply(value, b.value); return *this; }

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


struct number
{
    string value;
    vector<int> fail;
    vector<array<int, 10>> fail_not;

    explicit number(string value_)
        : value(move(value_)), fail(value.size() + 1), fail_not(value.size() + 1)
    {
        int L = SZ(value);
        fail[0] = -1;
        for (int j = 0; j < 10; j++)
            fail_not[0][j] = -1;
        for (int i = 1; i <= L; i++)
        {
            char c = value[i - 1];
            int f = fail[i - 1];
            while (f >= 0 && c != value[f])
                f = fail[f];
            fail[i] = f + 1;
            for (int j = 0; j < 10; j++)
            {
                if (fail[i] == -1 || value[fail[i]] != '0' + j)
                    fail_not[i][j] = fail[i];
                else
                    fail_not[i][j] = fail_not[fail[i]][j];
            }
        }
    }
};

static vector<int> matches(const string &a, const number &n)
{
    int L = SZ(a);
    vi out(L + 1, L);
    int p = 0;
    for (int i = 0; i < L; i++)
    {
        int v = a[i] - '0';
        int q = p;
        if (q < SZ(n.value) && a[i] == n.value[q])
            q = n.fail_not[q][v];
        for (; q >= 0; q = n.fail_not[q][v])
        {
            assert(out[i - q] == L);
            out[i - q] = i;
        }
        while (p >= 0 && (p == SZ(n.value) || a[i] != n.value[p]))
            p = n.fail[p];
        p++;
    }
    return out;
}

static void solve()
{
    string a, L_, R_;
    cin >> a >> L_ >> R_;
    int N = SZ(a);
    number L(move(L_));
    number R(move(R_));
    auto matchL = matches(a, L);
    auto matchR = matches(a, R);

    vector<mr> sum(N + 2);
    sum[N] = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        mr v = 0;
        if (a[i] == '0')
        {
            if (L.value == "0"s)
                v = sum[i + 1] - sum[i + 2];
        }
        else if (i + SZ(L.value) <= N)
        {
            int lo = i + SZ(L.value);
            if (matchL[i] < lo && a[matchL[i]] < L.value[matchL[i] - i])
                lo++;
            int hi = i + SZ(R.value);
            if (hi > N)
                hi = N;
            else if (matchR[i] < hi && a[matchR[i]] > R.value[matchR[i] - i])
                hi--;
            if (lo <= hi)
                v = sum[lo] - sum[hi + 1];
        }
        sum[i] = sum[i + 1] + v;
    }
    cout << sum[0] - sum[1] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}