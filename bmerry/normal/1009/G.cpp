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

static int bit(int x)
{
    return 1 << x;
}

static bool satisfy(const array<int, 64> &hfreq, const array<int, 64> &dfreq)
{
    for (int i = 0; i < 64; i++)
        if (hfreq[i] < dfreq[i])
            return false;
    return true;
}

static void solve()
{
    string s;
    int M;
    cin >> s >> M;
    int N = SZ(s);

    array<int, 6> freq{};
    array<int, 64> dfreq{}, hfreq{};
    for (char c : s)
        freq[c - 'a']++;
    for (int i = 0; i < 64; i++)
        for (int j = 0; j < 6; j++)
            if (i & bit(j))
                hfreq[i] += freq[j];

    vi valid(N, 63);
    for (int i = 0; i < M; i++)
    {
        int p;
        string fit;
        cin >> p >> fit;
        p--;
        int mask = 0;
        for (char c : fit)
            mask |= bit(c - 'a');
        valid[p] = mask;
        dfreq[mask]++;
    }

    for (int b = 0; b < 6; b++)
        for (int i = 0; i < 64; i++)
            if (!(i & bit(b)))
                dfreq[i | bit(b)] += dfreq[i];

    if (!satisfy(hfreq, dfreq))
    {
        cout << "Impossible\n";
        return;
    }

    string out(N, '?');
    for (int i = 0; i < N; i++)
    {
        int mask = valid[i];
        for (int j = 0; j < 64; j++)
            if ((j & mask) == mask)
                dfreq[j]--;
        int j;
        for (j = 0; j < 6; j++)
        {
            if (!(mask & bit(j)))
                continue;
            freq[j]--;
            for (int k = 0; k < 64; k++)
                if (k & bit(j))
                    hfreq[k]--;
            if (satisfy(hfreq, dfreq))
                break;
            freq[j]++;
            for (int k = 0; k < 64; k++)
                if (k & bit(j))
                    hfreq[k]++;
        }
        assert(j < 6);
        out[i] = 'a' + j;
    }
    cout << out << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}