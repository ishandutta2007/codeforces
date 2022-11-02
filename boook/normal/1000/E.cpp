
 /*input
4 3
1 2
4 3
3 2
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
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f

struct 	djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int n , m;
int use[MAX] , low[MAX] , dep[MAX];
vector<int> v[MAX] , g[MAX];
void DFS(int now , int fa , int deep){
	use[now] = 1;
	low[now] = deep;
	dep[now] = deep;
	for(auto to : v[now]){
		if(to == fa) continue;
		else if(use[to]) low[now] = min(low[now] , dep[to]);
		else {
			DFS(to , now , deep + 1);
			low[now] = min(low[now] , low[to]);
			if(low[to] > dep[now]);// DBGG(now , to);
			else ds.Union(now , to);
		}
	}
}
PII DFS2(int now , int fa , int deep){
	PII ans = mp(deep , now);
	for(auto to : g[now]) if(to != fa)
		ans = max(ans , DFS2(to , now , deep + 1));
	return ans;
}
int e[MAX][2];
int32_t main(){
	IOS;
	ds.init();
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		e[i][0] = a;
		e[i][1] = b;
		v[a].pb(b) , v[b].pb(a);
	}
	DFS(1 , 1 , 1);
	// REP(i , 1 , n + 1) cout << ds[i] << " " ; cout << endl;
	REP(i , 1 , m + 1){
		if(ds[e[i][0]] != ds[e[i][1]]){
			// DBGG(ds[e[i][0]] , ds[e[i][1]]);
			g[ds[e[i][0]]].pb(ds[e[i][1]]);
			g[ds[e[i][1]]].pb(ds[e[i][0]]);
		}
	}
	int now = ds[1];
	cout << DFS2(DFS2(now , 0 , 0).B , 0 , 0).A << endl;

    return 0;
}