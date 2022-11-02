/*input
5
1 2 3 1 2
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX][2];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1){
		if(x[i - 1] < x[i]){
			dp[i][0] = max(dp[i - 1][0] + x[i] - x[i - 1] , dp[i - 1][1]);
			dp[i][1] = max(dp[i - 1][0] , dp[i - 1][1]);
		}
		else {
			dp[i][1] = max(dp[i - 1][1] + x[i - 1] - x[i] , dp[i - 1][0]);
			dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1]);
		}
	}
	cout << max(dp[n][0] , dp[n][1]) << endl;
    return 0;
}