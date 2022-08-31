#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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

static vector<int> primes;
static vector<int> bad;

static int beauty(int x)
{
    int ans = 0;
    for (int b : bad)
    {
        if (x < b)
            break;
        while (x % b == 0)
        {
            ans--;
            x /= b;
        }
    }

    for (int p : primes)
    {
        if (x < p)
            break;
        while (x % p == 0)
        {
            ans++;
            x /= p;
        }
    }
    if (x != 1)
        ans++;
    return ans;
}

static void make_primes()
{
    vector<bool> sieve(32000);
    for (int i = 2; i < SZ(sieve); i++)
    {
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < SZ(sieve); j += i)
                sieve[j] = true;
        }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    make_primes();

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    bad.resize(M);
    for (int i = 0; i < M; i++)
        cin >> bad[i];

    int baseline = 0;
    for (int a : A)
        baseline += beauty(a);

    int ans = 0;
    vector<int> dp(N);
    int G = 0;
    for (int i = 0; i < N; i++)
    {
        G = gcd(G, A[i]);
        int B = -beauty(G);
        int score = B * (i + 1);
        for (int j = 0; j < i; j++)
            score = max(score, dp[j] + B * (i - j));
        dp[i] = score;
        ans = max(ans, score);
    }

    ans += baseline;
    cout << ans << '\n';

    return 0;
}