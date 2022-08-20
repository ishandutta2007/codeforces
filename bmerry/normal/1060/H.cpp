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
}

/*** TEMPLATE CODE ENDS HERE */

// Undefined sign for negative inputs
template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }
template<typename T> static constexpr T sqr(T a, T m) { return a * a % m; }
template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T, typename P>
static constexpr T power(T a, P b, T m) {
    assert(b >= 0);
    return b == 0 ? T(1) : (b % 2) ? power(a, b - 1, m) * a % m : sqr(power(a, b / 2, m), m);
}

template<typename T>
static constexpr T inverse(T a, T m) { return power(a, m - 2, m); }

const int ZERO = 4999;
const int ONE = 5000;
const int X = 1;
const int Y = 2;
static ll d, p;

struct cmd
{
    char op;
    array<int, 2> args;
    int trg;
};
static vector<cmd> cmds;

static void add(int e1, int e2, int t)
{
    cout << "+ " << e1 << ' ' << e2 << ' ' << t << '\n';
    cmds.push_back(cmd{'+', {{e1, e2}}, t});
}

static void copy(int e, int t)
{
    add(e, ZERO, t);
}

static void make_zero()
{
    const int tmp = 4998;
    for (ll m = 2; m <= p; m *= 2)
    {
        add(tmp, tmp, tmp);
        if (p & m)
            add(tmp, ZERO, ZERO);
    }
}

static void mul(int src, int trg, ll c)
{
    const int tmp = 100;
    copy(ZERO, trg);
    copy(src, tmp);
    c = mod(c, p);
    for (ll m = 1; m <= c; m *= 2)
    {
        if (c & m)
            add(tmp, trg, trg);
        add(tmp, tmp, tmp);
    }
}

static void expo(int src, int trg)
{
    cout << "^ " << src << ' ' << trg << '\n';
    cmds.push_back(cmd{'^', {{src, -1}}, trg});
}

static ll choose[11][11];

static void square(int src, int trg)
{
    const int tmp1 = 200;
    copy(src, tmp1);
    for (int i = 1; i <= d; i++)
        add(tmp1 + i - 1, ONE, tmp1 + i);
    for (int i = 0; i <= d; i++)
        expo(tmp1 + i, tmp1 + i);

    vector<vector<ll>> m(d + 1, vector<ll>(d + 1));
    vector<vector<ll>> inv(d + 1, vector<ll>(d + 1));
    for (int i = 0; i <= d; i++)
        for (int j = 0; j <= d; j++)
        {
            m[i][j] = choose[d][j] * power(ll(i), j, p);
            inv[i][j] = i == j;
        }
    for (int i = 0; i <= d; i++)
    {
        assert(m[i][i] != 0);
        ll s = inverse(m[i][i], p);
        for (int j = 0; j <= d; j++)
        {
            m[i][j] = (m[i][j] * s) % p;
            inv[i][j] = (inv[i][j] * s) % p;
        }
        for (int r = i + 1; r <= d; r++)
        {
            ll s = m[r][i];
            for (int j = 0; j <= d; j++)
            {
                m[r][j] = (m[r][j] - s * m[i][j]) % p;
                inv[r][j] = (inv[r][j] - s * inv[i][j]) % p;
            }
        }
    }

    for (int i = d; i >= 0; i--)
    {
        assert((m[i][i] - 1) % p == 0);
        for (int r = i - 1; r >= 0; r--)
        {
            ll s = m[r][i];
            for (int j = 0; j <= d; j++)
            {
                m[r][j] = (m[r][j] - s * m[i][j]) % p;
                inv[r][j] = (inv[r][j] - s * inv[i][j]) % p;
            }
        }
    }

    copy(ZERO, trg);
    for (int i = 0; i <= d; i++)
    {
        mul(tmp1 + i, tmp1 - 1, inv[d - 2][i]);
        add(tmp1 - 1, trg, trg);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> d >> p;
    for (int i = 0; i <= d; i++)
    {
        choose[i][i] = choose[i][0] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
    make_zero();
    add(X, Y, 3);
    square(X, 4);
    square(Y, 5);
    square(3, 6);
    mul(4, 7, -1);
    mul(5, 8, -1);
    add(7, 6, 6);
    add(8, 6, 6);
    mul(6, 9, (p + 1) / 2);
    cout << "f 9\n";

#if 0
    for (ll x = 0; x < p; x++)
        for (ll y = 0; y < p; y++)
        {
            cerr << "----------------------\nx = " << x << ", y = " << y << "\n\n";
            vll cells(5001, 1);
            cells[X] = x;
            cells[Y] = y;
            for (const cmd &c : cmds)
            {
                if (c.op == '+')
                    cells[c.trg] = mod(cells[c.args[0]] + cells[c.args[1]], p);
                else if (c.op == '^')
                    cells[c.trg] = power(cells[c.args[0]], d, p);
                cerr << "[" << c.trg << "] = " << cells[c.trg] << '\n';
            }
            assert(cells[9] == (x * y) % p);
        }
#endif

    return 0;
}