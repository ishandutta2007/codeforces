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

static void solve()
{
    string a, b;
    cin >> a >> b;
    int A = SZ(a);
    int B = SZ(b);
    vi pre(B, A), suf(B, -1);
    int pos = 0;
    for (int i = 0; i < B; i++)
    {
        while (pos < A && a[pos] != b[i])
            pos++;
        if (pos == A)
            break;
        pre[i] = pos;
        pos++;
    }
    pos = A - 1;
    for (int i = B - 1; i >= 0; i--)
    {
        while (pos >= 0 && a[pos] != b[i])
            pos--;
        if (pos < 0)
            break;
        suf[i] = pos;
        pos--;
    }

    int best = B;
    int bestL = 0;
    int bestR = B;
    int R = 0;
    for (int L = 0; L < B; L++)
    {
        int p = (L == 0) ? -1 : pre[L - 1];
        if (p == A)
            break;
        if (R < L)
            R = L;
        while (R < B && suf[R] <= p)
            R++;
        if (R - L < best)
        {
            best = R - L;
            bestL = L;
            bestR = R;
        }
    }
    b.erase(bestL, bestR - bestL);
    if (b.empty())
        b = "-";
    cout << b << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}