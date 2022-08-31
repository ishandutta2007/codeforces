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

struct node
{
    int depth;
    int parent = -1;
    int spine_dist = -1;
    int color = -1;
};

static vector<node> nodes;

static void recurse1(const vector<vi> &edges, int cur, int parent, int depth)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.depth = depth;
    for (int y : edges[cur])
        if (y != parent)
            recurse1(edges, y, cur, depth + 1);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    nodes.resize(N);
    vector<vi> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    recurse1(edges, 0, -1, 0);
    int root = 0;
    for (int i = 1; i < N; i++)
        if (nodes[i].depth > nodes[root].depth)
            root = i;
    recurse1(edges, root, -1, 0);
    int tail = 0;
    for (int i = 1; i < N; i++)
        if (nodes[i].depth > nodes[tail].depth)
            tail = i;

    int R = nodes[tail].depth;
    for (int i = tail; i != -1; i = nodes[i].parent)
        nodes[i].spine_dist = 0;

    if (K == 2)
    {
        for (int i = 0; i < N; i++)
            nodes[i].color = nodes[i].depth % 2;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            int d = 0;
            int y;
            for (y = i; nodes[y].spine_dist == -1; y = nodes[y].parent)
                d++;
            d += nodes[y].spine_dist;
            for (y = i; nodes[y].spine_dist == -1; y = nodes[y].parent)
            {
                nodes[y].spine_dist = d;
                d--;
            }

            if (nodes[i].spine_dist == 0)
                nodes[i].color = nodes[i].depth % K;
            else
            {
                int r1 = nodes[i].depth + 1;
                int sd = nodes[i].depth - nodes[i].spine_dist;
                int r2 = nodes[i].spine_dist + (R - sd) + 1;
                if (r1 >= K && r2 >= K)
                {
                    cout << "No\n";
                    return 0;
                }
                else if (r1 >= r2)
                    nodes[i].color = nodes[i].depth % K;
                else
                    nodes[i].color = (sd - nodes[i].spine_dist) % K;
            }
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < N; i++)
        cout << nodes[i].color + 1 << ' ';
    cout << '\n';

    return 0;
}