/*input
2 3
1 2 4
1 2 4
2 1 4
1
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

int n , m , ss;
vector<PII> G1[MAX] , G2[MAX];
vector<int> p;
int use[MAX] , scc[MAX] , sccpo = 0;
int dot[MAX];
vector<PII> v[MAX];

void DFS1(int now){
	if(use[now]) return;
	use[now] = 1;
	for(auto to : G1[now]) DFS1(to.A);
	p.pb(now);
}
void DFS2(int now){
	if(scc[now]) return;
	scc[now] = sccpo;
	for(auto to : G2[now]) DFS2(to.A);
}
int dp[MAX];
int DP(int now){
	if(dp[now] != -1) return dp[now];
	dp[now] = dot[now];
	for(auto to : v[now]){
		dp[now] = max(dp[now] , dot[now] + DP(to.A) + to.B);
	}
	return dp[now];
}
int hhh[MAX];
int GET(int val){
	int now = 0;
	RREP(i , 20 , 0){
		int to = now + (1LL << i);
		if(to * (to + 1) / 2 <= val) now = to;
	}
	return val * now + val - hhh[now];
}
int32_t main(){
	REP(i , 1 , MAX) hhh[i] = hhh[i - 1] + i;
	REP(i , 1 , MAX) hhh[i] += hhh[i - 1];
	IOS , cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		G1[a].pb(mp(b , c));
		G2[b].pb(mp(a , c));
	}
	cin >> ss;
	REP(i , 1 , n + 1) DFS1(i);
	RREP(i , p.size() - 1 , 0){
		if(scc[p[i]] == 0){
			sccpo ++;
			DFS2(p[i]);
		}
	}
	MEM(dp , -1);
	REP(i , 1 , n + 1){
		for(auto to : G1[i]){
			if(scc[i] == scc[to.A]){
				dot[scc[i]] += GET(to.B);
			}
			else v[scc[i]].pb(mp(scc[to.A] , to.B));
		}
	}
	cout << DP(scc[ss]) << endl;
    return 0;
}