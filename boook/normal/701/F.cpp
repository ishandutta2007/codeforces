/*input
6 7
1 6
2 1 6
2 3 5
3 4 9
4 6 4
4 6 5
4 5 1
3 1 3
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
#define int long long
#define MAX 40000
#define INF 10000000000000LL

int n , m , s , t , e[MAX][2] , w[MAX];
int use[MAX] , dep[MAX] , low[MAX] , pat[MAX] , cut[MAX] , tt = 0 , notgo = 0;
int ans = INF , d1 = -1 , d2 = -1;
vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	use[now] = tt;
	pat[now] = fa;
	dep[now] = deep;
	low[now] = deep;
	for(auto i : v[now]){
		int to = e[i][0] ^ e[i][1] ^ now;
		if(i == fa || i == notgo) continue;
		if(use[to] == tt) low[now] = min(low[now] , dep[to]);
		else {
			DFS(to , i , deep + 1);
			low[now] = min(low[now] , low[to]);
			if(low[to] > dep[now]) cut[i] = tt;
		}
	}
}
void update(int val , int v1 , int v2){
	if(val < ans) ans = val , d1 = v1 , d2 = v2;
}
int32_t main(){
	cin >> n >> m >> s >> t;
	REP(i , 1 , m + 1){
		cin >> e[i][0] >> e[i][1];
		cin >> w[i];
		v[e[i][0]].pb(i);
		v[e[i][1]].pb(i);
	}
	tt ++ , DFS(s , 0 , 1);
	if(use[t] != tt) return cout << 0 << endl << 0 << endl , 0;
	else {
		vector<int> sol;
		int now = t;
		while(now != s){
			if(cut[pat[now]] == tt) update(w[pat[now]] , pat[now] , -1);
			sol.pb(pat[now]);
			now = e[pat[now]][0] ^ e[pat[now]][1] ^ now;
		}
		for(auto to : sol){
			notgo = to;
			tt ++ , DFS(s , 0 , 1);
			if(use[t] != tt) continue;
			now = t;
			while(now != s){
				if(cut[pat[now]] == tt) update(w[to] + w[pat[now]] , pat[now] , to);
				now = e[pat[now]][0] ^ e[pat[now]][1] ^ now;
			}
		}
		if(ans == INF) cout << -1 << endl;
		else {
			cout << ans << endl;
			cout << (d1 != -1) + (d2 != -1) << endl;
			if(d1 != -1) cout << d1 << " ";
			if(d2 != -1) cout << d2 << " ";
			cout << endl;
		}
	}
    return 0;
}