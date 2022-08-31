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
    int N, M, Q;
    cin >> N >> M >> Q;
    vi p(N), ip(N), a(M);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        p[i]--;
        ip[p[i]] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vi next(N, M), p2(M + 1), jump(M + 1);
    for (int i = 0; i <= M; i++)
        jump[i] = i;
    p2[M] = M;
    for (int i = M - 1; i >= 0; i--)
    {
        int idx = ip[a[i]];
        idx++;
        if (idx == N)
            idx = 0;
        p2[i] = next[p[idx]];
        next[a[i]] = i;
    }
    for (int i = 1; i < N; i *= 2)
    {
        if ((N - 1) & i)
        {
            for (int j = 0; j < M; j++)
                jump[j] = jump[p2[j]];
        }
        for (int j = 0; j < M; j++)
            p2[j] = p2[p2[j]];
    }

    for (int i = M - 2; i >= 0; i--)
        jump[i] = min(jump[i], jump[i + 1]);

    string ans(Q, '0');
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        if (jump[L] < R)
            ans[i] = '1';
    }
    cout << ans << '\n';

    return 0;
}