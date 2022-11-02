/*input
5
10 10 10 -1 -1
-1 10 10 10 10
-1 10 10 10 10
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
#define MAX 100900
#define INF 1000000000000000LL

int n , x[MAX][3] , s[MAX] , dp[MAX][4];
void U(int &now , int val){
	now = max(now , val);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(j , 0 , 3) REP(i , 1 , n + 1) cin >> x[i][j];
	REP(j , 0 , 3) REP(i , 1 , n + 1) s[i] += x[i][j];
	REP(j , 0 , 4) REP(i , 0 , n + 1) dp[i][j] = -INF;
	dp[0][0] = 0;
	REP(i , 1 , n + 1){
		U(dp[i][0] , dp[i - 1][0] + x[i][0]);
		U(dp[i][0] , dp[i - 1][1] + x[i][0] + x[i][1]);
		U(dp[i][0] , dp[i - 1][2] + x[i][0] + x[i][1] + x[i][2]);
		U(dp[i][0] , dp[i - 1][3] + s[i]);

		U(dp[i][1] , dp[i - 1][0] + x[i][0] + x[i][1]);
		U(dp[i][1] , dp[i - 1][1] + x[i][1]);
		U(dp[i][1] , dp[i - 1][2] + x[i][1] + x[i][2]);

		U(dp[i][2] , dp[i - 1][0] + x[i][0] + x[i][1] + x[i][2]);
		U(dp[i][2] , dp[i - 1][1] + x[i][1] + x[i][2]);
		U(dp[i][2] , dp[i - 1][2] + x[i][2]);
		U(dp[i][2] , dp[i - 1][3] + s[i]);

		U(dp[i][3] , dp[i - 1][0] + s[i]);
		U(dp[i][3] , dp[i - 1][2] + s[i]);
		U(dp[i][3] , dp[i - 1][3] + s[i]);

	}
	cout << dp[n][2] << endl;
    return 0;
}