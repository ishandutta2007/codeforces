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

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    redirect(argc, argv);

    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    vector<int> c(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        c[i]--;
    }

    for (int i = 0; i < Q; i++)
    {
        ll a, b;
        cin >> a >> b;
        vector<ll> dp(N, LLONG_MIN / 2);
        ll best[2] = {0, 0};
        int bestc[2] = {-1, -1};
        ll ans = 0;

        for (int j = 0; j < N; j++)
        {
            ll d = dp[c[j]];
            d = max(d, d + a * v[j]);
            if (bestc[0] != c[j])
                d = max(d, best[0] + b * v[j]);
            else
                d = max(d, best[1] + b * v[j]);

            dp[c[j]] = d;
            if (d >= best[0])
            {
                if (bestc[0] != c[j])
                {
                    bestc[1] = bestc[0];
                    best[1] = best[0];
                }
                best[0] = d;
                bestc[0] = c[j];
            }
            else if (d > best[1])
            {
                best[1] = d;
                bestc[1] = c[j];
            }

            ans = max(ans, d);
        }
        cout << ans << '\n';
    }

    return 0;
}