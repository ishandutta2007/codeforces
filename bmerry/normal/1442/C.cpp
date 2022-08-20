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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

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


struct pqitem
{
    int trg;
    int prio;

    bool operator<(const pqitem &other) const
    {
        return prio > other.prio;
    }
};

struct pqitem2
{
    int trg;
    int phase;
    int flips;
    int steps;

    bool operator<(const pqitem2 &other) const
    {
        return pair(flips, steps) > pair(other.flips, other.steps);
    }
};

static int solve_small(const array<vector<vi>, 2> &edges)
{
    int N = SZ(edges[0]);
    vi prio(N, INT_MAX);
    prio[0] = 0;
    int add = 0;
    int ans = INT_MAX;
    for (int t = 0; t < 20; t++)
    {
        if (add >= ans)
            break;
        priority_queue<pqitem> q;
        for (int i = 0; i < N; i++)
            if (prio[i] != INT_MAX)
                q.push(pqitem{i, prio[i]});
        while (!q.empty())
        {
            int cur = q.top().trg;
            int p = q.top().prio;
            q.pop();
            if (p != prio[cur])
                continue;
            for (int y : edges[t & 1][cur])
            {
                if (p + 1 < prio[y])
                {
                    prio[y] = p + 1;
                    q.push(pqitem{y, p + 1});
                }
            }
        }
        if (prio.back() != INT_MAX)
            ans = min(ans, prio.back() + add);
        add = add * 2 + 1;
    }
    return ans;
}

static pair<int, int> solve_big(const array<vector<vi>, 2> &edges)
{
    int N = SZ(edges[0]);
    const array<int, 2> big = {INT_MAX, INT_MAX};
    vector<array<int, 2>> flips(N, big), steps(N, big);
    priority_queue<pqitem2> q;
    q.push(pqitem2{0, 0, 0, 0});
    flips[0][0] = 0;
    steps[0][0] = 0;
    while (!q.empty())
    {
        int cur = q.top().trg;
        int phase = q.top().phase;
        int f = q.top().flips;
        int s = q.top().steps;
        q.pop();
        if (f != flips[cur][phase] || s != steps[cur][phase])
            continue;
        for (int i = 0; i < 2; i++)
        {
            for (int y : edges[phase ^ i][cur])
            {
                int f2 = f + i;
                int s2 = s + 1;
                int p2 = phase ^ i;
                if (pair(f2, s2) < pair(flips[y][p2], steps[y][p2]))
                {
                    flips[y][p2] = f2;
                    steps[y][p2] = s2;
                    q.push(pqitem2{y, p2, f2, s2});
                }
            }
        }
        if (pair(f + 1, s) < pair(flips[cur][!phase], steps[cur][!phase]))
        {
            flips[cur][!phase] = f + 1;
            steps[cur][!phase] = s;
            q.push(pqitem2{cur, !phase, f + 1, s});
        }
    }

    pair ans1(flips.back()[0], steps.back()[0]);
    pair ans2(flips.back()[1], steps.back()[1]);
    return min(ans1, ans2);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    array<vector<vi>, 2> edges;
    edges[0].resize(N);
    edges[1].resize(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[0][u].push_back(v);
        edges[1][v].push_back(u);
    }
    ll ans1 = solve_small(edges);
    auto ans2 = solve_big(edges);
    mr ans;
    if (ans2.first <= 20)
    {
        ll ans2f = ans2.second + (1LL << ans2.first) - 1;
        ans = min(ans1, ans2f);
    }
    else
    {
        ans = power(mr(2), ans2.first) - 1 + ans2.second;
    }
    cout << ans << '\n';

    return 0;
}