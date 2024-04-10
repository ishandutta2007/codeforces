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

static std::vector<bool> sieve(int n)
{
    std::vector<bool> comp(n + 1);
    comp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!comp[i])
        {
            for (int j = 2 * i; j <= n; j += i)
                comp[j] = true;
        }
    }
    return comp;
}


static void solve()
{
    vector<bool> comp = sieve(2000000);

    int N;
    cin >> N;
    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(RA(a));
    int ones = 0;
    while (ones < SZ(a) && a[ones] == 1)
        ones++;

    vi ans;
    if (ones >= 2)
    {
        for (int i = 0; i < ones; i++)
            ans.push_back(1);
        for (int i = ones; i < N; i++)
            if (!comp[a[i] + 1])
            {
                ans.push_back(a[i]);
                break;
            }
    }
    else
    {
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (!comp[a[i] + a[j]])
                {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                    goto found;
                }
        ans.push_back(a[0]);
    }
found:
    cout << SZ(ans) << '\n';
    for (int v : ans)
        cout << v << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}