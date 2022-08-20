//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<pii> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(RA(a));

    vector<pii> seg(M);
    for (int i = 0; i < M; i++)
    {
        cin >> seg[i].first >> seg[i].second;
        seg[i].first--;
    }
    sort(RA(seg), [](const pii &u, const pii &v) {
        return pair(u.first, -u.second) < pair(v.first, -v.second);
    });

    vi segR(N + 1, 0);
    vi segL(N + 1, N);
    int R = 0;
    for (int i = 0; i < M; i++)
    {
        if (seg[i].second <= R)
            continue;
        segR[seg[i].first] = seg[i].second;
        segL[seg[i].second] = seg[i].first;
        R = seg[i].second;
    }
    for (int i = 1; i <= N; i++)
        segR[i] = max(segR[i], segR[i - 1]);
    for (int i = N - 1; i >= 0; i--)
        segL[i] = min(segL[i], segL[i + 1]);

    int p = 0;
    int limL = N;
    int limR = 0;
    vi minR(N + 1);
    vi maxL(N + 1, N);
    while (p < N)
    {
        int q = p;
        int v = a[p].first;
        while (q < N && a[q].first == v)
            q++;
        int t = p;
        for (int i = p; i < q; i++)
        {
            int x = a[i].second;
            while (t < i && segR[a[t].second] <= x)
                t++;
            if (t < i)
            {
                maxL[x] = a[t].second;
                minR[a[t].second + 1] = x + 1;
            }
            if (i > p && segR[a[i - 1].second] > x)
            {
                int x2 = a[i - 1].second;
                limL = min(limL, x);
                limR = max(limR, x2 + 1);
            }
        }
        p = q;
    }
    for (int i = 1; i <= N; i++)
        minR[i] = max(minR[i], minR[i - 1]);
    for (int i = N - 1; i >= 0; i--)
        maxL[i] = min(maxL[i], maxL[i + 1]);

    int q = limR;
    int ans = N;
    for (p = 0; p <= limL; p++)
    {
        q = max(q, p);
        while (q < N && (q < minR[p] || p > maxL[q]))
            q++;
        ans = min(ans, q - p);
    }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}