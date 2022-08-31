#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
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

static double cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static vector<pnt> clip(const vector<pnt> &poly, const pnt &p, const pnt &q)
{
    pnt d = q - p;
    vector<pnt> out;
    for (size_t i = 0; i < poly.size(); i++)
    {
        size_t j = (i == poly.size() - 1) ? 0 : i + 1;
        pnt pi = poly[i];
        pnt pj = poly[j];
        double ic = cross(d, pi - p);
        double jc = cross(d, pj - p);
        bool iins = ic > 0.0;
        bool jins = jc > 0.0;
        if (iins)
            out.push_back(pi);
        if (iins != jins)
        {
            pnt mid = (pi * jc - pj * ic) / (jc - ic);
            out.push_back(mid);
        }
    }
    return out;
}

static double area(const vector<pnt> &poly)
{
    if (poly.size() < 3)
        return 0.0;
    double area = cross(poly.back(), poly[0]);
    for (size_t i = 1; i < poly.size(); i++)
        area += cross(poly[i - 1], poly[i]);
    return area * 0.5;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    vector<vi> pieces(N, vi(K + 1));
    cout << fixed << setprecision(12);
    for (int i = 0; i < N; i++)
    {
        double ans = 0.0;
        for (int j = 0; j <= K; j++)
            cin >> pieces[i][j];
        const vi &pi = pieces[i];
        for (int j = 0; j < K; j++)
        {
            vector<pnt> poly{
                pnt(j, 0.0),
                pnt(j + 1, 0.0),
                pnt(j + 1, pi[j + 1]),
                pnt(j, pi[j])
            };
            for (int k = 0; k < i; k++)
                poly = clip(poly, pnt(j, pieces[k][j]), pnt(j + 1, pieces[k][j + 1]));
            ans += area(poly);
        }
        cout << ans << '\n';
    }

    return 0;
}