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
    ll s1, s2;
    cin >> N >> s1 >> s2;
    vll x(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    ll lo = abs(s2 - s1) - 1;
    ll hi = 1000000001;
    while (hi - lo > 1)
    {
        vector<pair<ll, ll>> rng(N);
        ll R = (lo + hi) / 2;
        rng[N - 1] = make_pair(x[N - 1] - R, x[N - 1] + R);
        bool good = false;
        for (int i = N - 2; i >= 0; i--)
        {
            if (x[i] >= rng[i + 1].first && x[i] <= rng[i + 1].second)
                rng[i] = make_pair(x[i] - R, x[i] + R);
            else
            {
                rng[i].first = max(x[i] - R, rng[i + 1].first);
                rng[i].second = min(x[i] + R, rng[i + 1].second);
                if (rng[i].first > rng[i].second)
                    goto bad;
            }
        }
        good = ((s1 >= rng[0].first && s1 <= rng[0].second)
                || (s2 >= rng[0].first && s2 <= rng[0].second));
        if (abs(s2 - s1) > R)
            good = false;
bad:
        if (good)
            hi = R;
        else
            lo = R;
    }
    cout << hi << '\n';
    return 0;
}