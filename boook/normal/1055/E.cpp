/*input
5 3 3 5
5 5 2 1 1
1 2
2 3
3 4
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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , s , m , k , x[MAX] , v[MAX] , dp[MAX][MAX] , g[MAX][2] , l[MAX];
// goal : find k - 1 sml
int judge(int val){
	REP(i , 1 , n + 1) v[i] = x[i] <= val ? 1 : 0;
	REP(i , 1 , n + 1) v[i] += v[i - 1];
	// REP(i , 1 , n + 1) cout << v[i] << " "; cout << endl;
	// REP(i , 1 , n + 1) cout << l[i] << " "; cout << endl;
	REP(i , 0 , n + 1) REP(j , 0 , m + 1) dp[i][j] = 0;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1){
		dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
		if(l[i] != INF) dp[i][j] = max(dp[i][j] , dp[l[i] - 1][j - 1] + v[i] - v[l[i] - 1]);
	}
	// cout << dp[2][1] << endl;
	// cout << dp[4][2] << endl;
	// cout << dp[n][m] << endl;
	return dp[n][m] >= k;
}
int32_t main(){
	IOS;
	cin >> n >> s >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , s + 1) cin >> g[i][0] >> g[i][1];

	REP(i , 1 , n + 1) l[i] = INF;
	REP(i , 1 , n + 1){
		REP(j , 1 , s + 1)
			if(g[j][0] <= i && i <= g[j][1])
				l[i] = min(l[i] , g[j][0]);
	}
	// cout << judge(2) << endl;
	// return 0;
	int ans = 1000000009;
	RREP(j , 30 , 0){
		int to = ans - (1LL << j);
		if(to >= 1 && judge(to)) ans = to;
	}
	if(ans == 1000000009) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}