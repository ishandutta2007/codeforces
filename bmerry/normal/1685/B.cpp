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
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    int nA = 0, nB = 0;
    for (char c : s)
    {
        if (c == 'A')
            nA++;
        else
            nB++;
    }
    if (nA != a + c + d || nB != b + c + d)
    {
        cout << "NO\n";
        return;
    }

    int N = SZ(s);
    int any = 0;
    int tA = 0, tB = 0;
    vi gA, gB;
    for (int i = 0; i < N; i++)
        if (i == 0 || s[i - 1] == s[i])
        {
            int j = i + 1;
            while (j < N && s[j] != s[j - 1])
                j++;
            int L = j - i;
            if (L % 2 == 1)
                any += L / 2;
            else if (s[i] == 'A')
            {
                gA.push_back(L / 2 - 1);
                tA += L / 2;
            }
            else
            {
                gB.push_back(L / 2 - 1);
                tB += L / 2;
            }
        }

    int flips = (any + tA + tB) - (c + d);
    if (flips < 0)
    {
        cout << "NO\n";
        return;
    }

    if (any + tA >= c)
    {
        swap(tA, tB);
        swap(gA, gB);
        swap(c, d);
    }
    if (any + tA < c)
    {
        sort(RA(gB), greater<int>());
        int extra = accumulate(gB.begin(), gB.begin() + min(SZ(gB), ll(flips)), 0);
        if (any + tA + extra < c)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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