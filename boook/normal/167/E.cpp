/*input
5 2 1000003
5 1
3 4
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 660
#define INF 0x3f3f3f3f

int n , nn , m , mod;
int dp[MAX][MAX] , uu[MAX][MAX] , o[MAX];
int ppow(int a , int k){
	// cout << a << " " << k << endl;
	if(k == 0) return 1 % mod;
	else if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	else if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int solve(vector<vector<int>> sol){
	int ans = 1;
	REP(now , 0 , nn){
		REP(i , now + 1 , nn) if(sol[now][now] < sol[i][now]){
			swap(sol[now] , sol[i]);
			ans = mod - ans;
		}
		int inv = ppow(sol[now][now] , mod - 2);
		REP(i , now + 1 , nn) if(sol[i][now] != 0){
			int tmp = sol[i][now] * inv % mod;
			REP(j , now , nn)
				(sol[i][j] = sol[i][j] + mod - sol[now][j] * tmp % mod) %= mod;
		}
	}
	// REP(i , 0 , nn){REP(j , 0 , nn) cout << sol[i][j] << " "; cout << endl;}
	REP(now , 0 , nn) ans = ans * sol[now][now] % mod;
	return ans;
}
vector<int> v[MAX] , in , out;
int DP(int i , int j){
	if(uu[i][j] == 1) return dp[i][j];
	uu[i][j] = 1;
	if(i == j) dp[i][j] = 1;
	else for(auto to : v[i]) dp[i][j] = (dp[i][j] + DP(to , j)) % mod;
	return dp[i][j];
}
int32_t main(){
	IOS;
	cin >> n >> m >> mod;
	REP(i , 1 , m + 1){
		int a , b; cin >> a >> b;
		v[a].pb(b) , o[b] ++;
	}
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) DP(i , j);
	REP(i , 1 , n + 1) if(o[i] == 0) in.pb(i);
	REP(i , 1 , n + 1) if(v[i].empty()) out.pb(i);

	assert(in.size() == out.size());
	nn = in.size();
	vector<vector<int>> sol(nn + 1 , vector<int>(nn + 1 , 0));
	REP(i , 0 , nn) REP(j , 0 , nn) sol[i][j] = dp[in[i]][out[j]];

	// for(auto to :  in) cout << to << " "; cout << endl;
	// for(auto to : out) cout << to << " "; cout << endl;
	// REP(i , 0 , nn){REP(j , 0 , nn) cout << sol[i][j] << " " ; cout << endl; }
	cout << solve(sol) << endl;
    return 0;
}