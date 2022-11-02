/*input
8
4 5 2 2 1 3 5 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 5050
#define INF 0x3f3f3f3f

int n , dp[MAX][MAX][2] , x[MAX];
int DP(int l , int r , int k){
    if(dp[l][r][k] != -1) return dp[l][r][k];

    if(l == r) dp[l][r][k] = 0;
    else if(k == 0){
        dp[l][r][k] = INF;
        dp[l][r][k] = min(dp[l][r][k] , DP(l + 1 , r , 0) + (x[l] != x[l + 1]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l + 1 , r , 1) + (x[l] != x[r]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l , r - 1 , 0) + (x[r] != x[l]) + (x[r] != x[l]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l , r - 1 , 1) + (x[r] != x[r - 1]) + (x[r] != x[l]));
    }
    else if(k == 1){
        dp[l][r][k] = INF;
        dp[l][r][k] = min(dp[l][r][k] , DP(l + 1 , r , 0) + (x[l] != x[l + 1]) + (x[r] != x[l]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l + 1 , r , 1) + (x[l] != x[r]) + (x[r] != x[l]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l , r - 1 , 0) + (x[r] != x[l]));
        dp[l][r][k] = min(dp[l][r][k] , DP(l , r - 1 , 1) + (x[r] != x[r - 1]));
    }
    return dp[l][r][k];
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    memset(dp , -1 , sizeof dp);
    cout << min(DP(1 , n , 0) , DP(1 , n , 1)) << endl;
    return 0;
}