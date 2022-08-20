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

static double dst(const pii &a, const pii &b)
{
    return hypot(a.first - b.first, a.second - b.second);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    set<pii> pnts;
    pnts.insert(pii(0, 0));
    if (M >= 1)
        pnts.insert(pii(0, 1));
    if (N >= 1)
        pnts.insert(pii(1, 0));
    pnts.insert(pii(N, M));
    if (M > 0)
        pnts.insert(pii(N, M - 1));
    if (N > 0)
        pnts.insert(pii(N - 1, M));
    pnts.insert(pii(N, 0));
    pnts.insert(pii(0, M));

    vector<pii> v(RA(pnts));
    sort(RA(v));
    double best = 0.0;
    array<pii, 4> best_pnts;
    do
    {
        double d = 0.0;
        for (int i = 0; i < 3; i++)
            d += dst(v[i], v[i + 1]);
        if (d >= best)
        {
            for (int i = 0; i < 4; i++)
                best_pnts[i] = v[i];
            best = d;
        }
    } while (next_permutation(RA(v)));

    for (int i = 0; i < 4; i++)
        cout << best_pnts[i].first << ' ' << best_pnts[i].second << '\n';
    return 0;
}