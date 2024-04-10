/*input
5 6 1 5
1 2
1 3
1 4
4 5
3 5
2 5
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

int dis[MAX][MAX] , e[MAX][MAX] , n , m , s , t;
vector<int> v[MAX];
void BFS(int from){
	queue<int> qu;
	qu.push(from) , dis[from][from] = 0;
	while(qu.size()){
		int now = qu.front(); qu.pop();
		for(auto to : v[now]){
			if(dis[from][to] > dis[from][now] + 1){
				dis[from][to] = dis[from][now] + 1;
				qu.push(to);
			}
		}
	}
}
int32_t main(){
	IOS;
	MEM(dis , INF);
	cin >> n >> m >> s >> t;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
		v[a].pb(b) , v[b].pb(a);
	}
	REP(i , 1 , n + 1) BFS(i);
	int ans = 0 , sml = dis[s][t];
	REP(i , 1 , n + 1) REP(j , i + 1 , n + 1){
		if(e[i][j]) continue;
		int val = INF;
		val = min(val , dis[s][i] + dis[j][t] + 1);
		val = min(val , dis[s][j] + dis[i][t] + 1);
		if(val >= sml) ans ++;
	}
	cout << ans << endl;
    return 0;
}