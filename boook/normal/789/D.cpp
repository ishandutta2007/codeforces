/*input
4 4
2 3
2 4
3 4
4 4
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , use[MAX] , o[MAX] , res = 0;
vector<int> v[MAX];
void DFS(int now){
	if(use[now]) return;
	use[now] = 1;
	for(auto to : v[now]) DFS(to);
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if(a == b){
			o[a] ++ , res ++;
			v[a].pb(a);
		}
		else {
			v[a].pb(b);
			v[b].pb(a);
		}
	}
	REP(i , 1 , n + 1) if(v[i].size()) { DFS(i); break; }
	REP(i , 1 , n + 1) if(v[i].size() == 0) use[i] = 1;
	REP(i , 1 , n + 1) if(use[i] == 0) return cout << 0 << endl , 0;
	int ans = res * (res - 1) / 2;
	REP(i , 1 , n + 1){
		int tmp = v[i].size();
		tmp -= o[i];
		// DBGG(i , tmp);
		ans += tmp * (tmp - 1) / 2;
		ans += o[i] * (m - res);
	}
	cout << ans << endl;
    return 0;
}