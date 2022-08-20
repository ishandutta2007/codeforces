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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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

struct cell
{
    int start, end;
    bool operator<(const cell &other) const { return start < other.start; }
};

static ll seed;

static ll rnd()
{
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

static ll pmod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return a * pmod(a, b - 1, m) % m;
    else
    {
        ll t = pmod(a, b / 2, m);
        return t * t % m;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    ll vmax;
    cin >> N >> M >> seed >> vmax;
    map<cell, ll> cells;

    for (int i = 0; i < N; i++)
    {
        ll a = rnd() % vmax + 1;
        cells.emplace(cell{i, i + 1}, a);
    }

    auto split = [&](int pos)
    {
        auto it = cells.lower_bound(cell{pos, pos});
        if (it == cells.end() || it->first.start > pos)
        {
            --it;
            cell old = it->first;
            ll value = it->second;
            cells.erase(it);
            cells.emplace(cell{old.start, pos}, value);
            cells.emplace(cell{pos, old.end}, value);
        }
    };

    for (int q = 0; q < M; q++)
    {
        int op = rnd() % 4 + 1;
        int l = rnd() % N;
        int r = rnd() % N;
        if (l > r)
            swap(l, r);

        ll x, y;
        if (op == 3)
            x = rnd() % (r - l + 1) + 1;
        else
            x = rnd() % vmax + 1;
        if (op == 4)
            y = rnd() % vmax + 1;
        int pos;
        ll sum = 0;
        vector<pair<ll, ll>> bits;
        r++;

        switch (op)
        {
        case 1:
            split(l);
            split(r);
            for (auto it = cells.lower_bound(cell{l, l}); it != cells.end() && it->first.end <= r; ++it)
                it->second += x;
            break;
        case 2:
            {
                split(l);
                split(r);
                auto it1 = cells.lower_bound(cell{l, l});
                auto it2 = cells.lower_bound(cell{r, r});
                cells.erase(it1, it2);
                cells.emplace(cell{l, r}, x);
            }
            break;
        case 3:
            split(l);
            split(r);
            for (auto it = cells.lower_bound(cell{l, l}); it != cells.end() && it->first.end <= r; ++it)
                bits.emplace_back(it->second, it->first.end - it->first.start);
            sort(RA(bits));
            x--;
            pos = 0;
            while (x >= bits[pos].second)
            {
                x -= bits[pos].second;
                pos++;
            }
            cout << bits[pos].first << '\n';
            break;
        case 4:
            split(l);
            split(r);
            for (auto it = cells.lower_bound(cell{l, l}); it != cells.end() && it->first.end <= r; ++it)
            {
                ll cur = pmod(it->second % y, x, y);
                sum += cur * ll(it->first.end - it->first.start) % y;
                sum %= y;
            }
            if (sum < 0) sum += y;
            cout << sum << '\n';
        }
    }

    return 0;
}