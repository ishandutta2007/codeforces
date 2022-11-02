/*input
427896435961371452 630581697708338740 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define	int long long
const int MAX = (1 << 11);
const int mod = 998244353;

int k;
int siz[1 << 11] , ten[20];
PII dp[20][1 << 11][2][10]; // sum value , way
vector<int> v;

void U(int &now , int val){
	now = (now + val) % mod;
}
PII DP(int idx , int pat , int can , int las){
	if(dp[idx][pat][can][las].F != -1) return dp[idx][pat][can][las];
	if(idx == 0){
		if(siz[pat] <= k && pat != 0)
			 dp[idx][pat][can][las] = mp(las , 1);
		else dp[idx][pat][can][las] = mp(0 , 0);
	}
	else {
		dp[idx][pat][can][las] = mp(0 , 0);
		PII tmp;
		if(can == 0){
			REP(to , 0 , v[idx - 1] + 1){
				int topat = (pat == 0 && to == 0) ? 0 : pat | (1 << to);
				if(to == v[idx - 1]) tmp = DP(idx - 1 , topat , 0 , to);
				if(to != v[idx - 1]) tmp = DP(idx - 1 , topat , 1 , to);
				U(dp[idx][pat][can][las].F , tmp.F + ten[idx] * las % mod * tmp.S);
				U(dp[idx][pat][can][las].S , tmp.S);
			}
		}
		if(can == 1){
			REP(to , 0 , 10){
				int topat = (pat == 0 && to == 0) ? 0 : pat | (1 << to);
				tmp = DP(idx - 1 , topat , 1 , to);
				U(dp[idx][pat][can][las].F , tmp.F + ten[idx] * las % mod * tmp.S);
				U(dp[idx][pat][can][las].S , tmp.S);	
			}
		}
	}
	// cout << idx << " " << pat << " " << can << " ";
	// DB4(las , " = " , dp[idx][pat][can][las].F , dp[idx][pat][can][las].S);
	return dp[idx][pat][can][las];
}
int solve(int n){
	if(n == 0) return 0;
	REP(i , 0 , 20) REP(j , 0 , (1 << 11)) 
		REP(ii , 0 , 2) REP(jj , 0 , 10) dp[i][j][ii][jj] = mp(-1 , -1);

	v.clear();
	while(n > 0) v.pb(n % 10) , n /= 10;

	int ans = 0 , vsiz = v.size();
	REP(i , 0 , v.back() + 1){
		if(i == 0)             U(ans , DP(vsiz - 1 ,               0 , 1 , i).F);
		else if(i != v.back()) U(ans , DP(vsiz - 1 , (1 << i) , 1 , i).F);
		else if(i == v.back()) U(ans , DP(vsiz - 1 , (1 << i) , 0 , i).F);
 	}
	return ans;
}
int l , r;
int32_t main(){
	IOS;
	ten[0] = 1;
	REP(i , 1 , 20) ten[i] = ten[i - 1] * 10 % mod;
	REP(i , 1 , MAX){
		if(i % 2 == 0) siz[i] = siz[i >> 1];
		if(i % 2 == 1) siz[i] = siz[i >> 1] + 1;
	}
	
	// 71022880
	// k = 1;
	// cout << solve(42LL) << endl;
	// cout << solve(427896435961371452LL) << endl;
	// // cout << solve(154)-solve(100) << endl;
	
	cin >> l >> r >> k;
	// cout << solve(r) << endl;
	// cout << solve(l - 1) << endl;
	cout << (solve(r) + mod - solve(l - 1)) % mod << endl;
    return 0;
}


				// REP(j , 0 , v[i] + 1){
				// 	if(j != v[i]) 
				// 		 U(dp[i - 1][pat | (1 << j)][1] , dp[i][pat][0]);
				// 	else U(dp[i - 1][pat | (1 << j)][0] , dp[i][pat][0]);
				// }
				// REP(j , 0 , 10){
				// 	int topat = (pat == 0 && j == 0) ? 0 : pat | (1 << j);
				// 	U(dp[i - 1][topat][1] , dp[i][pat][1]);
				// }