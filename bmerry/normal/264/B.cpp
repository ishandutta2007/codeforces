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

static vector<int> primes;
static int sieve[100001];

static void make_primes()
{
    memset(sieve, -1, sizeof(sieve));
    for (int i = 2; i < 100000; i++)
        if (sieve[i] == -1)
        {
            sieve[i] = primes.size();
            primes.push_back(i);
            for (int j = 2 * i; j <= 100000; j += i)
                sieve[j] = -2;
        }
}

static vector<int> factorise(int n)
{
    vector<int> ans;
    int i = 0;
    while (sieve[n] == -2)
    {
        if (n % primes[i] == 0)
        {
            ans.push_back(i);
            do
            {
                n /= primes[i];
            } while (n % primes[i] == 0);
        }
        i++;
    }
    if (n > 1)
        ans.push_back(sieve[n]);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    make_primes();

    int N;
    cin >> N;
    int P = primes.size();
    vector<int> dp(P);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vector<int> f = factorise(a);
        int L = 1;
        for (int j = 0; j < SZ(f); j++)
        {
            int p = f[j];
            L = max(L, dp[p] + 1);
        }
        for (int j = 0; j < SZ(f); j++)
        {
            int p = f[j];
            dp[p] = max(dp[p], L);
        }
    }
    int ans = *max_element(RA(dp));
    if (ans == 0)
        ans = 1;
    cout << ans << '\n';

    return 0;
}