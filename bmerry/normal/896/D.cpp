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

// Undefined sign for negative inputs
template<typename T>
static T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

/*** TEMPLATE CODE ENDS HERE */

static ll P;
static vi F;

static ll pmod(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return a * pmod(a, b - 1) % P;
    else
    {
        ll t = pmod(a, b / 2);
        return t * t % P;
    }
}

struct number
{
    ll rel;
    array<int, 10> ex;

    number() : rel(1), ex{{}} {}

    number operator *(const number &b) const
    {
        number out;
        out.rel = rel * b.rel % P;
        for (int i = 0; i < SZ(F); i++)
            out.ex[i] = ex[i] + b.ex[i];
        return out;
    }

    number operator /(const number &b) const
    {
        number out;
        out.rel = rel * inverse(b.rel, P) % P;
        for (int i = 0; i < SZ(F); i++)
            out.ex[i] = ex[i] - b.ex[i];
        return out;
    }

    ll eval() const
    {
        ll ans = rel;
        for (int i = 0; i < SZ(F); i++)
        {
            ll f = pmod(F[i], ex[i]);
            ans = ans * f % P;
        }
        return ans;
    }
};

static vi factors(int P)
{
    int s = int(sqrt(P) + 1);
    vi ans;
    for (int i = 2; i <= s; i++)
    {
        if (P % i == 0)
        {
            ans.push_back(i);
            while (P % i == 0)
                P /= i;
        }
    }
    if (P > 1)
        ans.push_back(P);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, l, r;
    cin >> N >> P >> l >> r;

    F = factors(P);
    vector<int> d1(N + 1, -1);
    for (int i = 0; i < SZ(F); i++)
        for (int j = F[i]; j <= N; j += F[i])
            d1[j] = i;

    vector<number> fact(N + 1);
    for (int i = 2; i <= N; i++)
    {
        number cur;
        ll rel = i;
        while (d1[rel] != -1)
        {
            cur.ex[d1[rel]]++;
            rel /= F[d1[rel]];
        }
        cur.rel = rel % P;
        assert(gcd(rel, P) == 1);
        fact[i] = fact[i - 1] * cur;
    }

    auto choose = [&](ll n, ll r)
    {
        number ans = fact[n] / (fact[r] * fact[n - r]);
        return ans.eval();
    };

    ll ans = 0;
    for (int k = l; k <= N; k++)
    {
        ll x = (k - l) / 2;
        ll y = (k - r + 1) / 2;
        ll term = choose(k, x);
        if (y > 0)
            term -= choose(k, y - 1);
        term %= P;
        term = term * choose(N, k) % P;
        ans = (ans + term) % P;
    }
    ans %= P;
    if (ans < 0)
        ans += P;
    cout << ans << '\n';

    return 0;
}