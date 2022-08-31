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

static vector<int> path;

static void recurse(const vector<vector<int>> &edges, vector<bool> &seen, int cur)
{
    seen[cur] = true;
    path.push_back(cur);
    for (int y : edges[cur])
    {
        if (!seen[y])
        {
            recurse(edges, seen, y);
            path.push_back(cur);
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<bool> seen(N);
    recurse(edges, seen, 0);
    int limit = (2 * N + K - 1) / K;
    int start = 0;
    for (int i = 0; i < K; i++)
    {
        start = min(start, SZ(path) - 1);
        int stop = min(start + limit, SZ(path));
        cout << stop - start;
        for (int j = start; j < stop; j++)
            cout << ' ' << path[j] + 1;
        cout << '\n';
        start = stop;
    }

    return 0;
}