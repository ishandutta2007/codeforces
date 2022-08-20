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
typedef complex<ll> pnt;
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

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b)
{
    return imag(conj(a) * b);
}

template<typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b, const std::complex<T> &c)
{
    return cross(b - a, c - a);
}

struct node
{
    bool dead = false;
    int size = 1;
    ll a;
    vi edges;
};

static vector<node> nodes;

static int get_size(int cur, int parent)
{
    node &n = nodes[cur];
    int size = 1;
    for (int y : n.edges)
        if (y != parent && !nodes[y].dead)
            size += get_size(y, cur);
    return n.size = size;
}

static int find_centroid(int cur, int parent, int target)
{
    const node &n = nodes[cur];
    for (int y : n.edges)
        if (y != parent && !nodes[y].dead && nodes[y].size >= target)
            return find_centroid(y, cur, target);
    return cur;
}

static void make_down(int cur, int parent, vector<pnt> &down, ll psum, ll sum, int depth)
{
    const node &n = nodes[cur];
    depth++;
    psum += depth * n.a;
    sum += n.a;
    down.emplace_back(psum, sum);
    for (int y : n.edges)
        if (y != parent && !nodes[y].dead)
            make_down(y, cur, down, psum, sum, depth);
}

static void make_up(int cur, int parent, vector<ll> &up, ll psum, ll sum, int depth)
{
    const node &n = nodes[cur];
    sum += n.a;
    psum += sum;
    depth++;
    if (SZ(up) <= depth)
        up.push_back(psum);
    else
        up[depth] = max(up[depth], psum);
    for (int y : n.edges)
        if (y != parent && !nodes[y].dead)
            make_up(y, cur, up, psum, sum, depth);
}

template<typename T>
static void check_convex(const T &down)
{
#if 0
    assert(is_sorted(down.begin(), down.end()));
    if (SZ(down) < 3)
        return;
    auto a = down.begin();
    auto b = next(a);
    auto c = next(b);
    while (c != down.end())
    {
        assert(cross(*a, *b, *c) <= 0);
        a = b;
        b = c;
        ++c;
    }
#endif
}

template<typename T>
ll combine(const vector<ll> &up, const T &down, ll a)
{
    check_convex(down);
    ll ans = 0;
    auto ptr = down.rbegin();
    for (int i = 0; i < SZ(up); i++)
    {
#if 1
        auto nxt = next(ptr);
        while (nxt != down.rend()
               && ptr->real() + (i + 1) * ptr->imag() < nxt->real() + (i + 1) * nxt->imag())
        {
            ptr = nxt;
            ++nxt;
        }
        ll score = up[i] + (i + 1) * a + ptr->real() + (i + 1) * ptr->imag();
        ans = max(ans, score);
#else
        for (const auto &p : down)
        {
            ll score = up[i] + (i + 1) * a + p.real() + (i + 1) * p.imag();
            ans = max(ans, score);
        }
#endif
    }
    return ans;
}

namespace std
{
bool operator<(const pnt &a, const pnt &b)
{
    return pair(a.real(), a.imag()) < pair(b.real(), b.imag());
}
}

static ll best_path(int root)
{
    node &r = nodes[root];
    set<pnt> cdown{pnt(0, 0)};
    vector<ll> cup{0};
    ll ans = 0;
    for (int y : r.edges)
        if (!nodes[y].dead)
        {
            vector<pnt> ndown1, ndown;
            make_down(y, root, ndown1, 0, 0, 0);
            sort(ndown1.begin(), ndown1.end());
            for (const auto &p : ndown1)
            {
                while (SZ(ndown) >= 2
                       && cross(ndown[SZ(ndown) - 2], ndown.back(), p) >= 0)
                    ndown.pop_back();
                ndown.push_back(p);
            }
            check_convex(ndown);

            vector<ll> nup{0};
            make_up(y, root, nup, 0, 0, 0);

            ans = max(ans, combine(nup, cdown, r.a));
            ans = max(ans, combine(cup, ndown, r.a));
            if (cup.size() < nup.size())
                cup.resize(nup.size());
            for (int i = 0; i < SZ(nup); i++)
                cup[i] = max(cup[i], nup[i]);
            for (const auto &p : ndown)
            {
                auto [pos, nu] = cdown.insert(p);
                if (!nu)
                    continue;
                if (pos != cdown.begin() && next(pos) != cdown.end()
                    && cross(*prev(pos), *pos, *next(pos)) >= 0)
                {
                    cdown.erase(pos);
                    continue;
                }
                if (pos != cdown.begin())
                {
                    auto x = prev(pos);
                    while (x != cdown.begin()
                           && cross(*prev(x), *x, *pos) >= 0)
                    {
                        auto tmp = prev(x);
                        cdown.erase(x);
                        x = tmp;
                    }
                }
                if (next(pos) != cdown.end())
                {
                    auto y = next(pos);
                    while (next(y) != cdown.end()
                           && cross(*pos, *y, *next(y)) >= 0)
                    {
                        auto tmp = next(y);
                        cdown.erase(y);
                        y = tmp;
                    }
                }
            }
            check_convex(cdown);
        }
    return ans;
}

static ll solve(int cur)
{
    int size = get_size(cur, -1);
    int root = find_centroid(cur, -1, (size + 1) / 2);
    ll ans = best_path(root);
    node &n = nodes[root];
    n.dead = true;
    for (int y : n.edges)
        if (!nodes[y].dead)
        {
            ll sub = solve(y);
            ans = max(ans, sub);
        }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    for (int i = 0; i < N; i++)
        cin >> nodes[i].a;
    ll ans = solve(0);
    cout << ans << '\n';

    return 0;
}