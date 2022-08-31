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

struct node
{
    const node *ch[2] = {nullptr, nullptr};
    ll val = 0;

    const node *add(int L, int R, int A, int B, ll v) const;
    ll query(int L, int R, int A) const;
};

static vector<unique_ptr<node>> node_pool;

static node *alloc_node()
{
    node_pool.push_back(make_unique<node>());
    return node_pool.back().get();
}

const node *node::add(int L, int R, int A, int B, ll v) const
{
    if (B <= L || A >= R)
        return this;

    node *n = alloc_node();
    *n = *this;
    if (A <= L && B >= R)
        n->val += v;
    else
    {
        int M = (L + R) / 2;
        n->ch[0] = ch[0]->add(L, M, A, B, v);
        n->ch[1] = ch[1]->add(M, R, A, B, v);
    }
    return n;
}

ll node::query(int L, int R, int A) const
{
    assert(A >= L && A < R);
    if (R - L == 1)
        return val;
    else
    {
        int M = (L + R) / 2;
        if (A >= M)
            return val + ch[1]->query(M, R, A);
        else
            return val + ch[0]->query(L, M, A);
    }
}

static const node *make_tree(int L, int R)
{
    node *n = alloc_node();
    if (R - L > 1)
    {
        int M = (L + R) / 2;
        n->ch[0] = make_tree(L, M);
        n->ch[1] = make_tree(M, R);
    }
    return n;
}

static void solve()
{
    constexpr int MAXX = 200003;
    const node *lin = make_tree(0, MAXX);
    const node *con = make_tree(0, MAXX);
    vector<pair<const node *, const node *>> history;
    history.emplace_back(lin, con);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x1, x2;
        ll a, b, y1, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        con = con->add(0, MAXX, 0, x1 + 1, y1);
        con = con->add(0, MAXX, x1 + 1, x2 + 1, b);
        con = con->add(0, MAXX, x2 + 1, MAXX, y2);
        lin = lin->add(0, MAXX, x1 + 1, x2 + 1, a);
        history.emplace_back(lin, con);
    }

    ll last = 0;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        x = (x + last) % 1000000000;
        x = min(x, ll(MAXX) - 1);
        ll clin = history[r].first->query(0, MAXX, x) - history[l].first->query(0, MAXX, x);
        ll ccon = history[r].second->query(0, MAXX, x) - history[l].second->query(0, MAXX, x);
        ll v = clin * x + ccon;
        cout << v << '\n';
        last = v;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}