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
    ios::sync_with_stdio(false);
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
    int N, M;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(RA(S), greater<int>());

    cin >> M;
    vector<pair<char, int> > acts;
    int P = 0;
    for (int i = 0; i < M; i++)
    {
        char a;
        int t;
        cin >> a >> t;
        t--;
        acts.emplace_back(a, t);
        if (a == 'p')
            P++;
    }
    S.resize(M);

    if (P == M)
    {
        int score = 0;
        for (int i = 0; i < M; i++)
            score += (acts[i].second ? -S[i] : S[i]);
        cout << score << '\n';
        return 0;
    }

    P = M;

    vector<int> dp(1 << P);
    vector<int> dp2(1 << P);
    for (int i = M - 1; i >= 0; i--)
    {
        char a = acts[i].first;
        int t = acts[i].second;
        for (int m = 1; m < (1 << P); m++)
        {
            if (__builtin_popcount(m) < M - i)
                continue;
            if (a == 'p')
            {
                int lo = __builtin_ctz(m);
                int lbit = 1 << lo;
                dp2[m] = dp[m ^ lbit] + (t ? -S[lo] : S[lo]);
            }
            else if (t == 0)
            {
                int best = dp[m];
                for (int j = 0; j < M; j++)
                    if (m & (1 << j))
                        best = max(best, dp[m ^ (1 << j)]);
                dp2[m] = best;
            }
            else
            {
                int best = dp[m];
                for (int j = 0; j < P; j++)
                    if (m & (1 << j))
                        best = min(best, dp[m ^ (1 << j)]);
                dp2[m] = best;
            }
        }
        dp.swap(dp2);
    }
    cout << dp[(1 << P) - 1] << '\n';

    return 0;
}