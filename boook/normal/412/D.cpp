/*input
3 3
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m , use[MAX];
vector<int> v[MAX] , g;
void DFS(int now){
	if(use[now]) return void();
	use[now] = 1;
	for(auto to : v[now]) DFS(to);
	g.pb(now);
}
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		v[b].pb(a);
	}
	REP(i , 1 , n + 1) DFS(i);
	reverse(ALL(g));
	for(auto to : g) cout << to << " " ; cout << endl;
    return 0;
}