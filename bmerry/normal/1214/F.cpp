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

template<typename T>
static T mod(T a, T b)
{
    a %= b;
    if (a < 0)
        a += b;
    return a;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll M;
    int N;
    cin >> M >> N;
    M *= 2;
    vll a(N), b(N);
    vector<pii> bya(N), byb(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[i] = (x - 1) * 2;
        bya[i] = make_pair(x, i);
    }
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        b[i] = (x - 1) * 2;
        byb[i] = make_pair(x, i);
    }
    sort(RA(a));
    sort(RA(b));
    sort(RA(bya));
    sort(RA(byb));

    const ll H = M / 2;

    vll delta(N);
    auto add = [&](int x, int y, ll d)
    {
        if (x >= y)
            return;
        x = mod(x, N);
        y = mod(y, N);
        delta[x] += d;
        delta[y] -= d;
        if (x >= y)
            delta[0] += d;
    };

    for (int i = 0; i < N; i++)
    {
        int c1 = upper_bound(RA(b), a[i] - H) - b.begin();
        int c2 = lower_bound(RA(b), a[i]) - b.begin();
        int c3 = upper_bound(RA(b), a[i] + H) - b.begin();
        add(-i, c1 - i, M - a[i]);
        add(c1 - i, c2 - i, a[i]);
        add(c2 - i, c3 - i, -a[i]);
        add(c3 - i, N - i, a[i] + M);
    }

    for (int i = 0; i < N; i++)
    {
        int c1 = lower_bound(RA(a), b[i] - H) - a.begin();
        int c2 = upper_bound(RA(a), b[i]) - a.begin();
        int c3 = lower_bound(RA(a), b[i] + H) - a.begin();
        add(i - c1 + 1, i + 1, -b[i]);
        add(i - c2 + 1, i - c1 + 1, b[i]);
        add(i - c3 + 1, i - c2 + 1, -b[i]);
        add(i - N + 1, i - c3 + 1, b[i]);
    }

    int bestr = -1;
    ll best = LLONG_MAX;
    ll cur = 0;
    for (int i = 0; i < N; i++)
    {
        cur += delta[i];
        if (cur < best)
        {
            best = cur;
            bestr = i;
        }
    }

    vi p(N);
    for (int i = 0; i < N; i++)
    {
        int j = (i + bestr) % N;
        p[bya[i].second] = byb[j].second;
    }

    cout << best / 2 << '\n';
    for (int i = 0; i < N; i++)
        cout << p[i] + 1 << ' ';
    cout << '\n';
    return 0;
}