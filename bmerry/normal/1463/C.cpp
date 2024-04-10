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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N;
        cin >> N;
        vll t(N + 1);
        vll x(N);
        int ans = 0;
        ll pos = 0;
        ll trg = 0;
        ll t0 = 0;
        for (int i = 0; i < N; i++)
            cin >> t[i] >> x[i];
        t[N] = 1000000000000LL;

        for (int i = 0; i < N; i++)
        {
            if (abs(pos - trg) <= t[i] - t0)
                pos = trg;
            else if (trg > pos)
                pos += t[i] - t0;
            else
                pos -= t[i] - t0;
            t0 = t[i];

            if (pos == trg)
            {
                trg = x[i];
                ans += abs(trg - pos) <= t[i + 1] - t[i];
            }
            else
            {
                ll lo, hi;
                if (trg > pos)
                {
                    lo = pos;
                    hi = min(trg, pos + (t[i + 1] - t[i]));
                }
                else
                {
                    lo = max(trg, pos - (t[i + 1] - t[i]));
                    hi = pos;
                }
                if (x[i] >= lo && x[i] <= hi)
                    ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}