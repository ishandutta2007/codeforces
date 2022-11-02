#include<bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i--)
#define int long long
#define pb push_back

int n , dp[15][70][1050];
int solve(int b , int val){
	vector<int> v;
	while(val){
		v.pb(val % b);
		val /= b;
	}
	int ans = 0 , p = 0;
	REP(i , 1 , v.size()){
		ans = ans + dp[b][i][0] - dp[b][i - 1][1];
	}
	RREP(i , v.size() - 1 , 0){
		REP(j , 0 , v[i]){
			if(i == v.size() - 1 && j == 0) continue;
			ans += dp[b][i][p ^ (1 << j)];
		}
		p ^= (1 << v[i]);
	}
	return ans;
}
main(){
	REP(i , 2 , 10 + 1){
		dp[i][0][0] = 1;
		REP(j , 1 , 63 + 1){
			REP(k , 0 , (1 << i)){
				REP(now , 0 , i){
					dp[i][j][k] += dp[i][j - 1][k ^ (1 << now)];
				}
			}
		}
	}
	cin >> n;
	REP(times , 0 , n){
		int l , r , k;
		cin >> k >> l >> r;
		cout << solve(k , r + 1) - solve(k , l) << endl;
	}
}