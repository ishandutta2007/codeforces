/*input
10 5 12
16 3 24 13 9 8 7 5 12 12
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
#define INF 0x3f3f3f3f

int n , m , k , x[500900] , dp[10010][110][110];
void U(int &now , int val){
	now = min(now , val);
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i] , x[i] %= k;
	if(n <= 10000){
		REP(i , 0 , 10010) REP(j , 0 , 110) REP(ii , 0 , 110) dp[i][j][ii] = INF;
		dp[1][1][x[1]] = x[1];
		REP(i , 1 , n){
			REP(j , 1 , m + 1){
				REP(ii , 0 , k){
					int val = (ii + x[i + 1]) % k;
					U(dp[i + 1][j + 0][(ii + x[i + 1]) % k] , dp[i][j][ii] - ii + val);
					U(dp[i + 1][j + 1][x[i + 1]] , dp[i][j][ii] + x[i + 1]);
				}
			}
		}
		int ans = INF;
		REP(i , 0 , k) ans = min(ans , dp[n][m][i]);
		cout << ans << endl;
	}
	else {
		vector<int> sol;
		int ans;
		REP(i , 1 , n + 1) x[i] = (x[i] + x[i - 1]) % k;
		REP(i , 1 , n + 1){
			if(sol.empty() || sol.back() <= x[i]) sol.pb(x[i]) , ans = sol.size();
			else {
				ans = upper_bound(ALL(sol) , x[i]) - sol.begin();
				sol[ans] = x[i] , ans ++;
			}
		}
		if(ans >= m) cout << x[n] << endl;
		else cout << x[n] + k << endl;
	}
    return 0;
}