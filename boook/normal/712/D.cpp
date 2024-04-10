/*input
100 1 1000 100
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
#define MAX 400020
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define N 200010

int dp[2][MAX + 10] , pre[MAX + 10] , n , m , k , t;
int32_t main(){
	IOS , cin >> n >> m >> k >> t;
	t = t + t;
	dp[0][N] = 1;
	int sml = INF , big = 0;
	REP(i , 1 , t + 1){
		pre[0] = dp[(i - 1) % 2][0];
		REP(j , 1 , MAX + 1) pre[j] = (dp[(i - 1) % 2][j] + pre[j - 1]) % mod;
		REP(j , 0 , MAX + 1){
			int l = j - k , r = j + k , ll , rr;
			rr = (r >= MAX) ? pre[MAX] : pre[r];
			ll = (l <=   0) ?        0 : pre[l - 1];
			dp[i % 2][j] = (rr + mod - ll) % mod;
		}
	}
	int ans = 0;
	REP(j , 0 , MAX) if(j - N + n > m) ans = (ans + dp[t % 2][j]) % mod;
	cout << ans << endl;
    return 0;
}