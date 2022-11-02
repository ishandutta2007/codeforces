/*input
2 2 3
1 2 2
2 1 3
2 1
2 2
2 3
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
#define MAX 500900
#define INF 0x3f3f3f3f

int n , m , k;
int e[MAX][3] , c[MAX][2] , dis[MAX] , ok[MAX];
vector<PII> v[MAX];
void dijkstra(){
	priority_queue<PII , vector<PII> , greater<PII>> pq;
	MEM(dis , INF) , dis[1] = 0;
	pq.push(mp(0 , 1));
	while(pq.size()){
		int step = pq.top().A;
		int now = pq.top().B;
		pq.pop();
		if(dis[now] != step) continue;
		for(auto to : v[now]){
			if(dis[to.A] > dis[now] + to.B){
				dis[to.A] = dis[now] + to.B;
				pq.push(mp(dis[to.A] , to.A));
			}
		}
	}
}
int32_t main(){
	cin >> n >> m >> k;
	REP(i , 0 , m) REP(j , 0 , 3) cin >> e[i][j];
	REP(i , 0 , k) REP(j , 0 , 2) cin >> c[i][j];
	REP(i , 0 , m){
		v[e[i][0]].pb(mp(e[i][1] , e[i][2]));
		v[e[i][1]].pb(mp(e[i][0] , e[i][2]));
	}
	REP(i , 0 , k){
		v[1].pb(mp(c[i][0] , c[i][1]));
		v[c[i][0]].pb(mp(1 , c[i][1]));
	}
	dijkstra();
	REP(i , 0 , m){
		int a = e[i][0] , b = e[i][1] , v = e[i][2];
		if(dis[a] + v == dis[b]) ok[b] = 1;
		if(dis[b] + v == dis[a]) ok[a] = 1;
	}
	int ans = 0;
	REP(i , 0 , k){
		if(ok[c[i][0]]){
			ans ++;
		}
		else ok[c[i][0]] = 1;
	}
	cout << ans << endl;
    return 0;
}