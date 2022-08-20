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

static double cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static double cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

static vector<pnt> clip(const vector<pnt> &poly, const pnt &p, const pnt &q)
{
    int N = poly.size();
    vector<pnt> out;
    for (int i1 = 0; i1 < N; i1++)
    {
        int i2 = (i1 + 1) % N;
        const pnt &v1 = poly[i1];
        const pnt &v2 = poly[i2];
        bool in1 = cross(p, q, v1) > 0;
        bool in2 = cross(p, q, v2) > 0;
        if (in1)
            out.push_back(v1);
        if (in1 != in2)
        {
            double d1 = cross(p, q, v1);
            double d2 = cross(p, q, v2);
            pnt cut = (d2 * v1 - d1 * v2) / (d2 - d1);
            out.push_back(cut);
        }
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    double w, h, a;
    cin >> w >> h >> a;
    a = a * M_PI / 180.0;
    pnt rot(cos(a), sin(a));

    vector<pnt> rect(4);
    rect[0] = pnt(w / 2, -h / 2);
    rect[1] = pnt(w / 2, h / 2);
    rect[2] = pnt(-w / 2, h / 2);
    rect[3] = pnt(-w / 2, -h / 2);
    vector<pnt> poly = rect;
    for (int i = 0; i < 4; i++)
    {
        poly = clip(poly, rect[i] * rot, rect[(i + 1) % 4] * rot);
    }
    double ans = 0.0;
    for (int i = 0; i < SZ(poly); i++)
        ans += cross(poly[i], poly[(i + 1) % SZ(poly)]);
    cout.precision(9);
    cout << fixed;
    cout << ans * 0.5 << '\n';
    return 0;
}