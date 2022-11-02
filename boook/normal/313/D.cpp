/*input

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
#define int int_fast64_t
#define MAX 330
#define INF 1000000000000000LL

int n , m , k , dp[MAX][MAX];
vector<PII> v[MAX];
void U(int &now , int val){ now = min(now , val); }
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , m + 1){
		int l , r , val;
		cin >> l >> r >> val;
		v[r].pb(mp(l , val));
	}
	REP(i , 0 , MAX) REP(j , 0 , MAX) dp[i][j] = INF;
	dp[0][0] = 0;
	REP(i , 1 , n + 1){
		REP(j , 0 , i + 1) dp[i][j] = dp[i - 1][j];
		for(auto to : v[i]){
			int len = i - to.A + 1;
			REP(j , len , i + 1) U(dp[i][j] , dp[to.A - 1][j - len] + to.B);
		}
		RREP(j , i , 0) U(dp[i][j] , dp[i][j + 1]);
		REP(j , 0 , i + 1){
			REP(ii , 0 , j + 1){
				U(dp[i - ii][j - ii] , dp[i][j]);
			}
		}
		// REP(j , 0 , i + 1) DB4(i , j , " = " , dp[i][j]);
	}
	if(dp[n][k] == INF) cout << -1 << endl;
	else cout << dp[n][k] << endl;
    return 0;
}