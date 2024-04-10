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

static void strip(string &n)
{
    if (n.empty())
    {
        n = "-1";
        return;
    }
    int p = 0;
    while (p < SZ(n) && n[p] == '0')
        p++;
    n.erase(n.begin(), n.begin() + p);
    if (n.empty())
        n = "0";
}

static void solve()
{
    string n;
    cin >> n;
    vi pos[3];
    int mod = 0;
    for (int i = 0; i < SZ(n); i++)
    {
        pos[n[i] % 3].push_back(i);
        mod = (mod + n[i]) % 3;
    }
    if (mod != 0)
    {
        string a = "-1", b = "-1";
        if (!pos[mod].empty())
        {
            a = n;
            a.erase(a.begin() + pos[mod].back());
            strip(a);
        }
        if (pos[3 - mod].size() >= 2)
        {
            b = n;
            b.erase(b.begin() + pos[3 - mod].back());
            pos[3 - mod].pop_back();
            b.erase(b.begin() + pos[3 - mod].back());
            strip(b);
        }
        if (a == "-1")
            n = b;
        else if (b == "-1" || SZ(a) > SZ(b))
            n = a;
        else
            n = b;
    }
    cout << n << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}