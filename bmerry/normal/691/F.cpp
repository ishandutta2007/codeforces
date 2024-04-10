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

static constexpr int MAXV = 3000000;

struct query
{
    int p;
    int idx;
    ll psum = 0;

    bool operator<(const query &other) const { return p < other.p; }
};

static void solve()
{
    int N;
    cin >> N;
    vi freq(MAXV + 1);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
    }
    int M;
    cin >> M;
    vector<query> q(M);
    for (int i = 0; i < M; i++)
    {
        cin >> q[i].p;
        q[i].idx = i;
    }
    sort(RA(q));

    for (int i = 1; i * i <= MAXV; i++)
    {
        if (!freq[i])
            continue;
        int qi = 0;
        int top = MAXV / i;
        for (int j = i; j <= top; j++)
        {
            if (!freq[j])
                continue;
            int prod = i * j;
            qi = upper_bound(q.begin() + qi, q.end(), query{prod, 0, 0}) - q.begin();
            if (qi == M)
                break;
            if (i == j)
                q[qi].psum += ll(freq[i]) * (freq[i] - 1) / 2;
            else
                q[qi].psum += ll(freq[i]) * freq[j];
        }
    }

    vll ans(M);
    ll run = ll(N) * (N - 1) / 2;
    for (int i = 0; i < M; i++)
    {
        run -= q[i].psum;
        ans[q[i].idx] = run;
    }
    for (int i = 0; i < M; i++)
        cout << ans[i] * 2 << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}