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

class UnionFind
{
private:
    mutable std::vector<int> parent;

public:
    explicit UnionFind(int size = 0) : parent(size, -1) {}

    int size() const { return parent.size(); }

    int find(int x) const
    {
        assert(x >= 0 && x < size());
        int y = x;
        while (parent[y] >= 0)
            y = parent[y];
        while (parent[x] >= 0)
        {
            int nxt = parent[x];
            parent[x] = y;
            x = nxt;
        }
        return y;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (-parent[x] > -parent[y])
            std::swap(x, y);
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }

    int component_size(int x) const
    {
        return -parent[find(x)];
    }
};

static ll solve(const vector<vi> &edges, const vector<pii> &a)
{
    int N = SZ(a);
    UnionFind uf(N);
    ll ans = 0;
    vector<bool> done(N);
    for (const pii &v : a)
    {
        int x = v.second;
        ans += v.first;
        for (int y : edges[x])
        {
            if (!done[y])
                continue;
            int p = uf.find(x);
            int q = uf.find(y);
            assert(p != q);
            ans += ll(v.first) * uf.component_size(p) * uf.component_size(q);
            uf.merge(p, q);
        }
        done[x] = true;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pii> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(RA(a), [](const pii &x, const pii &y) { return x.first < y.first; });

    vector<vi> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    ll ans1 = solve(edges, a);
    for (pii &v : a)
        v.first = -v.first;
    reverse(RA(a));
    ll ans2 = solve(edges, a);
    cout << ans1 + ans2 << '\n';

    return 0;
}