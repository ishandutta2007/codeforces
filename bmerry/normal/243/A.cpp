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
    vector<bool> ans(1048576);
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> next[20];

    for (int b = 0; b < 20; b++)
    {
        next[b].resize(N);
        int m = 1 << b;
        int l = N;
        for (int i = N - 1; i >= 0; i--)
        {
            if (a[i] & m)
                l = i;
            next[b][i] = l;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int cur = a[i];
        int e = i + 1;
        ans[cur] = true;
        while (e < N)
        {
            int best = N;
            for (int b = 0; b < 20; b++)
            {
                int m = 1 << b;
                if (!(cur & m))
                {
                    best = min(best, next[b][e]);
                }
            }
            if (best >= N)
                break;
            cur |= a[best];
            ans[cur] = true;
            e = best + 1;
        }
    }
    cout << count(ans.begin(), ans.end(), true) << '\n';

    return 0;
}