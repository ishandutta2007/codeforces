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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int M, K, N, S;
    cin >> M >> K >> N >> S;
    vi a(M);
    vi b(500001);
    for (int i = 0; i < M; i++)
        cin >> a[i];
    for (int i = 0; i < S; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    vi w(500001);
    int bad = 0;
    for (int i = 0; i <= 500000; i++)
        bad += b[i] > 0;

    int window = K + (M - N * K);
    for (int i = 0; i < M; i++)
    {
        int f = a[i];
        w[f]++;
        if (w[f] == b[f])
            bad--;
        if (i >= window)
        {
            f = a[i - window];
            if (w[f] == b[f])
                bad++;
            w[f]--;
        }
        if (bad == 0 && i - window + 1 >= 0 && (i - window + 1) % K == 0)
        {
            cout << window - K << '\n';
            int rem = 0;
            for (int j = i - window + 1; j <= i && rem < window - K; j++)
            {
                if (b[a[j]])
                    b[a[j]]--;
                else
                {
                    cout << j + 1 << ' ';
                    rem++;
                }
            }
            cout << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}