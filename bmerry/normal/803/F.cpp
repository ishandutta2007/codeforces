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

static constexpr ll MOD = 1000000007;

static ll pmod(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return pmod(a, b - 1) * a % MOD;
    else
    {
        ll t = pmod(a, b / 2);
        return t * t % MOD;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    int M = 100000;
    vector<ll> freq(M + 1);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
    }
    vector<ll> seqs(M + 1);
    for (int i = M; i >= 1; i--)
    {
        ll mult = 0;
        ll sub = 0;
        for (int j = i; j <= M; j += i)
        {
            mult += freq[j];
            sub = (sub + seqs[j]) % MOD;
        }
        seqs[i] = (pmod(2, mult) - 1 - sub) % MOD;
    }
    ll ans = seqs[1];
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';

    return 0;
}