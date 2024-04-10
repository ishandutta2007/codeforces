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

/*** TEMPLATE CODE ENDS HERE */

#define MOD 998244353

typedef MR<int, ll, MOD> mr;

static vector<array<mr, 11>> half(const array<int, 11> &dist)
{
    vector<array<mr, 11>> dp(1);
    dp[0][0] = 1;
    for (int m = 0; m < 11; m++)
    {
        for (int i = 0; i < dist[m]; i++)
        {
            vector<array<mr, 11>> dp2(SZ(dp) + 1);
            for (int j = 0; j < SZ(dp); j++)
                for (int k = 0; k < 11; k++)
                {
                    dp2[j][(k + m) % 11] += dp[j][k];
                    dp2[j + 1][(k + 11 - m) % 11] += dp[j][k];
                }
            dp = move(dp2);
        }
    }
    return dp;
}

void solve()
{
    int N;
    cin >> N;
    array<array<int, 11>, 2> dist{};
    int tdist[2]{};
    for (int i = 0; i < N; i++)
    {
        string v;
        cin >> v;
        int par = SZ(v) & 1;
        int rem = stoi(v) % 11;
        dist[par][rem]++;
        tdist[par]++;
    }

    vector<mr> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i;

    auto even = half(dist[0]);
    auto odd = half(dist[1]);
    auto base = odd[tdist[1] / 2];
    mr odd_scale = fact[tdist[1] / 2] * fact[tdist[1] - tdist[1] / 2];
    for (int i = 0; i < 11; i++)
        base[i] *= odd_scale;

    int slots[2] = {tdist[1] / 2 + 1, (tdist[1] + 1) / 2};
    array<mr, 11> merged{};
    for (int i = 0; i <= tdist[0]; i++)
    {
        int e = tdist[0] - i;
        auto scale = fact[slots[0] + e - 1] / fact[slots[0] - 1];
        if (slots[1] > 0)
            scale *= fact[slots[1] + i - 1] / fact[slots[1] - 1];
        else if (i > 0)
            break;
        for (int j = 0; j < 11; j++)
            merged[j] += even[i][j] * scale;
    }

    mr ans = 0;
    for (int i = 0; i < 11; i++)
        ans += base[i] * merged[(11 - i) % 11];
    cout << ans << '\n';
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