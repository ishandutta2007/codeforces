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


struct cond
{
    int l, r, x;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K, M;
    cin >> N >> K >> M;
    vector<cond> conds(M);
    for (int i = 0; i < M; i++)
    {
        cin >> conds[i].l >> conds[i].r >> conds[i].x;
        conds[i].l--;
    }

    mr ans = 1;
    for (int bit = 0; bit < K; bit++)
    {
        int mask = 1 << bit;
        vi level(N + 1);
        vi cut(N + 1, -1);
        for (const auto &c : conds)
        {
            if (c.x & mask)
            {
                level[c.l]++;
                level[c.r]--;
            }
            else
                cut[c.r] = max(cut[c.r], c.l);
        }
        for (int i = 0; i < N; i++)
            level[i + 1] += level[i];

        int tail = 0;
        vector<mr> dp(N + 1);
        dp[0] = 1;
        mr sum = 1;
        for (int i = 1; i <= N; i++)
        {
            int lft = cut[i];
            if (level[i - 1] == 0)
                dp[i] = sum;
            while (tail <= lft)
            {
                sum -= dp[tail];
                dp[tail] = 0;
                tail++;
            }
            sum += dp[i];
        }
        ans *= sum;
    }
    cout << ans << '\n';

    return 0;
}