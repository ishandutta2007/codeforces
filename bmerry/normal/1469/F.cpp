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

template<typename T, typename Op = std::plus<T> >
class BIT
{
private:
    std::vector<T> values;
    Op op;
    T identity;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    explicit BIT(size_type size = 0, Op op = Op(), T identity = T())
        : values(size + 1, identity), op(op), identity(identity) {}

    size_type size() const { return values.size() - 1; }

    void add(size_type idx, T delta)
    {
        assert(idx < size());
        idx++;
        while (idx < values.size())
        {
            values[idx] = op(values[idx], delta);
            idx += idx & ~(idx - 1);
        }
    }

    // Sum of values up to and including idx
    T sum(size_type idx) const
    {
        assert(idx < size());
        T ans = identity;
        idx++;
        while (idx > 0)
        {
            ans = op(ans, values[idx]);
            idx &= idx - 1;
        }
        return ans;
    }

    // Sum of values up to but excluding idx
    T sum_exclusive(size_type idx) const
    {
        return (idx == 0) ? identity : sum(idx - 1);
    }

    // Smallest i such that bound <= sum(i)
    // (requires prefix sums to be monotonic)
    template<typename Cmp = std::less<T>>
    size_type lower_bound(T bound, const Cmp &cmp = Cmp()) const
    {
        size_type cur = 0;
        T used = identity;
        size_type step = 1;
        while (step * 2 < values.size())
            step *= 2;
        while (step > 0)
        {
            size_type test = cur + step;
            if (test < values.size())
            {
                T testv = op(used, values[test]);
                if (cmp(testv, bound))
                {
                    used = testv;
                    cur = test;
                }
            }
            step /= 2;
        }
        return cur;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll K;
    cin >> N >> K;
    vll L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i];
    sort(RA(L));
    ll W = 1;
    BIT<ll> bit(1000002);
    bit.add(0, 1);
    bit.add(1, -1);
    int wd = 0;
    int ans = INT_MAX;
    int dK = 0;
    ll kK = 1;
    int maxd = 0;
    auto add = [&](int d, ll a)
    {
        bit.add(d, a);
        maxd = max(maxd, d);
        if (d <= dK)
            kK += a * (dK - d + 1);
    };
    while (W > 0 && !L.empty())
    {
        ll x = L.back() - 1;
        L.pop_back();
        while (bit.sum(wd) == 0)
            wd++;
        add(wd, -1);
        add(wd + 1, 1);
        add(wd + 2, 2);
        if (x % 2 == 0)
            add(wd + 2 + x / 2, -2);
        else
        {
            add(wd + 2 + x / 2, -1);
            add(wd + 3 + x / 2, -1);
        }
        W += x - 1;
        while (kK >= K)
        {
            ll u = bit.sum(dK);
            if (kK - u >= K)
            {
                kK -= u;
                dK--;
            }
            else
                break;
        }
        while (kK < K && dK < maxd)
        {
            dK++;
            kK += bit.sum(dK);
        }
        if (kK >= K)
            ans = min(ans, dK);
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';
    return 0;
}