/*input
5 2
1 5 4
1 4 5
1 3 2
4 1 2
5 6 1
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
	int from , to , cap , flow , cost;
};
struct MCMF{
	int s , t;
	int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
	vector<int> g[MAX];
	vector<N> e;
	int ADDE(int f , int t , int c , int cost){
		// cout << "ADD = " ; DB4(f , t , c , cost);
		g[f].pb(e.size());
		e.pb(N{f , t , c , 0 ,  cost});
		g[t].pb(e.size());
		e.pb(N{t , f , 0 , 0 , -cost});
		return e.size() - 2;
	}
	int Bellmanford(int &flow , int &cost){
		MEM(inq , 0) , MEM(d , INF);
		queue<int> qu;
		d[s] = 0 , a[s] = INF , qu.push(s);
		while(qu.size()){
			int now = qu.front(); qu.pop();
			inq[now] = 0;
			for(auto i : g[now]){
				N to = e[i];
				if(to.cap > to.flow && d[to.to] > d[now] + to.cost){
					a[to.to] = min(a[now] , to.cap - to.flow);
					d[to.to] = d[now] + to.cost;
					p[to.to] = i;
					if(inq[to.to] == 0){
						inq[to.to] = 1;
						qu.push(to.to);
					}
				}
			}
		}
		if(d[t] == INF) return 0;
		flow += a[t];
		cost += a[t] * d[t];
		for(int i = t ; i != s ; i = e[p[i]].from){
			e[p[i] ^ 0].flow += a[t];
			e[p[i] ^ 1].flow -= a[t];
		}
		return 1;
	}
	int FLOW(int s , int t){
		this -> s = s , this -> t = t;
		int flow = 0 , cost = 0;
		while(Bellmanford(flow , cost));
		// DB4("flow = " , flow , "cost = " , cost);
		return cost;
	}
} dc;

int n , m , s , t , x[MAX][2] , w[MAX] , id[MAX];
vector<int> uni;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> x[i][0] >> x[i][1] >> w[i];
	REP(i , 0 , n) x[i][1] += x[i][0];
	REP(i , 0 , n) REP(j , 0 , 2) uni.pb(x[i][j]);

	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) REP(j , 0 , 2) x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin() + 1;

	// REP(i , 0 , n) cout << x[i][0] << " " << x[i][1] << " " << w[i] << endl;

	REP(i , 0 , uni.size()) dc.ADDE(i , i + 1 , m , 0);
	REP(i , 0 , n) id[i] = dc.ADDE(x[i][0] , x[i][1] , 1 , -w[i]);
	dc.FLOW(0 , uni.size());
	REP(i , 0 , n) cout << dc.e[id[i]].flow << " "; cout << endl;
    return 0;
}