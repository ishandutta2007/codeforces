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

static ll ccw(const pii &a, const pii &b, const pii &c)
{
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    ll dx2 = c.first - a.first;
    ll dy2 = c.second - a.second;
    return dx1 * dy2 - dx2 * dy1;
}

struct key
{
    pii pos;
    mutable pii npos;

    key(const pii &pos) : pos(pos), npos(pos) {}
    key(const pii &pos, const pii &npos) : pos(pos), npos(npos) {}

    bool operator<(const key &other) const
    {
        return pos < other.pos;
    }

    bool operator<(ll q) const
    {
        ll dx = npos.first - pos.first;
        ll dy = npos.second - pos.second;
        return dy > -q * dx;
    }
};

struct node
{
    set<key, std::less<>> hull;

    void insert(const pii &p)
    {
        auto [ptr, added] = hull.emplace(p);
        if (!added)
            return;
        decltype(ptr) ptr1, ptr2;
        if (ptr != hull.begin() && (ptr1 = next(ptr)) != hull.end()
            && ccw(prev(ptr)->pos, p, ptr1->pos) >= 0)
        {
            hull.erase(ptr);
            return;
        }
        while ((ptr1 = next(ptr)) != hull.end() && (ptr2 = next(ptr1)) != hull.end()
               && ccw(p, ptr1->pos, ptr2->pos) >= 0)
            hull.erase(ptr1);
        while (ptr != hull.begin() && (ptr1 = prev(ptr)) != hull.begin()
               && ccw(prev(ptr1)->pos, ptr1->pos, p) >= 0)
            hull.erase(ptr1);

        if ((ptr1 = next(ptr)) != hull.end())
            ptr->npos = ptr1->pos;
        if (ptr != hull.begin())
            prev(ptr)->npos = p;
    }

    ll query(ll q) const
    {
        if (hull.empty())
            return LLONG_MIN;
        auto ptr = hull.lower_bound(q);
        return ptr->pos.first * q + ptr->pos.second;
    }
};

struct query
{
    int t;
    int a = -1, b = -1;
};

static void solve()
{
    int N;
    cin >> N;
    vector<query> queries(N);
    set<int> live;
    for (int i = 0; i < N; i++)
    {
        cin >> queries[i].t;
        if (queries[i].t == 1)
        {
            cin >> queries[i].a >> queries[i].b;
            live.insert(i);
        }
        else
        {
            cin >> queries[i].a;
            if (queries[i].t == 2)
            {
                queries[i].a--;
                live.erase(queries[i].a);
            }
        }
    }

    int offset = 1;
    while (offset < N)
        offset *= 2;
    vector<node> nodes(2 * offset);

    auto add = [&](int L)
    {
        pii v(queries[L].a, queries[L].b);
        int pos = offset + L;
        while (pos > 0)
        {
            nodes[pos].insert(v);
            pos >>= 1;
        }
    };

    vll ans;
    for (int L : live)
        add(L);
    for (int i = N - 1; i >= 0; i--)
    {
        if (queries[i].t == 2)
        {
            int L = queries[i].a;
            add(L);
        }
        else if (queries[i].t == 3)
        {
            ll q = queries[i].a;
            ll best = LLONG_MIN;
            int pos = offset + i;
            while (pos > 1)
            {
                if (pos & 1)
                    best = max(best, nodes[pos - 1].query(q));
                pos >>= 1;
            }
            ans.push_back(best);
        }
    }

    reverse(RA(ans));
    for (ll a : ans)
    {
        if (a == LLONG_MIN)
            cout << "EMPTY SET\n";
        else
            cout << a << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}