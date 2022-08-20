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

static long double choose[601][601];
static long double ratios[301 * 301];

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i <= 600; i++)
    {
        choose[i][0] = choose[i][i] = 1.0;
        for (int j = 1; j < i; j++)
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
    ratios[0] = 1.0;
    for (int i = 1; i <= N * N; i++)
        ratios[i] = ratios[i - 1] * (K - i + 1) / (M - i + 1);

    long double ans = 0.0;
    for (int p = 0; p <= N; p++)
        for (int q = 0; q <= N; q++)
        {
            int G = p * N + q * N - p * q;
            if (G <= K)
            {
                long double prob = choose[N][p] * choose[N][q];
                prob *= ratios[G];
                ans += prob;
            }
        }

    if (ans > 1e99)
        ans = 1e99;
    cout << setprecision(12) << ans << '\n';

    return 0;
}