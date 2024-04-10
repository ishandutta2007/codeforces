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

static ll cover1(ll x, ll y, ll t)
{
    if (x == 0 || y == 0)
        return 0;
    else if (t >= x + y - 1)
        return x * y;
    else
    {
        ll ans = t * (t + 1) / 2;
        if (t > x)
        {
            ll c = t - x;
            ans -= c * (c + 1) / 2;
        }
        if (t > y)
        {
            ll c = t - y;
            ans -= c * (c + 1) / 2;
        }
        return ans;
    }
}

static ll cover(ll N, ll x, ll y, ll t)
{
    return 1 + cover1(x, y - 1, t) + cover1(y, N - x, t)
        + cover1(N - x + 1, N - y, t) + cover1(N - y + 1, x - 1, t);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, x, y;
    ll C;
    cin >> N >> x >> y >> C;
    int lo = -1;
    int hi = 2 * N;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (cover(N, x, y, mid) >= C)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';

    return 0;
}