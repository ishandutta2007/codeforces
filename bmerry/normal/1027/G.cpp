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

static ll powermod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return __int128(a) * powermod(a, b - 1, m) % m;
    else
    {
        ll t = powermod(a, b / 2, m);
        return __int128(t) * t % m;
    }
}

static bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    else if (n < 64)
        return (0x28208a20a08a28acULL >> n) & 1;
    else if (n % 2 == 0)
        return false;
    else if (n < 1000000)
    {
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
    else
    {
        // Rabin-Miller
        ll d = n - 1;
        int r = 0;
        while (!(d & 1))
        {
            d >>= 1;
            r++;
        }
        for (ll a = 2; a <= 37; a++)
            if (is_prime(a))
            {
                ll x = powermod(a, d, n);
                if (x == 1 || x == n - 1)
                    continue;
                int i;
                for (i = 0; i < r - 1; i++)
                {
                    x = __int128(x) * x % n;
                    if (x == n - 1)
                        break;
                }
                if (i == r - 1)
                    return false;
            }
        return true;
    }
}

// Finds a factor of n (which *must* be composite and > 1)
static ll pollard_rho(ll n)
{
    std::mt19937_64 engine;
    std::uniform_int_distribution<ll> pick(2, n - 2);
    while (true)
    {
        ll a, b, s;
        a = b = pick(engine);
        s = pick(engine);
        while (true)
        {
            a = (__int128(a) * a + s) % n;
            b = (__int128(b) * b + s) % n;
            b = (__int128(b) * b + s) % n;
            if (a == b)
                break;
            ll g = gcd(llabs(a - b), n);
            if (g > 1)
                return g;
        }
    }
}

static std::vector<std::pair<ll, int>> factorise(ll n)
{
    std::vector<std::pair<ll, int>> out;
    if (n < 1000000)   // NB: match with is_prime
    {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
            {
                n /= i;
                int r = 1;
                while (n % i == 0)
                {
                    n /= i;
                    r++;
                }
                out.emplace_back(i, r);
            }
        if (n > 1)
            out.emplace_back(n, 1);
    }
    else if (is_prime(n))
    {
        out.emplace_back(n, 1);
    }
    else
    {
        ll a = pollard_rho(n);
        auto fa = factorise(a);
        auto fb = factorise(n / a);
        auto pa = fa.begin();
        auto pb = fb.begin();
        while (pa != fa.end() && pb != fb.end())
        {
            if (pa->first == pb->first)
            {
                out.emplace_back(pa->first, pa->second + pb->second);
                ++pa;
                ++pb;
            }
            else if (pa->first < pb->first)
                out.push_back(*pa++);
            else
                out.push_back(*pb++);
        }
        std::copy(pa, fa.end(), std::back_inserter(out));
        std::copy(pb, fb.end(), std::back_inserter(out));
    }
    return out;
}

static ll solve1(ll g, ll phi, ll x)
{
    if (g == 1)
        return 1;
    ll order = phi;
    auto fact = factorise(phi);
    for (int i = 0; i < SZ(fact); i++)
    {
        ll p = fact[i].first;
        while (order % p == 0 && powermod(x, order / p, g) == 1)
            order /= p;

    }
    return phi / order;
}

static ll recurse(const vector<pair<ll, int>> &decomp, ll g, ll phi, int pos, ll x)
{
    int N = SZ(decomp);
    if (pos == N)
        return solve1(g, phi, x);
    else
    {
        ll ans = recurse(decomp, g, phi, pos + 1, x);
        g *= decomp[pos].first;
        phi *= decomp[pos].first - 1;
        for (int i = 1; i <= decomp[pos].second; i++)
        {
            ans += recurse(decomp, g, phi, pos + 1, x);
            if (i < decomp[pos].second)
            {
                g *= decomp[pos].first;
                phi *= decomp[pos].first;
            }
        }
        return ans;
    }
}

static void solve()
{
    ll m, x;
    cin >> m >> x;
    auto decomp = factorise(m);
    ll ans = recurse(decomp, 1, 1, 0, x);
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}