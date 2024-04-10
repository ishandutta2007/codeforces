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

/*** TEMPLATE CODE ENDS HERE */

// Provides missing operators to a class with +, *, unary - and inverse()
template<typename Derived>
class field_mixin
{
public:
    Derived operator-(const Derived &other) const { return static_cast<const Derived &>(*this) + -other; }
    Derived operator/(const Derived &other) const { return static_cast<const Derived &>(*this) * other.inverse(); }
    Derived &operator+=(const Derived &other) { Derived &self = static_cast<Derived &>(*this); return self = self + other; }
    Derived &operator-=(const Derived &other) { Derived &self = static_cast<Derived &>(*this); return self = self - other; }
    Derived &operator*=(const Derived &other) { Derived &self = static_cast<Derived &>(*this); return self = self * other; }
    Derived &operator/=(const Derived &other) { Derived &self = static_cast<Derived &>(*this); return self = self / other; }
};

// Provides missing operators to a class with == and <
template<typename Derived>
class ordered_mixin
{
public:
    bool operator!=(const Derived &other) const { const Derived &self = static_cast<const Derived &>(*this); return !(self == other); }
    bool operator<=(const Derived &other) const { const Derived &self = static_cast<const Derived &>(*this); return !(other < self); }
    bool operator>=(const Derived &other) const { const Derived &self = static_cast<const Derived &>(*this); return !(self < other); }
    bool operator>(const Derived &other) const { const Derived &self = static_cast<const Derived &>(*this); return other < self; }
};

template<typename T>
class rational : public field_mixin<rational<T>>, public ordered_mixin<rational<T>>
{
    T num;
    T den;

public:
    using field_mixin<rational<T>>::operator-;

    rational(T num = 0, T den = 1)
    {
        assert(den != 0);
        if (den < T(0))
        {
            num = -num;
            den = -den;
        }
        T g = gcd(abs(num), den);
        this->num = num / g;
        this->den = den / g;
    }

    rational operator-() const { return rational(-num, den); }
    rational inverse() const { return rational(den, num); }
    rational operator+(const rational &other) const { return rational(num * other.den + den * other.num, den * other.den); }
    rational operator*(const rational &other) const { return rational(num * other.num, den * other.den); }

    bool operator==(const rational &other) const { return num == other.num && den == other.den; }
    bool operator<(const rational &other) const { return num * other.den < other.num * den; }

    T numerator() const { return num; }
    T denominator() const { return den; }
    explicit operator double() const { return double(num) / double(den); }
};

typedef rational<ll> frac;

struct solution
{
    frac value;
    int a, b, c;
    bool operator<(const solution &other) const
    {
        return value < other.value;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(RA(a));
    vector<ll> s(N + 1);
    partial_sum(RA(a), s.begin() + 1);
    solution ans{frac(-1, 1), 0, 0, 0};
    for (int i = 0; i < N; i++)
    {
        int lo = 0;
        int hi = min(i, N - 1 - i);
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            ll total = s[i + 1] - s[i - mid] + s[N] - s[N - mid];
            ll last = (a[i - mid] + a[N - mid]);
            if (last * (2 * mid + 1) > total * 2)
                lo = mid;
            else
                hi = mid;
        }
        ll items[2] = {lo, hi};
        for (int mid : items)
        {
            ll total = s[i + 1] - s[i - mid] + s[N] - s[N - mid];
            solution score{frac(total, 2 * mid + 1) - frac(a[i], 1), i - mid, i + 1, N - mid};
            ans = max(ans, score);
        }
    }

    for (int i = 1; i < N; i++)
    {
        int lo = 0;
        int hi = min(i - 1, N - 1 - i);
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            ll total = s[i + 1] - s[i - 1 - mid] + s[N] - s[N - mid];
            ll last = (a[i - 1 - mid] + a[N - mid]);
            if (last * (2 * mid + 2) > total * 2)
                lo = mid;
            else
                hi = mid;
        }
        ll items[2] = {lo, hi};
        for (int mid : items)
        {
            ll total = s[i + 1] - s[i - 1 - mid] + s[N] - s[N - mid];
            solution score{frac(total, 2 * mid + 2) - frac(a[i - 1] + a[i], 2), i - 1 - mid, i + 1, N - mid};
            ans = max(ans, score);
        }
    }
    cout << ans.b - ans.a + N - ans.c << '\n';
    for (int i = ans.a; i < ans.b; i++)
        cout << a[i] << ' ';
    for (int i = ans.c; i < N; i++)
    {
        cout << a[i];
        if (i != N - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}