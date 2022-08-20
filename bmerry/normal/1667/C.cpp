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
    int N;
    cin >> N;
    int origN = N;
    vector<pii> out;
    switch (N % 3)
    {
    case 1:
        N++;
        [[fallthrough]];
    case 2:
        {
            int M = 2 * N / 3;
            for (int i = 0; i < M / 2; i++)
                out.emplace_back(i, M / 2 - 1 - i);
            for (int i = M / 2; i < M; i++)
                out.emplace_back(i, M - 1 + M / 2 - i);
        }
        break;
    case 0:
        {
            int M = 2 * N / 3;
            for (int i = 0; i < M / 2 - 1; i++)
                out.emplace_back(i, M / 2 - 2 - i);
            out.emplace_back(M / 2 - 1, M / 2 - 1);
            for (int i = M / 2; i < M; i++)
                out.emplace_back(i, M - 1 + M / 2 - i);
        }
        break;
    }

    cout << out.size() << '\n';
    for (int i = 0; i < SZ(out); i++)
        cout << out[i].first + 1 << ' ' << out[i].second + 1 << '\n';
    cout << flush;

    if (N <= 30)
    {
        vector<vector<bool>> hit(N, vector<bool>(N));
        for (const auto [r, c] : out)
        {
            for (int i = 0; i < N; i++)
            {
                hit[i][c] = true;
                hit[r][i] = true;
            }
            for (int d = -N; d <= N; d++)
                if (r + d >= 0 && r + d < N && c + d >= 0 && c + d < N)
                    hit[r + d][c + d] = true;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                assert(hit[i][j]);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}