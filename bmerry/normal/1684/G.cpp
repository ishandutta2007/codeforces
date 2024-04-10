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

static bool augment(int x, const std::vector<std::vector<int> > &edges, std::vector<int> &back, std::vector<bool> &done)
{
    if (x == -1)
        return true;
    if (done[x])
        return false;
    done[x] = true;
    for (int y : edges[x])
    {
        int old = back[y];
        back[y] = x;
        if (augment(old, edges, back, done))
            return true;
        back[y] = old;
    }
    return false;
}

// back must be sized to the number of vertices on the right
int matching(const std::vector<std::vector<int> > &edges, std::vector<int> &back)
{
    std::fill(RA(back), -1);
    int ans = 0;
    int L = SZ(edges);
    for (int i = 0; i < L; i++)
    {
        std::vector<bool> done(L);
        if (augment(i, edges, back, done))
            ans++;
    }
    return ans;
}

static void solve()
{
    int N;
    ll M;
    cin >> N >> M;
    vll t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];
    vector<pll> p;

    int big = 0;
    vector<vi> edges(N);
    for (int i = 0; i < N; i++)
    {
        if (t[i] * 3 > M)
        {
            big++;
            for (int j = 0; j < N; j++)
                if (2 * t[i] + t[j] <= M && t[i] % t[j] == 0)
                    edges[i].push_back(j);
        }
    }

    vi back(N);
    if (matching(edges, back) < big)
    {
        cout << "-1\n";
        return;
    }

    vector<bool> used(N);
    for (int i = 0; i < N; i++)
        if (back[i] != -1)
        {
            ll x = t[i];
            ll y = t[back[i]];
            p.emplace_back(2 * y + x, y + x);
            used[i] = true;
            used[back[i]] = true;
        }
    for (int i = 0; i < N; i++)
        if (!used[i])
            p.emplace_back(3 * t[i], 2 * t[i]);

    cout << p.size() << '\n';
    for (const auto [a, b] : p)
        cout << a << ' ' << b << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}