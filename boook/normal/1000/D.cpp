/*input
4
1 1 1 1
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
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 998244353

int n , x[MAX] , dp[MAX] , c[MAX][MAX]; 
int32_t main(){
	IOS;
	REP(i , 0 , MAX) REP(j , 0 , i + 1){
		if(i == j) c[i][j] = 1;
		else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	dp[n + 1] = 1;
	RREP(i , n , 1){
		if(x[i] <= 0) continue;
		else {
			if(i + x[i] + 1 > n + 1) continue;
			else {
				// DBGG("here" , i);
				REP(j , i + x[i] + 1 , n + 2){
					int r = j - 1 , l = i + 1;
					dp[i] = (dp[i] + dp[j] * c[r - l + 1][x[i]]) % mod;
				}
			}
		}
	}
	int ans = 0;
	REP(i , 1 , n + 1) ans = (ans + dp[i]) % mod;
	cout << ans << endl;
    return 0;
}