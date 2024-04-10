#pragma GCC optimize("O3")
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

template<typename T>
class VMatrix
{
private:
    std::vector<std::vector<T> > values;

public:
    typedef T value_type;

    int rows() const { return values.size(); }
    int cols() const { return values[0].size(); }

    VMatrix(int R, int C, T diag = T(1)) : values(R)
    {
        for (int i = 0; i < R; i++)
        {
            values[i].resize(C);
            for (int j = 0; j < C; j++)
                values[i][j] = (i == j) ? diag : T(0);
        }
    }

    explicit VMatrix(int R = 1) : VMatrix(R, R) {}

    VMatrix operator *(const VMatrix &b) const
    {
        assert(cols() == b.rows());
        VMatrix ans(rows(), b.cols());
        for (int i = 0; i < rows(); i++)
            for (int j = 0; j < b.cols(); j++)
            {
                T sum = T();
                for (int k = 0; k < cols(); k++)
                    sum += values[i][k] * b.values[k][j];
                ans.values[i][j] = sum;
            }
        return ans;
    }

    VMatrix &operator *=(const VMatrix &b)
    {
        *this = *this * b;
        return *this;
    }

#define ELEMWISE(op, op_eq)                     \
    VMatrix operator op(const VMatrix &b) const \
    {                                           \
        assert(rows() == b.rows());             \
        assert(cols() == b.cols());             \
        VMatrix ans(rows(), cols());            \
        for (int i = 0; i < rows(); i++)        \
            for (int j = 0; j < cols(); j++)    \
                ans.values[i][j] = values[i][j] op b.values[i][j]; \
        return ans;                             \
    }                                           \
    VMatrix &operator op_eq(const VMatrix &b)   \
    {                                           \
        assert(rows() == b.rows());             \
        assert(cols() == b.cols());             \
        for (int i = 0; i < rows(); i++)        \
            for (int j = 0; j < cols(); j++)    \
                values[i][j] op_eq b.values[i][j]; \
        return *this;                           \
    }

    ELEMWISE(+, +=)
    ELEMWISE(-, -=)
#undef ELEMWISE

    VMatrix operator -() const
    {
        VMatrix ans(rows(), cols());
        for (int i = 0; i < rows(); i++)
            for (int j = 0; j < cols(); j++)
                ans.values[i][j] = -values[i][j];
        return ans;
    }

    template<typename P>
    VMatrix power(P exponent) const
    {
        assert(rows() == cols());
        VMatrix ans(rows(), cols());
        VMatrix p2 = *this;
        while (exponent > 0)
        {
            if (exponent & 1)
                ans *= p2;
            p2 *= p2;
            exponent >>= 1;
        }
        return ans;
    }

    bool operator==(const VMatrix &b) const
    {
        if (rows() != b.rows() || cols() != b.cols())
            return false;
        for (int i = 0; i < rows(); i++)
            for (int j = 0; j < cols(); j++)
                if (values[i][j] != b.values[i][j])
                    return false;
        return true;
    }

    bool operator!=(const VMatrix &b) const
    {
        return !(*this == b);
    }

    const std::vector<T> &operator[](int idx) const
    {
        assert(idx >= 0 && idx < rows());
        return values[idx];
    }

    std::vector<T> &operator[](int idx)
    {
        assert(idx >= 0 && idx < rows());
        return values[idx];
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vi> edges(N), redges(N);
    vi deg(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        redges[v].push_back(u);
        deg[u]++;
    }
    stack<int> st;
    vi grundy(N);
    vi seen(N + 1, -1);
    for (int i = 0; i < N; i++)
        if (deg[i] == 0)
            st.push(i);
    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        for (int v : edges[cur])
            seen[grundy[v]] = cur;
        int g = 0;
        while (seen[g] == cur)
            g++;
        grundy[cur] = g;
        for (int v : redges[cur])
            if (--deg[v] == 0)
                st.push(v);
    }

    int d = *max_element(RA(grundy)) + 1;
    while (d & (d - 1))
        d++;
    VMatrix<mr> mat(d, d, N + 1);
    for (int i = 0; i < d; i++)
        for (int j = 0; j < N; j++)
            mat[i][i ^ grundy[j]] -= 1;

    vector<mr> b(d, 1);
    b[0] = 0;
    for (int r = 0; r < d; r++)
    {
        int c = r;
        while (mat[r][c].get() == 0)
            c++;
        swap(mat[r], mat[c]);
        mr inv = mat[r][r].inverse();
        for (int i = r + 1; i < d; i++)
        {
            mr scale = mat[i][r] * inv;
            for (int j = r; j < d; j++)
                mat[i][j] -= scale * mat[r][j];
            b[i] -= scale * b[r];
        }
    }
    for (int r = d - 1; r >= 0; r--)
    {
        mr v = b[r];
        for (int i = r + 1; i < d; i++)
            v -= mat[r][i] * b[i];
        b[r] = v / mat[r][r];
    }
    cout << b[0] << '\n';

    return 0;
}