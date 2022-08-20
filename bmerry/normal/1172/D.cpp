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

static void verify(const vector<array<int, 4>> &ans, const vi &rperm, const vi &cperm)
{
    int N = SZ(rperm);
    map<array<int, 2>, array<int, 2>> jumps;
    for (const auto &e : ans)
    {
        array<int, 2> p{{e[0], e[1]}}, q{{e[2], e[3]}};
        assert(p != q);
        assert(!jumps.count(p));
        assert(!jumps.count(q));
        for (int i = 0; i < 4; i++)
            assert(0 <= e[i] && e[i] < N);
        jumps[p] = q;
        jumps[q] = p;
    }

    for (int i = 0; i < N; i++)
    {
        array<int, 2> cur{{i, -1}};
        while (cur[1] < N)
        {
            cur[1]++;
            if (jumps.count(cur))
                cur = jumps[cur];
        }
        assert(cur[0] == rperm[i]);
    }
    for (int i = 0; i < N; i++)
    {
        array<int, 2> cur{{-1, i}};
        while (cur[0] < N)
        {
            cur[0]++;
            if (jumps.count(cur))
                cur = jumps[cur];
        }
        assert(cur[1] == cperm[i]);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi r(N);
    vi c(N);
    for (int i = 0; i < N; i++)
    {
        cin >> r[i];
        r[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        c[i]--;
    }
    auto orig_r = r;
    auto orig_c = c;

    vector<array<int, 4>> ans;
    for (int n = N - 1; n >= 0; n--)
    {
        if (r[n] != n || c[n] != n)
        {
            ans.push_back(array<int, 4>{{n, c[n], r[n], n}});
            replace(r.begin(), r.begin() + n, n, r[n]);
            replace(c.begin(), c.begin() + n, n, c[n]);
        }
    }

    // verify(ans, orig_r, orig_c);

    cout << SZ(ans) << '\n';
    for (const auto &e : ans)
        cout << e[0] + 1 << ' ' << e[1] + 1 << ' ' << e[2] + 1 << ' ' << e[3] + 1 << '\n';

    return 0;
}