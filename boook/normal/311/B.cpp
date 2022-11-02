/*input
4 6 2
1 3 5
1 0
2 1
4 9
1 10
2 10
3 12
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
#define INF 1e16

int n , m , k , x[MAX] , p[MAX] , d[MAX] , dp[MAX][110] , nowj;
int w(int s , int t){
	return dp[s][nowj - 1] - (p[t] - p[s]) + x[t] * (t - s);
}
int check(int q , int w , int e){
	int a1 = -q , b1 = dp[q][nowj - 1] + p[q];
	int a2 = -w , b2 = dp[w][nowj - 1] + p[w];
	int a3 = -e , b3 = dp[e][nowj - 1] + p[e];
	return (b1 - b2) / (a2 - a1) >= (b2 - b3) / (a3 - a2);
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 2 , n + 1) cin >> d[i] , d[i] += d[i - 1];
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		x[i] = b - d[a];
	}
	sort(x + 1 , x + 1 + m);
	// REP(i , 1 , m + 1) cout << x[i] << " "; cout << endl;
	REP(i , 1 , m + 1) p[i] = p[i - 1] + x[i];
	// REP(i , 1 , m + 1) cout << p[i] << " "; cout << endl;

	REP(j , 0 , k + 1) REP(i , 0 , m + 1) dp[i][j] = INF;
	dp[0][0] = 0;
	// REP(j , 1 , k + 1){
	// 	nowj = j;
	// 	REP(i , 1 , m + 1){
	// 		dp[i][j] = INF;
	// 		REP(T , 0 , i){
	// 			dp[i][j] = min(dp[i][j] , w(T , i));
	// 		}
	// 		DB4(i , j , " = " , dp[i][j]);
	// 	}
	// }
	REP(j , 1 , k + 1){
		nowj = j;
		deque<int> dq;
		dq.push_back(0);
		REP(i , 1 , m + 1){
			while(dq.size() >= 2 && w(dq[0] , i) >= w(dq[1] , i)) dq.pop_front();
			dp[i][j] = w(dq[0] , i);
			// DB4(i , j , dq[0] , dp[i][j]);
			while(dq.size() >= 2 && check(dq[dq.size() - 1] , dq[dq.size() - 2] , i))
				dq.pop_back();
			dq.push_back(i);
		}
	}
	int ans = dp[m][1];
	REP(i , 1 , k + 1) ans = min(ans , dp[m][i]);
	cout << ans << endl;
    return 0;
}