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
    int parent;
    vector<int> ch;
    int heavy = 0;
    int hdist = 0;
    int depth;
    int size = 1;
    list<int> ndec;
    ll ans = 0;
};

static vector<node> nodes;

static void prepare(int cur, int depth)
{
    node &n = nodes[cur];
    n.depth = depth;
    int big = -1;
    int bigc = -1;
    for (int c : n.ch)
    {
        prepare(c, depth + 1);
        n.size += nodes[c].size;
        if (nodes[c].size > big)
        {
            bigc = c;
            big = nodes[c].size;
        }
    }
    n.heavy = bigc;
}

static void prepare_hdist(int cur)
{
    node &n = nodes[cur];
    if (n.parent != -1 && nodes[n.parent].heavy == cur)
        n.hdist = 1 + nodes[n.parent].hdist;
    for (int c : n.ch)
        prepare_hdist(c);
}

template<typename It>
static void push_down(int cur, It first, It last, ll mult)
{
    if (first == last)
        return;
    node &n = nodes[cur];
    n.ans += *first * mult;
    ++first;
    for (int c : n.ch)
        push_down(c, first, last, mult);
}

static void recurse(int cur)
{
    node &n = nodes[cur];
    n.ans += n.hdist + 1;
    if (!n.ch.empty())
    {
        recurse(n.heavy);
        n.ndec = move(nodes[n.heavy].ndec);
        n.ndec.push_front(0);
        list<int> newdec{1};
        for (int c : n.ch)
            if (c != n.heavy)
            {
                recurse(c);
                node &sub = nodes[c];
                auto ptr = next(newdec.begin());
                for (int value : sub.ndec)
                {
                    if (ptr == newdec.end())
                    {
                        newdec.push_back(value);
                        ptr = newdec.end();
                    }
                    else
                        *ptr++ += value;
                }
                sub.ndec.clear();
            }
        push_down(n.heavy, next(newdec.begin()), newdec.end(), n.hdist + 1);
        auto p = n.ndec.begin();
        for (auto value : newdec)
        {
            if (p == n.ndec.end())
            {
                n.ndec.push_back(value);
                p = n.ndec.end();
            }
            else
                *p++ += value;
        }
        for (int c : n.ch)
            if (c != n.heavy)
                push_down(c, next(n.ndec.begin()), n.ndec.end(), n.hdist + 1);
    }
    else
        n.ndec.push_back(1);
}

static void trickle(int cur)
{
    node &n = nodes[cur];
    if (n.parent != -1)
        n.ans += nodes[n.parent].ans;
    for (int c : n.ch)
        trickle(c);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    int root = -1;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        p--;
        nodes[i].parent = p;
        if (p >= 0)
            nodes[p].ch.push_back(i);
        else
            root = i;
    }

    prepare(root, 0);
    prepare_hdist(root);
    recurse(root);
    trickle(root);
    for (int i = 0; i < N; i++)
        cout << nodes[i].ans - nodes[i].depth - 1 << ' ';
    cout << '\n';

    return 0;
}