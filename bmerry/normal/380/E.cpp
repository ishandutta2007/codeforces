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

struct num
{
    int pos;
    int val;

    bool operator<(const num &b) const
    {
        return val > b.val;
    }
};

struct node
{
    double sum;
    double scale;
};

static constexpr int bias = 1 << 19;
static node lr[2 * bias];
static node rl[2 * bias];

static node combine(const node &a, const node &b)
{
    node out;
    out.scale = a.scale * b.scale;
    out.sum = a.sum + b.sum * a.scale;
    return out;
}

static inline void fix(node *nodes, int idx)
{
    nodes[idx] = combine(nodes[2 * idx], nodes[2 * idx + 1]);
}

static void add_hit(node *nodes, int idx)
{
    nodes[idx].sum = 0.5;
    nodes[idx].scale = 0.5;
    for (idx >>= 1; idx > 0; idx >>= 1)
        fix(nodes, idx);
}

static node compute_range(const node *nodes, int L, int R)
{
    if (L == R)
        return {0.0, 1.0};

    node ans = compute_range(nodes, (L + 1) >> 1, R >> 1);
    if (L & 1)
        ans = combine(nodes[L], ans);
    if (R & 1)
        ans = combine(ans, nodes[R - 1]);
    return ans;
}

static void init_nodes(node *nodes, int N)
{
    for (int i = 0; i < N; i++)
    {
        nodes[i + bias].sum = 1.0;
        nodes[i + bias].scale = 1.0;
    }
    for (int i = bias - 1; i > 0; i--)
        fix(nodes, i);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<num> nums(N);
    for (int i = 0; i < N; i++)
    {
        nums[i].pos = i;
        cin >> nums[i].val;
    }
    sort(RA(nums));

    double ans = 0.0;
    init_nodes(lr, N);
    init_nodes(rl, N);
    for (const num &n : nums)
    {
        node L = compute_range(lr, n.pos + bias, N + bias);
        node R = compute_range(rl, N - 1 - n.pos + bias, N + bias);
        ans += n.val * L.sum * R.sum;
        add_hit(lr, n.pos + bias);
        add_hit(rl, N - 1 - n.pos + bias);
    }

    ans = ans * 0.5 / (double(N) * N);
    cout << setprecision(15) << fixed << ans << '\n';

    return 0;
}