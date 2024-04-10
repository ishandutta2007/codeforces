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
    ll tx, ty;
    string s;
    cin >> N >> s >> tx >> ty;
    vll px(N + 1), py(N + 1);
    for (int i = 0; i < N; i++)
    {
        int dx = 0, dy = 0;
        switch (s[i])
        {
        case 'D': dy = -1; break;
        case 'U': dy = 1; break;
        case 'L': dx = -1; break;
        case 'R': dx = 1; break;
        }
        px[i + 1] = px[i] + dx;
        py[i + 1] = py[i] + dy;
    }

    auto possible = [&](int L) -> bool
    {
        for (int i = 0; i + L <= N; i++)
        {
            ll bx = px[i] + (px.back() - px[i + L]);
            ll by = py[i] + (py.back() - py[i + L]);
            ll e = abs(tx - bx) + abs(ty - by);
            if ((e + L) % 2 == 0 && e <= L)
                return true;
        }
        return false;
    };

    if (!possible(N))
    {
        cout << "-1\n";
        return;
    }
    int hi = N;
    int lo = -1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        (possible(mid) ? hi : lo) = mid;
    }
    cout << hi << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}