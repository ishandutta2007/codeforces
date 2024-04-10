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

struct edge
{
    int trg;
    int idx;
};

struct node
{
    int id = -1;
    int parent = -1;
    int pedge = -1;  // edge idx
    int top;
    vector<edge> edges;
};

static void recurse1(vector<node> &nodes, int x, int &pool)
{
    node &n = nodes[x];
    n.id = pool++;
    n.top = n.id;
    for (const edge &e : n.edges)
        if (e.trg != n.parent)
        {
            node &t = nodes[e.trg];
            if (t.id == -1)
            {
                t.parent = x;
                t.pedge = e.idx;
                recurse1(nodes, e.trg, pool);
                n.top = min(n.top, t.top);
            }
            else
            {
                n.top = min(n.top, t.id);
            }
        }
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<node> nodes(N);
    vector<int> id(N, -1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(edge{v, i});
        nodes[v].edges.push_back(edge{u, i});
    }

    int pool = 0;
    for (int i = 0; i < N; i++)
        if (nodes[i].id == -1)
            recurse1(nodes, i, pool);

    vi ans;
    for (int i = 0; i < N; i++)
        if (nodes[i].parent != -1 && nodes[i].top == nodes[nodes[i].parent].id)
        {
            vi edges{nodes[i].pedge};
            vi path{nodes[i].parent, i};
            int cur = i;
            while (cur != -1)
            {
                const node &n = nodes[cur];
                int nxt = -1;
                int up = -1;
                for (const edge &e : n.edges)
                    if (nodes[e.trg].parent == cur)
                    {
                        if (nodes[e.trg].top < nodes[cur].id)
                        {
                            if (nodes[e.trg].top != nodes[i].top || nxt != -1)
                                goto bad;
                            nxt = e.trg;
                        }
                    }
                    else if (e.trg != n.parent && nodes[e.trg].id < nodes[cur].id)
                    {
                        // up edge
                        if (e.trg != nodes[i].parent)
                            goto bad;
                        up = e.idx;
                    }
                if (nxt != -1 && up != -1)
                    goto bad;
                if (nxt == -1 && nodes[cur].top != nodes[i].top)
                    goto bad;
                if (nxt != -1)
                {
                    path.push_back(nxt);
                    edges.push_back(nodes[nxt].pedge);
                }
                else
                    edges.push_back(up);
                cur = nxt;
            }

            copy(RA(edges), back_inserter(ans));
bad:;
        }

    sort(RA(ans));
    cout << SZ(ans) << '\n';
    for (int idx : ans)
        cout << idx + 1 << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}