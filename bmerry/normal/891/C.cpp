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

struct edge
{
    int u;
    int v;
    int w;
    int idx;
    int ru = -1;
    int rv = -1;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u - 1;
        edges[i].v = v - 1;
        edges[i].w = w;
        edges[i].idx = i;
    }
    auto oedges = edges;
    sort(RA(edges), [](const edge &a, const edge &b) { return a.w < b.w; });
    UnionFind uf(N);
    int p = 0;
    while (p < M)
    {
        int i;
        for (i = p; i < M && edges[i].w == edges[p].w; i++)
        {
            edges[i].ru = uf.find(edges[i].u);
            edges[i].rv = uf.find(edges[i].v);
            oedges[edges[i].idx] = edges[i];
        }
        int q = i;
        for (i = p; i < q; i++)
            if (edges[i].ru != edges[i].rv)
                uf.merge(edges[i].ru, edges[i].rv);
        p = q;
    }

    int Q;
    cin >> Q;
    for (int ii = 0; ii < Q; ii++)
    {
        vector<edge> qe;
        int k;
        cin >> k;
        qe.reserve(k);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            qe.push_back(oedges[x - 1]);
        }
        sort(RA(qe), [](const edge &a, const edge &b) { return a.w < b.w; });
        int p = 0;
        bool good = true;
        while (p < k)
        {
            int q = p;
            while (q < k && qe[q].w == qe[p].w)
                q++;
            unordered_map<int, int> remap;
            int pool = 0;
            for (int i = p; i < q; i++)
            {
                int ends[2] = {qe[i].ru, qe[i].rv};
                for (int e : ends)
                {
                    if (!remap.count(e))
                        remap[e] = pool++;
                }
            }
            UnionFind qf(pool);
            for (int i = p; i < q; i++)
            {
                int ru = remap[qe[i].ru];
                int rv = remap[qe[i].rv];
                if (!qf.merge(ru, rv))
                    good = false;
            }
            p = q;
        }
        cout << (good ? "YES\n" : "NO\n");
    }

    return 0;
}