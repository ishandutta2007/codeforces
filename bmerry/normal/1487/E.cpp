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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static void solve()
{
    vi a[4];
    int N[4];
    for (int i = 0; i < 4; i++)
        cin >> N[i];
    for (int i = 0; i < 4; i++)
    {
        a[i].resize(N[i]);
        for (int j = 0; j < N[i]; j++)
            cin >> a[i][j];
    }
    int E[3];
    set<pii> bad[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> E[i];
        for (int j = 0; j < E[i]; j++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            bad[i].insert(pii(x, y));
        }
    }

    for (int i = 2; i >= 0; i--)
    {
        vector<pii> byp(N[i + 1]);
        for (int j = 0; j < N[i + 1]; j++)
            byp[j] = pii(a[i + 1][j], j);
        sort(RA(byp));
        for (int j = 0; j < N[i]; j++)
        {
            int p = 0;
            while (p < N[i + 1] && bad[i].count(pii(j, byp[p].second)))
                p++;
            if (p == N[i + 1])
                a[i][j] = INT_MAX / 2;
            else
            {
                a[i][j] += byp[p].first;
                a[i][j] = min(a[i][j], INT_MAX / 2);
            }
        }
    }
    int ans = *min_element(RA(a[0]));
    if (ans >= INT_MAX / 2)
        ans = -1;
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}