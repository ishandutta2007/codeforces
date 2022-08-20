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

namespace
{

struct node
{
    int leaves;
    vi edges;
    int make_leaves();
    int recurse(int phase);
};

static vector<node> nodes;

int node::make_leaves()
{
    leaves = edges.empty();
    for (int c : edges)
        leaves += nodes[c].make_leaves();
    return leaves;
}

int node::recurse(int phase)
{
    int ans = 0;
    if (edges.empty())
        ans = 0;
    else if (phase == 0)
    {
        for (int c : edges)
        {
            int sub = nodes[c].recurse(!phase);
            sub += leaves - nodes[c].leaves;
            ans = max(ans, sub);
        }
    }
    else
    {
        for (int c : edges)
            ans += nodes[c].recurse(!phase);
    }
    return ans;
}

} // anonymous

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
    }
    nodes[0].make_leaves();
    int upper = nodes[0].recurse(0);
    int lower = nodes[0].recurse(1);
    cout << upper + 1 << ' ' << nodes[0].leaves - lower << '\n';

    return 0;
}