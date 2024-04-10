#pragma GCC optimize("O3")
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

static bool solve()
{
    int N;
    cin >> N;
    vector<vi> a(N, vi(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    for (int i = 0; i < N; i++)
        if (a[i][i] != 0)
            return false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] != a[j][i])
                return false;
    constexpr int c_block = 256;
    constexpr int r_block = 64;
    for (int c0 = 0; c0 < N; c0 += c_block)
    {
        int c1 = min(c0 + c_block, N);
        for (int r0 = 0; r0 < N; r0 += r_block)
            for (int s0 = 0; s0 < N; s0 += r_block)
            {
                int r1 = min(r0 + r_block, N);
                int s1 = min(s0 + r_block, N);
                for (int i = r0; i < r1; i++)
                    for (int j = s0; j < s1; j++)
                    {
                        int v = a[i][j];
                        int bad = 0;
                        for (int k = c0; k < c1; k++)
                            bad += (a[i][k] < v) & (a[j][k] < v);
                        if (bad > 0)
                            return false;
                    }
            }
    }
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    if (solve())
        cout << "MAGIC\n";
    else
        cout << "NOT MAGIC\n";

    return 0;
}