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

struct vertex
{
    int depth;
    int anc[20];

    vertex() : depth(-1)
    {
        fill(RA(anc), -1);
    }
};

static int up(const vector<vertex> &vertices, int a, int k)
{
    int i = 0;
    while ((1 << i) <= k)
        i++;
    for (i--; i >= 0; i--)
        if (k & (1 << i))
            a = vertices[a].anc[i];
    return a;
}

static int lca(const vector<vertex> &vertices, int a, int b)
{
    if (vertices[a].depth > vertices[b].depth)
        a = up(vertices, a, vertices[a].depth - vertices[b].depth);
    else
        b = up(vertices, b, vertices[b].depth - vertices[a].depth);

    for (int i = 19; i >= 0; i--)
        if (vertices[a].anc[i] != vertices[b].anc[i])
        {
            a = vertices[a].anc[i];
            b = vertices[b].anc[i];
        }
    while (a != b)
    {
        a = vertices[a].anc[0];
        b = vertices[b].anc[0];
    }
    return a;
}

static int dist(const vector<vertex> &vertices, int a, int b)
{
    int l = lca(vertices, a, b);
    return vertices[a].depth + vertices[b].depth - 2 * vertices[l].depth;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int Q;
    cin >> Q;
    vector<vertex> vertices;
    vertices.reserve(Q + 4);
    vertices.resize(4);

    vertices[0].depth = 0;
    for (int i = 1; i < 4; i++)
    {
        vertices[i].depth = 1;
        vertices[i].anc[0] = 0;
    }
    int ends[2] = {1, 2};
    int diam = 2;

    for (int q = 0; q < Q; q++)
    {
        int p;
        cin >> p;
        p--;
        int n = vertices.size();
        vertices.emplace_back();
        vertices.emplace_back();
        for (int i = n; i < n + 2; i++)
        {
            vertices[i].depth = vertices[p].depth + 1;
            vertices[i].anc[0] = p;
            for (int j = 1; j < 20; j++)
            {
                int m = vertices[i].anc[j - 1];
                vertices[i].anc[j] = m >= 0 ? vertices[m].anc[j - 1] : -1;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int d = dist(vertices, ends[i], n);
            if (d > diam)
            {
                diam = d;
                ends[1 - i] = n;
            }
        }
        cout << diam << '\n';
    }

    return 0;
}