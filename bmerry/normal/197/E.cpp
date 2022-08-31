#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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

static ll cross(const pnt &a, const pnt &b) { return imag(conj(a) * b); }
static ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

struct node
{
    int parent;
    vi edges;
    int size;
    int pntid;

    node() : parent(-1), size(0), pntid(-1) {}
};

static void prepare(vector<node> &nodes, int cur, int parent)
{
    node &n = nodes[cur];
    n.parent = parent;
    n.size = 1;
    for (int i = 0; i < SZ(n.edges); i++)
    {
        int y = n.edges[i];
        if (y != parent)
        {
            prepare(nodes, y, cur);
            n.size += nodes[y].size;
        }
    }
}

struct compareYX
{
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }

    bool operator()(const pair<pnt, int> &a, const pair<pnt, int> &b) const
    {
        return (*this)(a.first, b.first);
    }
};

struct compareAngle
{
    pnt base;

    compareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        return cross(base, a, b) > 0;
    }

    bool operator()(const pair<pnt, int> &a, const pair<pnt, int> &b) const
    {
        return (*this)(a.first, b.first);
    }
};

typedef vector<pair<pnt, int> > pntvec;

static void place(vector<node> &nodes, int cur, pntvec::iterator first, pntvec::iterator last)
{
    node &n = nodes[cur];
    assert(last - first == n.size);
    pntvec::iterator lo = min_element(first, last, compareYX());
    swap(*first, *lo);

    n.pntid = first->second;

    sort(first + 1, last, compareAngle(first->first));
    first++;
    for (int i = 0; i < SZ(n.edges); i++)
    {
        int y = n.edges[i];
        if (y != n.parent)
        {
            place(nodes, y, first, first + nodes[y].size);
            first += nodes[y].size;
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<node> nodes(N);
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        nodes[u].edges.push_back(v);
        nodes[v].edges.push_back(u);
    }
    prepare(nodes, 0, -1);

    vector<pair<pnt, int> > pnts;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts.push_back(make_pair(pnt(x, y), i));
    }

    place(nodes, 0, pnts.begin(), pnts.end());
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++)
        ans[nodes[i].pntid] = i + 1;

    cout << ans[0];
    for (int i = 1; i < N; i++)
        cout << ' ' << ans[i];
    cout << '\n';

    return 0;
}