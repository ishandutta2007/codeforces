/*input
7067678 8
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
#define DBGG(i,j)     cout << (i) << " " << (j) << endl
#define DB4(i,j,k,l)  cout << (i) << " " << (j) << " " << (k) << " " << (l) << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define INF 0x3f3f3f3f

int n , mod , h[10][20] , dp[1 << 19][110] , x[20] , po;
int DP(int now , int to , int siz){
	// DB4("in = " , now , to , siz);
	if(dp[now][to] >= 0) return dp[now][to];
	if(siz == 0) return 0;
	dp[now][to] = 0;
	int ok[10];
	REP(i , 0 , 10) ok[i] = 0;
	REP(i , 0 , po){
		if(ok[x[i]] == 0 && (now & (1 << i))){
			ok[x[i]] = 1;
			dp[now][to] += DP(now ^ (1 << i) , (to + mod - h[x[i]][siz - 1]) % mod , siz - 1);
		}
	}
	// DB4(now , to , siz , dp[now][to]);
	return dp[now][to];
}
int32_t main(){
	IOS , cin >> n >> mod;
	REP(i , 0 , 10) h[i][0] = i;
	REP(i , 0 , 10) REP(j , 1 , 20) h[i][j] = h[i][j - 1] * 10 % mod;
	while(n){
		x[po ++] = n % 10;
		n /= 10;
	}
	MEM(dp , -1);
	dp[0][0] = 1;

	int ans = 0 , ok[10];
	REP(i , 0 , 10) ok[i] = 0; ok[0] = 1;

	REP(i , 0 , po){
		if(ok[x[i]] == 0){
			ok[x[i]] = 1;
			ans += DP(((1 << po) - 1) ^ (1 << i) , (mod - h[x[i]][po - 1]) % mod , po - 1);
		}
	}
	cout << ans << endl;
    return 0;
}