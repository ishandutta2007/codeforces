// WRONG

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
    int parent = -1;
    ll dv = 0;
    ll top = 0;
    ll bot = 0;
};

static vector<node> nodes;

static pair<int, ll> find(int x)
{
    if (nodes[x].parent < 0)
        return make_pair(x, 0LL);
    else
    {
        pair<int, ll> s = find(nodes[x].parent);
        s.second += nodes[x].dv;
        nodes[x].parent = s.first;
        nodes[x].dv = s.second;
        return s;
    }
}

static bool merge(int a, int b, ll dv)
{
    auto sa = find(a); dv -= sa.second;
    auto sb = find(b); dv += sb.second;

    a = sa.first;
    b = sb.first;
    if (a == b)
        return dv == 0;
    else
    {
        if (-nodes[a].parent > -nodes[b].parent)
        {
            swap(a, b);
            dv = -dv;
        }
        nodes[b].parent += nodes[a].parent;
        nodes[a].parent = b;
        nodes[a].dv = dv;
        nodes[b].top = max(nodes[b].top, nodes[a].top + dv);
        nodes[b].bot = min(nodes[b].bot, nodes[a].bot + dv);
        return true;
    }
}

static ll difference(int a, int b)
{
    auto sa = find(a);
    auto sb = find(b);
    if (sa.first != sb.first)
        return LLONG_MAX;
    else
        return sa.second - sb.second;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    nodes.resize(N);
    nodes[0].top = LLONG_MIN / 4;
    nodes[N - 1].bot = LLONG_MAX / 4;
    ll maxgap = 0;
    for (int i = 0; i < M; i++)
    {
        int f, t;
        ll w, b;
        cin >> f >> t >> w >> b;
        f--;
        t--;
        ll dv = w * b;
        bool bad = false;
        if (!merge(f, t, dv))
            bad = true;
        else
        {
            auto s0 = find(0);
            if (nodes[s0.first].top >= s0.second)
                bad = true;
            auto s1 = find(N - 1);
            if (nodes[s1.first].bot <= s1.second)
                bad = true;

            int x = find(t).first;
            maxgap = max(maxgap, nodes[x].top - nodes[x].bot);
            if (maxgap >= difference(0, N - 1))
                bad = true;
        }

        if (bad)
        {
            cout << "BAD " << i + 1 << '\n';
            return 0;
        }
    }

    ll dv = difference(0, N - 1);
    if (dv == LLONG_MAX)
        cout << "UNKNOWN\n";
    else
        cout << dv << '\n';
    return 0;
}