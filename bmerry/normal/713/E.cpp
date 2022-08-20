// DOESN'T WORK. AAARGHH!

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
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


static int prev(int p, int N)
{
    if (p-- == 0)
        p += N;
    return p;
}

static ll dist(ll a, ll b, ll R)
{
    if (b >= a)
        return b - a;
    else
        return b - a + R;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll R;
    int N;
    cin >> R >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    a.resize(unique(RA(a)) - a.begin());
    N = a.size();
    if (N == R)
    {
        cout << "0\n";
        return 0;
    }
    else if (N == 1)
    {
        cout << R - 1 << '\n';
        return 0;
    }
    ll lo = 0;
    ll hi = R;
    while (hi - lo > 1)
    {
        ll mid = (lo + hi) / 2;

        int gap = -1;
        for (int i = 0; i < N; i++)
            if (dist(a[prev(i, N)], a[i], R) > mid)
            {
                gap = i;
                break;
            }
        if (gap == -1)
        {
            hi = mid;
            continue;
        }

        vector<ll> b(N);
        for (int i = 0; i < N - gap; i++)
            b[i] = a[i + gap] - a[gap];
        for (int i = N - gap; i < N; i++)
            b[i] = a[i + gap - N] - a[gap] + R;

        bool good = false;
        for (int pass = 0; pass < 2; pass++)
        {
            ll wrap;
            vector<ll> dp(N, -1);
            int p;
            if (pass == 0)
            {
                wrap = R - mid + 1;
                dp[0] = 1;
                p = 1;
            }
            else
            {
                if (b[1] >= mid)
                    continue;
                wrap = R + b[1] - mid + 1;
                dp[0] = INT_MIN;
                dp[1] = mid;
                p = 2;
            }

            for (; p < N; p++)
            {
                if (dp[p - 1] >= b[p])
                    dp[p] = b[p] + mid;
                else if (p >= 2 && dp[p - 2] > b[p] - mid)
                    dp[p] = max(b[p] + 1, b[p - 1] + mid);
                else if (dp[p - 1] > b[p] - mid)
                    dp[p] = b[p] + 1;
                else
                    break;
            }
            if (p == N && dp[N - 1] >= wrap)
                good = true;
        }
        if (good)
            hi = mid;
        else
            lo = mid;
   }

    cout << hi - 1 << '\n';
    return 0;
}