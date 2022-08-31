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

struct station
{
    int f;
    ll x;
    ll r;
    int xi, xli, xri;
};

enum class event_type
{
    rhit = 0,
    lstart = 1,
    lstop = 2
};

struct event
{
    int xi;
    event_type type;
    int idx;

    bool operator<(const event &other) const
    {
        return pair(xi, int(type)) < pair(other.xi, int(other.type));
    }
};

static void solve()
{
    int N, K;
    cin >> N >> K;
    map<int, vector<station>> stations;
    map<ll, int> xmap;
    for (int i = 0; i < N; i++)
    {
        station s;
        cin >> s.x >> s.r >> s.f;
        stations[s.f].push_back(s);
        xmap[s.x] = 0;
        xmap[s.x - s.r] = 0;
        xmap[s.x + s.r] = 0;
    }
    int X = 0;
    for (auto &e : xmap)
        e.second = X++;
    for (auto &e : stations)
        for (station &s : e.second)
        {
            s.xi = xmap[s.x];
            s.xli = xmap[s.x - s.r];
            s.xri = xmap[s.x + s.r];
        }

    ll ans = 0;
    BIT<int> bit(X + 1);
    for (const auto &rstats : stations)
    {
        int rf = rstats.first;
        for (auto it = stations.lower_bound(rf - K); it != stations.upper_bound(rf + K); ++it)
        {
            vector<event> events;
            for (int i = 0; i < SZ(it->second); i++)
            {
                const station &s = it->second[i];
                events.push_back(event{s.xi, event_type::lstart, i});
                events.push_back(event{s.xri, event_type::lstop, i});
            }
            for (int i = 0; i < SZ(rstats.second); i++)
            {
                const station &s = rstats.second[i];
                events.push_back(event{s.xi, event_type::rhit, i});
            }
            sort(RA(events));
            for (const auto &ev : events)
            {
                switch (ev.type)
                {
                case event_type::lstart:
                    bit.add(ev.xi, 1);
                    break;
                case event_type::lstop:
                    bit.add(it->second[ev.idx].xi, -1);
                    break;
                case event_type::rhit:
                    ans += bit.sum(ev.xi) - bit.sum_exclusive(rstats.second[ev.idx].xli);
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}