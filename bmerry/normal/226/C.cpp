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

static ll finda(ll L, ll R, ll K)
{
    ll besta = 0;
    L--;
    for (ll a = 1; a <= 1000000; a++)
        if (R / a - L / a >= K)
            besta = a;
    for (ll p = K; p <= 1000000; p++)
    {
        ll a = R / p;
        if (a > besta && R / a - L / a >= K)
            besta = a;
    }
    return besta;
}

static void fibm(ll id, ll &a, ll &b, ll m)
{
    if (id == 0)
    {
        a = 0;
        b = 1 % m;
    }
    else if (id & 1)
    {
        ll p, q;
        fibm(id - 1, p, q, m);
        a = q;
        b = (p + q) % m;
    }
    else
    {
        ll p, q;
        fibm(id / 2, p, q, m);
        a = (p * (2 * q - p)) % m;
        b = (q * q + p * p) % m;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll M, L, R, K;
    cin >> M >> L >> R >> K;
    ll a = finda(L, R, K);
    ll p, q;
    fibm(a, p, q, M);
    if (p < 0) p += M;
    cout << p << '\n';
    return 0;
}