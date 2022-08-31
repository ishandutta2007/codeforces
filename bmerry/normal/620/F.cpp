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

static int xform(unsigned int x)
{
    switch (x % 4)
    {
    case 0: return x;
    case 1: return 1;
    case 2: return x + 1;
    case 3: return 0;
    }
    assert(false);
}

struct query
{
    int L, R;
    int id;
};

struct node
{
    unique_ptr<node> ch[2];
    int lo = INT_MAX;
    int hi = -1;

    void add(int a, int v, int b);
};

void node::add(int a, int v, int b)
{
    lo = min(lo, a);
    hi = max(hi, a);
    if (b > 0)
    {
        b--;
        unique_ptr<node> &c = ch[(v >> b) & 1];
        if (!c)
            c = make_unique<node>();
        c->add(a, v, b);
    }
}

struct up_set
{
    unique_ptr<node> trie;

    up_set() : trie(make_unique<node>()) {}
    void add(int a);
    int query(int a) const;
};

void up_set::add(int a)
{
    int x = xform(a);
    trie->add(a, x, 20);
}

int up_set::query(int a) const
{
    int x = xform(a - 1);
    const node *cur = trie.get();
    if (cur->hi < a)
        return -1;

    int v = 0;
    for (int i = 19; i >= 0; i--)
    {
        int mask = 1 << i;
        int side;
        if (cur->ch[0] && cur->ch[0]->hi >= a && (x & mask))
            side = 0;
        else if (cur->ch[1] && cur->ch[1]->hi >= a && !(x & mask))
            side = 1;
        else if (cur->ch[0] && cur->ch[0]->hi >= a)
            side = 0;
        else
            side = 1;
        cur = cur->ch[side].get();
        v += side << i;
    }
    return v ^ x;
}

struct down_set
{
    unique_ptr<node> trie;

    down_set() : trie(make_unique<node>()) {}
    void add(int a);
    int query(int a) const;
};

void down_set::add(int a)
{
    int x = xform(a - 1);
    trie->add(a, x, 20);
}

int down_set::query(int a) const
{
    int x = xform(a);
    const node *cur = trie.get();
    if (cur->lo > a)
        return -1;

    int v = 0;
    for (int i = 19; i >= 0; i--)
    {
        int mask = 1 << i;
        int side;
        if (cur->ch[0] && cur->ch[0]->lo <= a && (x & mask))
            side = 0;
        else if (cur->ch[1] && cur->ch[1]->lo <= a && !(x & mask))
            side = 1;
        else if (cur->ch[0] && cur->ch[0]->lo <= a)
            side = 0;
        else
            side = 1;
        cur = cur->ch[side].get();
        v += side << i;
    }
    return v ^ x;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    int B = int(round(sqrt(double(N))));
    int NB = (N + B - 1) / B;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];


    vi ans(M);
    vector<vector<query>> queries(NB);
    for (int i = 0; i < M; i++)
    {
        query q;
        cin >> q.L >> q.R;
        q.L--;
        q.id = i;
        int block = q.L / B;
        queries[block].push_back(q);
    }

    for (int block = 0; block < NB; block++)
    {
        auto &qu = queries[block];
        sort(RA(qu), [](const query &a, const query &b) { return a.R < b.R; });
        int cut = (block + 1) * B;
        up_set upr;
        down_set downr;
        int base = -1;
        int qid = 0;
        while (qid < SZ(qu) && qu[qid].R <= cut)
        {
            int score = -1;
            up_set upl;
            down_set downl;
            for (int j = qu[qid].L; j < qu[qid].R; j++)
            {
                upl.add(a[j]);
                downl.add(a[j]);
                score = max(score, upl.query(a[j]));
                score = max(score, downl.query(a[j]));
            }
            ans[qu[qid].id] = score;
            qid++;
        }
        for (int i = cut; i < N; i++)
        {
            upr.add(a[i]);
            downr.add(a[i]);
            base = max(base, upr.query(a[i]));
            base = max(base, downr.query(a[i]));
            while (qid < SZ(qu) && qu[qid].R == i + 1)
            {
                int score = base;
                up_set upl;
                down_set downl;
                for (int j = cut - 1; j >= qu[qid].L; j--)
                {
                    upl.add(a[j]);
                    downl.add(a[j]);
                    score = max(score, upl.query(a[j]));
                    score = max(score, downl.query(a[j]));
                    score = max(score, upr.query(a[j]));
                    score = max(score, downr.query(a[j]));
                }
                ans[qu[qid].id] = score;
                qid++;
            }
        }
    }

    for (int i = 0; i < M; i++)
        cout << ans[i] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}