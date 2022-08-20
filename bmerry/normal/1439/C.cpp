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

    template<typename T>
    size_type first_below(size_type cur, size_type L, size_type R, size_type A, size_type B, const T &value) const
    {
        assert(A < R && B > L && A < B);
        push_down(cur, L, R);
        if (R - L == 1)
            return nodes[cur].value <= value ? L : R;
        else
        {
            size_type M = (L + R) / 2;
            bool on_right;
            if (B <= M)
                on_right = false;
            else if (A >= M)
                on_right = true;
            else
            {
                T first = nodes[2 * cur + 1].first;
                on_right = first > value;
            }
            if (on_right)
                return first_below(2 * cur + 1, M, R, A, B, value);
            else
                return first_below(2 * cur, L, M, A, B, value);
        }
    }

    template<typename T>
    size_type sum_below(size_type cur, size_type L, size_type R, size_type B, const T &value) const
    {
        assert(B > L);
        push_down(cur, L, R);
        if (R - L == 1)
            return nodes[cur].sum <= value ? R : L;
        else
        {
            size_type M = (L + R) / 2;
            if (B <= M)
                return sum_below(2 * cur, L, M, B, value);
            else
            {
                ll s = nodes[2 * cur].sum;
                if (s <= value)
                    return sum_below(2 * cur + 1, M, R, B, value - s);
                else
                    return sum_below(2 * cur, L, M, B, value);
            }
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
        if (a == b)
            return 0;
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

    template<typename T>
    size_type first_below(size_type a, size_type b, const T &value) const
    {
        assert(a <= b && b <= N);
        if (a < b)
            return first_below(1, 0, offset, a, b, value);
        else
            return b;
    }

    template<typename T>
    size_type sum_below(size_type a, size_type b, const T &value) const
    {
        assert(a <= b && b <= N);
        if (a < b)
        {
            T test = value + query(0, a, plus<T>());
            return sum_below(1, 0, offset, b, test);
        }
        else
            return a;
    }
};

struct op_assign {};

template<typename T>
struct set_sum
{
    T sum{};
    T value{};
    T first{};
    bool force = false;

    void set_to(const T &value, std::size_t sz)
    {
        this->value = value;
        sum = value * sz;
        first = value;
        force = true;
    }

    void push_down(std::size_t L, std::size_t R, set_sum &left, set_sum &right)
    {
        if (force)
        {
            auto sz = (R - L) / 2;
            left.set_to(value, sz);
            right.set_to(value, sz);
            force = false;
        }
    }

    void update(std::size_t L, std::size_t R, const set_sum &left, const set_sum &right)
    {
        assert(!force);
        sum = left.sum + right.sum;
        first = left.first;
    }

    T query(std::size_t L, std::size_t R, const std::plus<T> &op) const { return sum; }

    void apply(std::size_t L, std::size_t R, const T &value, const op_assign &op)
    {
        set_to(value, R - L);
    }

    set_sum() = default;
    explicit set_sum(const T &value) : sum(value), value(value), first(value), force(true) {}
};

typedef SegmentTree<set_sum<ll>> seg_t;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    cin >> N >> Q;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    seg_t seg(RA(a));
    for (int i = 0; i < Q; i++)
    {
        int t, x;
        ll y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            int R = seg.first_below(0, x, y);
            seg.apply(R, x, y, op_assign());
        }
        else
        {
            int ans = 0;
            x--;
            while (x < N && y > 0)
            {
                x = seg.first_below(x, N, y);
                if (x >= N)
                    break;
                int L = seg.sum_below(x, N, y);
                ans += L - x;
                y -= seg.query(x, L, plus<ll>());
                x = L;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}