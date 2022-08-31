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
}

/*** TEMPLATE CODE ENDS HERE */

class SegmentTree
{
    struct node
    {
        ll add = 0;
        ll value = 0;
    };

    size_t offset;
    size_t N;
    mutable vector<node> nodes;

    void push_down(size_t idx)
    {
        if (idx < offset)
        {
            ll a = nodes[idx].add;
            nodes[2 * idx].add += a;
            nodes[2 * idx].value += a;
            nodes[2 * idx + 1].add += a;
            nodes[2 * idx + 1].value += a;
            nodes[idx].add = 0;
        }
    }

    void add(size_t cur, size_t L, size_t R, size_t A, size_t B, ll d)
    {
        if (A <= L && B >= R)
        {
            nodes[cur].add += d;
            nodes[cur].value += d;
        }
        else if (A < R && B > L)
        {
            size_t M = (L + R) / 2;
            push_down(cur);
            add(2 * cur, L, M, A, B, d);
            add(2 * cur + 1, M, R, A, B, d);
            nodes[cur].value = min(nodes[2 * cur].value, nodes[2 * cur + 1].value);
        }
    }

public:
    explicit SegmentTree(size_t N)
    {
        offset = 1;
        while (offset < N)
            offset *= 2;
        nodes.resize(2 * offset);
        add(N, offset, INT_MAX);
    }

    ll qmin() const
    {
        return nodes[1].value;
    }

    void add(size_t A, size_t B, ll d)
    {
        add(1, 0, offset, A, B, d);
    }
};

struct cross_t
{
    int x, y;
    ll z;

    bool operator<(const cross_t &other) const { return x < other.x; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> edges[2];
    edges[0].resize(N);
    edges[1].resize(N);
    for (int i = 0; i < N - 1; i++)
        cin >> edges[0][i] >> edges[1][i + 1];

    vector<cross_t> cross(M);
    for (int i = 0; i < M; i++)
    {
        cin >> cross[i].x >> cross[i].y >> cross[i].z;
        cross[i].x--;
    }
    sort(RA(cross));
    SegmentTree down(N);
    SegmentTree up(N);
    for (int i = 0; i < N; i++)
        down.add(i, i + 1, edges[1][i]);
    int ptr = 0;
    for (int i = 0; i < N; i++)
    {
        while (ptr < M && cross[ptr].x == i)
        {
            down.add(0, cross[ptr].y, cross[ptr].z);
            ptr++;
        }
        up.add(i, i + 1, edges[0][i] + down.qmin());
    }
    cout << up.qmin() << '\n';

    for (int i = 0; i < Q; i++)
    {
        ll v, w;
        cin >> v >> w;
        v--;
        up.add(v, v + 1, w - edges[0][v]);
        edges[0][v] = w;
        cout << up.qmin() << '\n';
    }

    return 0;
}