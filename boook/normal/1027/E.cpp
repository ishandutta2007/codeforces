/*input
49 1808
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
#define MAX 550 
#define INF 0x3f3f3f3f
#define mod 998244353

int n , k , dp[MAX][MAX];
void U(int &now , int val){
	now = (now + val) % mod;
}
int32_t main(){
	IOS;
	cin >> n >> k;
	dp[0][0] = 1;
	REP(i , 0 , n) REP(j , 0 , n){
		REP(k , 1 , n + 1) if(i + k <= n) U(dp[i + k][max(j , k)] , dp[i][j]);
	}
	// REP(i , 1 , n + 1) cout << dp[n][i] << " " ; cout << endl;
	int ans = 0;
	REP(i , 1 , n + 1) REP(j , 1 , n + 1){
		if(i * j < k) U(ans , dp[n][i] * dp[n][j]);
	}
	U(ans , ans);
	cout << ans << endl;
    return 0;
}