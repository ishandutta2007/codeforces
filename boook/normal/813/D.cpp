/*input
6
62 22 60 61 48 49
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX][MAX] , cnt[MAX * 100] , m[MAX];

int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int ans = 0;
	REP(i , 0 , n + 1){
		REP(j , 0 , 7) m[j] = 0;
		REP(j , 1 , i + 1) m[x[j] % 7] = max(m[x[j] % 7] , dp[i][j]);
		REP(j , 1 , i + 1) cnt[x[j]] = max(cnt[x[j]] , dp[i][j]);
		REP(j , i + 1 , n + 1){
			int tmp = 0;
			tmp = max(tmp ,   m[x[j] % 7] + 1);
			tmp = max(tmp , cnt[x[j] - 1] + 1);
			tmp = max(tmp , cnt[x[j] + 1] + 1);
			tmp = max(tmp , dp[i][0] + 1);
			dp[j][i] = dp[i][j] = tmp;
			m[x[j] % 7] = max(m[x[j] % 7] , dp[i][j]);
			cnt[x[j]] = max(cnt[x[j]] , dp[i][j]);
			// DB4(i , j , dp[i][j] , "");
		}
		REP(j , 1 , n + 1) cnt[x[j]] = 0;
		REP(j , 1 , n + 1) ans = max(ans , dp[i][j]);
	}
	cout << ans << endl;
    return 0;
}