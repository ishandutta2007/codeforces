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

static int solve(const int *f, int spare)
{
    int need = 2 * f[1] + f[2];
    if (spare > need)
    {
        int absorb = f[1] + f[2] + f[3];
        if (absorb < spare - need)
            return INT_MAX;
        else
            return spare;
    }
    else
    {
        if (f[4] >= need - spare)
            return need;
        else
            return INT_MAX;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int freq[5] = {};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
    }

    int cost = 0;
    int ans = INT_MAX;
    while (true)
    {
        int cur = solve(freq, cost);
        ans = min(ans, cur);
        if (freq[1] > 0)
        {
            freq[1]--;
            freq[0]++;
            cost++;
        }
        else if (freq[2] > 0)
        {
            freq[2]--;
            freq[0]++;
            cost += 2;
        }
        else
        {
            break;
        }
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}