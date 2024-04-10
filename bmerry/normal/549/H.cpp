// WRONG ANSWER

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

static pair<double, double> ranged(double a, double d, double r)
{
    double opts[4] = {(a + r) * (d + r), (a - r) * (d + r), (a + r) * (d - r), (a - r) * (d - r)};
    return {*min_element(opts, opts + 4), *max_element(opts, opts + 4)};
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    double vals[4];
    cin >> vals[0] >> vals[1] >> vals[2] >> vals[3];
    double lo = 0.0;
    double hi = 0.0;
    for (int i = 0; i < 4; i++)
        hi = max(hi, fabs(vals[i]));
    for (int i = 0; i < 1000; i++)
    {
        double mid = (lo + hi) * 0.5;
        pair<double, double> r1 = ranged(vals[0], vals[3], mid);
        pair<double, double> r2 = ranged(vals[1], vals[2], mid);
        if (r1.second < r2.first || r2.second < r1.first)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(10) << lo << '\n';
    return 0;
}