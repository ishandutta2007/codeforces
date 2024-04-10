/*input
2 2
5 5
2 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 300900;
const int INF = 0x3f3f3f3f;

int n , k , x[MAX] , y[MAX] , dp[MAX][2];
int U(int &now , int val){
	now = min(now , val);
}
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cin >> y[i];

	dp[0][0] = 0;
	dp[0][1] = 0;
	REP(i , 1 , n + 1){
		dp[i][0] = INF;
		dp[i][1] = INF;
		// dp[i - 1][0] to dp[i][1];
		if(dp[i - 1][0] <= k && y[i] >= 1 && x[i] - (k - dp[i - 1][0]) <= (y[i] - 1) * k){
			if((x[i] + 1) * k >= y[i]){
				U(dp[i][1] , max(1LL , y[i] - x[i] * k));
			}
		}
		// dp[i - 1][1] to dp[i][0]
		if(dp[i - 1][1] <= k && x[i] >= 1 && y[i] - (k - dp[i - 1][1]) <= (x[i] - 1) * k){
			if((y[i] + 1) * k >= x[i]){
				U(dp[i][0] , max(1LL , x[i] - y[i] * k));
			}
		}

		// dp[i - 1][0] to dp[i][0]
		if(dp[i - 1][0] <= k && x[i] >= 1 && x[i] <= (k - dp[i - 1][0]) + y[i] * k){
			if(y[i] <= x[i] * k){
				int A = x[i] , B = y[i];
				if(B == 0) U(dp[i][0] , max(1LL , dp[i - 1][0] + A));
				if(B != 0) U(dp[i][0] , max(1LL , A - (k - dp[i - 1][0]) - (B - 1) * k));
			}
		}

		// dp[i - 1][1] to dp[i][1]
		if(dp[i - 1][1] <= k && y[i] >= 1 && y[i] <= (k - dp[i - 1][1] + x[i] * k)){
			if(x[i] <= y[i] * k){
				int A = y[i] , B = x[i];
				if(B == 0) U(dp[i][1] , max(1LL , dp[i - 1][1] + A));
				if(B != 0) U(dp[i][1] , max(1LL , A - (k - dp[i - 1][1]) - (B - 1) * k));

			}
		}
		// DB4(i , " = " , dp[i][0] , dp[i][1]);
	}
	if(dp[n][0] <= k || dp[n][1] <= k) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}