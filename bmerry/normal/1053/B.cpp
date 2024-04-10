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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<unsigned char> bits(N);
    vector<pii> tbits[2];
    int cur = 0;
    tbits[0].emplace_back(0, 0);
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        int b = __builtin_popcountll(a);
        bits[i] = b;
        cur += b;
        tbits[cur & 1].emplace_back(i + 1, cur);
    }

    ll ans = 0;
    for (int side = 0; side < 2; side++)
    {
        const auto &tb = tbits[side];
        for (int i = 0; i < SZ(tb) - 1; i++)
        {
            int mx = 0;
            int bad = 0;
            auto tbi = tb[i];
            for (int j = i + 1; j < SZ(tb) && tb[j].first - tbi.first < 128; j++)
            {
                for (int k = tb[j - 1].first; k < tb[j].first; k++)
                {
                    if (bits[k] > mx)
                        mx = bits[k];
                }
                if (mx * 2 > tb[j].second - tbi.second)
                    bad++;
            }
            ans += SZ(tb) - 1 - i - bad;
        }
    }
    cout << ans << '\n';

    return 0;
}