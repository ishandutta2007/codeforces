/*input
5 5
5 19 10 20 12
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
#define MAX (1 << 22) + 100
#define INF 0x3f3f3f3f

int n , m , x[MAX] , c[MAX] , u[MAX] , all , ans;
void DFS(int now){
	if(u[now] == 1) return ;
	u[now] = 1;
	if(c[now] == 1) DFS(all ^ now);
	REP(i , 0 , n) if(now & (1 << i)) DFS(now ^ (1 << i));
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> x[i] , c[x[i]] = 1;
	all = (1 << n) - 1 , ans = 0;
	REP(i , 1 , m + 1) if(u[x[i]] == 0) ans ++ , DFS(all ^ x[i]);
	cout << ans << endl; 
    return 0;
}