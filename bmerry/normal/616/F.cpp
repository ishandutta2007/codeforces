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

struct SATmpEntry
{
    int str;
    int ofs;
    std::array<int, 2> rank;

    constexpr SATmpEntry(int str, int ofs, int r) : str(str), ofs(ofs), rank{{r, 0}} {}

    constexpr bool operator<(const SATmpEntry &other) const
    {
        return std::tie(rank, str, ofs) < tie(other.rank, other.str, other.ofs);
    }
};

template<typename Char>
struct SAInit
{
    Char value;
    int str;
    int ofs;

    constexpr SAInit(Char value, int str, int ofs) : value(value), str(str), ofs(ofs) {}
    constexpr bool operator<(const SAInit &other) const { return value < other.value; }
};

struct SAEntry
{
    int str;
    int ofs;
    int share;
};

template<typename Container>
std::vector<SAEntry> make_suffix_array(const Container &strings)
{
    typedef typename Container::value_type::value_type char_t;

    int N = strings.size();
    std::vector<std::vector<int>> rank(N), subrank(N);
    rank.resize(N);
    subrank.resize(N);
    int ae = 0;
    int mchars = 0;
    for (int i = 0; i < N; i++)
    {
        int sz = strings[i].size() + 1;
        rank[i].resize(sz);
        subrank[i].resize(sz);
        ae += sz;
        mchars = std::max(mchars, int(strings[i].size()));
    }

    // Initial (1-char) ranks
    std::vector<SAInit<char_t>> init;
    init.reserve(ae - N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < int(strings[i].size()); j++)
            init.emplace_back(strings[i][j], i, j);
    std::sort(init.begin(), init.end());

    std::vector<SATmpEntry> order;
    order.reserve(ae);
    int irank = 0;
    for (int i = 0; i < N; i++)
        order.emplace_back(i, int(strings[i].size()), irank++);
    for (std::size_t i = 0; i < init.size(); i++)
    {
        if (i > 0 && init[i - 1] < init[i])
            irank++;
        order.emplace_back(init[i].str, init[i].ofs, irank);
    }
    assert(SZ(order) == ae);

    for (int step = 1; step <= mchars; step *= 2)
    {
        for (const auto &e : order)
            rank[e.str][e.ofs] = e.rank[0];
        for (auto &e : order)
        {
            int L = strings[e.str].size();
            e.rank[1] = rank[e.str][std::min(e.ofs + step, L)];
        }

        sort(order.begin(), order.end());

        std::array<int, 2> prev{{-1, -1}};
        irank = -1;
        for (auto &e : order)
        {
            if (e.rank != prev)
                irank++;
            prev = e.rank;
            e.rank[0] = irank;
        }
    }

    std::vector<SAEntry> ans(ae);
    for (int i = 0; i < ae; i++)
    {
        rank[order[i].str][order[i].ofs] = i;
        ans[i].str = order[i].str;
        ans[i].ofs = order[i].ofs;
    }

    for (int i = 0; i < N; i++)
    {
        int s = 0;
        int L = strings[i].size();
        for (int j = 0; j <= L; j++)
        {
            s--;
            if (s < 0)
                s = 0;
            int p = rank[i][j];
            if (p > 0)
            {
                const int pi = ans[p - 1].str;
                const int pj = ans[p - 1].ofs;
                const int pL = strings[pi].size();
                while (j + s < L && pj + s < pL && strings[i][j + s] == strings[pi][pj + s])
                    s++;
            }
            else
                s = 0;
            ans[p].share = s;
        }
    }

    return ans;
}

static void solve()
{
    int N;
    cin >> N;
    vs t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];
    vll c(N);
    ll ans = 0;
    for (int i = 0; i < N; i++)
        cin >> c[i];

    auto sa = make_suffix_array(t);
    vector<ll> csum(SZ(sa) + 1);
    for (int i = 0; i < SZ(sa); i++)
        csum[i + 1] = csum[i] + c[sa[i].str];

    vector<pii> ranges;
    for (int i = 1; i < SZ(sa); i++)
    {
        int sid = sa[i].str;
        int sh = sa[i].share;
        int start = i;
        while (!ranges.empty() && ranges.back().second > sh)
        {
            ans = max(ans, ranges.back().second * (csum[i] - csum[ranges.back().first]));
            start = ranges.back().first;
            ranges.pop_back();
        }
        if (ranges.empty() || ranges.back().second < sh)
            ranges.emplace_back(start, sh);
        int len = SZ(t[sid]) - sa[i].ofs;
        if (sh < len)
            ranges.emplace_back(i, len);
    }
    while (!ranges.empty())
    {
        ans = max(ans, ranges.back().second * (csum.back() - csum[ranges.back().first]));
        ranges.pop_back();
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}