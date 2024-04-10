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
    int add = 0;
};

static list<unique_ptr<node>> storage;

static node *alloc_node()
{
    storage.push_back(make_unique<node>());
    return storage.back().get();
}

static int query(const node *root, int A, int B, int p)
{
    assert(A <= p && p < B);
    int ans = root->add;
    if (B - A > 1)
    {
        int M = (A + B) / 2;
        if (p < M)
            ans += query(root->ch[0], A, M, p);
        else
            ans += query(root->ch[1], M, B, p);
    }
    return ans;
}

static const node *incr(const node *root, int A, int B, int L, int R, int add)
{
    if (L >= B || R <= A)
        return root;
    node *n = alloc_node();
    *n = *root;
    if (L <= A && R >= B)
        n->add += add;
    else
    {
        int M = (A + B) / 2;
        n->ch[0] = incr(n->ch[0], A, M, L, R, add);
        n->ch[1] = incr(n->ch[1], M, B, L, R, add);
    }
    return n;
}

static const node *init(int A, int B)
{
    node *n = alloc_node();
    if (B - A > 1)
    {
        int M = (A + B) / 2;
        n->ch[0] = init(A, M);
        n->ch[1] = init(M, B);
    }
    return n;
}

static void solve()
{
    int N, K;
    cin >> N >> K;
    vector<vi> pos(100001);
    vector<const node *> history;
    history.push_back(init(0, N));
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        int L = (SZ(pos[a]) < K) ? 0 : pos[a][SZ(pos[a]) - K] + 1;
        const node *new_root = incr(history.back(), 0, N, L, i + 1, 1);
        history.push_back(new_root);
        pos[a].push_back(i);
    }

    int Q;
    cin >> Q;
    int last = 0;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        int L = (x + last) % N + 1;
        int R = (y + last) % N + 1;
        if (L > R)
            swap(L, R);
        L--;
        last = query(history[R], 0, N, L);
        cout << last << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}