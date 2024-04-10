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
    int N;
    ll T;
    cin >> N >> T;
    vll a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vi delta(N + 1);
    vi x(N);
    vector<bool> good(N), bad(N + 1);
    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;
        e--;
        x[i] = e;
        if (e < i)
        {
            cout << "No\n";
            return 0;
        }
        delta[i + 1]++;
        delta[e + 1]--;
        bad[e + 1] = true;
    }

    int lvl = 0;
    for (int i = 0; i < N; i++)
    {
        lvl += delta[i];
        good[i] = lvl;
    }

    for (int i = 1; i < N; i++)
    {
        if (i > 1 && a[i] - 1 == b[i - 2])
            good[i] = true;
        if (good[i] && bad[i])
        {
            cout << "No\n";
            return 0;
        }
        if (!good[i])
            b[i - 1] = a[i] - 1;
        else
            b[i - 1] = a[i];
    }
    b[N - 1] = a[N - 1] + 1;
    cout << "Yes\n";
    for (int i = 0; i < N; i++)
        cout << b[i] + T << ' ';
    cout << endl;

    return 0;
}