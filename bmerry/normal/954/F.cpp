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


template<typename T, int R, int C = R>
class Matrix
{
private:
    T values[R][C];
    template<typename T2, int R2, int C2> friend class Matrix;

public:
    struct uninitialized {};

    typedef T value_type;
    static constexpr int rows() { return R; }
    static constexpr int cols() { return C; }

    Matrix(uninitialized) {}

    explicit Matrix(T diag = T(1))
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] = (i == j) ? diag : T(0);
    }

    template<int D>
    Matrix<T, R, D> operator *(const Matrix<T, C, D> &b) const
    {
        Matrix<T, R, D> ans = typename Matrix<T, R, D>::uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < D; j++)
            {
                T sum = T();
                for (int k = 0; k < C; k++)
                    sum += values[i][k] * b.values[k][j];
                ans.values[i][j] = sum;
            }
        return ans;
    }

    Matrix &operator *=(const Matrix<T, C> &b)
    {
        *this = *this * b;
        return *this;
    }

    Matrix operator +(const Matrix &b) const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = values[i][j] + b.values[i][j];
        return ans;
    }

    Matrix &operator +=(const Matrix &b)
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] += b.values[i][j];
        return *this;
    }

    Matrix operator -(const Matrix &b) const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = values[i][j] - b.values[i][j];
        return ans;
    }

    Matrix &operator -=(const Matrix &b)
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] -= b.values[i][j];
        return *this;
    }

    Matrix operator -() const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = -values[i][j];
        return ans;
    }

    template<typename P, typename SFINAE = typename std::enable_if<R == C && std::is_same<P, P>::value>::type>
    Matrix power(P exponent) const
    {
        Matrix ans;
        Matrix p2 = *this;
        while (exponent > 0)
        {
            if (exponent & 1)
                ans *= p2;
            p2 *= p2;
            exponent >>= 1;
        }
        return ans;
    }

    bool operator==(const Matrix &b) const
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (values[i][j] != b.values[i][j])
                    return false;
        return true;
    }

    bool operator!=(const Matrix &b) const
    {
        return !(*this == b);
    }

    const T *operator[](int idx) const
    {
        assert(idx >= 0 && idx < R);
        return values[idx];
    }

    T *operator[](int idx)
    {
        assert(idx >= 0 && idx < R);
        return values[idx];
    }
};

template<typename T, int R, int C>
static inline std::ostream &operator<<(std::ostream &o, const Matrix<T, R, C> &m)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            o << m[i][j] << '\t';
        o << '\n';
    }
    return o;
}

typedef Matrix<mr, 3> mat;

struct event
{
    int r;
    ll c;
    int d;

    bool operator<(const event &other) const
    {
        return c < other.c;
    }
};

static void solve()
{
    int N;
    ll M;
    cin >> N >> M;

    vector<event> events;
    for (int i = 0; i < N; i++)
    {
        int a;
        ll l, r;
        cin >> a >> l >> r;
        a--;
        l--;
        events.push_back(event{a, l, 1});
        events.push_back(event{a, r, -1});
    }
    events.push_back(event{0, M, 0});
    sort(RA(events));

    mat base;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            base[i][j] = abs(i - j) <= 1;

    int levels[3] = {0, 0, 0};
    mat total;
    ll x = 1;
    for (const event &e : events)
    {
        mat cur;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cur[i][j] = (levels[i] ? 0 : base[i][j]);
        total = cur.power(e.c - x) * total;
        levels[e.r] += e.d;
        x = e.c;
    }
    cout << total[1][1] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}