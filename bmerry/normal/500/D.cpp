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

struct node
{
    int parent = -1;
    int size = 1;
    int len = 0;
    double p;
};

static vector<node> nodes;

static void make_tree(int cur, int parent, const vector<vector<pii> > &edges)
{
    nodes[cur].parent = parent;
    for (const auto &x : edges[cur])
        if (x.first != parent)
        {
            make_tree(x.first, cur, edges);
            nodes[cur].size += nodes[x.first].size;
            nodes[x.first].len = x.second;
        }
}

static inline double choose3(double x)
{
    return x * (x - 1) * (x - 2) / 6.0;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vector<pii> > edges(N);
    vector<pii> roads(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        edges[a].emplace_back(b, l);
        edges[b].emplace_back(a, l);
        roads[i] = pii(a, b);
    }
    nodes.resize(N);
    make_tree(0, -1, edges);

    double ex = 0.0;
    double total = choose3(N);
    for (int i = 1; i < N; i++)
    {
        nodes[i].p = 2.0 * (1.0 - (choose3(nodes[i].size) + choose3(N - nodes[i].size)) / total);
        ex += nodes[i].p * nodes[i].len;
    }

    int Q;
    cin >> Q;
    cout << fixed << setprecision(12);
    for (int i = 0; i < Q; i++)
    {
        int r, w;
        cin >> r >> w;
        r--;
        int a = roads[r].first;
        if (nodes[a].parent != roads[r].second)
            a = roads[r].second;
        double diff = nodes[a].len - w;
        nodes[a].len = w;
        ex -= diff * nodes[a].p;
        cout << ex << '\n';
    }

    return 0;
}