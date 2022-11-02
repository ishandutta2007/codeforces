/*input
10 14
xzyzyzyzqx
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , use[MAX] , scc[MAX] , sccpo = 0;
string s;
vector<int> G1[MAX] , G2[MAX] , p;
void DFS1(int now){
	if(use[now]) return;
	use[now] = 1;
	for(auto to : G1[now]) DFS1(to);
	p.pb(now);
}
void DFS2(int now){
	if(scc[now]) return;
	scc[now] = sccpo;
	for(auto to : G2[now]) DFS2(to);
}
int dp[MAX][30] , vis[MAX];
void DP(int now){
	if(vis[now]) return;
	vis[now] = 1;
	int tmp = s[now - 1] - 'a';
	dp[now][tmp] = 1;
	for(auto to : G1[now]){
		DP(to);
		REP(i , 0 , 26) dp[now][i] = max(dp[now][i] , dp[to][i] + (tmp == i));
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> s;
	int ans = 1;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if(a == b) return cout << -1 << endl , 0;
		else G1[a].pb(b) , G2[b].pb(a);
	}
	REP(i , 1 , n + 1) DFS1(i);
	RREP(i , p.size() - 1 , 0){
		if(scc[p[i]] == 0){
			sccpo ++ , DFS2(p[i]);
		}
	}
	// cout << "here" << endl;
	if(sccpo != n) cout << -1 << endl;
	else {
		REP(i , 1 , n + 1) DP(i);
		REP(i , 0 , 26){

			REP(j , 1 , n + 1){
				ans = max(ans , dp[j][i]);
			}
		}
		cout << ans << endl;
	}
    return 0;
}