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

struct edge
{
    int trg;
    int label;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> edges(N);
    vector<int> d(N);
    for (int i = 0; i < N; i++)
        cin >> d[i];
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(edge{v, i + 1});
        edges[v].push_back(edge{u, i + 1});
    }

    int odd = count(RA(d), 1);
    if (odd & 1)
    {
        auto any = find(RA(d), -1);
        if (any == d.end())
        {
            cout << "-1\n";
            return 0;
        }
        *any = 1;
        odd++;
    }
    for (int &deg : d)
        if (deg == -1)
            deg = 0;

    queue<int> q;
    vector<int> parent(N, -2);
    vector<int> plabel(N);
    parent[0] = -1;
    plabel[0] = -1;
    q.push(0);
    vector<int> order;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (const edge &e : edges[cur])
        {
            if (parent[e.trg] == -2)
            {
                parent[e.trg] = cur;
                plabel[e.trg] = e.label;
                q.push(e.trg);
            }
        }
    }

    vector<int> use;
    for (int ii = N - 1; ii >= 0; ii--)
    {
        int i = order[ii];
        if (d[i] == 1)
        {
            use.push_back(plabel[i]);
            d[parent[i]] ^= 1;
        }
    }
    sort(RA(use));
    cout << SZ(use) << '\n';
    for (int u : use)
        cout << u << '\n';

    return 0;
}