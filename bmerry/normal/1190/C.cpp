//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
    int N, K;
    string s;
    cin >> N >> K >> s;
    vi a(N + 1);
    vector<array<int, 2>> next(N + 1);
    for (int i = 1; i <= N; i++)
        a[i] = a[i - 1] + (s[i - 1] - '0');
    next[N][0] = next[N][1] = N;
    for (int i = N - 1; i >= 0; i--)
    {
        next[i] = next[i + 1];
        next[i][s[i] - '0'] = i;
    }

    auto solid = [&](int x, int y, int b) -> bool
    {
        return a[y] - a[x] == b * (y - x);
    };

    auto flippable = [&](int x, int y, int b) -> int
    {
        if (solid(x, y, b))
            return 0;
        int start = next[x][!b];
        int stop = min(start + K, y);
        if (solid(x, start, b) && solid(stop, y, b))
            return 1;
        return 2;
    };

    bool draw = false;
    for (int i = 0; i + K <= N; i++)
        for (int b = 0; b < 2; b++)
        {
            int f = flippable(0, i, b) + flippable(i + K, N, b);
            if (f == 0)
            {
                cout << "tokitsukaze\n";
                return 0;
            }
            else if (f != 1)
                draw = true;
        }
    cout << (draw ? "once again\n" : "quailty\n");

    return 0;
}