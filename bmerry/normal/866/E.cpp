// TOO SLOW

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
    string deltas;
    cin >> deltas;
    int S = SZ(deltas);
    vi delta(S);
    for (int i = 0; i < S; i++)
        delta[i] = (deltas[i] >= 'a') ? deltas[i] - 'a' + 10 : deltas[i] - '0';
    reverse(RA(delta));

    ll ans = LLONG_MAX;
    for (int carry = 0; carry < (1 << (S - 1)); carry++)
    {
        vi d(S);
        vll dp(1 << S, LLONG_MAX);
        for (int i = 0; i < S; i++)
        {
            d[i] = delta[i] - ((carry >> i) & 1) * 16;
            if (i > 0)
                d[i] += (carry >> (i - 1)) & 1;
            if (d[i] <= -16 || d[i] >= 16)
                goto bad;
        }
        if (accumulate(RA(d), 0) != 0)
            goto bad;

        dp[0] = 0;
        for (int mask = 1; mask < (1 << S); mask++)
        {
            ll sum = 0;
            for (int i = 0; i < S; i++)
                if (mask & (1 << i))
                    sum += d[i];
            if (sum < 0 || sum >= 16)
                continue;
            for (int i = 0; i < S; i++)
                if (mask & (1 << i))
                {
                    ll prev = dp[mask ^ (1 << i)];
                    if (prev != LLONG_MAX)
                    {
                        ll add = (sum - d[i]) << (4 * i);
                        dp[mask] = min(dp[mask], prev + add);
                    }
                }
        }
        ans = min(ans, dp.back());

bad:;
    }
    if (ans < LLONG_MAX / 4)
        cout << setw(S) << setfill('0') << hex << ans << '\n';
    else
        cout << "NO\n";

    return 0;
}