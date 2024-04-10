// TOO SLOW: need faster way to find previously existing contestants that
// are now potential winners.

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

enum compare_mode
{
    CMP_SET,
    CMP_LOW,
    CMP_HIGH
};

struct comp
{
    vi low, high;
    int size;
    compare_mode mode = CMP_SET;

    bool operator<(const comp &b) const
    {
        switch (max(mode, b.mode))
        {
        case CMP_SET:
            return low[0] < b.low[0];
        case CMP_LOW:
            for (int i = 0; i < SZ(low); i++)
                if (low[i] >= b.low[i])
                    return false;
            return true;
        case CMP_HIGH:
            for (int i = 0; i < SZ(high); i++)
                if (high[i] >= b.high[i])
                    return false;
            return true;
        }
        return false;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K;
    cin >> N >> K;
    set<comp> comps;
    for (int i = 0; i < N; i++)
    {
        vi cur(K);
        for (int j = 0; j < K; j++)
            cin >> cur[j];
        comp test;
        test.low = test.high = cur;
        test.mode = CMP_LOW;
        auto hi = comps.upper_bound(test);
        test.mode = CMP_HIGH;
        auto lo = comps.lower_bound(test);
        comp n;
        n.low = n.high = cur;
        n.size = 1;
        if (lo != hi && (hi == comps.end() || lo != next(hi)))
        {
            auto hi1 = prev(hi);
            for (int k = 0; k < K; k++)
            {
                n.low[k] = min(n.low[k], lo->low[k]);
                n.high[k] = max(n.high[k], hi1->high[k]);
            }
            for (auto i = lo; i != hi; ++i)
                n.size += i->size;
            comps.erase(lo, hi);
        }
        comps.insert(n);
        cout << comps.rbegin()->size << '\n';
    }

    return 0;
}