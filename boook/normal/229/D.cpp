/*input
1 
1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , pre[MAX] , dp[MAX][MAX];
int solve(){
	REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i];
	// dp[i][j] = max(dp[j - 1][k] + 1); // i to j > k to j - 1
	// j < i
	REP(i , 1 , n + 1){
		int po = i , ss = 0 , good = -INF;
		REP(j , i , n + 1){
			int sum = pre[j] - pre[i - 1];
			while(po - 1 >= 0 && ss + x[po - 1] <= sum){
				ss += x[--po];
				good = max(good , dp[i - 1][po] + 1);
			}
			if(po == i) dp[i][j] = dp[j][i] = -INF;
			else dp[i][j] = dp[j][i] = good;
		}
	}
	// REP(i , 1 , n + 1){
	// 	REP(j , 1 , n + 1) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	int ans = 0;
	REP(i , 1 , n + 1) ans = max(ans , dp[i][n]);
	return n - ans;
}
// int dd[MAX][MAX];
// int judge(){
// 	REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i];
// 	REP(i , 1 , n + 1) dd[1][i] = 1;
// 	REP(i , 2 , n + 1){
// 		REP(j , i , n + 1){
// 			dd[i][j] = -INF;
// 			REP(k , 1 , i){
// 				int v1 = pre[i - 1] - pre[k - 1];
// 				int v2 = pre[j] - pre[i - 1];
// 				if(v1 <= v2) dd[i][j] = max(dd[i][j] , dd[k][i - 1] + 1);
// 				// if(v1 <= v2) DB4(i , j , v1 , d[k][i - 1] + 1);
// 			}
// 			// DB4(i , j , dd[i][j] , "");
// 		}
// 		// break;
// 	}
// 	int ans = 0;
// 	REP(i , 1 , n + 1) ans = max(ans , dd[i][n]);
// 	return n - ans;
// }
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	cout << solve() << endl;
	// cout << judge() << endl;
    return 0;
}