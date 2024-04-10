#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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

typedef pair<PII , int> PIII;
int n , m;
int x[MAX][3] , pa[MAX];
PII dis[MAX];
vector<PII> v[MAX];
vector<int> path;
void dijkstra(int from , int to){
	priority_queue<PIII , vector<PIII> , greater<PIII> > pq;
	pq.push(mp(mp(0 , 0) , from));
	REP(i , 1 , n + 1) dis[i] = mp(INF , INF);
	dis[from] = mp(0 , 0);
	while(pq.size()){
		PIII now = pq.top(); pq.pop();
		if(now.A != dis[now.B]) continue;
		for(auto to : v[now.B]){
			PII tmp = mp(now.A.A + 1 , now.A.B + to.B);
			if(dis[to.A] > tmp){
				dis[to.A] = tmp;
				pq.push(mp(dis[to.A] , to.A));
				pa[to.A] = now.B;
			}
		}
	}
	int now = to;
	while(1){
		path.pb(now);
		if(now == from) return;
		now = pa[now];
	}
}
set<PII> cc;
vector<PIII> res;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1){
		REP(j , 0 , 3) cin >> x[i][j];
		v[x[i][0]].pb(mp(x[i][1] , 1 - x[i][2]));
		v[x[i][1]].pb(mp(x[i][0] , 1 - x[i][2]));
	}
	dijkstra(1 , n);
	REP(i , 1 , path.size()){
		int a = path[i - 1] , b = path[i];
		if(a > b) swap(a , b);
		cc.insert(mp(a , b));
		// DBGG(a , b);
	}
	REP(i , 1 , m + 1){
		int a = x[i][0] , b = x[i][1];
		if(a > b) swap(a , b);
		if(cc.find(mp(a , b)) != cc.end()){
			if(x[i][2] == 0) res.pb(mp(mp(x[i][0] , x[i][1]) , 1));
		}
		else if(x[i][2] == 1) res.pb(mp(mp(x[i][0] , x[i][1]) , 0));
	}
	cout << res.size() << endl;
	for(auto to : res){
		cout << to.A.A << " " << to.A.B << " " << to.B << endl;
	}
	// for(auto to : path) cout << to << " " ;cout << endl;
    return 0;
}