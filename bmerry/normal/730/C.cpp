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
typedef vector<int> vi;
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

struct store
{
    ll stock;
    ll price;
};

struct qitem
{
    ll quant;
    ll price;
    bool operator<(const qitem &other) const
    {
        return price < other.price;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, W;
    cin >> N >> M;
    vector<vi> edges(N);
    vector<vector<store>> nodes(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    cin >> W;
    for (int i = 0; i < W; i++)
    {
        int c, k, p;
        cin >> c >> k >> p;
        c--;
        nodes[c].push_back(store{k, p});
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int g, R;
        ll A;
        cin >> g >> R >> A;
        g--;
        vector<bool> seen(N);
        vector<int> layer{g};
        seen[g] = true;
        priority_queue<qitem> cheap;
        int ncheap = 0;
        ll ccheap = 0;
        int depth = -1;
        while (!layer.empty() && (ncheap < R || ccheap > A))
        {
            depth++;
            vector<int> nlayer;
            for (int v : layer)
            {
                for (const store &s : nodes[v])
                {
                    cheap.push(qitem{s.stock, s.price});
                    ncheap += s.stock;
                    ccheap += s.stock * s.price;
                    while (ncheap > R)
                    {
                        qitem worst = cheap.top();
                        cheap.pop();
                        ll delta = min(worst.quant, (ll) ncheap - R);
                        worst.quant -= delta;
                        ncheap -= delta;
                        ccheap -= delta * worst.price;
                        if (worst.quant > 0)
                            cheap.push(worst);
                    }
                }
                for (int y : edges[v])
                    if (!seen[y])
                    {
                        nlayer.push_back(y);
                        seen[y] = true;
                    }
            }
            layer = move(nlayer);
        }
        if (ncheap >= R && ccheap <= A)
            cout << depth << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}