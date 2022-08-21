// WRONG ANSWER

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

static double cross(const pnt &a, const pnt &b) { return imag(conj(a) * b); }

static bool good(const pnt &a, const pnt &b, double r)
{
    // cerr << fabs(cross(a, b)) / abs(b - a) << '\n';
    return fabs(cross(a, b)) > r * abs(b - a);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    double y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    if (y1 > y2)
        swap(y1, y2);
    yw -= r;

    y1 = 2 * yw - y1; y1 -= 1e-8;
    y2 = 2 * yw - y2; y2 += 1e-8;

    double L = y2;
    double R = y1 - r;
    if (!good(pnt(xb, yb - y2), pnt(0, R - y2), r))
    {
        cout << "-1\n";
        return 0 ;
    }
    for (int pass = 0; pass < 100; pass++)
    {
        double y = (L + R) / 2;
        if (good(pnt(xb, yb - y2), pnt(0, y - y2), r))
            R = y;
        else
            L = y;
    }
    double y = R;

    double xw = xb * (y - yw) / (y - yb);
    cout << fixed;
    cout.precision(19);
    cout << xw + 1e-8 << '\n';

    return 0;
}