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
    int rc = 1;
    int size = 1;
    node *parent = nullptr;
};

static node pool_storage[262144];
static vector<node *> pool;

static void free_node(node *n)
{
    pool.push_back(n);
}

static node *alloc_node()
{
    node *n = pool.back();
    pool.pop_back();
    *n = node();
    return n;
}

static void decref(node *n)
{
    if (!n)
        return;
    n->rc--;
    if (n->rc == 0)
    {
        node *p = n->parent;
        free_node(n);
        decref(p);
    }
}

static node *find(node *x)
{
    assert(x);
    while (x->parent)
        x = x->parent;
    return x;
}

static node *merge(node *x, node *y)
{
    x = find(x);
    y = find(y);
    assert(x != y);
    if (x->size > y->size)
        swap(x, y);
    y->size += x->size;
    x->parent = y;
    y->rc += 2;    // 1 for x->parent, one for the caller
    return y;
}

static void solve()
{
    int R, C;
    cin >> R >> C;

    pool.resize(size(pool_storage));
    for (node *n = begin(pool_storage); n != end(pool_storage); ++n)
        pool.push_back(n);

    vector<node *> base(C);
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        string line;
        cin >> line;
        vector<bool> bits(C);
        for (int j = 0; j < C; j += 4)
        {
            int v;
            char c = line[j / 4];
            if (c <= '9')
                v = c - '0';
            else
                v = c - 'A' + 10;
            assert(0 <= v && v <= 15);
            for (int k = 0; k < 4; k++)
            {
                bits[j + k] = (v >> 3) & 1;
                v <<= 1;
            }
        }

        for (int j = 0; j < C; j++)
        {
            if (bits[j])
            {
                node *nb = alloc_node();
                new (nb) node;
                ans++;
                if (base[j])
                {
                    node *p = merge(nb, base[j]);
                    ans--;
                    decref(nb);
                    nb = p;
                }
                if (j > 0 && base[j - 1])
                {
                    node *a = find(base[j - 1]);
                    if (a != nb)
                    {
                        node *p = merge(nb, a);
                        ans--;
                        decref(nb);
                        nb = p;
                    }
                }
                decref(base[j]);
                base[j] = nb;
            }
            else
            {
                decref(base[j]);
                base[j] = nullptr;
            }
        }
    }

    for (node *x : base)
        decref(x);
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}