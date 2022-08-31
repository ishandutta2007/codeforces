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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static constexpr int ALPHA = 14;

struct node
{
    char c = '\0';
    node *children[ALPHA] = {};
    node *advanced[ALPHA] = {};
    node *fail = nullptr;
    ll cost = 0;

    node *get(char c) const;
    node *create(char c);
    node *advance(char c);
};

static vector<node> nodes;
static node *root;

node *node::get(char c) const
{
    //assert('a' <= c && c <= 'n');
    return children[c - 'a'];
}

node *node::create(char c)
{
    node *s = get(c);
    if (s == nullptr)
    {
        nodes.emplace_back();
        s = &nodes.back();
        s->c = c;
        children[c - 'a'] = s;
    }
    return s;
}

node *node::advance(char c)
{
    node *&ans = advanced[c - 'a'];
    if (ans)
        return ans;
    node *p = this;
    node *q;
    while (p && !(q = p->get(c)))
        p = p->fail;
    if (p == nullptr)
        return ans = root;
    else
        return ans = q;
}

struct transition
{
    node *trg;
    ll cost;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    nodes.reserve(2000);
    nodes.emplace_back();
    root = &nodes[0];

    int K;
    cin >> K;
    vs t(K);
    for (int i = 0; i < K; i++)
    {
        ll cost;
        cin >> t[i] >> cost;
        node *cur = root;
        for (char c : t[i])
            cur = cur->create(c);
        cur->cost += cost;
    }
    string S;
    cin >> S;

    vi qs{-1};
    for (int i = 0; i < SZ(S); i++)
        if (S[i] == '?')
            qs.push_back(i);
    qs.push_back(SZ(S));

    vector<node *> lvl{root};
    while (!lvl.empty())
    {
        vector<node *> lvl2;
        for (node *old : lvl)
            for (node *p : old->children)
            {
                if (!p)
                    continue;
                lvl2.push_back(p);
                node *f = old->fail;
                while (f && !f->get(p->c))
                    f = f->fail;
                p->fail = f ? f->get(p->c) : root;
                p->cost += p->fail->cost;
            }
        lvl = move(lvl2);
    }

    vector<vector<transition>> trans(SZ(qs) - 1, vector<transition>(SZ(nodes)));
    for (int i = 0; i < SZ(qs) - 1; i++)
    {
        for (int j = 0; j < SZ(nodes); j++)
        {
            node *cur = &nodes[j];
            ll cost = 0;
            for (int k = qs[i] + 1; k < qs[i + 1]; k++)
            {
                cur = cur->advance(S[k]);
                cost += cur->cost;
            }
            trans[i][j] = transition{cur, cost};
        }
        cerr << '.' << flush;
    }
    cerr << '\n';

    vector<vector<ll>> dp(1 << ALPHA, vector<ll>(SZ(nodes), LLONG_MIN / 2));
    dp[0][0] = 0;
    for (int i = 0; i < SZ(qs) - 1; i++)
    {
        vector<vector<ll>> dp2(1 << ALPHA, vector<ll>(SZ(nodes), LLONG_MIN / 2));
        for (int mask = 0; mask < (1 << ALPHA); mask++)
            if (__builtin_popcount(mask) == max(0, i - 1))
                for (int nxt = 0; nxt < ALPHA; nxt++)
                    if (!(mask & (1 << nxt)))
                        for (int state = 0; state < SZ(nodes); state++)
                        {
                            ll cost = dp[mask][state];
                            if (cost <= LLONG_MIN / 2)
                                continue;
                            node *cur = &nodes[state];
                            int nmask = mask;
                            if (i > 0)
                            {
                                cur = cur->advance('a' + nxt);
                                cost += cur->cost;
                                nmask |= 1 << nxt;
                            }
                            const auto &t = trans[i][cur - &nodes[0]];
                            cur = t.trg;
                            cost += t.cost;
                            auto &d = dp2[nmask][cur - &nodes[0]];
                            d = max(d, cost);
                        }
        dp = move(dp2);
        cerr << '+' << flush;
    }
    cerr << '\n';

    ll ans = LLONG_MIN;
    for (int mask = 0; mask < (1 << ALPHA); mask++)
        ans = max(ans, *max_element(RA(dp[mask])));
    cout << ans << '\n';

    return 0;
}