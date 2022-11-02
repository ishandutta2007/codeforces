/*input
1 10000000
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
#define MAX 
#define INF 100000000000

vector<int> v;
void DFS(int now){
	if(now > INF) return ;
	v.pb(now);
	DFS(now * 10 + 4);
	DFS(now * 10 + 7);
}
int32_t main(){
	IOS;
	DFS(4);
	DFS(7);
	sort(ALL(v));
	int l , r;
	cin >> l >> r;
	int ans = 0;
	REP(i , 0 , v.size()){
		// cout << v[i] << " ";
		if(l <= v[i]){
			int tmp = min(v[i] , r) - l + 1;
			// DB4("tmp = " , tmp , v[i] , l);
			ans += tmp * v[i];
			l = min(v[i] , r) + 1;
		}
	}
	cout << ans << endl;
    return 0;
}