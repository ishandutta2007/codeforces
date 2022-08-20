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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

struct event
{
    ll t;
    int wp;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll c, d;
    cin >> N >> c >> d;
    ll crit = d / c;
    vector<event> events(N + 1);
    for (int i = 0; i < N; i++)
    {
        char wp;
        cin >> events[i].t >> wp;
        events[i].wp = (wp == 'P');
    }
    cin >> events[N].t;
    events[N].wp = -1;
    ll ans = d * N;

    int last[2] = {N, N};
    ll save[2] = {0, 0};
    ll dp[2] = {0, 0};
    for (int i = N - 1; i >= 0; i--)
    {
        int wp = events[i].wp;
        int next = last[!wp];
        ll gap = events[next].t - events[i].t;
        ll cost = dp[!wp] + c * gap + d * (next - i - 1) - save[!wp];
        dp[wp] = cost;
        ans = min(ans, cost + d * i);
        if (gap <= crit)
            save[!wp] += d - c * gap;
        save[wp] = 0;
        last[wp] = i;
    }
    cout << ans << '\n';

    return 0;
}