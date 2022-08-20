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

static bool cool(ll x, ll y)
{
    if (y % 2 == 1)
        return x % y == 0;
    else
        return llabs(x % y) == y / 2;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<ll> a(N + 1);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    a[N] = 1;
    vector<int> dp(N + 1, INT_MAX / 2);
    vector<ll> shifted = a;
    dp[N] = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int best = INT_MAX / 2;
        for (int j = i + 1; j <= N; j++)
        {
            if (cool(a[i], shifted[j]))
                best = min(best, dp[j]);

            if ((shifted[j] & 1) == 0)
                shifted[j] >>= 1;
            dp[j]++;
        }
        dp[i] = best;
    }
    cout << *min_element(RA(dp)) << '\n';
    return 0;
}