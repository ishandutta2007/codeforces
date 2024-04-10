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

static int N;
static map<pair<int, vi>, mr> cache;
static mr factN;
static vector<vector<mr>> choose;
static vector<mr> inverses;

static mr solve(int prev_layer, const vi &lens);

static mr pick(int prev_layer, const vi &lens, int pos, int last, ll mask)
{
    if (pos == SZ(lens))
    {
        int layer = 0;
        vi lens2;
        last = -1;
        int run = 0;
        int runp = 0;
        mr mult = 1;
        for (int i = 0; i < SZ(lens); i++)
        {
            if (lens[i] != last)
            {
                mult *= choose[run][runp];
                run = 0;
                runp = 0;
                last = lens[i];
            }
            if ((mask >> i) & 1)
            {
                layer += lens[i];
                runp++;
            }
            else
                lens2.push_back(lens[i]);
            run++;
        }
        mult *= choose[run][runp];
        if (!mask)
            return 0;
        else
            return mult * solve(layer, lens2);
    }
    else
    {
        mr ans = 0;
        if (last != lens[pos])
        {
            // Don't pick it
            ans += pick(prev_layer, lens, pos + 1, last, mask);
        }
        // Pick it
        int T = accumulate(RA(lens), 0);  // TODO: cache
        int L = lens[pos];
        mr perms_all = power(factN * inverses[T], L);
        mr perms_no_dep = power(factN * inverses[T + prev_layer], L);
        mr perms_good = prev_layer ? perms_all - perms_no_dep : perms_all;
        ans += perms_good * pick(prev_layer, lens, pos + 1, L, mask | (1LL << pos));
        return ans;
    }
}

static mr solve(int done, const vi &lens)
{
    if (lens.empty())
        return 1;
    pair key(done, lens);
    if (cache.count(key))
        return cache[key];
    return cache[key] = pick(done, lens, 0, -1, 0);
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N;
    vi perm(N);
    for (int i = 0; i < N; i++)
    {
        cin >> perm[i];
        perm[i]--;
    }

    factN = 1;
    for (int i = 2; i <= N; i++)
        factN *= i;
    inverses.resize(N + 1);
    choose.resize(N + 1);
    for (int i = 1; i <= N; i++)
        inverses[i] = mr(1) / i;
    for (int i = 0; i <= N; i++)
    {
        choose[i].resize(i + 1);
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }

    vi lens;
    for (int i = 0; i < N; i++)
        if (perm[i] != -1)
        {
            int L = 0;
            int x = i;
            while (perm[x] != -1)
            {
                L++;
                int y = perm[x];
                perm[x] = -1;
                x = y;
            }
            lens.push_back(L);
        }
    sort(RA(lens));
    mr ans = solve(0, lens);
    cout << ans << '\n';

    return 0;
}