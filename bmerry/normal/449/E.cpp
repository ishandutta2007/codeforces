#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    if (a == 1)
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

#define MOD 1000000007
#define MAXN 1000005

typedef MR<ll, MOD> mr;

static vector<int> factor(MAXN + 1);
static vector<int> phi(MAXN + 1);

static void make_factor()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (factor[i] == 0)
        {
            for (int j = i; j <= MAXN; j += i)
                factor[j] = i;
        }
    }

    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        int f = factor[i];
        int y = i / f;
        int p = f - 1;
        while (y % f == 0)
        {
            y /= f;
            p *= f;
        }
        phi[i] = phi[y] * p;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    make_factor();

    vector<mr> F(MAXN + 1);
    for (ll s = 1; s <= MAXN; s++)
        F[s] = s * (s + 1) * (2 * s + 1) / 3 - 3 * s * s;

    for (int g = 1; g <= MAXN; g++)
    {
        int m, s;
        for (m = 1, s = g; s <= MAXN; m++, s += g)
            F[s] += 2 * g * phi[m];
    }

    vector<mr> Fs(MAXN + 1);
    vector<mr> Fs2(MAXN + 1);
    for (int s = 1; s <= MAXN; s++)
    {
        Fs[s] = Fs[s - 1] + F[s] * s;
        Fs2[s] = Fs2[s - 1] + F[s] * s * s;
        F[s] += F[s - 1];
    }

    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N, M;
        cin >> N >> M;
        N++;
        M++;
        int S = min(N, M);
        mr ans = F[S] * M * N - Fs[S] * (M + N) + Fs2[S];
        cout << ans << '\n';
    }

    return 0;
}