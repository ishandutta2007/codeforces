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

template<typename T, typename Op = std::plus<T>>
class SegTree
{
    typedef std::size_t size_type;

    T identity;
    Op op;
    std::vector<T> nodes;

public:
    explicit SegTree(std::size_t n = 0, const T &identity = T(), const Op &op = Op())
        : identity(identity), op(op), nodes(2 * n, this->identity)
    {
        for (int i = n - 1; i > 0; i--)
            nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
    }

    template<typename Iterator>
    SegTree(Iterator first, Iterator last, const T &identity = T(), const Op &op = Op())
        : identity(identity), op(op)
    {
        size_type n = std::distance(first, last);
        nodes.reserve(2 * n);
        nodes.resize(n, this->identity);
        nodes.insert(nodes.end(), first, last);
        for (int i = n - 1; i > 0; i--)
            nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
    }

    size_type size() const { return nodes.size() / 2;}

    void set(size_type idx, T value)
    {
        assert(0 <= idx && idx < size());
        idx += size();
        nodes[idx] = std::move(value);
        while (idx > 0)
        {
            idx /= 2;
            nodes[idx] = op(nodes[2 * idx], nodes[2 * idx + 1]);
        }
    }

    const T &operator[](size_type idx) const
    {
        assert(0 <= idx && idx < size());
        return nodes[idx + size()];
    }

    T query(size_type a, size_type b) const
    {
        assert(0 <= a && a <= size());
        assert(0 <= b && b <= size());
        a += size();
        b += size();
        T left = identity, right = identity;
        while (a < b)
        {
            if (a & 1)
                left = op(left, nodes[a++]);
            if (b & 1)
                right = op(nodes[--b], right);
            a /= 2;
            b /= 2;
        }
        return op(left, right);
    }
};

struct query
{
    int L, R;
    int idx;

    bool operator<(const query &other) const
    {
        return R < other.R;
    }
};

using entry = pair<int, int>;

template<typename T>
class op_min
{
public:
    T operator()(const T &a, const T &b) const { return std::min(a, b); }
};

static void solve()
{
    int N, Q;
    cin >> N;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cin >> Q;
    vector<query> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--;
        queries[i].idx = i;
    }
    sort(RA(queries));

    SegTree<entry, op_min<entry>> seg(N, entry(INT_MAX, INT_MAX));

    vi last(500001, -1);
    int qid = 0;
    vi ans(Q, 0);
    for (int i = 0; i <= N; i++)
    {
        while (qid < Q && queries[qid].R == i)
        {
            auto best = seg.query(queries[qid].L, i);
            if (best.first < queries[qid].L)
                ans[queries[qid].idx] = best.second;
            qid++;
        }
        if (i == N)
            break;

        int v = a[i];
        if (last[v] != -1)
            seg.set(last[v], entry(INT_MAX, INT_MAX));
        seg.set(i, entry(last[v], v));
        last[v] = i;
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}