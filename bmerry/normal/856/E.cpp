// WRONG

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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
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

typedef std::complex<ll> pnt;

static inline ll dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

class CompareAngle
{
private:
    const pnt base;

public:
    explicit CompareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        return cross(base, a, b) > 0;
    }
};

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

/*** TEMPLATE CODE ENDS HERE */

typedef pair<int, int> sample;

struct opmin
{
    sample operator()(const sample &a, const sample &b) const { return min(a, b); }
};

struct event
{
    int t;
    int x, y;
};

static bool cut_within(const pnt &a, const pnt &p, const pnt &b, const pnt &q)
{
    pnt dp = p - a;
    pnt dq = q - b;
    return dot(dp, dq) < 0;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll R, N;
    cin >> R >> N;
    vector<event> events;
    vector<pnt> pnts;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            events.push_back(event{1, SZ(pnts), -1});
            pnts.emplace_back(x, y);
        }
        else if (t == 2)
        {
            int idx;
            cin >> idx;
            idx--;
            events.push_back(event{2, idx, -1});
        }
        else
        {
            int a, b;
            cin >> a >> b;
            events.push_back(event{3, a - 1, b - 1});
        }
    }

    pnt A(-R, 0);
    pnt B(R, 0);
    int P = SZ(pnts);
    vector<int> byA(P);
    for (int i = 0; i < P; i++)
        byA[i] = i;
    auto byB = byA;
    CompareAngle cmpA(A);
    CompareAngle cmpB(B);
    sort(RA(byA), [&](int a, int b) { return cmpA(pnts[b], pnts[a]); });
    sort(RA(byB), [&](int a, int b) { return cmpB(pnts[a], pnts[b]); });
    vector<pair<int, int>> rank(P);

    rank[byA[0]].first = 0;
    int nxt = 0;
    for (int i = 1; i < P; i++)
    {
        if (cmpA(pnts[byA[i]], pnts[byA[i - 1]]))
            nxt++;
        rank[byA[i]].first = nxt;
    }
    int NA = nxt + 1;

    rank[byB[0]].second = 0;
    nxt = 0;
    for (int i = 1; i < P; i++)
    {
        if (cmpB(pnts[byB[i - 1]], pnts[byB[i]]))
            nxt++;
        rank[byB[i]].second = nxt;
    }

    vector<set<pair<int, int>>> line(NA);
    for (int i = 0; i < NA; i++)
        line[i].emplace(INT_MAX, INT_MAX);
    auto get_sample = [&](int row) { return *line[row].begin(); };
    SegTree<sample, opmin> seg(NA, get_sample(0));

    auto add = [&](int idx)
    {
        auto r = rank[idx];
        line[r.first].emplace(r.second, idx);
        seg.set(r.first, get_sample(r.first));
    };
    auto remove = [&](int idx)
    {
        auto r = rank[idx];
        line[r.first].erase(line[r.first].find(make_pair(r.second, idx)));
        seg.set(r.first, get_sample(r.first));
    };
    for (const event &ev : events)
    {
        if (ev.t == 1)
            add(ev.x);
        else if (ev.t == 2)
            remove(ev.x);
        else
        {
            pnt p = cross(A, pnts[ev.x], pnts[ev.y]) >= 0 ? pnts[ev.x] : pnts[ev.y];
            pnt q = cross(B, pnts[ev.x], pnts[ev.y]) >= 0 ? pnts[ev.y] : pnts[ev.x];
            bool good = true;
            if (cut_within(A, p, B, q))
                good = false;
            else
            {
                int ar = max(rank[ev.x].first, rank[ev.y].first);
                int br = max(rank[ev.x].second, rank[ev.y].second);
                remove(ev.x);
                remove(ev.y);
                sample samp = seg.query(0, ar + 1);
                if (samp.first <= br)
                    good = false;
                add(ev.x);
                add(ev.y);
            }
            cout << (good ? "YES\n" : "NO\n");
        }
    }

    return 0;
}