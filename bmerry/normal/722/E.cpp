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

template<typename T, T Modulus>
class MR
{
private:
    struct tag_plus {}; // indicates value is in range [0, 2 * Modulus)
    struct tag_minus {}; // indicates value is in range (-Modulus, Modulus)

    T value;

    enum
    {
        ASSERT_FALSE = 0,
        ASSERT_TEST = (T(1) << (std::numeric_limits<T>::digits - 1)) / Modulus / Modulus > 0 ? 1 : 0
    };

    void reduce()
    {
        value %= Modulus;
        if (value < 0)
            value += Modulus;
    }

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

public:
    typedef T value_type;
    static const T modulus = Modulus;

    MR() : value(0) {}
    MR(T value) : value(value) { reduce(); }
    template<typename tag_t>
    MR(T value, tag_t tag) : value(value) { reduce(tag); }

    MR &operator=(T value) { this->value = value; reduce(); return *this; }

    MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
    MR operator -(MR b) const { return MR(value - b.value, tag_minus()); }
    MR operator *(MR b) const { return MR(value * b.value); }
    MR operator -() const { return MR(-value); }

    MR &operator +=(MR b) { value += b.value; reduce(tag_plus()); return *this; }
    MR &operator -=(MR b) { value -= b.value; reduce(tag_minus()); return *this; }
    MR &operator *=(MR b) { value *= b.value; reduce(); return *this; }

    bool operator==(MR b) const { return value == b.value; }
    bool operator!=(MR b) const { return value != b.value; }

    T get() const { return value; }

    // These are only valid if the Modulus is prime, or at least if
    // the dividend is relatively prime to the modulus
    MR inverse() const
    {
        assert(value);
        return MR(::inverse(value, Modulus));
    }
    MR operator /(MR b) const { return *this * b.inverse(); }
    MR &operator /=(MR b) { return *this *= b.inverse(); }
};

template<typename T, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, Modulus> mr)
{
    return o << mr.get();
}

/*** TEMPLATE CODE ENDS HERE */

static const int MOD = 1000000007;
typedef MR<ll, MOD> mr;

static vector<mr> fac, rfac;

static mr choose(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return fac[n] * rfac[r] * rfac[n - r];
}

static mr paths(ll dr, ll dc)
{
    return choose(dr + dc, dr);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, M, S;
    int K;
    cin >> N >> M >> K >> S;
    vector<pii> a(K);
    for (int i = 0; i < K; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }
    if (!count(RA(a), pii(0, 0)))
    {
        a.emplace_back(0, 0);
        S *= 2;
    }
    if (!count(RA(a), pii(N - 1, M - 1)))
    {
        a.emplace_back(N - 1, M - 1);
        S *= 2;
    }
    sort(RA(a));
    K = SZ(a);

    fac.push_back(1);
    rfac.push_back(1);
    for (ll i = 1; i <= N + M; i++)
    {
        fac.push_back(fac.back() * i);
        rfac.push_back(fac.back().inverse());
    }

    const int T = 25;
    vector<array<mr, T>> dp(K);
    dp[0][1] = 1;
    for (int i = 1; i < K; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].second > a[i].second)
                continue;
            mr p = paths(a[i].first - a[j].first, a[i].second - a[j].second);
            for (int t = 1; t < T; t++)
                dp[i][t] += (dp[j][t - 1] - dp[j][t]) * p;
        }
        dp[i][1] += paths(a[i].first, a[i].second);
    }
    mr rem = paths(N - 1, M - 1);
    mr ans = 0;
    for (int t = 0; t < T; t++)
    {
        ans += mr(S) * dp[K - 1][t];
        rem -= dp[K - 1][t];
        S = (S + 1) / 2;
    }
    ans += rem;
    ans /= paths(N - 1, M - 1);
    cout << ans << '\n';

    return 0;
}