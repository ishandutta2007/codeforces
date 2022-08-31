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
typedef unsigned long long ull;
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

static constexpr int LVLS = 62;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int Q;
    cin >> Q;
    vector<ull> flat(LVLS);
    vector<ull> stacked(LVLS);
    ull lvl_shift[LVLS];
    for (int qid = 0; qid < Q; qid++)
    {
        int t;
        ll x, k, up;
        cin >> t >> x;
        int lvl = 63 - __builtin_clzll(x);
        switch (t)
        {
        case 1:
            cin >> k;
            flat[lvl] += k;
            break;
        case 2:
            cin >> k;
            up = ull(k) << (LVLS - lvl);
            stacked[lvl] += up;
            break;
        case 3:
            {
                ull s = 0;
                for (int i = 0; i <= lvl; i++)
                {
                    s += stacked[i];
                    lvl_shift[i] = (s >> (LVLS - i)) + flat[i];
                }
                ull base = 1ULL << lvl;
                ull ofs = x - base;
                ull pos = (ofs + lvl_shift[lvl]) & (base - 1);
                for (int i = lvl; i >= 0; i--)
                {
                    ull value = (pos - lvl_shift[i]) & (base - 1);
                    cout << value + base << ' ';
                    pos >>= 1;
                    base >>= 1;
                }
                cout << '\n';
            }
            break;
        }
    }

    return 0;
}