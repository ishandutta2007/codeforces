#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
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

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

// Returns DOUBLE the signed area of the polygon
static ll polygon_area2(const std::vector<pnt> &pnts)
{
    ll ans = cross(pnts.back(), pnts[0]);
    for (size_t i = 1; i < pnts.size(); i++)
        ans += cross(pnts[i - 1], pnts[i]);
    return ans;
}

/*** TEMPLATE CODE ENDS HERE */

static int N;
static int nxt(int i)
{
    i++;
    if (i == N)
        return 0;
    else
        return i;
}

#define MOD 1000000007

int main(int argc, const char **argv)
{
    bool valid[201][201] = {{}};

    redirect(argc, argv);
    cin >> N;
    vector<pnt> pnts;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts.push_back(pnt(x, y));
    }
    if (polygon_area2(pnts) < 0)
        reverse(RA(pnts));

    ll dp[201][201] = {{}};
    for (int i = 0; i < N; i++)
    {
        dp[nxt(i)][i] = 1;
    }
    for (int g = 2; g < N; g++)
        for (int j = 0; j < N; j++)
        {
            ll ans = 0;
            int i = (j + g) % N;
            for (int k = nxt(j); k != i; k = nxt(k))
                if (cross(pnts[i], pnts[j], pnts[k]) > 0)
                    ans = (ans + dp[k][j] * dp[i][k]) % MOD;
            dp[i][j] = ans;
        }

    cout << dp[0][1] << '\n';
#if 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                valid[i][j] = false;
            else if (nxt(i) == j || nxt(j) == i)
                valid[i][j] = true;
            else
            {
                bool good = true;
                for (int k = 0; k < N; k++)
                {
                    if (cross(pnts[i], pnts[j], pnts[k]

                for (int k = nxt(i); k != j; k++)
            }
#endif

    return 0;
}