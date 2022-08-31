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

    int last_pos(size_type cur, size_type L, size_type R) const
    {
        if (nodes[cur].max <= 0)
            return -1;
        else if (R - L == 1)
            return L;
        else
        {
            size_type M = (L + R) / 2;
            push_down(cur, L, R);
            int ans = last_pos(2 * cur + 1, M, R);
            if (ans == -1)
                ans = last_pos(2 * cur, L, M);
            return ans;
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

    int last_pos() const
    {
        return last_pos(1, 0, offset);
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
    }

    void apply(size_t L, size_t R, const T &value, const std::plus<T> &op)
    {
        add += value;
        max += value;
    }

    T query(size_t L, size_t R, const op_max<T> &op) const { return max; }

    add_max() = default;
    explicit add_max(const T &value) : add(value), max(value) {}
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vi a(N);
    vi b(M);
    const int TOP = 1000001;
    SegmentTree<add_max<int>> st(TOP);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        st.apply(0, a[i] + 1, 1, plus<int>());
    }
    for (int i = 0; i < M; i++)
    {
        cin >> b[i];
        st.apply(0, b[i] + 1, -1, plus<int>());
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int t, i, x;
        cin >> t >> i >> x;
        i--;
        if (t == 1)
        {
            if (x < a[i])
                st.apply(x + 1, a[i] + 1, -1, plus<int>());
            else
                st.apply(a[i] + 1, x + 1, 1, plus<int>());
            a[i] = x;
        }
        else
        {
            if (x < b[i])
                st.apply(x + 1, b[i] + 1, 1, plus<int>());
            else
                st.apply(b[i] + 1, x + 1, -1, plus<int>());
            b[i] = x;
        }

        cout << st.last_pos() << '\n';
    }

    return 0;
}