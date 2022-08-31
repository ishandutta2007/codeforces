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

/*** TEMPLATE CODE ENDS HERE */

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

typedef MR<int, ll, 1000000007> mr;
typedef MR<int, ll, 1000000006> mrp;

template<typename T>
static T power(const T &a, ll b)
{
    if (b == 0)
        return T(1);
    else if (b & 1)
        return power(a, b - 1) * a;
    else
    {
        T tmp = power(a, b / 2);
        return tmp * tmp;
    }
}

template<typename T, typename U>
static T sumag(T a, T b, T s, U apow, U bpow)
{
    if (s == 1)
        return (a + b - 1) * (b - a) / 2;
    else
    {
        auto inv = (s - 1).inverse();
        T part = (b - 1) * power(s, bpow.get()) - a * power(s, apow.get())
            + inv * (power(s, apow.get() + 1) - power(s, bpow.get()));
        return part * inv;
    }
}

struct value
{
    mr base;
    mr step;
};

static string line;
static int pos;

static value concat(const value &a, const value &b)
{
    return value{a.base * b.step + b.base, a.step * b.step};
}

static string parse_number()
{
    int stop = pos;
    while (line[stop] >= '0' && line[stop] <= '9')
        stop++;
    string out = line.substr(pos, stop - pos);
    pos = stop;
    return out;
}

template<typename T>
static T simple(const string &number)
{
    T out = 0;
    for (char c : number)
        out = out * 10 + (c - '0');
    return out;
}

static value value_of(const string &number)
{
    value out{0, 1};
    for (char c : number)
    {
        int d = c - '0';
        out.base *= 10;
        out.base += d;
        out.step *= 10;
    }
    return out;
}

static value repeat(const string &r, const value &a)
{
    mrp rv = simple<mrp>(r);
    mr rm = simple<mr>(r);
    value out;
    out.step = power(a.step, rv.get());
    if (a.step.get() == 1)
        out.base = rm * a.base;
    else
        out.base = (out.step - 1) / (a.step - 1) * a.base;
    return out;
}

static value make_range1(ll d, const mr &a, const mr &b, const mrp &ap, const mrp &bp)
{
    mr scale = power(mr(10), ((bp - 1) * d).get());
    mr s = power(mr(10), d).inverse();
    value out;
    out.base = sumag(a, b, s, ap, bp) * scale;
    mrp digits = (bp - ap) * d;
    out.step = power(mr(10), digits.get());
    return out;
}

static value make_range(const string &a, const string &b)
{
    if (a.size() == b.size())
    {
        return make_range1(a.size(),
            simple<mr>(a), simple<mr>(b) + 1,
            simple<mrp>(a), simple<mrp>(b) + 1);
    }
    else
    {
        value out = make_range1(a.size(),
            simple<mr>(a), power(mr(10), a.size()),
            simple<mrp>(a), power(mrp(10), a.size()));
        for (int d = SZ(a) + 1; d < SZ(b); d++)
        {
            value cur = make_range1(d,
                power(mr(10), d - 1), power(mr(10), d),
                power(mrp(10), d - 1), power(mrp(10), d));
            out = concat(out, cur);
        }
        value last = make_range1(b.size(),
            power(mr(10), SZ(b) - 1), simple<mr>(b) + 1,
            power(mrp(10), SZ(b) - 1), simple<mrp>(b) + 1);
        out = concat(out, last);
        return out;
    }
}

static value parse_expression();

static value parse_term()
{
    string left = parse_number();
    if (line[pos] == '-')
    {
        pos++;
        string right = parse_number();
        return make_range(left, right);
    }
    else if (line[pos] == '(')
    {
        pos++;
        value right = parse_expression();
        assert(line[pos] == ')');
        pos++;
        return repeat(left, right);
    }
    else
        return value_of(left);
}

static value parse_expression()
{
    value left = parse_term();
    if (line[pos] == '+')
    {
        pos++;
        value right = parse_expression();
        return concat(left, right);
    }
    else
        return left;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> line;
    line += '$';
    pos = 0;
    value ans = parse_expression();
    cout << ans.base << '\n';
    return 0;
}