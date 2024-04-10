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

#define MOD 1000000000

struct node
{
    ll fs[2]; // a + b + ..., a + 2b + ...
    ll eval(int base) const;
    ll eval_range(int nid, int A, int B, int l, int r, int base) const;

    node() { fs[0] = fs[1] = 0; }
};

static vector<ll> fib;
static int Z;
static vector<node> nodes;

ll node::eval(int base) const
{
    if (base < 2)
        return fs[base];
    else
        return (fib[base - 2] * fs[0] + fib[base - 1] * fs[1]) % MOD;
}

ll node::eval_range(int nid, int A, int B, int l, int r, int base) const
{
    l = max(l, A);
    r = min(r, B);
    if (l >= r)
        return 0;
    if (l == A && r == B)
        return eval(base);
    else
    {
        int lc = 2 * nid;
        int rc = lc + 1;
        int M = (A + B) / 2;
        return (nodes[lc].eval_range(lc, A, M, l, r, base)
            + nodes[rc].eval_range(rc, M, B, l, r, base + M - A)) % MOD;
    }
}

static void fix1(int nid, int A, int B)
{
    if (B - A == 1)
        return;
    int M = (A + B) / 2;
    int l = nid * 2;
    int r = l + 1;
    nodes[nid].fs[0] = (nodes[l].fs[0] + nodes[r].eval(M - A)) % MOD;
    nodes[nid].fs[1] = (nodes[l].fs[1] + nodes[r].eval(M - A + 1)) % MOD;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M;
    cin >> N >> M;

    Z = 1;
    while (Z < N)
        Z *= 2;
    nodes.resize(2 * Z);

    fib.resize(2 * Z + 1);
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 2 * Z; i++)
        fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;

    for (int i = 0; i < N; i++)
    {
        cin >> nodes[Z + i].fs[0];
        nodes[Z + i].fs[1] = nodes[Z + i].fs[0];
    }

    for (int i = 0; (Z >> i) > 0; i++)
    {
        int start = Z >> i;
        int step = Z / start;
        for (int a = 0; a < start; a++)
            fix1(start + a, a * step, (a + 1) * step);
    }

    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            {
                int x, v;
                cin >> x >> v;
                x--;
                nodes[Z + x].fs[0] = nodes[Z + x].fs[1] = v;
                for (int i = 0; (Z >> i) > 0; i++)
                {
                    int start = Z >> i;
                    int step = Z / start;
                    int l = x >> i;
                    fix1(start + l, l * step, (l + 1) * step);
                }
            }
            break;
        case 2:
            {
                int l, r;
                cin >> l >> r;
                l--;
                ll ans = nodes[1].eval_range(1, 0, Z, l, r, -l);
                cout << ans << '\n';
            }
            break;
        }
    }

    return 0;
}