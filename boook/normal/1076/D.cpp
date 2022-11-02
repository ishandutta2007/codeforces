/*input
4 5 2
4 1 8
2 4 1
2 1 3
3 4 9
3 1 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 300900;
const int INF = 1e17;

int n , m , k , e[MAX][3];

vector<int> v[MAX];
int dis[MAX] , pre[MAX];
void dijkstra(int s){
    priority_queue<PII , vector<PII> , greater<PII> > pq;
    REP(i , 1 , n + 1) dis[i] = INF;
    dis[s] = 0 , pq.push(mp(0 , s));
    while(pq.size()){
        int step = pq.top().F , now = pq.top().S;
        pq.pop();
        if(dis[now] != step) continue;
		REP(i , 0 , v[now].size()){
			int id = v[now][i];
			int to = now ^ e[id][0] ^ e[id][1];
			if(dis[to] > dis[now] + e[id][2]){
                dis[to] = dis[now] + e[id][2];
                pre[to] = id;
                pq.push(mp(dis[to] , to));
            }
		}
    }
}
int take = 0;
vector<int> g[MAX] , ans;
void DFS(int now , int fa){
	for(auto idx : g[now]){
		int to = e[idx][0] ^ e[idx][1] ^ now;
		if(to != fa){
			if(take < k){
				take ++;
				ans.pb(idx);
				DFS(to , now);
			}
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;

	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		e[i][0] = a , e[i][1] = b , e[i][2] = c;
		v[a].pb(i);
		v[b].pb(i);
	}
	dijkstra(1);
	// REP(i , 1 , n + 1) cout << pre[i] << " "; cout << endl;
	REP(i , 2 , n + 1){
		int idx = pre[i];
		g[e[idx][0]].pb(idx);
		g[e[idx][1]].pb(idx);
	}
	DFS(1 , 1);
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}