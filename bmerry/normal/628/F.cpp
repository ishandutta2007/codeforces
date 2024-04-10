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

[[noreturn]] static void unfair()
{
    cout << "unfair\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, B, Q;
    cin >> N >> B >> Q;
    vector<pii> hints;
    hints.emplace_back(0, 0);
    hints.emplace_back(B, N);
    for (int i = 0; i < Q; i++)
    {
        int u, q;
        cin >> u >> q;
        hints.emplace_back(u, q);
    }
    sort(RA(hints));
    for (int mask = 1; mask < 32; mask++)
    {
        int fit = 0;
        for (int i = 0; i < SZ(hints) - 1; i++)
        {
            int q = hints[i + 1].second - hints[i].second;
            int r = hints[i + 1].first - hints[i].first;
            if (q < 0 || q > r)
                unfair();

            int s = 0;
            for (int j = 0; j < 5; j++)
                if (mask & (1 << j))
                    s += (hints[i + 1].first + j) / 5 - (hints[i].first + j) / 5;
            fit += min(s, q);
        }
        if (fit < __builtin_popcount(mask) * N / 5)
            unfair();
    }
    cout << "fair\n";
    return 0;
}