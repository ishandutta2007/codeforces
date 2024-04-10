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
    int N;
    cin >> N;
    vll a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[i] -= i;
    }

    vi lisb(N + 1, INT_MIN);
    vi restore_idx(N);
    vll restore_val(N);
    for (int i = N - 1; i > 0; i--)
    {
        auto pos = upper_bound(RA(lisb), a[i], greater<int>());
        restore_idx[i] = pos - lisb.begin();
        restore_val[i] = *pos;
        *pos = a[i];
    }

    vi lis(N + 1, INT_MAX);
    lis[0] = INT_MIN;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto pos = upper_bound(RA(lis), a[i]);
        *pos = a[i];
        int L = pos - lis.begin();
        if (i + 1 < N)
            lisb[restore_idx[i + 1]] = restore_val[i + 1];
        pos = upper_bound(RA(lisb), a[i] - 1, greater<int>());
        int R = pos - lisb.begin();
        ans = max(ans, L + R);
    }

    int score = max(0, N - 1 - ans);
    cout << score << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}