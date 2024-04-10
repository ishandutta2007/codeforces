#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    ios::sync_with_stdio(false);
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
    vector<int> edges;
    vector<int> children;
    int size;
    int color;
    ll ans;
};

struct state
{
    map<int, int> freq;
    vector<ll> fsum;

    void add(int color, int reps)
    {
        int &c = freq[color];
        int old = c;
        c += reps;
        if (SZ(fsum) <= c)
            fsum.resize(c + 1);
        fsum[old] -= color;
        fsum[c] += color;
    }

    void merge(const state &b)
    {
        for (const auto &f : b.freq)
            add(f.first, f.second);
    }

    ll ans() const
    {
        return fsum.back();
    }
};

static vector<node> nodes;

static void make_tree(int root, int parent)
{
    node &n = nodes[root];
    n.size = 1;
    for (int e : n.edges)
        if (e != parent)
        {
            n.children.push_back(e);
            make_tree(e, root);
            n.size += nodes[e].size;
        }
    int big = -1;
    int big_size = -1;
    for (int i = 0; i < SZ(n.children); i++)
    {
        int csize = nodes[n.children[i]].size;
        if (csize > big_size)
        {
            big_size = csize;
            big = i;
        }
    }
    if (big_size != -1)
        swap(n.children[0], n.children[big]);
}

static state solve(int root)
{
    state st;
    node &n = nodes[root];
    if (!n.children.empty())
    {
        st = solve(n.children[0]);
        for (int i = 1; i < SZ(n.children); i++)
            st.merge(solve(n.children[i]));
    }
    st.add(n.color, 1);
    n.ans = st.ans();
    return st;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nodes[i].color;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        nodes[x].edges.push_back(y);
        nodes[y].edges.push_back(x);
    }
    make_tree(0, -1);
    solve(0);
    for (int i = 0; i < N - 1; i++)
        cout << nodes[i].ans << ' ';
    cout << nodes[N - 1].ans << '\n';

    return 0;
}