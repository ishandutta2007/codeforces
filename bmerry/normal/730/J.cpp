#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
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

static int dp[101][10001];

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
    vi bsort = b;
    sort(RA(bsort), greater<int>());
    int soda = accumulate(RA(a), 0);
    int k = 0;
    int sum = 0;
    while (sum < soda)
    {
        sum += bsort[k];
        k++;
    }

    int cap = 0;
    memset(dp, 0x80, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        cap += b[i];
        for (int j = min(k, i + 1); j > 0; j--)
            for (int c = b[i]; c <= cap; c++)
                dp[j][c] = max(dp[j][c], dp[j - 1][c - b[i]] + a[i]);
    }
    int keep = *max_element(&dp[k][soda], &dp[k][cap + 1]);
    int pour = soda - keep;
    cout << k << ' ' << pour << '\n';
    return 0;
}