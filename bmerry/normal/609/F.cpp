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

/*** TEMPLATE CODE ENDS HERE */

struct frog
{
    ll x;
    ll t;
    int xi, ti;
    int id;
    int eat = 0;

    bool operator<(const frog &other) const
    {
        return x < other.x;
    }
};

struct mosi
{
    ll x;
    ll size;

    bool operator<(const mosi &other) const
    {
        return x < other.x;
    }
};

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

    template<typename ForwardIterator>
    SegmentTree(ForwardIterator first, ForwardIterator last)
    {
        prepare(std::distance(first, last));
        for (size_type i = 0; i < N; i++)
            nodes[i + offset] = node(*first++);
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


////////////  Add to range, query min or max of range

template<typename T>
class op_min
{
public:
    T operator()(const T &a, const T &b) const { return std::min(a, b); }
};

struct node
{
    int min = INT_MAX;
    int lower = INT_MAX;

    void push_down(size_t L, size_t R, node &left, node &right)
    {
        left.min = std::min(left.min, lower);
        right.min = std::min(right.min, lower);
        left.lower = std::min(left.lower, lower);
        right.lower = std::min(right.lower, lower);
        lower = INT_MAX;
    }

    void update(size_t L, size_t R, const node &left, const node &right)
    {
        assert(lower == INT_MAX);
        min = std::min(left.min, right.min);
    }

    void apply(size_t L, size_t R, int value, const op_min<int> &op)
    {
        lower = std::min(lower, value);
        min = std::min(min, value);
    }

    int query(size_t L, size_t R, const op_min<int> &op) const { return min; }

    node() = default;
    explicit node(int value) : min(value), lower(INT_MAX) {}
};

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<frog> frogs(N);
    vi xs;
    for (int i = 0; i < N; i++)
    {
        cin >> frogs[i].x >> frogs[i].t;
        frogs[i].id = i;
        xs.push_back(frogs[i].x);
    }
    sort(RA(frogs));
    vector<mosi> mosis(M);
    for (int i = 0; i < M; i++)
    {
        cin >> mosis[i].x >> mosis[i].size;
        xs.push_back(mosis[i].x);
    }
    sort(RA(xs));
    xs.resize(unique(RA(xs)) - xs.begin());
    int X = SZ(xs);
    SegmentTree<node> seg(X);

    for (int i = 0; i < N; i++)
    {
        frogs[i].xi = lower_bound(RA(xs), frogs[i].x) - xs.begin();
        frogs[i].ti = upper_bound(RA(xs), frogs[i].x + frogs[i].t) - xs.begin();
        seg.apply(frogs[i].xi, frogs[i].ti, i, op_min<int>());
    }

    multiset<mosi> unclaimed;
    for (int i = 0; i < M; i++)
    {
        int xi = lower_bound(RA(xs), mosis[i].x) - xs.begin();
        int f = seg.query(xi, xi + 1, op_min<int>());
        unclaimed.insert(mosis[i]);
        if (f != INT_MAX)
        {
            while (true)
            {
                auto nxt = unclaimed.lower_bound(mosi{frogs[f].x, 0});
                if (nxt == unclaimed.end() || nxt->x > frogs[f].x + frogs[f].t)
                    break;
                frogs[f].eat++;
                frogs[f].t += nxt->size;
                unclaimed.erase(nxt);
            }
            int old_ti = frogs[f].ti;
            frogs[f].ti = upper_bound(RA(xs), frogs[f].x + frogs[f].t) - xs.begin();
            seg.apply(old_ti, frogs[f].ti, f, op_min<int>());
        }
    }

    sort(RA(frogs), [&](const auto &a, const auto &b) { return a.id < b.id; });
    for (int i = 0; i < N; i++)
        cout << frogs[i].eat << ' ' << frogs[i].t << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}