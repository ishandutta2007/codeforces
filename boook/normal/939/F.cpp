/*input
20 1
3 19
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
#define MAX 100900
#define INF 0x3f3f3f3f

int len , n , s[MAX] , t[MAX] , dp[110][MAX];
int dq[MAX] , l , r;
int32_t main(){
	IOS;
	cin >> len >> n;
	REP(i , 1 , n + 1) cin >> s[i] >> t[i];
	REP(i , 1 , MAX) dp[0][i] = INF;
	REP(i , 1 , n + 1){
		REP(j , 0 , len + 1) dp[i][j] = dp[i - 1][j];

		l = 1 , r = 0;
		REP(j , 0 , len + 1){
			while(l <= r && dp[i - 1][dq[r]] >= dp[i - 1][j]) r --;
			dq[++r] = j;
			while(l <= r && j - dq[l] > t[i] - s[i]) l ++;
			dp[i][j] = min(dp[i][j] , dp[i - 1][dq[l]] + 2);
		}
		l = 1 , r = 0;
		int pos = t[i];
		RREP(j , t[i] , 0){
			int now = t[i] - j;
			while(l <= r && dp[i - 1][dq[r]] >= dp[i - 1][now]) r --;
			dq[++r] = now;
			int ql = s[i] - j , qr = t[i] - j;
			while(l <= r && (ql <= dq[l] && dq[l] <= qr) == 0) l ++;
			// DB4(j , ql , qr , dq[l]);
			if(l <= r) dp[i][j] = min(dp[i][j] , dp[i - 1][dq[l]] + 1);
		}
	}
	if(dp[n][len] == INF) cout << "Hungry" << endl;
	else cout << "Full" << endl << dp[n][len] << endl;
    return 0;
}