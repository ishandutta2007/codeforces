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

static vi sieve;

static std::vector<std::pair<ll, int>> factorise(ll n)
{
    std::vector<std::pair<ll, int>> out;
    while (n > 1)
    {
        int f = sieve[n];
        int r = 0;
        while (sieve[n] == f)
        {
            r++;
            n /= f;
        }
        out.emplace_back(f, r);
    }
    return out;
}

static void solve()
{
    int N;
    cin >> N;
    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    map<vll, int> freqs;
    for (int v : a)
    {
        auto factors = factorise(v);
        vll odd;
        for (auto entry : factors)
            if (entry.second & 1)
                odd.push_back(entry.first);
        freqs[odd]++;
    }
    int sink = 0;
    int mb = 0;
    for (const auto &e : freqs)
    {
        if (e.first.empty() || e.second % 2 == 0)
            sink += e.second;
        mb = max(mb, e.second);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll w;
        cin >> w;
        int ans = mb;
        if (w > 0)
            ans = max(ans, sink);
        cout << ans << '\n';
    }
}

int main(int argc, const char **argv)
{
    sieve.resize(1000001);
    for (int i = 2; i <= 1000000; i++)
        if (sieve[i] == 0)
        {
            sieve[i] = i;
            for (int j = 2 * i; j <= 1000000; j += i)
                sieve[j] = i;
        }

    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}