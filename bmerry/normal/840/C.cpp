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
};

/*** TEMPLATE CODE ENDS HERE */

static int normalise(ll x)
{
    for (ll i = 2; i < 32000; i++)
        while (x % (i * i) == 0)
            x /= i * i;
    return x;
}

#define MOD 1000000007

typedef MR<int, ll, MOD> mr;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[i] = normalise(x);
    }
    sort(RA(a));
    vector<int> grp;
    int p = 0;
    while (p < N)
    {
        int q = p;
        while (q < N && a[q] == a[p])
            q++;
        grp.push_back(q - p);
        p = q;
    }

    vector<mr> fact(2 * N + 1);
    fact[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
        fact[i] = fact[i - 1] * i;
    vector<vector<mr>> choose(2 * N + 1, vector<mr>(2 * N + 1));
    for (int i = 0; i <= 2 * N; i++)
    {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }

    vector<mr> dp(N + 1);
    dp[1] = 1;
    mr scale = 1;
    for (int g : grp)
    {
        vector<mr> dp2(N + 1);
        for (int i = 0; i <= N; i++)
        {
            for (int w = 0; w <= min(i, g); w++)
                for (int e = 0; e <= g - w; e++)
                {
                    int o = i - w;
                    int r = g - w - e;
                    int nxt = i - w + r;
                    mr c;
                    if (r == 0)
                        c = 1;
                    else if (o + r - 1 >= r)
                        c = choose[o + r - 1][r];
                    else
                        c = 0;
                    if (nxt >= 0 && nxt <= N)
                    {
                        mr prod = choose[i][w] * choose[2 * o][e] * c * dp[i];
                        dp2[nxt] += prod;
                    }
                }
        }
        dp = move(dp2);
        scale *= fact[g];
    }

    mr ans = dp[0] * scale;
cout << ans.get() << '\n';

    return 0;
}