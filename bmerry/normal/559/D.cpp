#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
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

static ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static int next(int x, int N)
{
    if (++x == N)
        x = 0;
    return x;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N;
    cin >> N;
    vector<pnt> pnts;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts.emplace_back(x, y);
    }
    double den = 1.0 - ldexp(1.0, -N) * (N * (N - 1) / 2 + N + 1);
    double A = 0.0;
    for (int i = 0; i < N; i++)
    {
        int j = i;
        for (int d = 1; d < min(40LL, N - 1); d++)
        {
            j = next(j, N);
            double p = (ldexp(1.0, -1 - d) - ldexp(1.0, -N)) / den;
            double a = 0.5 * cross(pnts[i], pnts[j]);
            pnt delta = pnts[j] - pnts[i];
            ll b = gcd(llabs(delta.real()), llabs(delta.imag()));
            A += p * (a - 0.5 * b);
        }
    }
    cout << setprecision(9) << fixed << A + 1.0 << '\n';

    return 0;
}