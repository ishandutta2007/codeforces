/*input
5
1 2 3 2 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX][MAX][2];
int Q(int i , int j , int k){
    if(j == 0) return 0;
    if(i < 0) return INF;
    else return dp[i][j][k];
}
void U(int &now , int val){
    now = min(now , val);
}
int ans[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    // MEM(dp , INF) , MEM(ans , INF);
    REP(i , 0 , n + 1) REP(j , 0 , n + 1) dp[i][j][0] = dp[i][j][1] = INF;
    REP(i , 0 , n + 1) ans[i] = INF;
    dp[0][0][0] = 0;
    REP(i , 1 , n + 1){
        REP(j , 1 , i + 1){

            
            U(dp[i][j][0] , Q(i - 3 , j - 1 , 1) + max(0LL , x[i - 1] - (x[i] - 1))
                                                 + max(0LL , x[i + 1] - (x[i] - 1)));
            if(i >= 3 && j >= 2){
                int tmp = x[i - 1] - max(0LL , x[i - 1] - (x[i - 2] - 1));
                U(dp[i][j][0] , Q(i - 2 , j - 1 , 0) + max(0LL , tmp      - (x[i] - 1))
                                                     + max(0LL , x[i + 1] - (x[i] - 1)));
            }
            dp[i][j][1] = min(dp[i][j][0] , dp[i - 1][j][1]);

            ans[j] = min(ans[j] , dp[i][j][0]);
            ans[j] = min(ans[j] , dp[i][j][1]);
        }
    }
            // DB4(i , j , " = " , dp[i][j]);
    REP(i , 1 , (n + 1) / 2 + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}