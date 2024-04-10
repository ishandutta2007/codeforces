// WRONG ANSWER

//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

static void no()
{
    cout << "-1\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll X, d;
    cin >> X >> d;
    vector<ll> a;
    a.push_back(1);
    X--;
    while (X > 0)
    {
        ll s = 0;
        while ((2LL << s) <= X)
            s++;
        s = min(s, SZ(a));
        ll t;
        if (s < SZ(a))
            t = a[SZ(a) - 1 - s] + d;
        else
            t = 0;
        t = max(t, a.back());
        if (t > 1000000000000000000LL)
            no();
        s = 0;
        while (s < SZ(a) && t - a[SZ(a) - 1 - s] < d)
            s++;
        a.push_back(t);
        X -= 1LL << s;
        if (SZ(a) > 10000)
            no();
    }
    cout << SZ(a) << '\n';
    for (ll v : a)
        cout << v << ' ';
    cout << '\n';

    return 0;
}