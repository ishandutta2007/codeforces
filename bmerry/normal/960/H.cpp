//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

    T query(size_t L, size_t R, const std::plus<T> &op) const { return sum; }

    add_sum() = default;
    explicit add_sum(const T &value) : add(value), sum(value) {}
};

typedef SegmentTree<add_sum<ll>> Tree;
static std::plus<ll> Op;


struct node
{
    int parent = -1;
    vi ch;
    int size = 1;
    int hid = -1;
    int hpos = -1;
};

static vector<node> nodes;

enum event_t
{
    EV_ADD,
    EV_REMOVE,
    EV_QUERY
};

struct event
{
    event_t type;
    int pos;
};

struct hpath
{
    int up = -1;
    int upos = -1;
    int size = 0;
    Tree tree;

    hpath() : tree(0) {}
};

static vector<hpath> hpaths;

static void make_size(int cur)
{
    node &n = nodes[cur];
    for (int v : n.ch)
    {
        make_size(v);
        n.size += nodes[v].size;
    }
}

static void make_hpaths(int cur)
{
    node &n = nodes[cur];
    for (int v : n.ch)
    {
        node &y = nodes[v];
        if (y.size * 2 >= n.size)
        {
            y.hid = n.hid;
            y.hpos = n.hpos + 1;
        }
        else
        {
            y.hid = SZ(hpaths);
            y.hpos = 0;
            hpaths.emplace_back();
            hpaths.back().up = n.hid;
            hpaths.back().upos = n.hpos;
        }
        hpaths[y.hid].size++;
        make_hpaths(v);
    }
}

static inline ll sqr(ll x)
{
    return x * x;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, Q;
    ll C;
    cin >> N >> M >> Q >> C;
    nodes.resize(N);
    vector<vector<event>> events(M);
    vector<double> repl(M);
    vector<int> f(N);
    for (int i = 0; i < N; i++)
    {
        cin >> f[i];
        f[i]--;
        events[f[i]].push_back(event{EV_ADD, i});
    }
    for (int i = 1; i < N; i++)
    {
        cin >> nodes[i].parent;
        nodes[i].parent--;
        nodes[nodes[i].parent].ch.push_back(i);
    }
    for (int i = 0; i < M; i++)
        cin >> repl[i];

    hpaths.emplace_back();
    hpaths[0].up = -1;
    hpaths[0].size++;
    nodes[0].hid = 0;
    nodes[0].hpos = 0;
    make_size(0);
    make_hpaths(0);
    for (auto &hp : hpaths)
        hp.tree = Tree(hp.size);

    vector<double> answers;
    for (int q = 0; q < Q; q++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, w;
            cin >> x >> w;
            x--;
            w--;
            events[f[x]].push_back(event{EV_REMOVE, x});
            events[w].push_back(event{EV_ADD, x});
            f[x] = w;
        }
        else
        {
            int k;
            cin >> k;
            k--;
            events[k].push_back(event{EV_QUERY, int(SZ(answers))});
            answers.push_back(0.0);
        }
    }
    for (int i = 0; i < N; i++)
        events[f[i]].push_back(event{EV_REMOVE, i});

    ll lin = 0;
    ll quad = 0;
    for (int m = 0; m < M; m++)
    {
        for (const event &e : events[m])
        {
            switch (e.type)
            {
            case EV_ADD:
            case EV_REMOVE:
                {
                    int d = (e.type == EV_ADD) ? 1 : -1;
                    int hid = nodes[e.pos].hid;
                    int hpos = nodes[e.pos].hpos;
                    while (hid != -1)
                    {
                        ll u = hpaths[hid].tree.query(0, hpos + 1, Op);
                        quad += 2 * d * u + hpos + 1;
                        lin += d * (hpos + 1);
                        hpaths[hid].tree.apply(0, hpos + 1, d, Op);
                        hpos = hpaths[hid].upos;
                        hid = hpaths[hid].up;
                    }
                }
                break;
            case EV_QUERY:
                {
                    double tot = (quad * repl[m] - 2 * C * lin) * repl[m] / N + C * C;
                    answers[e.pos] = tot;
                }
                break;
            }
        }
    }

    cout << fixed << setprecision(12);
    for (double d : answers)
        cout << d << '\n';

    return 0;
}