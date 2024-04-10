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
typedef unsigned long long ull;
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

static ull matp2mod(ull a, int k, ull m)
{
    a %= m;
    for (int i = 0; i < k; i++)
    {
        a <<= 1;
        if (a >= m)
            a -= m;
    }
    return a;
}

static ll matmod(ull a, ull b, ull m)
{
#if 1
    ull al = a & UINT_MAX;
    ull ah = a >> 32;
    ull bl = b & UINT_MAX;
    ull bh = b >> 32;
    ull ans1 = al * bl % m;
    ull ans2 = matp2mod(al * bh % m + ah * bl % m, 32, m);
    ull ans3 = matp2mod(ah * bh, 64, m);
    return (ans1 + ans2 + ans3) % m;
#else
    return __int128(a) * b % m;
#endif

}

static ll powermod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return matmod(a, powermod(a, b - 1, m), m);
    else
    {
        ll t = powermod(a, b / 2, m);
        return matmod(t, t, m);
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
                    x = matmod(x, x, n);
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
            a = (matmod(a, a, n) + s) % n;
            b = (matmod(b, b, n) + s) % n;
            b = (matmod(b, b, n) + s) % n;
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

static ll order(ll x, ll M, ll phi, const vector<pair<ll, int>> &factors)
{
    ll ans = phi;
    for (const auto &e : factors)
    {
        while (ans % e.first == 0 && powermod(x, ans / e.first, M) == 1)
            ans /= e.first;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, M, P;
    cin >> N >> M >> P;
    auto factors = factorise(M);
    ll Q = factors[0].first;
    int K = factors[0].second;
    factors = factorise(Q - 1);
    if (K > 1)
        factors.emplace_back(Q, K - 1);

    ll phi = 1;
    for (const auto &e : factors)
        for (int i = 0; i < e.second; i++)
            phi *= e.first;

    if (gcd(P, M) > 1)
        P = 1;
    ll ordP = order(P, M, phi, factors);
    ll good = phi - ordP;
    if (good < N)
    {
        cout << "-1\n";
        return 0;
    }

    vector<ll> out;
    mt19937_64 engine;
    uniform_int_distribution<ll> dist(2, M - 1);
    ll g;
    if (Q != 2 || K <= 2)
    {
        do
        {
            g = dist(engine);
        } while (gcd(g, M) != 1 || order(g, M, phi, factors) != phi);
        ll cur = 1;
        ll step = phi / ordP;
        for (ll i = 1; SZ(out) < N; i++)
        {
            cur = matmod(cur, g, M);
            if (i % step != 0)
                out.push_back(cur);
        }
    }
    else
    {
        bool P1 = (P % 4 == 1);
        if (P1)
        {
            for (ll i = 3; i < M && SZ(out) < N; i += 4)
                out.push_back(i);
        }

        do
        {
            g = dist(engine);
        } while (g % 4 != 1 || gcd(g, M) != 1 || order(g, M, phi, factors) != phi / 2);
        ll cur = 1;
        ll step = phi / (P1 ? 2 * ordP : ordP);
        for (ll i = 1; SZ(out) < N; i++)
        {
            cur = matmod(cur, g, M);
            if (i % step != 0)
            {
                out.push_back(cur);
                if (!P1 && SZ(out) < N)
                    out.push_back(matmod(P, cur, M));
            }
        }
    }

    for (ll v : out)
        cout << v << ' ';
    cout << '\n';

    return 0;
}