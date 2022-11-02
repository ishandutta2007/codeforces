/*input
5 5 8
1 0 1 1 1
6 5 4 2 8
0 6 3 2 3 4 0
0 8 3 3 2 4 0
0 0 3 3 4 1 1
0 10 3 4 3 1 1
0 4 3 3 4 1 1
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
#define MAX 100000
#define INF 0x3f3f3f3f

struct N{
	int from , to , cap , flow;
};
struct dinic{
	int s , t;
	int res[MAX] , dep[MAX] , use[MAX];
	vector<int> g[MAX];
	vector<N> e;
	void ADDE(int f , int t , int c){
		g[f].pb(e.size());
		e.pb(N{f , t , c , 0});
		g[t].pb(e.size());
		e.pb(N{t , f , 0 , 0});
	}
	int BFS(){
		MEM(dep , 0) , MEM(use , 0);
		queue<int> qu;
		qu.push(s) , use[s] = dep[s] = 1;
		while(qu.size()){
			int now = qu.front(); qu.pop();
			for(auto i : g[now]){
				N to = e[i];
				if(use[to.to] == 0 && to.cap > to.flow){
					use[to.to] = 1;
					dep[to.to] = dep[now] + 1;
					qu.push(to.to);
				}
			}
		}
		return use[t];
	}
	int DFS(int now , int lim){
		if(now == t || lim == 0) return lim;
		int flow = 0 , tmp;
		for(int &i = res[now] ; i < g[now].size() ; i ++){
			N to = e[g[now][i]];
			if(dep[to.to] == dep[now] + 1){
				tmp = DFS(to.to , min(lim , to.cap - to.flow));
				if(tmp > 0){
					e[g[now][i] ^ 0].flow += tmp;
					e[g[now][i] ^ 1].flow -= tmp;
					flow += tmp , lim -= tmp;
					if(lim == 0) break;
				}
			}
		}
		return flow;
	}
	int FLOW(int s , int t){
		this -> s = s , this -> t = t;
		int flow = 0;
		while(BFS()){
			MEM(res , 0);
			flow += DFS(s , INF);
		}
		return flow;
	}
} dc;
int n , m , d , x[MAX] , v[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> d;
	int s = 0 , t = n + 1 , pos = n + 2 , ans = 0;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cin >> v[i];
	REP(i , 1 , n + 1){
		if(x[i] == 0) dc.ADDE(s , i , v[i]);
		if(x[i] == 1) dc.ADDE(i , t , v[i]);
	}
	REP(i , 1 , m + 1){
		int type , get , nn , in , good;
		vector<int> sol;
		cin >> type >> get >> nn , ans += get;
		REP(j , 1 , nn + 1) cin >> in , sol.pb(in);
		cin >> good;
		if(type == 0) dc.ADDE(s , pos , get + good * d);
		if(type == 1) dc.ADDE(pos , t , get + good * d);
		for(auto to : sol){
			if(type == 0) dc.ADDE(pos , to , INF);
			if(type == 1) dc.ADDE(to , pos , INF);
		}
		pos ++;
	}
	// DBGG("ans = " , ans);
	cout << ans - dc.FLOW(s , t) << endl;
    return 0;
}