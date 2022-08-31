//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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
}

/*** TEMPLATE CODE ENDS HERE */

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

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
    return o << mr.get();
}

typedef MR<int, ll, 1000000007> mr;


static vector<pii> filter(vector<pii> &ranges)
{
    vector<pii> out;
    sort(RA(ranges), [](const pii &a, const pii &b) {
        return pii(a.first, -a.second) < pii(b.first, -b.second);
    });
    for (const auto &r : ranges)
    {
        while (!out.empty() && r.first >= out.back().first
               && r.second <= out.back().second)
            out.pop_back();
        out.push_back(r);
    }
    return out;
}

static mr power(mr a, int b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return power(a, b - 1) * a;
    else
    {
        mr t = power(a, b / 2);
        return t * t;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K, N[2];
    cin >> K >> N[0] >> N[1];
    vector<pii> ranges[2];
    for (int i = 0; i < 2; i++)
    {
        ranges[i].resize(N[i]);
        for (int j = 0; j < N[i]; j++)
        {
            int l, r;
            cin >> l >> r;
            ranges[i][j] = pii(l - 1, r);
        }
        ranges[i] = filter(ranges[i]);
        N[i] = SZ(ranges[i]);
    }

    int nxt[2] = {0, 0};
    deque<mr> states[2];
    mr ssum[2] = {0, 0};
    mr zero = 1;

    vi step;
    step.push_back(0);
    step.push_back(K);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N[i]; j++)
        {
            step.push_back(ranges[i][j].first);
            step.push_back(ranges[i][j].second);
        }
    sort(RA(step));
    step.resize(unique(RA(step)) - step.begin());

    for (int px = 1; px < SZ(step); px++)
    {
        int ps = step[px - 1];
        int pe = step[px];
        bool incr[2] = {false, false};
        for (int j = 0; j < 2; j++)
            if (nxt[j] < N[j] && ranges[j][nxt[j]].first == ps)
            {
                incr[j] = true;
                nxt[j]++;
            }
        mr mixed = ssum[0] + ssum[1] + zero;
        mixed *= power(2, pe - ps) - 2;
        mr az = 0, a1[2] = {0, 0};
        for (int i = 0; i < 2; i++)
        {
            mr a = ssum[i] + zero;
            if (incr[!i])
                a1[!i] = a;
            else
                az += a;
        }
        for (int i = 0; i < 2; i++)
        {
            if (incr[i])
            {
                states[i].push_front(a1[i]);
                ssum[i] += a1[i];
            }
            int L = SZ(states[i]);
            if (L > 0)
            {
                int end = ranges[i][nxt[i] - L].second;
                if (end == pe)
                {
                    ssum[i] -= states[i].back();
                    states[i].pop_back();
                }
            }
        }
        zero = az + mixed;
    }

    cout << zero << '\n';

    return 0;
}