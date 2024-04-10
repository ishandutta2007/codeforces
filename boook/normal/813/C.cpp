/*input
4 3
1 2
2 3
2 4
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
#define MAX 300000
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int n , m , dis[MAX] , dep[MAX];
int DFS1(int now , int fa , int deep){
	dep[now] = deep;
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS1(to , now , deep + 1);
	}
}
int DFS2(int now , int fa , int deep){
	dis[now] = deep;
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS2(to , now , deep + 1);
	}
}
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	DFS1(1 , 0 , 0);
	DFS2(m , 0 , 0);
	int ans = 0;
	REP(i , 1 , n + 1){
		if(dis[i] < dep[i]) ans = max(ans , dep[i]);
	}
	cout << ans * 2 << endl;
    return 0;
}