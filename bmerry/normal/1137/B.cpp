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
    string s, t;
    cin >> s >> t;

    int cs[2];
    cs[0] = count(RA(s), '0');
    cs[1] = SZ(s) - cs[0];
    int ct[2];
    ct[0] = count(RA(t), '0');
    ct[1] = SZ(t) - ct[0];

    int L = SZ(t);
    vi fail(L + 1);
    fail[0] = -1;
    for (int i = 1; i <= L; i++)
    {
        char c = t[i - 1];
        int f = fail[i - 1];
        while (f >= 0 && t[f] != c)
            f = fail[f];
        fail[i] = f + 1;
    }
    int period = L - fail[L];
    int cp[2];
    cp[0] = count(t.begin(), t.begin() + period, '0');
    cp[1] = period - cp[0];

    if (ct[0] > cs[0] || ct[1] > cs[1])
    {
        cout << s << '\n';
        return 0;
    }
    string out = t;
    string rep(t.end() - period, t.end());
    int c[2] = {ct[0], ct[1]};
    while (c[0] + cp[0] <= cs[0] && c[1] + cp[1] <= cs[1])
    {
        c[0] += cp[0];
        c[1] += cp[1];
        out += rep;
    }
    out += string(cs[0] - c[0], '0');
    out += string(cs[1] - c[1], '1');
    cout << out << '\n';

    return 0;
}