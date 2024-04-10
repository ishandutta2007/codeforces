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
    int N, Q;
    cin >> N >> Q;
    set<pii> working;
    working.emplace(0, N);
    ll nworking = N;

    for (int i = 0; i < Q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;

        auto it = working.lower_bound(pii(l, -1));
        if (it != working.begin())
        {
            --it;
            if (it->second > l)
            {
                pii old = *it;
                auto nxt = working.emplace(l, old.second).first;
                working.emplace(old.first, l);
                working.erase(it);
                it = nxt;
            }
            else
                ++it;
        }
        while (it != working.end() && it->second <= r)
        {
            nworking -= it->second - it->first;
            auto nxt = next(it);
            working.erase(it);
            it = nxt;
        }
        if (it != working.end() && it->first < r)
        {
            nworking -= r - it->first;
            working.emplace(r, it->second);
            working.erase(it);
        }

        if (k == 2)
        {
            nworking += r - l;
            working.emplace(l, r);
        }
        cout << nworking << '\n';
    }

    return 0;
}