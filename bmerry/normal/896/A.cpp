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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
}

/*** TEMPLATE CODE ENDS HERE */

static const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
static const string f1 = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
static const string f1p[3] = {
    "What are you doing while sending \"",
    "\"? Are you busy? Will you send \"",
    "\"?"
};
static vector<ll> len;
static constexpr ll BIG = 1000000000000000001;

static char solve(int n, ll k)
{
    if (k >= len[n])
        return '.';
    if (n == 0)
        return f0[k];
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (k < SZ(f1p[i]))
                return f1p[i][k];
            k -= SZ(f1p[i]);
            if (k < len[n - 1])
                return solve(n - 1, k);
            k -= len[n - 1];
        }
    }
    return '.';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int Q;
    cin >> Q;
    len.resize(100001);
    len[0] = SZ(f0);
    for (int i = 1; i <= 100000; i++)
    {
        ll L = SZ(f1) + 2 * len[i - 1];
        L = min(L, BIG);
        len[i] = L;
    }
    for (int i = 0; i < Q; i++)
    {
        ll n, k;
        cin >> n >> k;
        k--;
        cout << solve(n, k);
    }
    cout << '\n';

    return 0;
}