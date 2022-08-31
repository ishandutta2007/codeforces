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

static int get(map<int, int> &xmap, int x, int &pool)
{
    if (xmap.count(x))
        return xmap[x];
    else
        return xmap[x] = pool++;
}

static pii dfs(const vector<vi> &edges, vector<bool> &seen, int cur)
{
    seen[cur] = true;
    int nv = 1;
    int ne = SZ(edges[cur]);
    for (int v : edges[cur])
        if (!seen[v])
        {
            auto sub = dfs(edges, seen, v);
            nv += sub.first;
            ne += sub.second;
        }
    return {nv, ne};
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

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
    return o << mr.get();
}

typedef MR<int, ll, 1000000007> mr;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    map<int, int> xmap, ymap;
    vi x(N), y(N);
    int V = 0;
    for (int i = 0; i < N; i++)
    {
        int cx, cy;
        cin >> cx >> cy;
        x[i] = get(xmap, cx, V);
        y[i] = get(ymap, cy, V);
    }
    vector<vi> edges(V);
    for (int i = 0; i < N; i++)
    {
        edges[x[i]].push_back(y[i]);
        edges[y[i]].push_back(x[i]);
    }
    vector<bool> seen(V);

    mr ans = 1;
    vector<mr> p2(V + 1);
    p2[0] = 1;
    for (int i = 1; i <= V; i++)
        p2[i] = p2[i - 1] + p2[i - 1];
    for (int i = 0; i < V; i++)
        if (!seen[i])
        {
            auto sub = dfs(edges, seen, i);
            int nv = sub.first;
            int ne = sub.second / 2;
            if (ne < nv)
                ans *= p2[nv] - 1;
            else
                ans *= p2[nv];
        }
    cout << ans << '\n';
    return 0;
}