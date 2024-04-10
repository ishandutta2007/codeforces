// TOO SLOW: O(n log n)

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
    char c = 0;
    unique_ptr<node> child, sib;
    node *fail = nullptr;
    int present = 0;
    int hits = 0;

    node *find(char c) const
    {
        for (node *n = child.get(); n; n = n->sib.get())
            if (n->c == c)
                return n;
        return nullptr;
    }

    node *force(char c)
    {
        node *n = find(c);
        if (n == nullptr)
        {
            unique_ptr<node> nn = make_unique<node>();
            n = nn.get();
            nn->c = c;
            nn->sib = move(child);
            child = move(nn);
        }
        return n;
    }
};

struct group
{
    unique_ptr<node> root;
    list<string> strings;

    void rebuild()
    {
        root = make_unique<node>();
        for (const string &s : strings)
        {
            node *cur = root.get();
            for (char c : s)
                cur = cur->force(c);
            cur->present++;
        }
        queue<node *> q;
        q.push(root.get());
        while (!q.empty())
        {
            node *cur = q.front();
            q.pop();
            for (node *n = cur->child.get(); n; n = n->sib.get())
            {
                node *nxt;
                node *f = cur->fail;
                while (f && (nxt = f->find(n->c)) == nullptr)
                    f = f->fail;
                if (f == nullptr)
                    nxt = root.get();
                n->fail = nxt;
                n->hits = nxt->hits + n->present;
                q.push(n);
            }
        }
    }
};

struct collection
{
    std::vector<group> groups;

    void add(const string &s)
    {
        int k = 0;
        while (k < SZ(groups) && groups[k].root)
            k++;
        group g;
        g.strings.push_back(s);
        for (int i = 0; i < k; i++)
        {
            g.strings.splice(g.strings.begin(), groups[i].strings);
            groups[i].root.reset();
        }
        g.rebuild();
        if (SZ(groups) <= k)
            groups.push_back(move(g));
        else
            groups[k] = move(g);
    }

    ll count(const string &s) const
    {
        ll ans = 0;
        for (const group &g : groups)
        {
            if (!g.root)
                continue;
            node *cur = g.root.get();
            for (char c : s)
            {
                node *fwd = nullptr;
                while (cur != nullptr && (fwd = cur->find(c)) == nullptr)
                    cur = cur->fail;
                if (cur == nullptr)
                    cur = g.root.get();
                else
                    cur = fwd;
                ans += cur->hits;
            }
        }
        return ans;
    }
};

static void solve()
{
    int N;
    cin >> N;
    collection added, removed;
    for (int i = 0; i < N; i++)
    {
        int t;
        string s;
        cin >> t >> s;
        if (t == 1)
            added.add(s);
        else if (t == 2)
            removed.add(s);
        else
        {
            ll ans = added.count(s) - removed.count(s);
            cout << ans << endl;
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}