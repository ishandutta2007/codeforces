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

struct SAEntry
{
    int str;
    int ofs;
    ll score;
    int share;

    SAEntry() : share(0) {}
    SAEntry(int str, int ofs, ll score) : str(str), ofs(ofs), score(score), share(0) {}

    bool operator<(const SAEntry &b) const
    {
        if (score != b.score)
            return score < b.score;
        else
            return str < b.str;
    }
};

template<typename Container>
std::vector<SAEntry> make_suffix_array(const Container &strings)
{
    int N = strings.size();
    std::vector<std::vector<int> > rank(N);
    int ae = 0;
    int mchars = 0;
    for (int i = 0; i < N; i++)
    {
        rank[i].resize(strings[i].size() + 1);
        ae += rank[i].size();
        mchars = std::max(mchars, int(strings[i].size()));
    }

    std::vector<SAEntry> ans;
    ans.reserve(ae);
    for (int i = 0; i < N; i++)
    {
        for (std::size_t j = 0; j < strings[i].size(); j++)
        {
            ans.push_back(SAEntry(i, j, strings[i][j]));
        }
        ans.push_back(SAEntry(i, strings[i].size(), 0));
    }
    assert(SZ(ans) == ae);
    sort(ans.begin(), ans.end());

    for (int step = 1; step <= mchars; step *= 2)
    {
        ll pscore = -1;
        int r = -1;
        for (int i = 0; i < ae; i++)
        {
            if (ans[i].score != pscore)
            {
                pscore = ans[i].score;
                r++;
            }
            rank[ans[i].str][ans[i].ofs] = r;
        }

        for (int i = 0; i < ae; i++)
        {
            int s = ans[i].str;
            int o = ans[i].ofs;
            ans[i].score = rank[s][o];
            ans[i].score <<= 32;
            if (o + step < SZ(rank[s]))
                ans[i].score += rank[s][o + step];
        }
        sort(ans.begin(), ans.end());
    }

    for (int i = 0; i < ae; i++)
        rank[ans[i].str][ans[i].ofs] = i;

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


int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    ll A, B;
    vs s(1);
    cin >> N >> A >> B >> s[0];
    reverse(RA(s[0]));
    auto sa = make_suffix_array(s);
    vi extend(N + 1);
    for (int i = 0; i < SZ(sa); i++)
    {
        int share = INT_MAX;
        int e = 0;
        for (int j = i + 1; j < SZ(sa); j++)
        {
            share = min(share, sa[j].share);
            if (sa[j].ofs > sa[i].ofs)
                e = max(e, min(sa[j].ofs - sa[i].ofs, share));
        }
        share = INT_MAX;
        for (int j = i - 1; j >= 0; j--)
        {
            share = min(share, sa[j + 1].share);
            if (sa[j].ofs > sa[i].ofs)
                e = max(e, min(sa[j].ofs - sa[i].ofs, share));
        }

        extend[N - sa[i].ofs] = e;
    }

    vll dp(N + 1);
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1] + A;
        if (extend[i] >= 1)
            dp[i] = min(dp[i], dp[i - extend[i]] + B);
    }
    cout << dp[N] << '\n';

    return 0;
}