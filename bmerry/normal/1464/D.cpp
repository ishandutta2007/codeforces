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

typedef MR<int, ll, 1000000007> mr;

static void solve()
{
    int N;
    cin >> N;
    vi p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    vi freq(5);
    int steps = 0;
    for (int i = 0; i < N; i++)
        if (p[i] != -1)
        {
            int x = i;
            int L = 0;
            do
            {
                int y = p[x];
                p[x] = -1;
                x = y;
                L++;
            } while (x != i);

            if (L >= 4)
            {
                int q = L / 3;
                int r = L % 3;
                if (r == 1 && q >= 1)
                {
                    r = 4;
                    q--;
                }
                steps += r ? q : q - 1;
                freq[3] += q;
                freq[r]++;
            }
            else
                freq[L]++;
        }

    int e3 = N / 3;
    if (N % 3 == 1)
        e3--;
    int r = N - 3 * e3;

    while (freq[3] < e3)
    {
        if (freq[1] && freq[2])
        {
            freq[3]++;
            freq[1]--;
            freq[2]--;
            steps++;
        }
        else if (freq[4] && freq[2] * 2 + freq[4] * 4 > r)
        {
            freq[4]--;
            freq[3]++;
            freq[1]++;
            steps++;
        }
        else if (freq[2] >= 3)
        {
            freq[2] -= 3;
            freq[3] += 2;
            steps += 3;
        }
        else if (freq[1] >= 3)
        {
            freq[3]++;
            freq[1] -= 3;
            steps += 2;
        }
        else
            abort();
    }
    while (freq[3] > e3)
    {
        if (r == 4 && freq[4] == 0 && freq[1] > 0)
        {
            freq[4]++;
            freq[3]--;
            freq[1]--;
            steps++;
        }
        else
        {
            freq[3]--;
            freq[1]++;
            freq[2]++;
        }
    }
    while (freq[1])
    {
        assert(freq[1] > 1);
        freq[1] -= 2;
        freq[2]++;
        steps++;
    }

    cout << power(mr(2), freq[2] + 2 * freq[4]) * power(mr(3), freq[3]) << ' ' << steps << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}