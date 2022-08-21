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

struct Gripper
{
    ll d, r;
    int m, p;
    bool used;

    bool operator<(const Gripper &g) const
    {
        return d < g.d;
    }
};

struct ComparePtr
{
    bool operator()(Gripper *a, Gripper *b) const
    {
        return a->m > b->m;
    }
};

struct Tree
{
    ll lo, hi;
    Tree *left;
    Tree *right;
    vector<Gripper *> items;
};

void extract(Tree *cur, ll d, int m, vector<Gripper *> &out)
{
    if (cur == NULL)
        return;
    if (d < cur->lo)
        return;
    if (d >= cur->hi)
    {
        while (!cur->items.empty() && cur->items.back()->m <= m)
        {
            Gripper *g = cur->items.back();
            if (!g->used)
            {
                out.push_back(g);
                g->used = true;
            }
            cur->items.pop_back();
        }
    }
    else
    {
        extract(cur->left, d, m, out);
        extract(cur->right, d, m, out);
    }
}

Tree *make_tree(Gripper *first, Gripper *last)
{
    int n = last - first;
    if (n == 0)
        return NULL;
    Tree *t = new Tree;
    t->items.reserve(n);
    for (int i = 0; i < n; i++)
        t->items.push_back(first + i);
    sort(RA(t->items), ComparePtr());

    if (n >= 2)
    {
        int m = n / 2;
        t->left = make_tree(first, first + m);
        t->right = make_tree(first + m, last);
    }
    t->lo = first->d;
    t->hi = (last - 1)->d;
    return t;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    ll x, y, r;
    int p, N;
    cin >> x >> y >> p >> r >> N;
    r *= r;
    vector<Gripper> g(N);
    for (int i = 0; i < N; i++)
    {
        ll xi, yi, r;
        int m, p;
        cin >> xi >> yi >> m >> p >> r;
        g[i].d = (xi - x) * (xi - x) + (yi - y) * (yi - y);
        g[i].r = r * r;
        g[i].m = m;
        g[i].p = p;
        g[i].used = false;
    }
    sort(RA(g));
    Tree *t = make_tree(&g[0], &g[N]);

    int ans = 0;
    vector<Gripper *> out;
    extract(t, r, p, out);
    while (ans < (int) out.size())
    {
        extract(t, out[ans]->r, out[ans]->p, out);
        ans++;
    }
    cout << ans << '\n';

    return 0;
}