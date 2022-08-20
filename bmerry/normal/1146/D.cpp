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

struct pqitem
{
    int pos;
    int prio;

    bool operator<(const pqitem &other) const { return prio > other.prio; }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int m, a, b;
    cin >> m >> a >> b;
    int g = gcd(a, b);
    int r = a + b;
    vector<int> prio(r + 1, INT_MAX / 2);
    prio[0] = 0;
    priority_queue<pqitem> q;
    q.push(pqitem{0, 0});
    while (!q.empty())
    {
        int x = q.top().pos;
        int p = q.top().prio;
        q.pop();
        if (p != prio[x])
            continue;
        if (x >= b && p < prio[x - b])
        {
            prio[x - b] = p;
            q.push(pqitem{x - b, p});
        }
        int p2 = max(x + a, p);
        if (x + a <= r && p2 < prio[x + a])
        {
            prio[x + a] = p2;
            q.push(pqitem{x + a, p2});
        }
    }

    ll ans = 0;
    for (int i = 0; i <= r; i++)
    {
        if (prio[i] <= m)
            ans += m - prio[i] + 1;
    }
    int u = r / g * g + g;
    if (u <= m)
    {
        int v = m / g * g;
        int k = (v - u) / g + 1;
        //for (int i = u; i <= v; i += g)
        //    ans += m - i + 1;
        ans += ll((m - u + 1) + (m - v + 1)) * k / 2;
    }
    cout << ans << '\n';

    return 0;
}