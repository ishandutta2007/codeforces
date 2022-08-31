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

static ll add(ll p, ll q)
{
    p += q;
    if (p > INT_MAX)
        return INT_MAX;
    else
        return p;
}

struct str
{
    bool sc;
    bool ea;
    int rep;
};

str operator+(const str &a, const str &b)
{
    str out;
    out.sc = a.sc;
    out.ea = b.ea;
    out.rep = add(a.rep, b.rep);
    if (a.ea && b.sc)
        out.rep = add(out.rep, 1);
    return out;
}

static int limit(int n, int mask)
{
    bool sc = mask & 1;
    bool ea = mask & 2;
    n -= sc + ea;
    if (n < 0)
        return -1;
    else
        return n / 2;
}

static string make_str(int n, int r, int mask)
{
    string out(n, 'B');
    int p = 0;
    if (mask & 1)
    {
        out[0] = 'C';
        p++;
    }
    if (mask & 2)
    {
        out[n - 1] = 'A';
    }
    for (int i = 0; i < r; i++)
    {
        out[p++] = 'A';
        out[p++] = 'C';
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll k, x, n, m;
    cin >> k >> x >> n >> m;
    for (int s1m = 0; s1m < 4; s1m++)
        for (int s2m = 0; s2m < 4; s2m++)
            for (int s1i = 0; s1i <= limit(n, s1m); s1i++)
                for (int s2i = 0; s2i <= limit(m, s2m); s2i++)
                {
                    str a = {bool(s1m & 1), bool(s1m & 2), s1i};
                    str b = {bool(s2m & 1), bool(s2m & 2), s2i};
                    for (int j = 3; j <= k; j++)
                    {
                        str tmp = b;
                        b = a + b;
                        a = tmp;
                    }
                    if (b.rep == x)
                    {
                        cout << make_str(n, s1i, s1m) << '\n';
                        cout << make_str(m, s2i, s2m) << '\n';
                        return 0;
                    }
                }
    cout << "Happy new year!\n";

    return 0;
}