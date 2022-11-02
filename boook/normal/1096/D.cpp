/*input
6
hhaarr
1 2 3 4 5 6
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
#define INF 1e18

int n;
string s , p = "hard";
int dp[MAX][5] , a[MAX];
int32_t main(){
	IOS;
	cin >> n >> s;
	REP(i , 0 , n) cin >> a[i];

	REP(i , 0 , s.size() + 1) REP(j , 0 , 4) dp[i][j] = INF;
	dp[0][0] = 0;
	REP(i , 0 , s.size()){
		REP(j , 0 , 4){
			if(s[i] == p[j]){
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1] , dp[i][j]);
			}
			else {
				dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
			}
			dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j] + a[i]);
		}
	}
	int ans = INF;
	ans = min(ans , dp[s.size()][0]);
	ans = min(ans , dp[s.size()][1]);
	ans = min(ans , dp[s.size()][2]);
	ans = min(ans , dp[s.size()][3]);
	cout << ans << endl;
    return 0;
}