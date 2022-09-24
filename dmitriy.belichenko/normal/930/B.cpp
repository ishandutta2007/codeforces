#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 1e4 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 26;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int gr[50][50][N];
string s;
int n;
int dp[50];
double ans = 0;
void gen_cycles()
{
    s += s;
    for(int i = 0; i < n; i++)
    {
        string sub = s.substr(i , n );
     //   cout << sub << "\n";
        for(int j = 0; j < n; j++)
        {
            gr[to_i(sub[0])][to_i(sub[j])][j]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> s;
    n = s.size();
    gen_cycles();
    for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sum = 0;
            if(j != 0)
            {
                for(int p = 0; p < MAXN; p++)
                {
                    if(gr[i][p][j] == 1) sum++;
                }
            }
            dp[i] = max(dp[i] , sum);
        }
        ans += (1.0 * dp[i]) / (1.0 * n);
    }
    cout << setprecision(12) << fixed << ans  << "\n";
  //  cout << (double)clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}