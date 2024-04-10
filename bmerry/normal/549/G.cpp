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
    int N;
    cin >> N;
    vector<pii> g;
    for (int i = N - 1; i >= 0; i--)
    {
        int v;
        cin >> v;
        g.emplace_back(v - i, i);
    }
    sort(RA(g), greater<pii>());
    for (int i = 1; i < N; i++)
        if (g[i - 1].first == g[i].first)
        {
            cout << ":(\n";
            return 0;
        }

    vi ans(N);
    for (int i = 0; i < N; i++)
    {
        int v = g[i].first + g[i].second;
        int delta = i - g[i].second;
        ans[i] = v + delta;
        if (ans[i] < 0)
        {
            cout << ":(\n";
            return 0;
        }
    }
    cout << ans[N - 1];
    for (int i = N - 2; i >= 0; i--)
        cout << ' ' << ans[i];
    cout << '\n';

    return 0;
}