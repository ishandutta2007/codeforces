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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<double> P{1.0};
    int score = 0;
    double scale = 1.0 / (M - 1);
    for (int i = 0; i < N; i++)
    {
        int r;
        cin >> r;
        r--;
        score += r;
        vector<double> Q(SZ(P) + 1);
        partial_sum(RA(P), Q.begin() + 1);
        vector<double> P2(SZ(P) + M - 1);
        for (int j = 0; j < SZ(P2); j++)
        {
            int A = max(0, j - M + 1);
            int B = min(SZ(Q) - 1, j + 1);
            P2[j] = Q[B] - Q[A];
            if (j - r >= 0 && j - r < SZ(P))
                P2[j] -= P[j - r];
        }
        P = move(P2);
        for (double &x : P)
            x *= scale;
    }
    double p = accumulate(P.begin(), P.begin() + score, 0.0);
    double ans = p * (M - 1) + 1;
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}