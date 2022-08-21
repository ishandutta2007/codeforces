// WRONG SOLUTION: exceeds time limit

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
#include <tr1/unordered_map>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;
using namespace std::tr1;

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

static unordered_map<ll, int> cache;

static int recurse(int N, const vector<int> next[15], int to, int L, int R)
{
    ll key = (ll(L) << 40) | (ll(R) << 20) | to;
    if (cache.count(key))
        return cache[key];

    int &ans = cache[key];

    if (to == 0)
    {
        return ans = 0;
    }
    if (L >= R)
        return ans = INT_MAX / 2;
    int x = __builtin_ctz(to);
    int p = next[x][L];
    if (p >= R)
        return ans = INT_MAX / 2;

    int mx = 1 << x;
    int tos = to ^ mx;
    int best = INT_MAX / 2;
    for (int s = tos; ; s = (s - 1) & tos)
    {
        int sl = recurse(N, next, s, L, p);
        int rs = tos ^ s;
        int sr = recurse(N, next, rs, p + 1, R);
        if (sl != INT_MAX / 2 && sr != INT_MAX / 2)
        {
            int sscore = sl + sr;
            int r = 1;
            for (int i = x; i < N; i++)
            {
                if (rs & (1 << i))
                    r++;
                else if (s & (1 << i))
                    sscore += r;
            }
            best = min(best, sscore);
        }
        if (s == 0)
            break;
    }
    return ans = best;
}

static int dp[1 << 15][106];

static int solve(int N, int P, const vector<int> next[15])
{
    const int BIG = INT_MAX / 2;
    int NN = N * (N - 1) / 2;
    for (int i = 1; i <= NN; i++)
        dp[0][i] = BIG;
    dp[0][0] = 0;
    for (int b = 1; b < (1 << N); b++)
    {
        int cost[15];
        for (int i = 0; i < N; i++)
        {
            if (b & (1 << i))
            {
                int c = 0;
                for (int j = i + 1; j < N; j++)
                    if (b & (1 << j))
                        c++;
                cost[i] = c;
            }
            else
                cost[i] = -1;
        }
        for (int x = 0; x <= NN; x++)
        {
            int d = BIG;
            for (int i = 0; i < N; i++)
                if (cost[i] >= 0 && cost[i] <= x)
                {
                    int p = x - cost[i];
                    int m = b ^ (1 << i);
                    if (dp[m][p] < P)
                    {
                        int n = next[i][dp[m][p]];
                        if (n < P)
                            d = min(d, n + 1);
                    }
                }
            dp[b][x] = d;
        }
    }

    int ans = 0;
    while (ans <= NN && dp[(1 << N) - 1][ans] == BIG)
        ans++;
    if (ans > NN)
        return BIG;
    else
        return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N, M;
    cin >> N;

    unordered_map<string, int> posmap;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        posmap[s] = i;
    }

    cin >> M;
    int best;
    int bestscore = INT_MAX / 2;
    for (int sub = 0; sub < M; sub++)
    {
        cache.clear();
        int K;
        cin >> K;
        vector<int> prob;
        for (int i = 0; i < K; i++)
        {
            string s;
            cin >> s;
            if (posmap.count(s))
                prob.push_back(posmap[s]);
        }

        int P = prob.size();
        vector<int> next[15];
        for (int i = 0; i < N; i++)
            next[i].resize(P);
        int last[15];
        fill(last, last + N, P);
        for (int i = P - 1; i >= 0; i--)
        {
            last[prob[i]] = i;
            for (int j = 0; j < N; j++)
                next[j][i] = last[j];
        }

        int score = solve(N, P, next);
        if (score < bestscore)
        {
            best = sub;
            bestscore = score;
        }
    }

    if (bestscore >= INT_MAX / 2)
        cout << "Brand new problem!\n";
    else
    {
        int s = N * (N - 1) / 2 - bestscore + 1;
        cout << best + 1 << "\n[:";
        for (int i = 0; i < s; i++)
            cout << '|';
        cout << ":]\n";
    }

    return 0;
}