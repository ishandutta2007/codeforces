// WORK IN PROGRESS

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
}

/*** TEMPLATE CODE ENDS HERE */

struct impossible {};

static constexpr int GOOD = -1;

struct node
{
    // Element 0 is for tree, element 1 is for tree without root
    // Value is
    // - nodal point count if tweight is odd
    // - 0/GOOD if tweight is even
    array<int, 2> dp;
    array<int, 2> idp;
    int size = 1;
    int parent = -1;
    vector<int> edges;
    int good_sub = 0;
    vector<int> special;
};

static vector<node> nodes;

static int combine(int a, int b)
{
    if (a == GOOD || b == GOOD)
        return a + b - GOOD;
    else
        return 0;
}

static int sum(int a, int b)
{
    if (a < 0)
        return min(a, b);
    else
        return a + b;
}

static array<int, 2> mini(const vector<array<int, 2>> &sdp, int good_sub)
{
    array<int, 2> out;
    if (sdp.empty())
    {
        out[0] = 1 + good_sub;
        out[1] = GOOD;
    }
    else
    {
        out[1] = GOOD;
        for (const auto &v : sdp)
            out[1] = combine(out[1], v[0]);
        out[0] = 0;
        for (int i = 0; i < SZ(sdp); i++)
        {
            int score = GOOD;
            for (int j = 0; j < SZ(sdp); j++)
                score = combine(score, sdp[j][i == j]);
            out[0] = sum(out[0], score);
        }
    }
    return out;
}

static void down(int root, int parent)
{
    node &n = nodes[root];
    n.parent = parent;
    n.dp[0] = 1;
    n.dp[1] = GOOD;
    vector<int> &special = n.special;
    int &good_sub = n.good_sub;
    for (int v : n.edges)
        if (v != parent)
        {
            down(v, root);
            n.size += nodes[v].size;
            if (nodes[v].dp[0] == GOOD)
                good_sub += nodes[v].dp[1];
            else
            {
                special.push_back(v);
                if (special.size() > 3)
                    throw impossible();
            }
        }

    vector<array<int, 2>> sdp;
    sdp.reserve(special.size());
    for (int v : special)
        sdp.push_back(nodes[v].dp);
    n.dp = mini(sdp, n.good_sub);
}

static void up(int root)
{
    const node &n = nodes[root];
    for (int v : n.edges)
        if (v != n.parent)
        {
            vector<array<int, 2>> sdp;
            for (int s : n.special)
                if (s != v)
                    sdp.push_back(nodes[s].dp);
            int good_sub = n.good_sub;
            if (nodes[v].dp[0] == GOOD)
                good_sub -= nodes[v].dp[1];
            if (n.parent != -1)
            {
                if (n.idp[0] == GOOD)
                    good_sub += n.idp[1];
                else
                    sdp.push_back(n.idp);
            }
            nodes[v].idp = mini(sdp, good_sub);
            up(v);
        }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }

    try
    {
        if (N & 1)
            throw impossible();
        down(0, -1);
        up(0);
    }
    catch (impossible)
    {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < N; i++)
    {
        const node &n = nodes[i];
        if (n.size & 1)
            ans += (ll) n.dp[0] * n.idp[0];
        else if (n.dp[0] == GOOD && n.idp[0] == GOOD)
            ans += (ll) n.size * (N - n.size);
    }
    cout << ans << '\n';

    return 0;
}