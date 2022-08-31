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
class rational : public ordered_mixin<rational<T>>
{
    T num;
    T den;

public:
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

    rational inverse() const { return rational(den, num); }
    rational operator+(const rational &other) const { return rational(num * other.den + den * other.num, den * other.den); }
    rational operator*(const rational &other) const { return rational(num * other.num, den * other.den); }

    bool operator==(const rational &other) const { return num == other.num && den == other.den; }
    bool operator<(const rational &other) const { return num * other.den < other.num * den; }

    T numerator() const { return num; }
    T denominator() const { return den; }
    explicit operator long double() const { return (long double)(num) / (long double)(den); }
};

typedef rational<ll> frac;

static ll N, T, Q;
static vector<ll> P, L;
static set<pair<frac, int>, greater<pair<frac, int>>> up_slope;
static set<pair<frac, int> > down_slope;
static vector<decltype(up_slope)::iterator> up_it;
static vector<decltype(down_slope)::iterator> down_it;
static long double expect = 0.0;
static vector<ll> cur;

static void rm_up(int idx)
{
    auto &pos = up_it[idx];
    if (pos == up_slope.end())
        return;
    up_slope.erase(pos);
    pos = up_slope.end();
}

static void rm_down(int idx)
{
    auto &pos = down_it[idx];
    if (pos == down_slope.end())
        return;
    down_slope.erase(pos);
    pos = down_slope.end();
}

static void add_up(int idx)
{
    assert(up_it[idx] == up_slope.end());
    if (cur[idx] < L[idx])
    {
        ll num = L[idx] * P[idx];
        ll den = (L[idx] + cur[idx]) * (L[idx] + cur[idx] + 1);
        auto pos = up_slope.emplace(frac(num, den), idx).first;
        up_it[idx] = pos;
    }
}

static void add_down(int idx)
{
    assert(down_it[idx] == down_slope.end());
    if (cur[idx] > 0)
    {
        ll num = L[idx] * P[idx];
        ll den = (L[idx] + cur[idx] - 1) * (L[idx] + cur[idx]);
        auto pos = down_slope.emplace(frac(num, den), idx).first;
        down_it[idx] = pos;
    }
}

static void go_up()
{
    auto best = *up_slope.begin();
    int idx = best.second;
    expect += (long double) best.first;
    rm_up(idx);
    rm_down(idx);
    cur[idx]++;
    T--;
    add_up(idx);
    add_down(idx);
}

static void go_down()
{
    auto best = *down_slope.begin();
    int idx = best.second;
    expect -= (long double) best.first;
    rm_up(idx);
    rm_down(idx);
    cur[idx]--;
    T++;
    add_up(idx);
    add_down(idx);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N >> T >> Q;
    P.resize(N);
    L.resize(N);
    cur.resize(N);
    up_it.resize(N, up_slope.end());
    down_it.resize(N, down_slope.end());
    for (int i = 0; i < N; i++)
        cin >> P[i];
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
        add_up(i);
    }
    cur.resize(N);
    while (T > 0 && !up_slope.empty())
        go_up();
    cout << setprecision(9) << fixed;
    for (int i = 0; i < Q; i++)
    {
        int dir, r;
        cin >> dir >> r;
        r--;
        rm_up(r);
        rm_down(r);
        expect -= P[r] * cur[r] / (long double) (cur[r] + L[r]);
        if (dir == 1)
            L[r]++;
        else
            L[r]--;
        if (L[r] < cur[r])
        {
            cur[r]--;
            T++;
        }
        expect += P[r] * cur[r] / (long double) (cur[r] + L[r]);
        add_up(r);
        add_down(r);
        while (T > 0 && !up_slope.empty())
            go_up();
        while (!up_slope.empty() && !down_slope.empty()
               && up_slope.begin()->first > down_slope.begin()->first)
        {
            go_down();
            go_up();
        }
        cout << expect << '\n';
    }

    return 0;
}