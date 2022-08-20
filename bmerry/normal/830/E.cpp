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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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
        while (num % 2 == 0 && den % 2 == 0)
        {
            num >>= 1;
            den >>= 1;
        }
        this->num = num;
        this->den = den;
    }

    rational operator-() const { return rational(-num, den); }
    rational inverse() const { return rational(den, num); }
    rational operator+(const rational &other) const { return rational(num * other.den + den * other.num, den * other.den); }
    rational operator*(const rational &other) const { return rational(num * other.num, den * other.den); }

    bool operator==(const rational &other) const { return num * other.den == other.num * den; }
    bool operator<(const rational &other) const { return num * other.den < other.num * den; }

    T numerator() const { return num; }
    T denominator() const { return den; }
    explicit operator double() const { return double(num) / double(den); }
};

template<typename T>
static std::ostream &operator<<(std::ostream &o, const rational<T> &r)
{
    return o << r.numerator() << '/' << r.denominator();
}

/*** TEMPLATE CODE ENDS HERE */

typedef rational<ll> rat;

struct node
{
    bool seen = false;
    int parent = -1;
    rat lambda = 1;
    vector<int> ch;
};

static pii recurse(vector<node> &nodes, const vector<vector<int>> &edges, int cur, int parent)
{
    node &n = nodes[cur];
    n.seen = true;
    n.parent = parent;
    rat r = 1;
    for (int y : edges[cur])
    {
        if (y == parent)
            continue;
        if (nodes[y].seen)
            return pii(cur, y);
        auto sub = recurse(nodes, edges, y, cur);
        if (sub.first != -1)
            return sub;
        r -= rat(1, 4) / nodes[y].lambda;
        n.ch.push_back(y);
    }
    if (r <= 0)
        return pii(cur, -1);
    else if (r > rat(1, 2) && r < rat(4, 7))
    {
        r = nodes[n.ch[0]].lambda;
        nodes[n.ch[0]].lambda = rat(1, 2);
    }
    n.lambda = r;
    return {-1, -1};
}

static void pushdown(const vector<node> &nodes, vector<rat> &c, int cur, rat value)
{
    const node &n = nodes[cur];
    c[cur] = value;
    for (int y : n.ch)
    {
        rat x = rat(1, 2) / nodes[y].lambda;
        pushdown(nodes, c, y, value * x);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T = 0;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> edges(N);
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        vector<node> nodes(N);
        pii base{-1, -1};
        for (int i = 0; i < N; i++)
        {
            if (!nodes[i].seen)
            {
                base = recurse(nodes, edges, i, -1);
                if (base.first != -1)
                    break;
            }
        }

        bool win = false;
        vector<ll> c(N);
        if (base.second != -1)
        {
            win = true;
            int cur = base.first;
            while (cur != base.second)
            {
                c[cur] = 1;
                cur = nodes[cur].parent;
            }
            c[cur] = 1;
        }
        else if (base.first != -1)
        {
            win = true;
            vector<rat> cr(N);
            pushdown(nodes, cr, base.first, 1);
            ll lcm = 1;
            for (int i = 0; i < N; i++)
            {
                ll d = cr[i].denominator();
                if (d != 1)
                    lcm = lcm * (d / gcd(lcm, d));
            }
            for (int i = 0; i < N; i++)
                c[i] = cr[i].numerator() * (lcm / cr[i].denominator());
        }

        if (win)
        {
            cout << "YES\n";
            ll produce = 0;
            for (int i = 0; i < N; i++)
            {
                cout << c[i] << ' ';
                produce -= c[i] * c[i];
                for (int trg : edges[i])
                    if (trg > i)
                        produce += c[i] * c[trg];
            }
            cout << '\n';
            //assert(produce >= 0);
        }
        else
            cout << "NO\n";
    }

    return 0;
}