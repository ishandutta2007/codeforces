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

struct node
{
    char c = 0;
    unique_ptr<node> sib;
    unique_ptr<node> child;
    node *chain = nullptr;
    vector<node *> rchain;

    node *get_child(char ch, bool make = false)
    {
        unique_ptr<node> *cur = &child;
        while ((*cur) && (*cur)->c != ch)
            cur = &(*cur)->sib;
        if ((*cur) && (*cur)->c == ch)
            return (*cur).get();
        else if (make)
        {
            unique_ptr<node> n(new node);
            n->c = ch;
            *cur = move(n);
            return (*cur).get();
        }
        else
            return nullptr;
    }

    array<int, 2> count1()
    {
        array<int, 2> ans{0, 1};
        if (!c)
            ans[1] = 0;
        for (node *s : rchain)
        {
            auto sub = s->count1();
            ans[0] += max(sub[0], sub[1]);
            ans[1] += sub[0];
        }
        return ans;
    }

    int count()
    {
        int ans = 0;
        if (!chain)
        {
            auto sub = count1();
            ans = max(sub[0], sub[1]);
        }
        if (child)
            ans += child->count();
        if (sib)
            ans += sib->count();
        return ans;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N;
        cin >> N;
        vector<string> S(N);
        unique_ptr<node> root(new node);
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
            node *p = root.get();
            for (char c : S[i])
                p = p->get_child(c, true);
        }
        for (int i = 0; i < N; i++)
        {
            node *p = root.get();
            node *q = root->get_child(S[i][0], false);
            if (!q->chain)
            {
                q->chain = p;
                p->rchain.push_back(q);
            }
            for (int j = 1; j < SZ(S[i]); j++)
            {
                p = p->get_child(S[i][j], false);
                if (!p)
                    break;
                q = q->get_child(S[i][j], false);
                if (!q->chain)
                {
                    q->chain = p;
                    p->rchain.push_back(q);
                }
            }
        }
        int ans = root->count();
        cout << ans << '\n';
    }
    return 0;
}