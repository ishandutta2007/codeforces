// WRONG ANSWER

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

static ll K;

static ll mod(ll x, ll m)
{
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

struct ntable
{
    vector<ll> values;
    vector<ll> flags;
    ll nonce = 1;
    bool negated = 0;
    ll bias = 0;

    explicit ntable(int size = 0) : values(size), flags(size) {}

    ll fix_idx(ll idx) const
    {
        idx -= bias;
        if (negated)
            idx = -idx;
        return mod(idx, K);
    }

    ll operator[](ll idx) const
    {
        idx = fix_idx(idx);
        if (flags[idx] == nonce)
            return values[idx];
        else
            return 0;
    }

    void put(ll idx)
    {
        idx = fix_idx(idx);
        if (flags[idx] == nonce)
            values[idx]++;
        else
            values[idx] = 1;
        flags[idx] = nonce;
    }

    void add_all(ll add)
    {
        bias = (bias + add) % K;
    }

    void negate_all()
    {
        negated = !negated;
        bias = -bias;
    }

    void reset()
    {
        nonce++;
        bias = 0;
        negated = false;
    }
};

static vector<ll> a;
static vector<ll> node_sum;
static vector<array<int, 2> > ch;

static ll get_node_sum(int root)
{
    return root == -1 ? 0 : node_sum[root];
}

static ll recurse(int root, int L, int R, ntable &table, int &l2r)
{
    table.reset();
    if (L == R)
    {
        table.put(0);
        return 0;
    }
    ll ans = 0;
    int sL[2] = {L, root + 1};
    int sR[2] = {root, R};
    int big = (root - L < R - root);
    ans += recurse(ch[root][!big], sL[!big], sR[!big], table, l2r);
    ans += recurse(ch[root][big], sL[big], sR[big], table, l2r);
    ll ns = a[root] + get_node_sum(ch[root][0]) + get_node_sum(ch[root][1]);
    node_sum[root] = ns;

    int A = big ? root - 1 : root + 1;
    int B = big ? L - 1 : R;
    int dir = big ? -1 : 1;
    ll sum = 0;
    if (l2r != big)
    {
        table.negate_all();
        table.add_all(get_node_sum(ch[root][big]));
        l2r = !l2r;
    }
    for (int i = A; i != B; i += dir)
    {
        ans += table[-sum];
        sum += a[i];
    }
    ans += table[-sum];

    table.negate_all();
    table.add_all(get_node_sum(ch[root][big]));
    l2r = !l2r;

    sum = a[root] + get_node_sum(ch[root][big]);
    table.put(sum);
    for (int i = A; i != B; i += dir)
    {
        sum += a[i];
        table.put(sum);
    }

    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N;
    cin >> N >> K;
    a.resize(N);
    ch.resize(N, array<int, 2>{{-1, -1}});
    node_sum.resize(N);
    stack<int> desc;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        while (!desc.empty() && a[i] > a[desc.top()])
        {
            int last = desc.top();
            desc.pop();
            if (!desc.empty() && a[i] > a[desc.top()])
                ch[desc.top()][1] = last;
            else
                ch[i][0] = last;
        }
        desc.push(i);
    }
    int root = -1;
    while (!desc.empty())
    {
        int last = desc.top();
        desc.pop();
        if (!desc.empty())
            ch[desc.top()][1] = last;
        else
            root = last;
    }

    ntable table(K);
    int l2r = 0;
    ll ans = recurse(root, 0, N, table, l2r) - N;
    cout << ans << '\n';
    return 0;
}