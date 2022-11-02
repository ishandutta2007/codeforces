/*input
5 2 3
1 2
1 3
3 4
5 3
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
#define MAX 500000
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int ans = 0;
int DFS(int now , int fa){
	int res = 0;
	for(auto to : v[now]) if(to != fa) res += DFS(to , now);
	if(res == 0) return 1;
	if(res == 1) return ans ++ , 1;
	else return ans += 2 , 0;
}
int n , x , y , big = 0 , o[MAX];
int32_t main(){
	IOS , cin >> n >> x >> y;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		o[a] ++ , o[b] ++;
		big = max(big , o[a]);
		big = max(big , o[b]);
		v[a].pb(b) , v[b].pb(a);
	}
	if(x < y){
		DFS(1 , 0);
		cout << ans * x + (n - 1 - ans) * y << endl;
	}
	else {
		if(big == n - 1) cout << (n - 2) * y + x << endl;
		else cout << (n - 1) * y << endl;
	}
    return 0;
}