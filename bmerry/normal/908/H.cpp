// Work in progress
// Needs O*(2^n) minimum clique cover

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

class UnionFind
{
private:
    mutable std::vector<int> parent;

public:
    explicit UnionFind(int size = 0) : parent(size, -1) {}

    int size() const { return parent.size(); }

    int find(int x) const
    {
        assert(x >= 0 && x < size());
        int y = x;
        while (parent[y] >= 0)
            y = parent[y];
        while (parent[x] >= 0)
        {
            int nxt = parent[x];
            parent[x] = y;
            x = nxt;
        }
        return y;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (-parent[x] > -parent[y])
            std::swap(x, y);
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }

    int component_size(int x) const
    {
        return -parent[find(x)];
    }
};

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

static inline int bit(int x)
{
    return 1 << x;
}

typedef MR<int, ll, 1000000009> mr;

static int min_colours(const vi &edges)
{
    int N = SZ(edges);
    int M = 1 << N;
    vector<mr> a(M);
    a[0] = 1;
    for (int i = 1; i < M; i++)
    {
        int v = __builtin_ctz(i);
        a[i] = a[i & ~bit(v)] + a[i & ~bit(v) & ~edges[v]];
    }
    vector<mr> ak(M, mr(1));

    for (int k = 1; ; k++)
    {
        mr sum = 0;
        for (int i = 0; i < M; i++)
        {
            ak[i] *= a[i];
            sum += __builtin_parity(i) ? ak[i] : -ak[i];
        }
        if (sum.get() != 0)
            return k;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vs matrix(N);

    UnionFind scc(N);

    for (int i = 0; i < N; i++)
    {
        cin >> matrix[i];
        for (int j = 0; j < i; j++)
            if (matrix[i][j] == 'A')
                scc.merge(i, j);
    }

    vector<pii> comps;
    for (int i = 0; i < N; i++)
        if (i == scc.find(i))
            comps.emplace_back(scc.component_size(i), i);
    sort(RA(comps));
    reverse(RA(comps));
    vi cmap(N);
    int C = SZ(comps);
    int C2 = 0;
    while (C2 < C && comps[C2].first >= 2)
        C2++;
    for (int i = 0; i < C; i++)
        cmap[comps[i].second] = i;

    C = C2;
    vector<int> edge(C);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] == 'X')
            {
                int p = cmap[scc.find(i)];
                int q = cmap[scc.find(j)];
                if (p == q)
                {
                    cout << "-1\n";
                    return 0;
                }
                if (p < C && q < C)
                {
                    edge[p] |= bit(q);
                    edge[q] |= bit(p);
                }
            }

    int mc = C2 ? min_colours(edge) : 0;
    cout << N - 1 + mc << '\n';
    return 0;
}