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


struct cut_point
{
    int value;
    int cid;
    int pos;

    bool operator<(const cut_point &other) const
    {
        return value < other.value;
    }
};

static void solve()
{
    int N;
    cin >> N;
    vi p(N), pi(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        p[i]--;
        pi[p[i]] = i;
    }

    vector<vi> cycles;
    vector<int> owner(N, -1);
    for (int i = 0; i < N; i++)
        if (owner[i] == -1)
        {
            int C = SZ(cycles);
            vi c;
            int y = i;
            do
            {
                c.push_back(y);
                owner[y] = C;
                y = p[y];
            } while (y != i);
            reverse(RA(c));
            cycles.push_back(move(c));
        }

    int C = SZ(cycles);
    UnionFind uf(C);
    vi link(N);
    for (int i = 0; i < N; i++)
        link[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        int a = uf.find(owner[i]);
        int b = uf.find(owner[i + 1]);
        if (a != b)
        {
            swap(link[i], link[i + 1]);
            uf.merge(a, b);
        }
    }

    int cur = 0;
    vi q;
    for (int i = 0; i < N; i++)
    {
        q.push_back(cur);
        cur = pi[link[cur]];
    }

    for (int v : q)
        cout << v + 1 << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}