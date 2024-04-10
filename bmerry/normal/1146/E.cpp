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

static void up(set<int> &pf, int x, int ph)
{
    while (!pf.empty() && *pf.rbegin() >= x)
        pf.erase(prev(pf.end()));
    if (SZ(pf) % 2 == ph)
        pf.insert(pf.end(), x);
}

static void down(set<int> &pf, int x)
{
    auto pos = pf.find(x);
    if (pos != pf.end())
        pf.erase(pos);
    else
        pf.insert(x);
}

static void down(set<int> &pf, int x1, int x2)
{
    down(pf, x1);
    down(pf, x2);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    set<int> pf, nf;
    for (int i = 0; i < Q; i++)
    {
        char s;
        int x;
        cin >> s >> x;
        if (s == '>' && x >= 0)
        {
            up(pf, x + 1, 0);
            up(nf, x + 1, 1);
        }
        else if (s == '<' && x < 0)
        {
            up(nf, -x + 1, 0);
            up(pf, -x + 1, 1);
        }
        else if (s == '>')
        {
            down(nf, 0, -x);
            down(pf, 0, -x);
            up(pf, -x, 0);
            up(nf, -x, 1);
        }
        else
        {
            down(pf, 0, x);
            down(nf, 0, x);
            up(nf, x, 0);
            up(pf, x, 1);
        }
    }

    vi pfv(RA(pf)), nfv(RA(nf));
    for (int v : a)
    {
        int f = 0;
        if (v >= 0)
            f = upper_bound(RA(pfv), v) - pfv.begin();
        else
            f = upper_bound(RA(nfv), -v) - nfv.begin();
        if (f & 1)
            v = -v;
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}