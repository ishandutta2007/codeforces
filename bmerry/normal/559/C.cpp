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

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a == 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

/*** TEMPLATE CODE ENDS HERE */

#define MOD 1000000007LL

static ll fact[200001];

static ll choose(ll n, ll r)
{
    return mod(fact[n] * inverse(fact[n - r] * fact[r], MOD), MOD);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    fact[0] = 1;
    for (ll i = 1; i <= 200000; i++)
        fact[i] = fact[i - 1] * i % MOD;

    int R, C, N;
    cin >> R >> C >> N;
    vector<pii> black;
    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        black.emplace_back(r, c);
    }
    sort(RA(black));
    black.emplace_back(R - 1, C - 1);
    N++;
    vector<ll> dp(N);
    for (int i = 0; i < N; i++)
    {
        dp[i] = choose(black[i].first + black[i].second, black[i].first);
        for (int j = 0; j < i; j++)
            if (black[j].second <= black[i].second)
            {
                int dr = black[i].first - black[j].first;
                int dc = black[i].second - black[j].second;
                dp[i] = mod(dp[i] - choose(dr + dc, dr) * dp[j], MOD);
            }
    }
    cout << mod(dp[N - 1], MOD) << '\n';

    return 0;
}