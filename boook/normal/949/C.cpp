/*input
4 5 4
2 1 0 3
4 3
3 2
1 2
1 4
1 3
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k;
int x[MAX] , ok[MAX];
int use[MAX] , scc[MAX] , siz[MAX] , sccpo = 0;
vector<int> G1[MAX] , G2[MAX] , p , in[MAX];
void ADDE(int a , int b){
	G1[a].pb(b);
	G2[b].pb(a);
}
void DFS1(int now){
	if(use[now]) return ;
	use[now] = 1;
	for(auto to : G1[now]) DFS1(to);
	p.pb(now);
}
void DFS2(int now){
	if(scc[now]) return;
	scc[now] = sccpo;
	siz[sccpo] ++;
	in[sccpo].pb(now);
	for(auto to : G2[now]) DFS2(to);
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if((x[a] + 1) % k == x[b]) ADDE(a , b);
		if((x[b] + 1) % k == x[a]) ADDE(b , a);
	}
	REP(i , 1 , n + 1) DFS1(i);
	RREP(i , p.size() - 1 , 0){
		if(scc[p[i]] == 0){
			sccpo ++;
			DFS2(p[i]);
		}
	}
	// DBGG("sccpo = " , sccpo);
	// REP(i , 1 , sccpo + 1) cout << siz[i] << " " ; cout << endl;
	int ans = INF , id;
	REP(i , 1 , n + 1) for(auto to : G1[i]) if(scc[i] != scc[to]) ok[scc[i]] = 1;
	REP(i , 1 , sccpo + 1) if(ok[i] == 0 && siz[i] < ans) ans = siz[i] , id = i;
	cout << siz[id] << endl;
	for(auto to : in[id]) cout << to << " " ; cout << endl;
    return 0;
}