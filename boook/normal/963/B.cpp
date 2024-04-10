/*input
5
0 1 2 1 2
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , p[MAX] , d[MAX] , o[MAX];
vector<int> v[MAX] , ans;
void bye(int now , int fa){
	ans.pb(now);
	for(auto to : v[now]) if(to != fa && d[to] == 0) bye(to , now);
	d[now] = 1;
}
void DFS(int now , int fa){
	for(auto to : v[now]) if(to != fa) DFS(to , now);
	if((((int)v[now].size()) - o[now]) % 2 == 0){
		bye(now , fa);
		o[fa] ++;
	} 
}
int32_t main(){
	IOS;
	cin >> n;

	REP(i , 1 , n + 1) cin >> p[i];
	REP(i , 1 , n + 1){
		if(p[i] != 0) v[p[i]].pb(i) , v[i].pb(p[i]);
	}
	DFS(1 , 1);	
	if(ans.size() == n){
		cout << "YES" << endl;
		for(auto to : ans) cout << to << endl;
	}
	else cout << "NO" << endl;
    return 0;
}