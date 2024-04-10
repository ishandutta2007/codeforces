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
#define MAX (1 << 20)
#define INF 0x3f3f3f3f
#define mod 1000000007LL
using namespace std;

int n , in , dp[MAX] , one[MAX] , two[MAX];
signed main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> in , dp[in] ++;
	RREP(i , 19 , 0) REP(j , 0 , (1 << 20))
		if((j & (1 << i)) == 0) dp[j] = (dp[j] + dp[j | (1 << i)]) % mod;
	two[0] = 1;
	REP(i , 1 , (1 << 20)) two[i] = two[i - 1] * 2 % mod;
	REP(i , 1 , (1 << 20)){
		if(i % 2 == 0) one[i] = one[i >> 1];
		if(i % 2 == 1) one[i] = one[i >> 1] + 1;
	}
	int ans = 0;
	REP(i , 0 , (1 << 20)){
		if(one[i] % 2 == 0) ans += two[dp[i]];
		if(one[i] % 2 == 1) ans -= two[dp[i]];
		ans = (ans % mod + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}