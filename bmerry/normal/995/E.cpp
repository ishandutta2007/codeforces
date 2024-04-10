//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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
}

/*** TEMPLATE CODE ENDS HERE */

// Undefined sign for negative inputs
template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }
template<typename T> static constexpr T sqr(T a, T p) { return a * a % p; }
template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T, typename P>
static constexpr T power(T a, P b, T p)
{
    return b == 0 ? T(1) : (b % 2) ? power(a, b - 1, p) * a % p : sqr(power(a, b / 2, p), p);
}

template<typename T>
static constexpr T inverse(T a, T m) { return power(a, m - 2, m); }

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll u, v, p;
    cin >> u >> v >> p;
    unordered_map<ll, pair<ll, int>> forw, rev;
    queue<ll> fq, rq;
    forw[u] = make_pair(-1LL, -1LL);
    rev[v] = make_pair(-1LL, -1LL);
    fq.push(u);
    rq.push(v);

    auto apply = [&] (ll x, int op)
    {
        if (op == 1)
            return (x + 1) % p;
        else if (op == 2)
            return (x + p - 1) % p;
        else
            return inverse(x, p);
    };

    ll mid = -1;
    while (!fq.empty() || !rq.empty())
    {
        auto advance = [&](unordered_map<ll, pair<ll, int>> &forw,
                           unordered_map<ll, pair<ll, int>> &rev,
                           queue<ll> &fq)
        {
            if (!fq.empty())
            {
                ll cur = fq.front();
                fq.pop();
                if (rev.count(cur))
                {
                    mid = cur;
                    return true;
                }
                for (int op = 1; op <= 3; op++)
                {
                    ll nxt = apply(cur, op);
                    if (!forw.count(nxt))
                    {
                        forw[nxt] = make_pair(cur, op);
                        fq.push(nxt);
                    }
                }
            }
            return false;
        };

        if (advance(forw, rev, fq))
            break;
        if (advance(rev, forw, rq))
            break;
    }

    ll cur = mid;
    vi ops;
    while (cur != u)
    {
        const auto &item = forw[cur];
        ops.push_back(item.second);
        cur = item.first;
    }
    reverse(RA(ops));
    cur = mid;
    while (cur != v)
    {
        const auto &item = rev[cur];
        int op = item.second;
        if (op != 3)
            op = 3 - op;
        ops.push_back(op);
        cur = item.first;
    }

    cout << SZ(ops) << '\n';
    for (int op : ops)
    {
        cout << op << ' ';
    }
    cout << '\n';

    return 0;
}