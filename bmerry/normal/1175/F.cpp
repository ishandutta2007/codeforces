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

#define RA(x) std::begin(x), std::end(x)
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
    int N;
    cin >> N;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vi last(N + 1, -1);
    vi prev(N, -1);
    vi next(N, N);
    for (int i = 0; i < N; i++)
    {
        int p = last[a[i]];
        prev[i] = p;
        if (p != -1)
            next[p] = i;
        last[a[i]] = i;
    }

    int nonce = 0;
    vi hi(N);
    vi adj(N);

    ll ans = 0;
    stack<pii> work;
    work.emplace(0, N);
    while (!work.empty())
    {
        int L, R;
        tie(L, R) = work.top();
        work.pop();
        if (R - L == 1)
        {
            ans += (a[L] == 1);
            continue;
        }
        int M = (L + R) / 2;
        nonce++;

        int hiR = -1, hiL = -1;
        int mxpR = -1, mnnL = INT_MAX;
        for (int q = M; q < R; q++)
        {
            hiR = max(hiR, a[q]);
            mxpR = max(mxpR, prev[q]);
            hi[q] = hiR;
            adj[q] = mxpR;
        }
        for (int p = M - 1; p >= L; p--)
        {
            hiL = max(hiL, a[p]);
            mnnL = min(mnnL, next[p]);
            hi[p] = hiL;
            adj[p] = mnnL;
        }

        for (int i = M; i < R; i++)
        {
            int D = hi[i];
            int j = i - D + 1;
            if (j < M && j >= L && hi[j] <= D && adj[i] < j && adj[j] > i)
                ans++;
        }
        for (int i = L; i < M; i++)
        {
            int D = hi[i];
            int j = i + D - 1;
            if (j >= M && j < R && hi[j] <= D && adj[i] > j && adj[j] < i)
                ans++;
        }

        work.emplace(L, M);
        work.emplace(M, R);
    }
    cout << ans << '\n';

    return 0;
}