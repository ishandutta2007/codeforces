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
}

/*** TEMPLATE CODE ENDS HERE */

static vector<int> log2i;
static vector<vi> g(17);

static int rgcd(int p, int q)
{
    int r = log2i[q - p];
    return gcd(g[r][p], g[r][q - (1 << r)]);
}

static ll countit(ll c, ll s, ll a, ll b)
{
#if 0
    ll ans2 = 0;
    for (ll i = 0; i < c; i++)
        ans2 += (s + i * a) / b;
#endif

    assert(c >= 0);
    if (c == 0)
        return 0;
    ll ans = 0;
    ans += c * (s / b);
    s %= b;
    ans += c * (c - 1) / 2 * (a / b);
    a %= b;
    if (a != 0)
    {
        ll delta = a + b - s - 1;
        ll L = (a * c - delta + b) / b;
        ans += L * c - countit(L, delta, b, a);
    }

#if 0
    assert(ans == ans2);
#endif
    return ans;
}

struct freq_t
{
    ll d;
    ll n;
    ll p;

    freq_t(ll d = 1, ll n = 1) : d(d), n(n), p(d * n) {}
};

static ll countlte(const vector<freq_t> &freq, ll trg)
{
    ll ans = 0;
#if 1
    ll pp = 0;
    ll pn = 0;
    ll qp = 0;
    ll qn = 0;
    ll sum = 0;
    ll dist = 0;
    int N = SZ(freq);
    while (qp < N && sum + freq[qp].p <= trg)
    {
        sum += freq[qp].p;
        dist += freq[qp].n;
        qp++;
    }
    if (qp != N)
    {
        qn = (trg - sum) / freq[qp].d;
        dist += qn;
        sum += qn * freq[qp].d;
    }

    while (qp < N)
    {
        ll a = freq[pp].d;
        ll b = freq[qp].d;
        ll prem = freq[pp].n - pn;
        ll qrem = freq[qp].n - qn;
        ll pn2, qn2;
        if (qp > pp && sum - a * prem + b * qrem > trg)
        {
            pn2 = freq[pp].n;
            qn2 = qn + (trg - (sum - a * prem)) / b;
        }
        else
        {
            qn2 = freq[qp].n;
            pn2 = pn + (sum + b * qrem - trg + a - 1) / a;
        }

        ll c = pn2 - pn;
        ans += c * dist - c * (c - 1) / 2;
        ans += countit(c, trg - sum, a, b);

        dist += (qn2 - qn) - (pn2 - pn);
        sum += (qn2 - qn) * b - (pn2 - pn) * a;
        pn = pn2;
        qn = qn2;
        if (pn == freq[pp].n)
        {
            pp++;
            pn = 0;
        }
        if (qn == freq[qp].n)
        {
            qp++;
            qn = 0;
        }
    }
    ans += dist * (dist + 1) / 2;
#else
    vector<ll> lst;
    for (const auto &f : freq)
        for (ll i = 0; i < f.n; i++)
            lst.push_back(f.d);
    for (int i = 0; i < SZ(lst); i++)
    {
        ll sum = 0;
        int j = i;
        while (j < SZ(lst) && sum + lst[j] <= trg)
        {
            sum += lst[j];
            j++;
        }
        ans += j - i;
    }
#endif
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N;
    cin >> N;

    log2i.resize(N + 1);
    log2i[0] = -1;
    for (int i = 1; i <= N; i++)
        log2i[i] = 31 - __builtin_clz(i);

    g[0].resize(N);
    for (int i = 0; i < N; i++)
        cin >> g[0][i];
    for (int i = 1; i < SZ(g); i++)
    {
        int s = 1 << (i - 1);
        g[i] = g[i - 1];
        for (int j = 0; j < N - s; j++)
            g[i][j] = gcd(g[i][j], g[i - 1][j + s]);
    }

    vector<ll> freq(100001);
    for (int i = 0; i < N; i++)
    {
        int start = i;
        while (start < N)
        {
            int c = rgcd(i, start + 1);
            int lo = start + 1;
            int hi = N + 1;
            while (hi - lo > 1)
            {
                int mid = (lo + hi) / 2;
                if (rgcd(i, mid) == c)
                    lo = mid;
                else
                    hi = mid;
            }
            freq[c] += lo - start;
            start = lo;
        }
    }

    vector<freq_t> freqt;
    ll total = 0;
    ll M = 0;
    for (int i = 1; i < SZ(freq); i++)
        if (freq[i])
        {
            freqt.emplace_back(i, freq[i]);
            total += freqt.back().p;
            M += freq[i];
        }
    M = M * (M + 1) / 2;
    M = (M + 1) / 2;

    ll lo = 0;
    ll hi = total;
    while (hi - lo > 1)
    {
        ll mid = lo + (hi - lo) / 2;
        ll lte = countlte(freqt, mid);
        if (lte >= M)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';

    return 0;
}