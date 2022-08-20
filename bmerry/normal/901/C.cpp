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
        for (int i = 0; i < N; i++)
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

// Add to range, query min or max of range
template<typename T>
struct add_sum
{
    T add{};
    T sum{};

    void push_down(size_t L, size_t R, add_sum &left, add_sum &right)
    {
        size_t sz = (R - L) / 2;
        left.add += add;
        left.sum += add * sz;
        right.add += add;
        right.sum += add * sz;
        add = T();
    }

    void update(size_t L, size_t R, const add_sum &left, const add_sum &right)
    {
        assert(add == T());
        sum = left.sum + right.sum;
    }

    void apply(size_t L, size_t R, const T &value, const std::plus<T> &op)
    {
        add += value;
        sum += value * (R - L);
    }

    T query(size_t L, size_t R, const plus<T> &op) const { return sum; }

    add_sum() = default;
    explicit add_sum(const T &value) : add(value), sum(value) {}
};

static int N, M;
static vector<vi> edges;
static vi parent;
static vector<vi> cend;
static vi order;

static void dfs(int cur, int p, int &pool)
{
    order[cur] = pool++;
    for (int v : edges[cur])
    {
        if (v == p)
            continue;
        if (order[v] == -1)
        {
            parent[v] = cur;
            dfs(v, cur, pool);
        }
        else if (order[v] < order[cur])
        {
            int lo = v, hi = v;
            int u = cur;
            while (u != v)
            {
                lo = min(lo, u);
                hi = max(hi, u);
                u = parent[u];
            }
            cend[lo].push_back(hi);
        }
    }
}

struct query
{
    int L, idx;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    cin >> N >> M;
    edges.resize(N);
    parent.resize(N, -1);
    order.resize(N, -1);
    cend.resize(N);
    vector<vector<query>> queries(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int pool = 0;
    for (int i = 0; i < N; i++)
        if (parent[i] == -1)
        {
            parent[i] = -2;
            dfs(i, -2, pool);
        }

    vector<pii> cc;
    for (int lo = 0; lo < N; lo++)
        for (int hi : cend[lo])
        {
            while (!cc.empty() && cc.back().second >= hi)
                cc.pop_back();
            cc.emplace_back(lo, hi);
        }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        queries[R].push_back(query{L, i});
    }
    vector<ll> ans(Q);

    SegmentTree<add_sum<ll>> st(N);
    int p = 0;
    for (int R = 0; R < N; R++)
    {
        if (p > 0)
            st.apply(0, cc[p - 1].first + 1, 1, std::plus<ll>());
        while (p < SZ(cc) && cc[p].second == R)
        {
            int last = p > 0 ? cc[p - 1].first + 1 : 0;
            st.apply(last, cc[p].first + 1, 1, std::plus<ll>());
            p++;
        }
        for (const auto &q : queries[R])
        {
            ll sz = (ll) R - q.L + 1;
            ll base = sz * (sz + 1) / 2;
            ll bad = st.query(q.L, R + 1, std::plus<ll>());
            ans[q.idx] = base - bad;
        }
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}