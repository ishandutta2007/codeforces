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

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419716939937510
#endif

static double dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static double cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static double cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, x, y;
    cin >> N >> x >> y;
    pnt P = pnt(x, y);
    vector<pnt> pnts;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        pnts.emplace_back(x, y);
    }
    double hi = 0.0;
    double lo = HUGE_VAL;
    for (int i = 0; i < N; i++)
    {
        double d = dot(pnts[i] - P, pnts[i] - P);
        lo = min(lo, d);
        hi = max(hi, d);
        const pnt &a = pnts[i];
        const pnt &b = pnts[i ? i - 1 : N - 1];
        double dd = dot(P - a, b - a);
        if (dd >= 0.0 && dd <= dot(b - a, b - a))
        {
            double c = fabs(cross(a, b, P));
            c = c * c / dot(b - a, b - a);
            lo = min(lo, c);
        }
    }
    double ans = (hi - lo) * M_PI;
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}