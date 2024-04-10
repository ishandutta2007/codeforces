/*input
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 -1
3 4 0 -3
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
#define MAX 309
#define INF 0x3f3f3f3f

int n , m , dp[9][MAX][MAX] , now[MAX][MAX] , tmp[MAX][MAX];
int32_t main(){
    IOS;
    cin >> n >> m;

    MEM(dp , INF) , MEM(now , INF);
    REP(i , 0 , 8 + 1) REP(j , 1 , n + 1) dp[i][j][j] = now[j][j] = 0;

    REP(i , 1 , m + 1){
    	int a , b , v1 , v2;
    	cin >> a >> b >> v1 >> v2;
    	dp[0][a][b] = min(dp[0][a][b] , -v1);
    	dp[0][b][a] = min(dp[0][b][a] , -v2);
    }
    REP(ii , 1 , 8 + 1){
    	REP(i , 1 , n + 1) REP(j , 1 , n + 1) REP(k , 1 , n + 1)
    		dp[ii][i][k] = min(dp[ii][i][k] , dp[ii - 1][i][j] + dp[ii - 1][j][k]);
    }

    // REP(i , 1 , n + 1){REP(j , 1 , n + 1) cout << now[i][j] << " "; cout << endl; }

    int ans = 0 , ok;
    RREP(ii , 8 , 0){
    	MEM(tmp , INF) , ok = 1;
    	REP(i , 1 , n + 1) REP(j , 1 , n + 1) REP(k , 1 , n + 1){
    		tmp[i][k] = min(tmp[i][k] , now[i][j] + dp[ii][j][k]);
    	}
    	// cout << now[1][1] << " " << dp[8][1][1] << endl;
    	REP(i , 1 , n + 1) if(tmp[i][i] < 0) ok = 0;
    // REP(i , 1 , n + 1){REP(j , 1 , n + 1) cout << tmp[i][j] << " "; cout << endl; }
    	if(ok){
    		REP(i , 1 , n + 1) REP(j , 1 , n + 1) now[i][j] = tmp[i][j];
    		ans += (1 << ii);
    	}
    }
    if(ans > n) ans = -1;
    cout << ans + 1 << endl;
    return 0;
}