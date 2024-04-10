#include <bits/stdc++.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define PII pair<int , int>
#define mp make_pair
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define ALL(i) i.begin() , i.end()
#define A first
#define B second
///--------------------------------------
#define int long long
#define MAX 2020
#define INF 0x3f3f3f3f
#define mod 1000000007LL
using namespace std;

int n , m , x[MAX] , dp[MAX][MAX];
int U(int &now , int val){
	now = (now + val) % mod;
}
signed main(){
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(x[i] > m) return cout << 0 << endl , 0;
	
	dp[0][0] = 1;
	REP(i , 1 , n + 1){
		int need = m - x[i];
				 U(dp[i][need - 0] , dp[i - 1][need - 0]); // no
		if(need) U(dp[i][need - 0] , dp[i - 1][need - 1]); // left
		
		if(need) U(dp[i][need - 1] , dp[i - 1][need - 0] * (need)); // right
		if(need) U(dp[i][need - 1] , dp[i - 1][need - 1] * (need)); // both
		
	}
	cout << dp[n][0] << endl;
	return 0;
}