#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

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

static void bit_add(vector<int> &bit, int p, int v)
{
    p++;
    while (p < SZ(bit))
    {
        bit[p] += v;
        p += p & ~(p - 1);
    }
}

static int bit_get(const vector<int> &bit, int p)
{
    int ans = 0;
    p++;
    while (p > 0)
    {
        ans += bit[p];
        p &= p - 1;
    }
    return ans;
}

struct node
{
    int a;
    int level;
    int bid;
    int end;
    vector<int> edges;
};

static void process(vector<node> &nodes, int cur, int level, int parent, int &pool, vector<int> &ridx)
{
    node &n = nodes[cur];
    n.level = level;
    n.bid = pool++;
    ridx[n.bid] = cur;
    if (n.level & 1)
        n.a = -n.a;
    for (int y : n.edges)
        if (y != parent)
            process(nodes, y, level + 1, cur, pool, ridx);
    n.end = pool;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;

    vector<node> nodes(N);
    vector<int> bit(N + 1);
    vector<int> ridx(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nodes[i].a;
        nodes[i].bid = -1;
        nodes[i].level = -1;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }

    int pool = 0;
    process(nodes, 0, 0, -1, pool, ridx);
    int prev = nodes[ridx[0]].a;
    bit_add(bit, 0, prev);
    for (int i = 1; i < N; i++)
    {
        int cur = nodes[ridx[i]].a;
        bit_add(bit, i, cur - prev);
        prev = cur;
    }

    for (int i = 0; i < M; i++)
    {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1)
        {
            int v;
            cin >> v;
            if (nodes[x].level & 1)
                v = -v;
            bit_add(bit, nodes[x].bid, v);
            bit_add(bit, nodes[x].end, -v);
        }
        else
        {
            int v = bit_get(bit, nodes[x].bid);
            if (nodes[x].level & 1)
                v = -v;
            cout << v << '\n';
        }
    }

    return 0;
}