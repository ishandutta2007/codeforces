// Doesn't work: orders intervals first by length rather than score

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

struct event
{
    int y;
    int x;
};

static ll measure(const vector<vector<event>> &events, ll M)
{
    int N = SZ(events);
    vll diff(N + 1);
    int a = 0;
    ll ans = 0;
    int cur = 0;
    for (int i = 0; i < N; i++)
    {
        for (const event &e : events[i])
        {
            diff[e.y] += e.x;
            diff[i + 1] -= e.x;
            if (e.y <= a)
                cur += e.x;
        }
        while (a < i && cur + diff[a + 1] >= M)
        {
            cur += diff[a + 1];
            a++;
        }
        if (cur >= M)
            ans += a + 1;
    }
    return ans;
}

static ll add(const vector<vector<event>> &events, ll M)
{
    int N = SZ(events);
    vll diff(N + 1);
    int a = 0;
    ll ans = 0;
    ll cur = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (const event &e : events[i])
        {
            diff[e.y] += e.x;
            diff[i + 1] -= e.x;
            if (e.y <= a)
            {
                cur += e.x;
                sum += ll(a - e.y + 1) * e.x;
            }
        }
        while (a < i && cur + diff[a + 1] >= M)
        {
            cur += diff[a + 1];
            sum += cur;
            a++;
        }
        if (cur >= M)
            ans += sum;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, K;
    cin >> N >> K;

    map<int, int> h;
    h[-1] = 0;
    h[1000000001] = 0;
    vector<vector<event>> events(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        auto pa = h.lower_bound(a);
        if (pa->first > a)
            pa = h.insert(pa, pii(a, pa->second));
        auto pb = h.lower_bound(b);
        if (pb->first > b)
            pb = h.insert(pb, pii(b, pb->second));
        auto end = next(pb);
        int x = a;
        for (auto p = next(pa); p != end; ++p)
        {
            events[i].push_back(event{p->second, p->first - x});
            x = p->first;
        }
        h.erase(next(pa), pb);
        pb->second = i + 1;
    }

    ll lo = 1;
    ll hi = 1000000001;
    while (hi - lo > 1)
    {
        ll mid = (lo + hi) / 2;
        if (measure(events, mid) >= K)
            lo = mid;
        else
            hi = mid;
    }

    ll ans = add(events, lo);
    ll c = measure(events, lo);
    ans -= (c - K) * lo;
    cout << ans << '\n';

    return 0;
}