/*input
2 1
1 1 3
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
#define int long long
#define MAX 100
#define INF 0x3f3f3f3f

int n , m , dis[MAX][MAX] , x[MAX] , o[MAX] , dp[1 << 20] , po = 0;
int DP(int now){
	if(dp[now] != -1) return dp[now];
	dp[now] = INF;
	REP(i , 0 , n) REP(j , i + 1 , n){
		if((now & (1 << i)) && (now & (1 << j))){
			dp[now] = min(dp[now] , DP(now ^ (1 << i) ^ (1 << j)) + dis[x[i]][x[j]]);
		}
	}
	return dp[now];
}
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 0 , n) REP(j , 0 , n) dis[i][j] = INF;
	REP(i , 0 , n) dis[i][i] = 0;

	int ans = 0;
	REP(i , 0 , m){
		int a , b , c;
		cin >> a >> b >> c;
		a -- , b -- , ans += c;
		o[a] ++ , o[b] ++;
		dis[a][b] = min(dis[a][b] , c);
		dis[b][a] = min(dis[b][a] , c);
	}

	REP(k , 0 , n) REP(i , 0 , n) REP(j , 0 , n){
		dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
	}

	REP(j , 0 , n) if(dis[0][j] == INF && o[j])
		return cout << -1 << endl , 0;

	REP(i , 0 , n) if(o[i] % 2) x[po ++] = i;

	MEM(dp , -1) , dp[0] = 0;

	cout << ans + DP((1 << po) - 1) << endl;
    return 0;
}