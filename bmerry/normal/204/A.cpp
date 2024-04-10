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

static ll solve(ll top)
{
    ll p10 = 1;
    ll ans = 0;
    for (int d = 1; d <= 18; d++)
    {
        for (int f = 1; f < 10; f++)
        {
            ll x = p10 * f / 10;
            if (f > top) break;
            ll y = (top - f) / 10;
            y = min(y, (p10 * (f + 1) - 1) / 10);
            if (x <= y)
                ans += y - x + 1;
        }

        p10 *= 10;
        if (p10 >= top)
            break;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll l, r;
    cin >> l >> r;
    ll ans = solve(r) - solve(l - 1);
    cout << ans << endl;
    return 0;
}