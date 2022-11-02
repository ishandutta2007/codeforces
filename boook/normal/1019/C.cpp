/*input
5 3
1 2
2 3
3 1
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
#define MAX 1000900
#define INF 0x3f3f3f3f

vector<int> G1[MAX] , G2[MAX];
int n , m , use[MAX] , ans[MAX];
void DFS(int now){
	if(now == n + 1) return;
	else if(use[now] == 1) DFS(now + 1);
	else {
		use[now] = 1;
		for(auto to : G1[now]) use[to] = 1;
		DFS(now + 1) , ans[now] = 1;
		for(auto to : G2[now]) if(ans[to] == 1) ans[now] = 0;
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		G1[a].pb(b);
		G2[b].pb(a);
	}
	DFS(1);
	int cnt = 0;
	REP(i , 1 , n + 1) cnt += ans[i];
	cout << cnt << endl;
	REP(i , 1 , n + 1) if(ans[i]) cout << i << " "; cout << endl;
    return 0;
}