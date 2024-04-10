/*input
5 6 2
1 2
1 3
2 4
2 5
3 4
3 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

vector<int> v[MAX] , g[MAX];
int n , m , k , ans[MAX];
int dis[MAX] , e[MAX][2];
void dijkstra(){
	MEM(dis , INF);
	priority_queue<PII , vector<PII> , greater<PII>> pq;
	pq.push(mp(0 , 1)) , dis[1] = 0;
	while(pq.size()){
		int step = pq.top().A;
		int now = pq.top().B;
		pq.pop();
		if(step != dis[now]) continue;
		for(auto to : v[now]){
			if(dis[to] > dis[now] + 1){
				dis[to] = dis[now] + 1;
				pq.push(mp(dis[to] , to));
			}
		}
	}
}
int base;
void DFS(int now){
	if(base == 0) exit(0);
	if(now == n + 1){
		base --;
		REP(i , 1 , m + 1) cout << ans[i];
		cout << endl;
	}
	else {
		DFS(now + 1);
		REP(i , 1 , g[now].size()){
			ans[g[now][0]] = 0;
			ans[g[now][i]] = 1;
			DFS(now + 1);
			ans[g[now][i]] = 0;
			ans[g[now][0]] = 1;
		}
	}
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , m + 1){
    	int a , b;
    	cin >> a >> b;
    	e[i][0] = a;
    	e[i][1] = b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    dijkstra();
    REP(i , 1 , m + 1){
    	if(dis[e[i][0]] > dis[e[i][1]]) swap(e[i][0] , e[i][1]);
    	if(dis[e[i][0]] + 1 == dis[e[i][1]]) g[e[i][1]].pb(i);
    }
    // REP(i , 1 , n + 1) cout << dis[i] << " "; cout << endl;
//     REP(i , 1 , n + 1){
//     	DBGG("now = " , i);
//     	for(auto to : g[i]) cout << to << " "; cout << endl;
//     }
// return 0;
    base = 1;
    REP(i , 2 , n + 1) base = min(k , base * g[i].size());
    REP(i , 2 , n + 1) ans[g[i][0]] = 1;
    cout << base << endl;
    DFS(2);
    return 0;
}