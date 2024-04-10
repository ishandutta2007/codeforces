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
    redirect(argc, argv);

    int N;
    cin >> N;
    vector<ll> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<ll>());
    vector<ll> sums(N + 1);
    for (int i = 0; i < N; i++)
        sums[i + 1] = sums[i] + nums[i];

    vector<ll> ans(N + 1);
    for (int i = 1; i <= N; i++)
    {
        ll x = 1;
        int p = 0;
        ll start = 0;
        ll A = 0;
        while (start < N)
        {
            ll end = min(start + x, (ll) N);
            A += (sums[end] - sums[start]) * p;
            p++;
            x *= i;
            start = end;
        }
        ans[i] = A;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int k;
        cin >> k;
        k = min(k, N);
        cout << ans[k] << ' ';
    }
    cout << '\n';
    return 0;
}