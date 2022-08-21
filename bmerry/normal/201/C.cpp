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
    vector<ll> B(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> B[i];

    vector<ll> lscore(N), rscore(N);
    lscore[0] = 0;
    for (int i = 1; i < N; i++)
    {
        if (B[i - 1] >= 2)
            lscore[i] = lscore[i - 1] + (B[i - 1] / 2 * 2);
    }

    rscore[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        if (B[i] >= 2)
            rscore[i] = rscore[i + 1] + (B[i] / 2 * 2);
    }

    ll run = lscore[0] + rscore[0];
    ll ans = run;
    for (int i = 1; i < N; i++)
    {
        run -= rscore[i - 1];
        run += rscore[i];
        run += (B[i - 1] - 1) / 2 * 2 + 1;
        run = max(run, lscore[i] + rscore[i]);
        ans = max(ans, run);
    }

    cout << ans << '\n';

    return 0;
}