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
};

struct op_assign {};

template<typename T>
struct set_sum
{
    T sum{};
    T value{};
    bool force = false;

    void set_to(const T &value, std::size_t sz)
    {
        this->value = value;
        sum = value * sz;
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
    }

    T query(std::size_t L, std::size_t R, const std::plus<T> &op) const { return sum; }

    void apply(std::size_t L, std::size_t R, const T &value, const op_assign &op)
    {
        set_to(value, R - L);
    }

    set_sum() = default;
    explicit set_sum(const T &value) : sum(value), value(value), force(true) {}
};


struct update
{
    int t;
    ll L, R;
};

static void solve()
{
    int Q;
    cin >> Q;
    vector<update> updates(Q);
    vector<ll> xs{1, LLONG_MAX / 2};
    for (int i = 0; i < Q; i++)
    {
        cin >> updates[i].t >> updates[i].L >> updates[i].R;
        updates[i].R++;
        xs.push_back(updates[i].L);
        xs.push_back(updates[i].R);
    }
    sort(RA(xs));
    xs.resize(unique(RA(xs)) - xs.begin());
    int M = SZ(xs);
    SegmentTree<set_sum<int>> seg(M + 1);
    for (int i = 0; i < Q; i++)
    {
        int t = updates[i].t;
        int L = lower_bound(RA(xs), updates[i].L) - xs.begin();
        int R = lower_bound(RA(xs), updates[i].R) - xs.begin();
        if (t == 1 || t == 2)
        {
            int oldL = seg.query(0, L, plus<int>());
            int oldR = seg.query(0, R, plus<int>());
            int trg = (t == 1) ? 1 : 0;
            int upL = (oldL % 2) ^ trg;
            seg.apply(L, L + 1, upL, op_assign());
            seg.apply(L + 1, R, 0, op_assign());
            if ((oldL + upL) % 2 != oldR % 2)
            seg.apply(R, R + 1, seg.query(R, R + 1, plus<int>()) ^ 1, op_assign());
        }
        else
        {
            seg.apply(L, L + 1, seg.query(L, L + 1, plus<int>()) ^ 1, op_assign());
            seg.apply(R, R + 1, seg.query(R, R + 1, plus<int>()) ^ 1, op_assign());
        }

        if (seg.query(0, 1, plus<int>()) == 0)
            cout << "1\n";
        else
        {
            int bL = 0;
            int bR = M;
            while (bR - bL > 1)
            {
                int mid = (bL + bR) / 2;
                if (seg.query(0, mid, plus<int>()) < 2)
                    bL = mid;
                else
                    bR = mid;
            }
            cout << xs[bL] << '\n';
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}