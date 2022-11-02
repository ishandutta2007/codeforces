/*input
3
0 0 1
0 0 1
1 1 0
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
#define MAX 550
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX][MAX] , dp[MAX][MAX][2][2];
int ppow(int a , int k){
	if(k == 0) return 1 % mod;
	if(k % 2 == 0) return 1LL * ppow(1LL * a * a % mod , k >> 1);
	if(k % 2 == 1) return 1LL * ppow(1LL * a * a % mod , k >> 1) * a % mod;
}
inline int T(int now){
	if(now > n) now -= n;
	if(now < 1) now += n;
	return now;
}
inline int DP(int i , int j , int a , int b){
	if(dp[i][j][a][b] != -1) return dp[i][j][a][b];


	if(i == j) dp[i][j][a][b] = x[i][T(i - 1)] * a + x[i][T(j + 1)] * b;
	else {

		int fr = T(i - 1) , ba = T(j + 1);
		long long val = 0;
		dp[i][j][a][b] = 0;

		if(a == 1 && b == 1){
			int k = i;
			while(1){
				if(x[fr][k]){
					int vl = (k == i) ? 1 : DP(i , T(k - 1) , 1 , 1);
					int vr = (k == j) ? 1 : DP(T(k + 1) , j , 1 , 1);
					val = (val + 1LL * vl * vr) % mod;
				}
				if(k == j) break;
				else k = T(k + 1);
			}
			dp[i][j][a][b] = val + DP(i , j , 0 , 1);
			if(dp[i][j][a][b] >= mod) dp[i][j][a][b] -= mod;
		}
		else {
			int k = i , who = (a == 1) ? fr : ba , vl , vr;
			while(1){
				if(x[who][k]){
					if(a == 1){
						vl = (k == i) ? 1 : DP(i , T(k - 1) , 1 , 1);
						vr = (k == j) ? 1 : DP(T(k + 1) , j , a , b);
					}
					if(b == 1){
						vl = (k == i) ? 1 : DP(i , T(k - 1) , a , b);
						vr = (k == j) ? 1 : DP(T(k + 1) , j , 1 , 1);
					}
					val = (val + 1LL * vl * vr) % mod;
				}
				if(k == j) break;
				else k = T(k + 1);
			}
			dp[i][j][a][b] = val;
		}
		// cout << i << " " << j << " " << a << " " << b << " = " << dp[i][j][a][b] << endl;
	}
	return dp[i][j][a][b];
}
int32_t main(){
	IOS;
	cin >> n;
	MEM(dp , -1);
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) cin >> x[i][j];
	long long ans = 0;
	REP(i , 1 , n + 1) REP(j , i , n + 1) if(x[i][j]){
		long long v1 = T(i + 1) == j ? 1 : DP(T(i + 1) , T(j - 1) , 1 , 1);
		long long v2 = T(j + 1) == i ? 1 : DP(T(j + 1) , T(i - 1) , 1 , 1);
		ans = (ans + v1 * v2) % mod;
	}
	// DBGG("ans = " , ans);
	cout << ans * ppow(n - 1 , mod - 2) % mod << endl;
    return 0;
}