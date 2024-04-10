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

static double dot(const pnt &a, const pnt &b) { return real(conj(a) * b); }
static double cross(const pnt &a, const pnt &b) { return imag(conj(a) * b); }

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static double dist(pnt a, pnt b, double r)
{
    double ab = abs(b - a);
    if (ab < 1e-9)
        return ab;
    double mdist = abs(cross(a, b - a) / ab);
    if (mdist >= r)
        return ab;
    if (dot(-a, b - a) < 0.0 || dot(-b, a - b) < 0.0)
        return ab;

    double as = sqrt(dot(a, a) - r * r);
    double bs = sqrt(dot(b, b) - r * r);
    double aang = arg(pnt(r, as));
    double bang = arg(pnt(r, bs));

    double best = HUGE_VAL;
    double aa[2] = { arg(a) - aang, arg(a) + aang };
    double bb[2] = { arg(b) - bang, arg(b) + bang };
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            double d = aa[i] - bb[j];
            while (d < -M_PI)
                d += 2 * M_PI;
            while (d >= M_PI)
                d -= 2 * M_PI;
            best = min(best, abs(d));
        }
    return as + bs + best * r;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    double xp, yp, vp;
    double x, y, v, r;
    cin >> xp >> yp >> vp >> x >> y >> v >> r;
    pnt xy0(x, y);
    pnt xyp0(xp, yp);
    double rp = abs(xyp0);

    double L = 0.0;
    double R = 1e9;

    while (R - L > 1e-8)
    {
        double t = (L + R) * 0.5;
        pnt xyp = xyp0 * exp(pnt(0, vp / rp * t));
        double d = dist(xy0, xyp, r);
        if (d <= v * t)
            R = t;
        else
            L = t;
    }
    cout.precision(9);
    cout << L << '\n';

    return 0;
}