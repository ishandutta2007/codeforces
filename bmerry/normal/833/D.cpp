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

// Undefined sign for negative inputs
template<typename T>
static T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
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

    // These are only valid if the Modulus is prime, or at least if
    // the dividend is relatively prime to the modulus
    MR inverse() const
    {
        assert(value);
        return MR(::inverse(C(value), C(Modulus)), tag_good());
    }
    MR operator /(MR b) const { return *this * b.inverse(); }
    MR &operator /=(MR b) { return *this *= b.inverse(); }
};

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
    return o << mr.get();
}

template<typename T>
static T power(T a, ll b)
{
    if (b == 0)
        return T(1);
    else if (b & 1)
        return power(a, b - 1) * a;
    else
    {
        auto t = power(a, b / 2);
        return t * t;
    }
}

/*** TEMPLATE CODE ENDS HERE */

typedef MR<int, ll, 1000000007> mr;

struct edge
{
    int trg;
    mr clam;
    int color;
};

struct pathgroup
{
    ll num;
    mr prod;

    pathgroup() : num(0), prod(1) {}
    pathgroup(ll num, mr prod) : num(num), prod(prod) {}

    pathgroup operator+(const pathgroup &other) const
    {
        return pathgroup(num + other.num, prod * other.prod);
    }

    pathgroup &operator+=(const pathgroup &other)
    {
        num += other.num;
        prod *= other.prod;
        return *this;
    }

    pathgroup operator-() const
    {
        return pathgroup(-num, prod.inverse());
    }

    pathgroup operator-(const pathgroup &other) const
    {
        return *this + -other;
    }

    pathgroup &operator-=(const pathgroup &other)
    {
        return *this += -other;
    }

    pathgroup extra(mr factor) const
    {
        return pathgroup(num, power(factor, num) * prod);
    }
};

struct pathset
{
    deque<pathgroup> groups;
    pathgroup gez;
    int offset = 0;
    mr extra = 1;

    pathgroup fix(const pathgroup &value) const
    {
        assert(value.num >= 0);
        return value.extra(extra);
    }

    pathgroup ge0(int value) const
    {
        if (value >= SZ(groups) + offset)
            return pathgroup();
        value = max(value, offset);

        pathgroup adj;
        if (value > 0)
        {
            for (int i = 0; i < value; i++)
                adj += groups[i - offset];
            return gez - adj;
        }
        else
        {
            for (int i = value; i < 0; i++)
                adj += groups[i - offset];
            return gez + adj;
        }
    }

    pathgroup ge(int value) const
    {
        return fix(ge0(value));
    }

    pathgroup get(int value) const
    {
        return fix(groups[value - offset]);
    }

    mr joint_paths(const pathset &b) const
    {
        mr ans = 1;
        pathgroup rhs;
        for (int i = SZ(b.groups) - 1; i >= 0; i--)
        {
            rhs += b.fix(b.groups[i]);
            int need = -(i + b.offset) - offset + 1;
            if (need < 0 || need >= SZ(groups))
                continue;
            auto lhs = fix(groups[need]);
            mr prod = power(rhs.prod, lhs.num) * power(lhs.prod, rhs.num);
            ans *= prod;
        }
        auto lhs = ge(1 - (-1 + b.offset));
        mr prod = power(rhs.prod, lhs.num) * power(lhs.prod, rhs.num);
        ans *= prod;
        return ans;
    }

    void merge(const pathset &b)
    {
        while (offset > b.offset)
        {
            offset--;
            groups.emplace_front();
        }
        mr factor = b.extra / extra;
        while (offset + SZ(groups) < b.offset + SZ(b.groups))
            groups.emplace_back();
        for (int i = 0; i < SZ(b.groups); i++)
            groups[i + b.offset - offset] += b.groups[i].extra(factor);
        gez += b.gez.extra(factor);
    }

    void offset_by(int ofs)
    {
        gez = ge0(-ofs);
        offset += ofs;
        while (offset > 0)
        {
            offset--;
            groups.emplace_front();
        }
    }
};

struct node
{
    pathset paths;
    int size = 1;
    int parent = -1;
    int weight = 1;
    int color = 0;
    mr clam;
    vector<int> ch;
};

static vector<node> nodes;

static void make_tree(int root, int parent, const vector<vector<edge>> &edges)
{
    node &n = nodes[root];
    n.size = 1;
    n.parent = parent;
    for (const auto &edge : edges[root])
    {
        int y = edge.trg;
        if (y != parent)
        {
            n.ch.push_back(edge.trg);
            nodes[y].color = edge.color;
            nodes[y].clam = edge.clam;
            make_tree(y, root, edges);
            n.size += nodes[y].size;
        }
    }
    if (!n.ch.empty())
    {
        auto big = max_element(RA(n.ch), [&] (int a, int b) {
                               return nodes[a].size < nodes[b].size; });
        swap(*big, n.ch[0]);
    }
}

static mr make_paths(int root)
{
    node &n = nodes[root];
    mr ans = 1;
    for (int y : n.ch)
        ans *= make_paths(y);

    n.paths = pathset();
    n.paths.groups.emplace_back(1, 1);
    n.paths.gez = n.paths.groups[0];
    for (int y : n.ch)
    {
        node &ny = nodes[y];
        ny.paths.offset_by(ny.weight);
        ny.paths.extra *= ny.clam;
        if (ny.paths.groups.size() > n.paths.groups.size())
            swap(n.paths, ny.paths);
        //cerr << SZ(ny.paths.groups) << '\n';
        ans *= n.paths.joint_paths(ny.paths);
        n.paths.merge(ny.paths);
        ny.paths = pathset();
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, clam, color;
        cin >> u >> v >> clam >> color;
        u--;
        v--;
        edges[u].push_back(edge{v, clam, color});
        edges[v].push_back(edge{u, clam, color});
    }
    nodes.resize(N);
    make_tree(0, -1, edges);
    mr all = make_paths(0);
    for (node &n : nodes)
        n.weight = n.color ? 1 : -2;
    mr sub1 = make_paths(0);
    for (node &n : nodes)
        n.weight = n.color ? -2 : 1;
    mr sub2 = make_paths(0);
    mr ans = all / (sub1 * sub2);
    cout << ans << '\n';
}