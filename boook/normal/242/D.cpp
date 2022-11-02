/*input
4 2
1 2
3 4
0 0 0 0
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , ok[MAX] , sum[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	REP(i , 1 , n + 1) cin >> x[i];
	queue<int> qu;
	REP(i , 1 , n + 1) if(sum[i] == x[i]) qu.push(i);
	while(qu.size()){
		int now = qu.front(); qu.pop();
		if(sum[now] != x[now]) continue;
		ok[now] = 1;
		sum[now] ++;
		for(auto to : v[now]){
			sum[to] ++;
			if(sum[to] == x[to]) qu.push(to);
		}
	}
	vector<int> ans;
	REP(i , 1 , n + 1) if(ok[i]) ans.pb(i);
	// REP(i , 1 , n + 1) cout << sum[i] << " " ;cout << endl;
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " "; cout << endl;
    return 0;
}