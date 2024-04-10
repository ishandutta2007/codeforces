/*input
8
2 2
3 2
5 1
3 1
6 1
5 1
8 2
7 1
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
#define MAX 100090
#define INF 0x3f3f3f3f

PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }

int n , dot , p[MAX] , x[MAX] , u[MAX];
PII dp[MAX][2] , totalans = mp(0 , 0);

vector<PII> ans , tmp;
vector<int> v[MAX];

void DFS(int now){
	u[now] = 1 , dp[now][0] = dp[now][1] = mp(0 , 0);
	for(auto to : v[now]) if(to != dot) DFS(to);
	for(auto to : v[now]) if(to != dot) 
		dp[now][0] = max(dp[to][0] , dp[to][1]) + dp[now][0];
	for(auto to : v[now]) if(to != dot) 
		dp[now][1] = max(dp[now][1] , dp[now][0] - max(dp[to][0] , dp[to][1]) + dp[to][0] + mp(1 , x[now] != x[to]));
}
void getans(int now , int ty){
	if(ty == 0){
		for(auto to : v[now]) if(to != dot){
			if(dp[to][0] >= dp[to][1]) 
				 getans(to , 0);
			else getans(to , 1); 
		}
	}
	if(ty == 1){
		int idx = -1;
		for(auto to : v[now]) if(to != dot){
			if(dp[now][0] - max(dp[to][0] , dp[to][1]) + dp[to][0] + mp(1 , x[now] != x[to]) == dp[now][1]) idx = to;
		}
		assert(idx != -1);
		tmp.pb(now , idx);
		getans(idx , 0);
		for(auto to : v[now]) if(to != dot && to != idx){
			if(dp[to][0] >= dp[to][1]) 
				 getans(to , 0);
			else getans(to , 1); 
		}
	}
}
void solve(int now){
	while(u[now] == 0) u[now] = 1 , now = p[now];
	PII val = mp(0 , 0);
	REP(times , 0 , 2){
		dot = now , DFS(now);
		if(max(dp[now][0] , dp[now][1]) > val){
			val = max(dp[now][0] , dp[now][1]);
			tmp.clear();
			if(dp[now][0] >= dp[now][1])
				 getans(now , 0);
			else getans(now , 1);
		}
		now = p[now];
	}
	totalans = totalans + val;
	for(auto to : tmp) ans.pb(to);
}
struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int a){ return Find(a); }
} ds;
vector<int> G[MAX];
int use[MAX] , T[MAX];
void DFS0(int now , int fa){
	T[now] = fa;
	for(auto to : G[now]) if(to != fa && to != dot){
		DFS0(to , now);
	}
}
void solveinit(){
	ds.init();
	REP(i , 1 , n + 1) if(ds[i] != ds[p[i]]) use[i] = 1 , ds.Union(i , p[i]) , G[i].pb(p[i]) , G[p[i]].pb(i);
	REP(i , 1 , n + 1) if(use[i] == 0){
		int a = i , b = p[i];
		dot = a , DFS0(a , a) , T[a] = b;
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> p[i] >> x[i];
	solveinit();
	// REP(i , 1 , n + 1) cout << p[i] << " " ; cout << endl;
	// REP(i , 1 , n + 1) cout << T[i] << " " ; cout << endl;
	// REP(i , 1 , n + 1) cout << ds[i] << " "; cout << endl;
	REP(i , 1 , n + 1) assert(T[i] != i && T[i] != 0);
	REP(i , 1 , n + 1) p[i] = T[i];
	REP(i , 1 , n + 1) v[p[i]].pb(i);

	REP(i , 1 , n + 1) if(u[i] == 0) solve(i);
	cout << totalans.A << " " << totalans.B << endl;
	for(auto to : ans) cout << to.A << " " << to.B << endl;
    return 0;
}