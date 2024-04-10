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

    int N, X;
    cin >> N >> X;
    X--;
    vi F(N, -1);
    vi P(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> F[i];
        F[i]--;
        if (F[i] != -1)
            P[F[i]] = i;
    }

    vi chains;
    int Xp = -1;
    for (int i = 0; i < N; i++)
        if (F[i] == -1)
        {
            int cur = i;
            int len = 0;
            bool hasX = false;
            while (cur != -1)
            {
                len++;
                if (cur == X)
                {
                    Xp = len;
                    hasX = true;
                }
                cur = P[cur];
            }
            if (!hasX)
                chains.push_back(len);
        }

    vector<bool> dp(N + 1);
    dp[0] = true;
    for (int i = 0; i < SZ(chains); i++)
    {
        int c = chains[i];
        for (int j = N; j >= c; j--)
            dp[j] = dp[j] | dp[j - c];
    }
    for (int i = 0; i <= N; i++)
        if (dp[i])
            cout << i + Xp << '\n';

    return 0;
}