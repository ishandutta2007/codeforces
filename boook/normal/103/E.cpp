/*input
20
1 9
1 5
1 1
1 16
1 4
2 3 16
1 20
1 7
2 8 11
3 3 7 12
3 12 19 20
2 12 17
1 6
1 13
1 11
1 2
2 1 10
1 15
1 18
2 7 14
-191706 -404849 -831879 630465 -329932 735014 -560879 -735142 -980003 -638196 -363875 -961092 297579 -187227 511989 -60742 -814423 656950 763284 442057
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
#define MAX 1010
#define INF 0x3f3f3f3f

struct N{
	int from , to , cap , flow;
};
struct dinic{
	int s , t;
	int dep[MAX] , use[MAX] , res[MAX];
	vector<int> g[MAX];
	vector<N> e;
	void ADDE(int f , int t , int c){
		g[f].pb(e.size());
		e.pb(N{f , t , c , 0});
		g[t].pb(e.size());
		e.pb(N{t , f , 0 , 0});
	}
	int BFS(){
		MEM(use , 0) , MEM(dep , 0);
		queue<int> qu;
		qu.push(s) , dep[s] = use[s] = 1;
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
		if(lim == 0 || now == t) return lim;
		int flow = 0 , tmp;
		for(int &i = res[now] ; i < g[now].size() ; i ++){
			N to = e[g[now][i]];
			if(dep[to.to] == dep[now] + 1){
				tmp = DFS(to.to , min(lim , to.cap - to.flow));
				if(tmp > 0){
					e[g[now][i] ^ 0].flow += tmp;
					e[g[now][i] ^ 1].flow -= tmp;
					flow += tmp;
					lim -= tmp;
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
} fir , sec;
int n , x[MAX] , idx[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n;
	int s = 0 , t = n + n + 1;
	REP(i , 1 , n + 1) fir.ADDE(s , i + 0 , 1);
	REP(i , 1 , n + 1) fir.ADDE(i + n , t , 1);
	REP(i , 1 , n + 1){
		int nn , val;
		cin >> nn;
		while(nn--){
			cin >> val , v[i].pb(val);
			fir.ADDE(i , val + n , 1);
		}
	}
	fir.FLOW(s , t);

	for(auto to : fir.e) if(to.cap != 0 && to.from != s && to.to != t && to.flow != 0){
		idx[to.to - n] = to.from;
	}
	REP(i , 1 , n + 1) cin >> x[i];
	s = 0 , t = n + 1;
	int ans = 0;
	REP(i , 1 , n + 1) if(x[i] > 0) sec.ADDE(i , t , x[i]);
	REP(i , 1 , n + 1) if(x[i] < 0) sec.ADDE(s , i , -x[i]) , ans += x[i];
	REP(i , 1 , n + 1){
		for(auto to : v[i]){
			if(idx[to] != i) sec.ADDE(i , idx[to] , INF);
		}
	}
	cout << ans + sec.FLOW(s , t) << endl;
    return 0;
}