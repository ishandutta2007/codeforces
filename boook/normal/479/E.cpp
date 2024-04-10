#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007

int n , a , b , k;
int dp[MAX][MAX];
int32_t main(){
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    REPNM(i , 0 , k){
        REPNM(j , 1 , n + 1){
            int dis = abs(j - b);
            if(dis <= 1) continue;
            int l = j - dis + 1 , r = j + dis - 1;
            l = max(l , 1LL) , r = min(r , n);
            dp[i + 1][l] += dp[i][j] , dp[i + 1][j] -= dp[i][j];
            dp[i + 1][j + 1] += dp[i][j] , dp[i + 1][r + 1] -= dp[i][j];
        }
        REPNM(j , 1 , n + 1){
            dp[i + 1][j] = (dp[i + 1][j] + dp[i + 1][j - 1]) % mod;
            dp[i + 1][j] = (dp[i + 1][j] % mod + mod) % mod;
        }
    }
    int ans = 0;
    REPNM(i , 1 , n + 1) ans = (ans + dp[k][i]) % mod;
    cout << ans << endl;
    return 0;
}