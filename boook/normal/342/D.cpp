/*input
3
...
...
..O
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
#define MAX 20000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX][3] , idx , idy;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int dp[MAX][10];
int DP(){
	// REP(i , 1 , n + 1) {
	// 	REP(j , 0 , 3) cout << x[i][j] << " " ; cout << endl;
	// }
	// cout << "------" << endl;
	MEM(dp , 0) , dp[0][0] = 1;
	REP(i , 1 , n + 1){
		REP(now , 0 , 8){
			REP(from , 0 , 8){
				int pat = 0 , ok = 1;
				if(now & from) ok = 0;
				REP(ii , 0 , 3) if(x[i][ii] && ( now & (1 << ii))) ok = 0;
				REP(ii , 0 , 3) if(x[i][ii] && (from & (1 << ii))) ok = 0;
				REP(ii , 0 , 3) if(x[i][ii] || (from & (1 << ii)) || (now & (1 << ii)))
					pat |= (1 << ii);
				if((pat == 1 || pat == 4 || pat == 7) && ok){
					dp[i][now] = (dp[i][now] + dp[i - 1][from]) % mod;
				}
			}
			// if(dp[i][now])DB4(i , now , " = " , dp[i][now]);
		}
	}
	// DBGG("final = " , dp[n][0]);
	return dp[n][0];
}
int IN(PII now){
	return now.A >= 1 && now.A <= n && now.B >= 0 && now.B < 3 && x[now.A][now.B] == 0;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(j , 0 , 3) REP(i , 1 , n + 1){
		char in; cin >> in;
		if(in == 'O') idx = i , idy = j;
		x[i][j] = in != '.';
	}
	vector<int> sol;
	REP(i , 0 , 4){
		PII d1 = mp(idx + X[i] * 1 , idy + Y[i] * 1);
		PII d2 = mp(idx + X[i] * 2 , idy + Y[i] * 2);
		if(IN(d1) && IN(d2)) sol.pb(i);
	}
	if(sol.empty()) return cout << 0 << endl , 0;
	int N = sol.size() , ans = 0;
	REP(i , 1 , (1 << N)){
		int cnt = -1;
		REP(j , 0 , 4) if(i & (1 << j)) cnt = -cnt;
		REP(j , 0 , 4){
			if(i & (1 << j)){
				x[idx + X[sol[j]] * 1][idy + Y[sol[j]] * 1] = 1;
				x[idx + X[sol[j]] * 2][idy + Y[sol[j]] * 2] = 1;
			}
		}
		ans = (ans + DP() * cnt) % mod;
		ans = (ans + mod) % mod;
		REP(j , 0 , 4){
			if(i & (1 << j)){
				x[idx + X[sol[j]] * 1][idy + Y[sol[j]] * 1] = 0;
				x[idx + X[sol[j]] * 2][idy + Y[sol[j]] * 2] = 0;
			}
		}
	}
	cout << ans << endl;
    return 0;
}