#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

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

#define MOD 1000000007

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    string state;
    cin >> N >> state;
    string state2;
    for (char c : state)
        if (state2.empty() || c != state2.back())
            state2 += c;
    state = move(state2);
    int L = state.size();

    vector<int> prev(L);
    vector<int> byc(26, -1);
    for (int i = 0; i < L; i++)
    {
        prev[i] = byc[state[i] - 'a'];
        byc[state[i] - 'a'] = i;
    }

    vector<ll> dp(L);
    vector<ll> dps(L + 1);
    for (int j = 0; j < L; j++)
        if (prev[j] == -1)
            dp[j] = 1;
    for (int j = 0; j < L; j++)
        dps[j + 1] = (dps[j] + dp[j]) % MOD;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < L; j++)
            dp[j] = (dp[j] + dps[j] - dps[prev[j] + 1]) % MOD;
        for (int j = 0; j < L; j++)
            dps[j + 1] = (dps[j] + dp[j]) % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < L; i++)
        ans = (ans + dp[i]) % MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';

    return 0;
}