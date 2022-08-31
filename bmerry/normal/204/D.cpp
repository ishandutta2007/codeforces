#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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

static ll power2[1000001];

#define MOD 1000000007
static vector<ll> ways(const string &s, char b, char w, int K)
{
    int N = SZ(s);
    vector<int> sumB(N + 1), sumX(N + 1), sumW(N + 1);
    vector<ll> ans(N + 1);
    vector<ll> asum(N + 1);
    for (int i = 1; i <= N; i++)
    {
        sumB[i] = sumB[i - 1];
        sumW[i] = sumW[i - 1];
        sumX[i] = sumX[i - 1];
        if (s[i - 1] == b)
            sumB[i]++;
        else if (s[i - 1] == w)
            sumW[i]++;
        else
            sumX[i]++;

        ans[i] = 0;
        if (i >= K)
        {
            if (sumW[i - K] == sumW[i])
            {
                if (i == K)
                    ans[i] = 1;
                else if (s[i - K - 1] != b)
                {
                    ans[i] = (power2[sumX[i - K - 1]] - asum[i - K - 1]) % MOD;
                }
            }
            if (s[i - 1] == 'X')
                asum[i] = (asum[i - 1] * 2 + ans[i]) % MOD;
            else
                asum[i] = (asum[i - 1] + ans[i]) % MOD;
        }
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;

    power2[0] = 1;
    for (int i = 1; i <= N; i++)
        power2[i] = (power2[i - 1] * 2) % MOD;

    vector<ll> L = ways(s, 'B', 'W', K);
    reverse(RA(s));
    vector<ll> R = ways(s, 'W', 'B', K);
    reverse(RA(s));
    ll sumL = 0;
    ll ans = 0;
    for (int i = K; i + K <= N; i++)
    {
        if (s[i - 1] == 'X')
            sumL = (2 * sumL) % MOD;
        sumL = (sumL + L[i]) % MOD;
        ans = (ans + sumL * R[N - i]) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';

    return 0;
}