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

static vector<ll> convolve(const vector<ll> &a, const vector<ll> &b)
{
    int M = SZ(a) + SZ(b) - 1;
    vector<ll> out(M);
    for (int i = 0; i < SZ(a); i++)
        for (int j = 0; j < SZ(b); j++)
            out[i + j] += a[i] * b[j];
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(RA(a));
    double choose = N * (N - 1) / 2;
    vector<ll> ways(5001);
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ways[a[j] - a[i]]++;

    vector<ll> half = convolve(ways, ways);
    reverse(RA(ways));
    vector<ll> full = convolve(half, ways);
    ll T = accumulate(full.begin(), full.begin() + 5000, 0LL);
    double ans = T / (choose * choose * choose);
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}