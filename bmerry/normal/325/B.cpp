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

static ll eval(ll t, ll m)
{
    return (2 * t + 1) * (t + m);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N;
    cin >> N;
    vector<ll> ans;
    for (ll s = 0; (1LL << s) <= 2 * N; s++)
    {
        ll m = (1LL << s) - 1;
        ll lo = -1;
        ll hi = 1;
        while (eval(hi, m) < N)
            hi <<= 1;
        while (hi - lo > 1)
        {
            ll t = (lo + hi) / 2;
            if (eval(t, m) < N)
                lo = t;
            else
                hi = t;
        }
        if (eval(hi, m) == N)
            ans.push_back((2 * hi + 1) << s);
    }
    sort(RA(ans));
    for (int i = 0; i < SZ(ans); i++)
        cout << ans[i] << '\n';
    if (ans.empty())
        cout << "-1\n";

    return 0;
}