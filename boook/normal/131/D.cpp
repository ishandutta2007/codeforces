/*input
6
1 2
3 4
6 4
2 3
1 3
3 5
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
#define MAX 4040
#define INF 0x3f3f3f3f

int n , e[MAX][2] , dis[MAX];
int dep[MAX] , low[MAX] , use[MAX] , cut[MAX];

vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	dep[now] = deep;
	low[now] = deep;
	use[now] = 1;
	for(auto i : v[now]){
		int to = e[i][0] ^ e[i][1] ^ now;
		if(to == fa) continue;
		if(use[to]) low[now] = min(low[now] , dep[to]);
		else {
			DFS(to , now , deep + 1);
			if(low[to] > dep[now]) cut[i] = 1;
			low[now] = min(low[now] , low[to]);
		}
	}
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1){
		cin >> e[i][0] >> e[i][1];
		v[e[i][0]].pb(i);
		v[e[i][1]].pb(i);
	}
	DFS(1 , 0 , 1);
	MEM(dis , INF);
	priority_queue<PII , vector<PII> , greater<PII> > pq;
	REP(i , 1 , n + 1){
		if(cut[i] == 0){
			dis[e[i][0]] = 0;
			dis[e[i][1]] = 0;
			pq.push(mp(0 , e[i][0]));
			pq.push(mp(0 , e[i][1]));
		}
	}
	while(pq.size()){
		int now = pq.top().B;
		int step = pq.top().A;
		pq.pop();
		if(dis[now] != step) continue;
		for(auto i : v[now]){
			int to = e[i][0] ^ e[i][1] ^ now;
			if(dis[to] > dis[now] + 1){
				dis[to] = dis[now] + 1;
				pq.push(mp(dis[to] , to));
			}
		}
	}
	REP(i , 1 , n + 1) cout << dis[i] << " " ; cout << endl;
    return 0;
}