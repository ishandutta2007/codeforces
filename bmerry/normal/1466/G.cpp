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

typedef MR<int, ll, 1000000007> mr;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    string s0, t;
    cin >> N >> Q >> s0 >> t;
    vs s{s0};
    for (int i = 0; i < N; i++)
    {
        if (s.back().size() > 2000000)
            break;
        s.push_back(s.back() + t[i] + s.back());
    }

    vector<array<mr, 26>> dp(N + 1);
    for (int i = 0; i < 26; i++)
        dp[N][i] = 0;
    mr p2 = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        dp[i][t[i] - 'a'] += p2;
        p2 += p2;
    }

    mr half = mr(1) / mr(2);
    for (int i = 0; i < Q; i++)
    {
        mr ans = 0;
        int k;
        string w;
        cin >> k >> w;

        int L = SZ(w);
        int u = 0;
        while (u < k && SZ(s[u]) <= 2 * L)
            u++;

        int internal = 0;
        vector<bool> prefix(L + 1);

        vi fail(L + 1);
        fail[0] = -1;
        for (int i = 0; i < L; i++)
        {
            int f = fail[i];
            while (f >= 0 && w[i] != w[f])
                f = fail[f];
            fail[i + 1] = f + 1;
        }
        int p = 0;
        for (int i = 0; i < SZ(s[u]); i++)
        {
            while (p >= 0 && (p == L || w[p] != s[u][i]))
                p = fail[p];
            p++;
            if (p == L)
                internal++;
        }
        while (p >= 0)
        {
            prefix[p] = true;
            p = fail[p];
        }

        ans += power(mr(2), k - u) * internal;

        // Walk in reverse
        fail[0] = -1;
        for (int i = 0; i < L; i++)
        {
            int f = fail[i];
            while (f >= 0 && w[L - 1 - i] != w[L - 1 - f])
                f = fail[f];
            fail[i + 1] = f + 1;
        }
        p = 0;
        for (int i = 0; i < SZ(s[u]); i++)
        {
            char c = s[u][SZ(s[u]) - 1 - i];
            while (p >= 0 && (p == L || w[L - 1 - p] != c))
                p = fail[p];
            p++;
        }
        while (p >= 0)
        {
            if (p < L && prefix[L - 1 - p])
            {
                int c = w[L - 1 - p] - 'a';
                ans += (dp[u][c] - dp[k][c]) * power(half, N - k);
            }
            p = fail[p];
        }

        cout << ans << '\n';
    }

    return 0;
}