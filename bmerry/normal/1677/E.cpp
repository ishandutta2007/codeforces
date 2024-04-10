//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

struct event
{
    int x;
    int y;
    ll d_xy, d_x, d_y, d_c;

    bool operator<(const event &other)
    {
        return tie(x, y) < tie(other.x, other.y);
    }
};

static event make_event(int x, int y, ll d_xy, ll d_x, ll d_y, ll d_c)
{
    return event{x, y, d_xy, d_x, d_y, d_c};
}

static event q_event(int x, int id, int scale)
{
    return event{x, -1, scale, id, 0, 0};
}

static ll bit_eval(const BIT<ll> &bit_xy, const BIT<ll> &bit_x, const BIT<ll> &bit_y, const BIT<ll> &bit_c,
                   ll x, ll y)
{
    ll v_xy = bit_xy.sum_exclusive(y);
    ll v_x = bit_x.sum_exclusive(y);
    ll v_y = bit_y.sum_exclusive(y);
    ll v_c = bit_c.sum_exclusive(y);
    y--;
    return x * y * v_xy + x * v_x + y * v_y + v_c;
}

static void solve()
{
    int N, Q;
    cin >> N >> Q;
    vi p(N);
    vi invp(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        invp[p[i]] = i;
    }

    vi bigl(N), bigr(N);
    stack<pii> st;
    st.emplace(-1, INT_MAX);
    for (int i = 0; i < N; i++)
    {
        while (p[i] > st.top().second)
            st.pop();
        bigl[i] = st.top().first;
        st.emplace(i, p[i]);
    }
    while (!st.empty())
        st.pop();
    st.emplace(N, INT_MAX);
    for (int i = N - 1; i >= 0; i--)
    {
        while (p[i] > st.top().second)
            st.pop();
        bigr[i] = st.top().first;
        st.emplace(i, p[i]);
    }

    vector<vector<pii>> factors(N);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i + 1; i * j <= N; j++)
        {
            int pos = invp[i * j];
            int x1 = min({invp[i], invp[j], pos}) + 1;
            int y0 = max({invp[i], invp[j], pos});
            int x0 = bigl[pos] + 1;
            int y1 = bigr[pos];
            if (x0 < x1 && y0 < y1)
            {
                factors[pos].emplace_back(x1, y0);
                // cerr << "[" << x0 << "," << x1 << ") x [" << y0 << "," << y1 << ")\n";
            }
        }
    }

    vector<event> events;
    for (int i = 0; i < N; i++)
    {
        vector<pii> &fact = factors[i];
        sort(RA(fact), greater<pii>());
        ll x0 = bigl[i] + 1;
        ll y1 = bigr[i];
        ll last_y = y1;
        for (const auto [x1, y0] : fact)
        {
            if (y0 < last_y)
            {
                ll x0e = x0 - 1;
                ll y0e = y0 - 1;
                ll tx = x1 - x0;
                ll ty = last_y - y0;
                events.push_back(make_event(x0, y0, 1, -y0e, -x0e, x0e * y0e));
                events.push_back(make_event(x0, last_y, -1, ty + y0e, x0e, x0e * (-y0e - ty)));
                events.push_back(make_event(x1, y0, -1, y0e, tx + x0e, y0e * (-x0e - tx)));
                events.push_back(make_event(x1, last_y, 1, -ty - y0e, -tx - x0e,
                                            tx * ty - x0e * y0e + x0e * (y0e + ty) + y0e * (x0e + tx)));
                last_y = y0;
            }
        }
    }


    vector<pii> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        events.push_back(q_event(L, i, -1));
        events.push_back(q_event(R, i, 1));
        queries[i] = pii(L, R);
    }

    sort(RA(events));
    BIT<ll> bit_xy(N + 1), bit_x(N + 1), bit_y(N + 1), bit_c(N + 1);
    vll ans(Q);
    for (const event &e : events)
    {
        if (e.y == -1)
        {
            int scale = e.d_xy;
            int id = e.d_x;
            auto [L, R] = queries[id];
            ll vR = bit_eval(bit_xy, bit_x, bit_y, bit_c, e.x - 1, R);
            ll vL = bit_eval(bit_xy, bit_x, bit_y, bit_c, e.x - 1, L);
            ans[id] += (vR - vL) * scale;
        }
        else
        {
            bit_xy.add(e.y, e.d_xy);
            bit_x.add(e.y, e.d_x);
            bit_y.add(e.y, e.d_y);
            bit_c.add(e.y, e.d_c);
        }
    }
    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}