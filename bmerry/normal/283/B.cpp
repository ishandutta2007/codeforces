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

static vector<ll> cache;

static ll total(int x, const vector<int> &a)
{
    if (x <= 0 || x > SZ(a))
        return 0;
    else if (cache[x] != -2)
        return cache[x];
    else
    {
        cache[x] = -1;
        int x2 = x + a[x - 1];
        if (x2 > SZ(a))
            return cache[x] = a[x - 1];
        int x3 = x2 - a[x2 - 1];
        ll sub = total(x3, a);
        if (sub >= 0)
            return cache[x] = a[x - 1] + a[x2 - 1] + sub;
        else
            return cache[x] = sub;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 1; i < N; i++)
        cin >> a[i];

    cache.clear();
    cache.resize(N + 1, -2);
    for (int i = 1; i < N; i++)
    {
        a[0] = i;
        cache[1] = -2;
        cout << total(1, a) << '\n';
    }
    return 0;
}