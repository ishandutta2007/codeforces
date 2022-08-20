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

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, T = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        T += x == 2;
    }

    ll fact[N + 1];
    ll ifact[N + 1];
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = inverse(fact[i], MOD);
    }

    ll dp[N][N];
    dp[0][0] = 1;
    for (int n = 1; n <= N; n++)
    {
        for (int t = 0; t <= n; t++)
        {
            if (t == n)
                dp[n][t] = 1;
            else
            {
                ll s = 0;
                for (int i = 0; i <= t; i++)
                    s = (s + dp[n - 1 - i][t - i]) % MOD;
                if (t < n - 1)
                    for (int i = 0; i <= t; i++)
                        s = (s + dp[n - 2 - i][t - i] * (n - t - 1) * (i + 1)) % MOD;
                dp[n][t] = s;
            }
        }
    }
    cout << dp[N][T] * fact[T] % MOD << '\n';

    return 0;
}