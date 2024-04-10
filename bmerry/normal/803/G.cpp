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

static int N;
static int bmin;
static vector<vector<int>> blow;

static int bquery(int p, int q)
{
    int L = q - p;
    if (L <= 0)
        return INT_MAX;
    int lvl = 0;
    while ((2 << lvl) <= L)
        lvl++;
    return min(blow[lvl][p], blow[lvl][q - (1 << lvl)]);
}

struct node
{
    bool is_b;
    int idx[2];
    int cval;
    int low;
    std::unique_ptr<node> ch[2];

    int rmq(int p, int q) const
    {
        p = max(p, idx[0]);
        q = min(q, idx[1]);
        if (p >= q)
            return INT_MAX;
        else if (p == idx[0] && q == idx[1])
            return low;
        else if (ch[0])
            return min(ch[0]->rmq(p, q), ch[1]->rmq(p, q));
        else if (!is_b)
            return cval;
        else if (q - p >= N)
            return bmin;
        else
        {
            int r0 = p / N;
            int r1 = q / N;
            if (r0 == r1)
                return bquery(p % N, q % N);
            else
            {
                int pmin = bquery(p % N, N);
                int qmin = bquery(0, q % N);
                return min(pmin, qmin);
            }
        }
    }

    void split()
    {
        assert(!ch[0] && !ch[1]);
        assert(idx[1] - idx[0] > 1);
        int mid = (idx[0] + idx[1]) / 2;
        int lmin = rmq(idx[0], mid);
        int rmin = rmq(mid, idx[1]);
        ch[0].reset(new node);
        ch[0]->is_b = is_b;
        ch[0]->idx[0] = idx[0];
        ch[0]->idx[1] = mid;
        ch[0]->cval = cval;
        ch[0]->low = lmin;
        ch[1].reset(new node);
        ch[1]->is_b = is_b;
        ch[1]->idx[0] = mid;
        ch[1]->idx[1] = idx[1];
        ch[1]->cval = cval;
        ch[1]->low = rmin;
    }

    void set_const(int p, int q, int val)
    {
        p = max(p, idx[0]);
        q = min(q, idx[1]);
        if (p >= q)
            return;
        if (p == idx[0] && q == idx[1])
        {
            is_b = false;
            cval = val;
            low = val;
            ch[0].reset();
            ch[1].reset();
        }
        else
        {
            if (!ch[0])
                split();
            ch[0]->set_const(p, q, val);
            ch[1]->set_const(p, q, val);
            low = min(ch[0]->low, ch[1]->low);
        }
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K;
    cin >> N >> K;
    blow.emplace_back(N);
    for (int i = 0; i < N; i++)
        cin >> blow[0][i];
    for (int lvl = 1; (1 << lvl) <= N; lvl++)
    {
        int h = 1 << (lvl - 1);
        blow.emplace_back(N - h);
        for (int i = 0; i < N - h; i++)
            blow[lvl][i] = min(blow[lvl - 1][i], blow[lvl - 1][i + h]);
    }
    bmin = bquery(0, N);

    unique_ptr<node> root(new node);
    root->is_b = true;
    root->idx[0] = 0;
    root->idx[1] = N * K;
    root->cval = -1;
    root->low = bmin;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        int t;
        cin >> t >> l >> r;
        l--;
        if (t == 1)
        {
            int x;
            cin >> x;
            root->set_const(l, r, x);
        }
        else
        {
            cout << root->rmq(l, r) << '\n';
        }
    }

    return 0;
}