// TOO SLOW: does badly with many small queries

//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

template<typename T>
class op_min
{
public:
    T operator()(const T &a, const T &b) const { return std::min(a, b); }
};

struct SATmpEntry
{
    int str;
    int ofs;
    std::array<int, 2> rank;

    constexpr SATmpEntry(int str, int ofs, int r) : str(str), ofs(ofs), rank{{r, 0}} {}

    constexpr bool operator<(const SATmpEntry &other) const
    {
        return std::tie(rank, str, ofs) < tie(other.rank, other.str, other.ofs);
    }
};

template<typename Char>
struct SAInit
{
    Char value;
    int str;
    int ofs;

    constexpr SAInit(Char value, int str, int ofs) : value(value), str(str), ofs(ofs) {}
    constexpr bool operator<(const SAInit &other) const { return value < other.value; }
};

struct SAEntry
{
    int str;
    int ofs;
    int share;
};

template<typename Container>
std::vector<SAEntry> make_suffix_array(const Container &strings)
{
    typedef typename Container::value_type::value_type char_t;

    int N = strings.size();
    std::vector<std::vector<int>> rank(N), subrank(N);
    rank.resize(N);
    subrank.resize(N);
    int ae = 0;
    int mchars = 0;
    for (int i = 0; i < N; i++)
    {
        int sz = strings[i].size() + 1;
        rank[i].resize(sz);
        subrank[i].resize(sz);
        ae += sz;
        mchars = std::max(mchars, int(strings[i].size()));
    }

    // Initial (1-char) ranks
    std::vector<SAInit<char_t>> init;
    init.reserve(ae - N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < int(strings[i].size()); j++)
            init.emplace_back(strings[i][j], i, j);
    std::sort(init.begin(), init.end());

    std::vector<SATmpEntry> order;
    order.reserve(ae);
    int irank = 0;
    for (int i = 0; i < N; i++)
        order.emplace_back(i, int(strings[i].size()), irank++);
    for (std::size_t i = 0; i < init.size(); i++)
    {
        if (i > 0 && init[i - 1] < init[i])
            irank++;
        order.emplace_back(init[i].str, init[i].ofs, irank);
    }
    assert(SZ(order) == ae);

    for (int step = 1; step <= mchars; step *= 2)
    {
        for (const auto &e : order)
            rank[e.str][e.ofs] = e.rank[0];
        for (auto &e : order)
        {
            int L = strings[e.str].size();
            e.rank[1] = rank[e.str][std::min(e.ofs + step, L)];
        }

        sort(order.begin(), order.end());

        std::array<int, 2> prev{{-1, -1}};
        irank = -1;
        for (auto &e : order)
        {
            if (e.rank != prev)
                irank++;
            prev = e.rank;
            e.rank[0] = irank;
        }
    }

    std::vector<SAEntry> ans(ae);
    for (int i = 0; i < ae; i++)
    {
        rank[order[i].str][order[i].ofs] = i;
        ans[i].str = order[i].str;
        ans[i].ofs = order[i].ofs;
    }

    for (int i = 0; i < N; i++)
    {
        int s = 0;
        int L = strings[i].size();
        for (int j = 0; j <= L; j++)
        {
            s--;
            if (s < 0)
                s = 0;
            int p = rank[i][j];
            if (p > 0)
            {
                const int pi = ans[p - 1].str;
                const int pj = ans[p - 1].ofs;
                const int pL = strings[pi].size();
                while (j + s < L && pj + s < pL && strings[i][j + s] == strings[pi][pj + s])
                    s++;
            }
            else
                s = 0;
            ans[p].share = s;
        }
    }

    return ans;
}

static ll compute(const vector<SAEntry> &sa, const SegTree<int, op_min<int>> &seg, const array<vi, 2> &ab)
{
    int p[2] = {0, 0};
    int N = SZ(sa) - 1;
    stack<pll> st[2];
    ll sum[2] = {0, 0};
    ll ans = 0;
    int i = -1;
    while (p[0] < SZ(ab[0]) || p[1] < SZ(ab[1]))
    {
        int oldi = i;
        if (p[0] == SZ(ab[0]))
            i = ab[1][p[1]];
        else if (p[1] == SZ(ab[1]))
            i = ab[0][p[0]];
        else
            i = min(ab[0][p[0]], ab[1][p[1]]);
        int share = seg.query(oldi + 1, i + 1);

        for (int j = 0; j < 2; j++)
        {
            ll flat = 0;
            while (!st[j].empty() && st[j].top().first >= share)
            {
                pll cur = st[j].top();
                st[j].pop();
                sum[j] -= (cur.first - share) * cur.second;
                flat += cur.second;
            }
            if (flat > 0)
                st[j].emplace(share, flat);
        }
        for (int j = 0; j < 2; j++)
        {
            if (p[j] < SZ(ab[j]) && ab[j][p[j]] == i)
            {
                st[j].emplace(N - sa[i].ofs, 1);
                sum[j] += N - sa[i].ofs;
                ans += sum[!j];
                p[j]++;
            }
        }
    }
    return ans;
}

static void solve()
{
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    auto sa = make_suffix_array(vs{s});
    vi rev(N + 1);
    vi share(N + 1);
    for (int i = 0; i <= N; i++)
    {
        rev[sa[i].ofs] = i;
        share[i] = sa[i].share;
    }
    SegTree<int, op_min<int>> seg(RA(share), INT_MAX);

    for (int i = 0; i < Q; i++)
    {
        int K[2];
        cin >> K[0] >> K[1];
        array<vi, 2> ab;
        for (int j = 0; j < 2; j++)
        {
            ab[j].resize(K[j]);
            for (int k = 0; k < K[j]; k++)
            {
                int x;
                cin >> x;
                x--;
                ab[j][k] = rev[x];
            }
            sort(RA(ab[j]));
        }
        ll ans = compute(sa, seg, ab);
        cout << ans << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}