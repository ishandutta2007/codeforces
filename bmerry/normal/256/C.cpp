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

static ll p4(ll x)
{
    return x * x * x * x;
}

static ll p2(ll x)
{
    return x * x;
}

static int grundy(ll x)
{
    if (x < 4)
        return 0;

    int lo = ceil(sqrt(sqrt(double(x)))) - 1;
    while (p4(lo) < x)
        lo++;
    int hi = floor(sqrt(x)) + 1;
    while (p2(hi) > x)
        hi--;

    int limits[] = {0, 4, 16, 82, 6724, 50626, 900000};
    int values[] = {0, 1, 2, 0, 3, 1};
    bool seen[5] = {};
    for (int i = 0; i < 7; i++)
        if (hi >= limits[i] && lo < limits[i + 1])
            seen[values[i]] = true;
    int g = 0;
    while (seen[g])
        g++;
    return g;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    int g = 0;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        g ^= grundy(a);
    }
    if (g != 0)
        cout << "Furlo\n";
    else
        cout << "Rublo\n";

    return 0;
}