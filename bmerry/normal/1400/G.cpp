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

/*** TEMPLATE CODE ENDS HERE */

static int choose[22][22];
static vector<mr> fact, ifact;

struct event
{
    int x;
    int id;
    int delta;

    bool operator<(const event &other) const
    {
        return x < other.x;
    }
};

static int alloc(map<int, int> &remap, int &B, int x)
{
    if (remap.count(x))
        return remap[x];
    else
        return remap[x] = B++;
}

template<size_t Z>
static void add_pick(array<int, Z> &trg, const array<int, Z> &src, int nf, int scale)
{
    for (int i = 0; i <= nf; i++)
        for (int j = 0; src[j]; j++)
            trg[i + j] += choose[nf][i] * src[j] * scale;
}

static mr fchoose(int n, int r)
{
    if (0 <= r && r <= n)
        return fact[n] * ifact[n - r] * ifact[r];
    else
        return 0;
}

int main(int argc, const char **argv)
{
    for (int i = 0; i <= 21; i++)
    {
        choose[i][i] = choose[i][0] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }

    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<event> events;
    events.reserve(2 * N);
    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        events.push_back(event{L, i, 1});
        events.push_back(event{R + 1, i, -1});
    }
    sort(RA(events));
    map<int, int> remap;
    int B = 0;
    vector<ll> masks(M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = alloc(remap, B, a);
        b = alloc(remap, B, b);
        masks[i] = (1LL << a) | (1LL << b);
    }

    vector<array<int, 22>> pick(1 << M);
    vector<ll> fmasks(1 << M);
    vector<int> sizes(1 << M);
    pick[0][0] = 1;
    for (int i = 0; i < M; i++)
    {
        int m = 1 << i;
        int share[2] = {};
        ll smask[2];
        smask[0] = masks[i] & (masks[i] - 1);
        smask[1] = masks[i] - smask[0];
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < i; j++)
                if (smask[k] & masks[j])
                    share[k] |= 1 << j;
        for (int j = 0; j < m; j++)
        {
            fmasks[j + m] = fmasks[j] | masks[i];
            sizes[j + m] = __builtin_popcountll(fmasks[j + m]);
            for (int k = 0; k < 2; k++)
            {
                int rem = j & ~share[k];
                ll freed = fmasks[j + m] & ~smask[k] & ~fmasks[rem];
                int nfreed = __builtin_popcountll(freed);
                add_pick(pick[j + m], pick[rem], nfreed, 1);
            }
            int rem = j & ~(share[0] | share[1]);
            ll freed = fmasks[j] & ~masks[i] & ~fmasks[rem];
            int nfreed = __builtin_popcountll(freed);
            add_pick(pick[j + m], pick[rem], nfreed, -1);
        }
    }

    fact.resize(N + 1);
    ifact.resize(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i;
    ifact[N] = mr(1) / fact[N];
    for (int i = N; i > 0; i--)
        ifact[i - 1] = ifact[i] * i;

    ll active = 0;
    int aset = 0;
    int ne = 0;
    int pool = 0;
    mr ans = 0;
    for (int i = 1; i <= N; i++)
    {
        bool dirty = false;
        while (ne < SZ(events) && events[ne].x <= i)
        {
            pool += events[ne].delta;
            if (remap.count(events[ne].id))
            {
                int id = remap[events[ne].id];
                if (events[ne].delta > 0)
                    active |= 1LL << id;
                else
                    active &= ~(1LL << id);
                dirty = true;
            }
            ne++;
        }
        if (dirty)
        {
            aset = 0;
            for (int j = 0; j < M; j++)
                if (!(masks[j] & ~active))
                    aset |= 1 << j;
        }
        if (pool >= i)
        {
            int s = sizes[aset];
            for (int j = 0; j <= i && pick[aset][j]; j++)
                ans += fchoose(pool - s, i - j) * pick[aset][j];
        }
    }
    cout << ans << '\n';

    return 0;
}