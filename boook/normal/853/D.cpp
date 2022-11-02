/*input
6
2000 2000 2000 2000 2000 1000
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
#define MAX 300700
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX][55];
void U(int &now , int val){ now = min(now , val); }
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i] , x[i] /= 100;
	MEM(dp , INF) , dp[0][0] = 0;
	REP(i , 0 , n){
		REP(j , 0 , 50 + 1){
			U(dp[i + 1][j + x[i + 1] / 10] , dp[i][j] + x[i + 1]);
			int v = min(j , x[i + 1]);
			U(dp[i + 1][j - v] , dp[i][j] + x[i + 1] - v);
		}
	}
	int ans = INF;
	REP(i , 0 , 50 + 1) U(ans , dp[n][i]);
	cout << ans * 100 << endl;
    return 0;
}