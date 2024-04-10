// TOO SLOW

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
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

// Undefined sign for negative inputs
template<typename T>
static T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

static ll M;
static ll inv10;

struct edge
{
    int trg;
    int w;

    edge() = default;
    edge(int trg, int w) : trg(trg), w(w) {}
};

static ll mget(const map<ll, ll> &m, ll key)
{
    auto p = m.find(key);
    return p == m.end() ? 0 : p->second;
}

struct collection
{
    map<ll, ll> values;
    ll scale = 1;
    ll bias = 0;
    ll inv_scale = 1;

    ll count(ll v) const
    {
        v = mod((v - bias) * inv_scale, M);
        return mget(values, v);
    }

    void insert(ll v, ll n)
    {
        v = mod((v - bias) * inv_scale, M);
        values[v] += n;
    }

    void xform(ll s, ll is, ll b)
    {
        bias = (bias * s + b) % M;
        scale = (scale * s) % M;
        inv_scale = (inv_scale * is) % M;
    }

    ll fix(ll v)
    {
        return (v * scale + bias) % M;
    }
};

struct node
{
    vector<edge> edges;
    int parent = -1;
    int size = 1;

    collection up, down;
};

vector<node> nodes;

static void prepare(int cur)
{
    node &n = nodes[cur];
    for (const auto &e : n.edges)
    {
        if (e.trg == n.parent)
            continue;
        node &c = nodes[e.trg];
        c.parent = cur;
        prepare(e.trg);
        n.size += c.size;
    }
    for (int i = 0; i < SZ(n.edges); i++)
    {
        edge &e = n.edges[i];
        if (e.trg == n.parent)
        {
            swap(e, n.edges.back());
            n.edges.pop_back();
            break;
        }
    }
    sort(RA(n.edges), [] (const edge &a, const edge &b) { return nodes[a.trg].size > nodes[b.trg].size; });
}

static ll solve(int cur)
{
    node &n = nodes[cur];
    ll ans = 0;
    n.up.insert(0, 1);
    n.down.insert(0, 1);
    for (const auto &e : n.edges)
    {
        node &c = nodes[e.trg];
        ans += solve(e.trg);

        c.up.xform(10, inv10, e.w);
        c.down.xform(inv10, 10, mod(-e.w * inv10, M));

        if (c.up.values.size() > n.up.values.size())
        {
            swap(c.up, n.up);
            swap(c.down, n.down);
        }
        for (const auto &u : c.up.values)
            ans += u.second * n.down.count(c.up.fix(u.first));
        for (const auto &d : c.down.values)
            ans += d.second * n.up.count(c.down.fix(d.first));

        for (const auto &u : c.up.values)
            n.up.insert(c.up.fix(u.first), u.second);
        for (const auto &d : c.down.values)
            n.down.insert(c.down.fix(d.first), d.second);
        c.up.values.clear();
        c.down.values.clear();
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N >> M;
    inv10 = inverse(10LL, M);
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].edges.emplace_back(v, w);
        nodes[v].edges.emplace_back(u, w);
    }
    prepare(0);
    ll ans = solve(0);
    cout << ans << '\n';
    return 0;
}