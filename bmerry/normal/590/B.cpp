// WRONG ANSWER. No idea why

#include <bits/stdc++.h>

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

static pnt read_ipnt()
{
    int x, y;
    cin >> x >> y;
    return pnt(x, y);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    pnt start = read_ipnt();
    pnt end = read_ipnt();
    pnt travel = end - start;
    double v, t;
    cin >> v >> t;
    pnt wind1 = read_ipnt();
    pnt wind2 = read_ipnt();
    double force_v = v - abs(wind2);
    double lo = 0.0;
    double hi = 1e18;
    for (int i = 0; i < 2000; i++)
    {
        double m = (lo + hi) * 0.5;
        double m1 = min(m, t);
        double m2 = m - m1;
        if (abs(travel - (wind1 * m1 + wind2 * m2)) < v * m)
            hi = m;
        else
            lo = m;
    }
    cout << fixed << setprecision(12) << lo << '\n';

    return 0;
}