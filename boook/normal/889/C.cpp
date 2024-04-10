/*input
5 2
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
#define mod 1000000007LL

int n , m , dp[MAX];
int ni[MAX] , gi[MAX];
int C(int a , int b){
	if(a < b) return 0;
	return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
	gi[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
	IOS;
	cin >> n >> m;
	dp[1] = 1;
	int help = 0;
	REP(i , 2 , n + 1){
		int to = i - m - 1;
		help = help * (i - 2) % mod;
		if(to >= 1){
			int tmp = dp[to] * C(i - 2 , i - to - 1) % mod * gi[i - to - 1] % mod;
			help = (help - tmp + mod) % mod;
		}
		help = (help + dp[i - 1]) % mod;
		dp[i] = help;
		// REP(j , 1 , i){
		// 	if(i - j <= m){
		// 		int val = dp[j] * C(i - 2 , i - j - 1) % mod * gi[i - j - 1] % mod; 
		// 		dp[i] = (dp[i] + val) % mod;
		// 	}
		// }
		// DB4("dp[" , i , "] = " , dp[i]);
	}

	int ans = gi[n];
	// DBGG("ans = " , ans);
	int cnt = 0;
	REP(i , 1 , n + 1){
		int tmp = dp[i] * C(n - 1 , n - i) % mod * gi[n - i] % mod;
		cnt += tmp;
		// DB4("cnt = " , cnt , C(n - 1 , n - i) , gi[n - i]);
		ans = (ans - tmp + mod) % mod;
	}
	cout << ans << endl;
    return 0;
}