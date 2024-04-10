/*input
2 3
2 -6 2
-2 -2 1
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
#define MAX 2000
#define INF 1000000000000LL

int n , m , x[MAX][MAX] , p[MAX][MAX];
int big[MAX] , dp[MAX][MAX];
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] = p[i][j - 1] + x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) dp[i][j] = -INF;

	// REP(i , 1 , n + 1) {
	// 	REP(j , 1 , m + 1)  cout << p[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << "---" << endl;
	big[0] = big[m + 1] = -INF;
	REP(i , 1 , m + 1) dp[1][i] = p[1][i];// , cout << p[1][i]; cout << endl;
	REP(i , 2 , n + 1){
		if(i % 2 == 0){
			RREP(j , m , 1)    big[j] = max(big[j + 1] , dp[i - 1][j]);
			REP(j , 1 , m + 1) dp[i][j] = big[j + 1] + p[i][j];
		}
		else {
			REP(j , 1 , m + 1) big[j] = max(big[j - 1] , dp[i - 1][j]);
			REP(j , 1 , m + 1) dp[i][j] = big[j - 1] + p[i][j];
		}
		// REP(j , 1 , m + 1) cout << big[i] << " "; cout << endl;
	}
	int ans = -INF;
	REP(j , 1 , m + 1) ans = max(ans , dp[n][j]);
	cout << ans << endl;
    return 0;
}