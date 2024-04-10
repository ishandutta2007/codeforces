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

struct node
{
    int v;
    int l, r;
};

static void recurse(vector<node> &nodes, int root, int lo, int hi, set<int> &match)
{
    if (root < 0 || hi < lo)
        return;
    const node &n = nodes[root];
    if (n.v >= lo && n.v <= hi)
        match.insert(n.v);
    recurse(nodes, n.l, lo, min(hi, n.v - 1), match);
    recurse(nodes, n.r, max(lo, n.v + 1), hi, match);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N;
    cin >> N;
    set<int> match;
    vector<node> nodes(N);
    ll root = N * (N - 1) / 2;
    for (int i = 0; i < N; i++)
    {
        int v, l, r;
        cin >> v >> l >> r;
        if (l > 0)
        {
            l--;
            root -= l;
        }
        if (r > 0)
        {
            r--;
            root -= r;
        }
        nodes[i].v = v;
        nodes[i].l = l;
        nodes[i].r = r;
    }
    recurse(nodes, root, 0, INT_MAX, match);
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += !match.count(nodes[i].v);
    cout << ans << '\n';

    return 0;
}