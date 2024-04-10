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

template<typename Node>
class SegmentTree
{
public:
    typedef std::size_t size_type;
    typedef Node node;

private:
    size_type N;
    size_type offset;
    mutable std::vector<node> nodes;

    void push_down(size_type idx, int L, int R) const
    {
        if (idx < offset)
            nodes[idx].push_down(L, R, nodes[2 * idx], nodes[2 * idx + 1]);
    }

    template<typename Op>
    auto query(size_type cur, size_type L, size_type R, size_type A, size_type B, const Op &op) const
        -> decltype(nodes[0].query(L, R, op))
    {
        assert(A < R && B > L && A < B);
        if (A <= L && B >= R)
            return nodes[cur].query(L, R, op);
        else
        {
            size_type M = (L + R) / 2;
            push_down(cur, L, R);
            if (B <= M)
                return query(2 * cur, L, M, A, B, op);
            else if (A >= M)
                return query(2 * cur + 1, M, R, A, B, op);
            else
            {
                auto left = query(2 * cur, L, M, A, B, op);
                auto right = query(2 * cur + 1, M, R, A, B, op);
                return op(left, right);
            }
        }
    }

    template<typename T, typename Op>
    void apply(size_type cur, size_type L, size_type R, size_type A, size_type B, const T &value,
               const Op &op)
    {
        assert(A < R && B > L && A < B);
        push_down(cur, L, R);
        if (A <= L && B >= R)
            nodes[cur].apply(L, R, value, op);
        else
        {
            size_type M = (L + R) / 2;
            if (A < M)
                apply(2 * cur, L, M, A, B, value, op);
            if (B > M)
                apply(2 * cur + 1, M, R, A, B, value, op);
            nodes[cur].update(L, R, nodes[2 * cur], nodes[2 * cur + 1]);
        }
    }

    void prepare(size_type N)
    {
        this->N = N;
        offset = 1;
        while (offset < N)
            offset *= 2;
        nodes.resize(2 * offset);
    }

    void pull_up()
    {
        for (size_type i = 0; i < offset; i++)
            nodes[i + offset].init(i);
        for (size_type step = 2; step <= offset; step <<= 1)
        {
            int base = offset / step;
            for (int i = base; i < base * 2; i++)
                nodes[i].update(i * step, (i + 1) * step, nodes[2 * i], nodes[2 * i + 1]);
        }
    }

public:
    explicit SegmentTree(size_type N)
    {
        prepare(N);
        pull_up();
    }

    size_type size() const { return N; }

    template<typename Op>
    auto query(size_type a, size_type b, const Op &op = Op()) const
        -> decltype(query(1, 0, offset, a, b, op))
    {
        assert(a < b && b <= N);
        return query(1, 0, offset, a, b, op);
    }

    template<typename T, typename Op>
    void apply(size_type a, size_type b, const T &value, const Op &op = Op())
    {
        assert(a <= b && b <= N);
        if (a < b)
            apply(1, 0, offset, a, b, value, op);
    }
};

template<typename T>
class op_max
{
public:
    T operator()(const T &a, const T &b) const { return std::max(a, b); }
};

template<typename T>
struct add_max
{
    T add{};
    T max{};
    size_t max_pos{};

    void push_down(size_t L, size_t R, add_max &left, add_max &right)
    {
        left.add += add;
        left.max += add;
        right.add += add;
        right.max += add;
        add = T();
    }

    void update(size_t L, size_t R, const add_max &left, const add_max &right)
    {
        assert(add == T());
        max = std::max(left.max, right.max);
        if (right.max > left.max)
            max_pos = right.max_pos;
        else
            max_pos = left.max_pos;
    }

    void apply(size_t L, size_t R, const T &value, const std::plus<T> &op)
    {
        add += value;
        max += value;
    }

    pair<T, size_t> query(size_t L, size_t R, const op_max<pair<T, size_t>> &op) const
    {
        return make_pair(max, max_pos);
    }

    void init(size_t pos) { max_pos = pos; }

    add_max() = default;
    explicit add_max(const T &value) : add(value), max(value) {}
};

typedef SegmentTree<add_max<ll>> segt;

struct pnt
{
    ll x, y, c;

    bool operator<(const pnt &other) const { return x < other.x; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pnt> pnts(N);
    map<ll, int> ys;
    for (int i = 0; i < N; i++)
    {
        cin >> pnts[i].x >> pnts[i].y >> pnts[i].c;
        if (pnts[i].x > pnts[i].y)
            swap(pnts[i].x, pnts[i].y);
        ys[pnts[i].x] = -1;
        ys[pnts[i].y] = -1;
    }
    sort(RA(pnts));

    int Y = SZ(ys);
    vll y;
    y.reserve(Y);
    for (auto &e : ys)
    {
        e.second = SZ(y);
        y.push_back(e.first);
    }

    segt tree(Y);
    for (int i = 0; i < Y; i++)
        tree.apply(i, i + 1, -y[i], plus<ll>());

    int p = N;
    ll ans = 0;
    ll ans_x = 1000000001, ans_y = 1000000001;
    while (p > 0)
    {
        int q = p;
        ll x = pnts[q - 1].x;
        while (p > 0 && pnts[p - 1].x == x)
            p--;
        for (int i = p; i < q; i++)
            tree.apply(ys[pnts[i].y], Y, pnts[i].c, plus<ll>());
        auto score = tree.query(ys[x], Y, op_max<pair<ll, size_t>>());
        score.first += x;
        if (score.first > ans)
        {
            ans = score.first;
            ans_x = x;
            ans_y = y[score.second];
        }
    }
    cout << ans << '\n' << ans_x << ' ' << ans_x << ' ' << ans_y << ' ' << ans_y << '\n';

    return 0;
}