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

template<typename T, typename Op = std::plus<T> >
class BIT
{
private:
    std::vector<T> values;
    Op op;
    T identity;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    explicit BIT(size_type size = 0, Op op = Op(), T identity = T())
        : values(size + 1, identity), op(op), identity(identity) {}

    size_type size() const { return values.size() - 1; }

    void add(size_type idx, T delta)
    {
        assert(idx < size());
        idx++;
        while (idx < values.size())
        {
            values[idx] = op(values[idx], delta);
            idx += idx & ~(idx - 1);
        }
    }

    // Sum of values up to and including idx
    T sum(size_type idx) const
    {
        assert(idx < size());
        T ans = identity;
        idx++;
        while (idx > 0)
        {
            ans = op(ans, values[idx]);
            idx &= idx - 1;
        }
        return ans;
    }

    // Sum of values up to but excluding idx
    T sum_exclusive(size_type idx) const
    {
        return (idx == 0) ? identity : sum(idx - 1);
    }
};

struct change
{
    int r, c;
    int t;

    change() = default;
    change(int r, int c, int t) : r(r), c(c), t(t) {}
};

struct label
{
    vector<change> adds;
    vector<change> rems;
    int end = 0;
};

static pii find(vector<vector<pii>> &parent, int r, int c)
{
    if (parent[r][c].first >= 0)
        return parent[r][c] = find(parent, parent[r][c].first, parent[r][c].second);
    else
        return pii(r, c);
}

static void merge(vector<vector<pii>> &parent, int r1, int c1, int r2, int c2)
{
    if (-parent[r1][c1].first < -parent[r2][c2].first)
    {
        swap(r1, r2);
        swap(c1, c2);
    }
    parent[r1][c1].first += parent[r2][c2].first;
    parent[r2][c2] = pii(r1, c1);
}

static int combine(vector<vector<pii>> &parent, int r, int c)
{
    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, -1, 0, 1};
    assert(parent[r][c].first == -1);
    assert(parent[r][c].second == -1);
    parent[r][c].second = 0;
    int ans = 1;
    for (int d = 0; d < 4; d++)
    {
        int r2 = r + dr[d];
        int c2 = c + dc[d];
        if (r2 >= 0 && r2 < SZ(parent) && c2 >= 0 && c2 < SZ(parent[0])
            && parent[r2][c2].second >= 0)
        {
            auto root1 = find(parent, r, c);
            auto root2 = find(parent, r2, c2);
            if (root1 != root2)
            {
                merge(parent, root1.first, root1.second, root2.first, root2.second);
                ans--;
            }
        }
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C, Q;
    cin >> R >> C >> Q;
    vector<vi> mat(R, vi(C, 0));
    vector<label> labels(1);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            labels[0].adds.emplace_back(i, j, 0);
    for (int i = 0; i < Q; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        r--;
        c--;
        if (v >= SZ(labels))
            labels.resize(v + 1);
        int old = mat[r][c];
        if (old != v)
        {
            labels[old].rems.emplace_back(r, c, i + 1);
            labels[v].adds.emplace_back(r, c, i + 1);
            mat[r][c] = v;
        }
    }

    int L = labels.size();
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            int v = mat[i][j];
            labels[v].rems.emplace_back(i, j, Q + 1);
        }

    BIT<int> ans(Q + 2);
    for (int i = 0; i < L; i++)
    {
        vector<vector<pii>> parent(R, vector(C, pii(-1, -1)));
        for (const auto &add : labels[i].adds)
        {
            int delta = combine(parent, add.r, add.c);
            ans.add(add.t, delta);
        }

        parent = vector<vector<pii>>(R, vector(C, pii(-1, -1)));
        reverse(RA(labels[i].rems));
        for (const auto &rem : labels[i].rems)
        {
            int delta = combine(parent, rem.r, rem.c);
            ans.add(rem.t, -delta);
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans.sum(i) << '\n';

    return 0;
}