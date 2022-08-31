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

static const int ar[12] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1};
static const int ac[12] = {0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0};

static vector<int> follow(int start, const vector<pair<int, int>> &edges)
{
    queue<int> q;
    set<int> ans;
    ans.insert(start);
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (const auto &e : edges)
        {
            int y;
            if (e.first == cur)
                y = e.second;
            else if (e.second == cur)
                y = e.first;
            else
                continue;
            if (ans.insert(y).second)
                q.push(y);
        }
    }
    return vector<int>(RA(ans));
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C, Q;
    cin >> R >> C >> Q;
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    UnionFind uf((R + 1) * (C + 1));
    auto idx = [R, C] (int r, int c) -> int { return r * (C + 1) + c; };
    for (int i = 0; i < C - 1; i++)
    {
        uf.merge(idx(0, i + 1), idx(0, i + 2));
        uf.merge(idx(R, i), idx(R, i + 1));
    }
    for (int i = 0; i < R - 1; i++)
    {
        uf.merge(idx(i + 1, 0), idx(i + 2, 0));
        uf.merge(idx(i, C), idx(i + 1, C));
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '#')
            {
                for (int p = 0; p < 12; p += 2)
                    uf.merge(idx(i + ar[p], j + ac[p]), idx(i + ar[p + 1], j + ac[p + 1]));
            }

    set<pair<int, int>> near;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if ((i != 0 || j != 0) && (i != R - 1 || j != C - 1))
            {
                for (int p = 0; p < 12; p += 2)
                {
                    int x = uf.find(idx(i + ar[p], j + ac[p]));
                    int y = uf.find(idx(i + ar[p + 1], j + ac[p + 1]));
                    if (x == y)
                        continue;
                    if (x > y)
                        swap(x, y);
                    near.insert(make_pair(x, y));
                }
            }

    int bottom_left = uf.find(idx(R, 0));
    int top_right = uf.find(idx(0, C));
    for (int i = 0; i < Q; i++)
    {
        vector<pair<int, int>> edges;
        int K;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            int r, c;
            cin >> r >> c;
            r--;
            c--;
            for (int p = 0; p < 12; p += 2)
            {
                int x = uf.find(idx(r + ar[p], c + ac[p]));
                int y = uf.find(idx(r + ar[p + 1], c + ac[p + 1]));
                if (x != y)
                    edges.push_back(make_pair(x, y));
            }
        }
        vector<int> X = follow(bottom_left, edges);
        vector<int> Y = follow(top_right, edges);
        bool blocked = false;
        for (int x : X)
            for (int y : Y)
                if (x == y || near.count(make_pair(min(x, y), max(x, y))))
                    blocked = true;
        cout << (blocked ? "NO\n" : "YES\n") << flush;
    }

    return 0;
}