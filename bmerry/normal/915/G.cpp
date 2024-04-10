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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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
};

typedef MR<int, ll, 1000000007> mr;

template<typename T>
static T power(T a, ll b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return power(a, b - 1) * a;
    else
    {
        T t = power(a, b / 2);
        return t * t;
    }
}

static vector<pii> factorise(int K, const vi &factor)
{
    vector<pii> f;
    while (K > 1)
    {
        int p = factor[K];
        int r = 1;
        K /= p;
        while (K % p == 0)
        {
            K /= p;
            r++;
        }
        f.emplace_back(p, r);
    }
    return f;
}

static void factors(const vector<pii> &primes, int p, int cur, vi &out)
{
    if (p == SZ(primes))
        out.push_back(cur);
    else
    {
        factors(primes, p + 1, cur, out);
        for (int i = 0; i < primes[p].second; i++)
        {
            cur *= primes[p].first;
            factors(primes, p + 1, cur, out);
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;

    vector<int> factor(K + 1);
    for (int i = 2; i <= K; i++)
        if (factor[i] == 0)
        {
            for (int j = i; j <= K; j += i)
                factor[j] = i;
        }

    vector<mr> dp(K + 1);
    mr sub = 0;
    mr total = 0;
    for (int i = 1; i <= K; i++)
    {
        mr s = power(mr(i), N);
        auto primes = factorise(i, factor);
        vi facts;
        factors(primes, 0, 1, facts);
        for (int f : facts)
        {
            if (f > 1)
            {
                int r = i / f;
                sub += dp[r] - dp[r - 1];
            }
        }
        s -= sub;
        dp[i] = s;
        total += (s.get() ^ i);
    }
    cout << total.get() << '\n';

    return 0;
}