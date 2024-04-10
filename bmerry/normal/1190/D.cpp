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
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pii> pnts(N);
    map<int, int> xs, ys;
    for (int i = 0; i < N; i++)
    {
        cin >> pnts[i].first >> pnts[i].second;
        xs[pnts[i].first] = -1;
        ys[pnts[i].second] = -1;
    }
    int cnt = 0;
    for (auto &e : xs)
        e.second = cnt++;
    int X = cnt;
    cnt = 0;
    for (auto &e : ys)
        e.second = cnt++;
    int Y = cnt;

    vector<vi> rows(Y);
    for (const auto &p : pnts)
        rows[ys[p.second]].push_back(xs[p.first]);

    BIT<int> bit(X + 1);
    ll ans = 0;
    for (int y = Y - 1; y >= 0; y--)
    {
        vi &row = rows[y];
        sort(RA(row));
        int prev = -1;
        for (int x : row)
            if (bit.sum(x) == bit.sum_exclusive(x))
                bit.add(x, 1);
        for (int x : row)
        {
            ll L = bit.sum_exclusive(x) - bit.sum_exclusive(prev + 1) + 1;
            ll R = bit.sum(X) - bit.sum(x) + 1;
            ans += L * R;
            //cerr << "x = " << x << " y = " << y << " L = " << L << " R = " << R << '\n';
            prev = x;
        }
    }
    cout << ans << '\n';

    return 0;
}