#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 5005;
const int MOD = 1e9 + 7;
int sum(int a , int b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
set<pair<char , char>> t;
vector<char> a;
int dp[N][N];
int dp3[N];
int dp2[N][N];
int mem1[N] , mem2[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
        dp3[0] = 1;
        dp[0][0] = 1;
        dp2[0][0] = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(a[i] == 'f')
        {
            dp3[i] = dp3[i - 1] + 1;
        }
        else dp3[i] = dp3[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        fill(mem1 , mem1 + N , 0);
        fill(mem2 , mem2 + N , 0);
        for(int j = 0; j <= n; j++)
        {
           if(a[i] == 'f')
           {
               dp[i + 1][j + 1] = sum( dp[i + 1][j + 1] ,  dp[i][j]);
               mem1[j + 1] = sum( mem1[j + 1] , dp2[i][j]);
               mem1[0] = sum(mem1[0] , -dp2[i][j]);
            }
            else
            {
                dp2[i + 1][j] = sum( dp2[i + 1][j] ,  dp[i][j]);
                mem2[j] = sum( mem2[j ] , dp2[i][j]);
            }
        }
        for(int j = n + 1; j >= 0; j--)
        {
            mem2[j] = sum( mem2[j + 1] , mem2[j]);
            dp2[i + 1][j] = sum(dp2[i + 1][j] , mem2[j]);
            
        }
        for(int j = n + 1; j >= 0; j--)
        {
            mem1[j] = sum( mem1[j + 1] , mem1[j]);
            dp[i + 1][j] = sum(dp[i + 1][j] , mem1[j]);
            
        }
    }
    int ans = 0;
    for(int i = 0; i <= n + 1; i++)
    {
        ans = sum(ans , dp2[n][i]);
    }
    cout << ans << "\n";
    return 0;
}