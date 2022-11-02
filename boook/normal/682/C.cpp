/*input
9
88 22 83 14 95 91 98 53 11
3 24
7 -8
1 67
1 64
9 65
5 12
6 -80
3 8
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , p[MAX] , ok[MAX] , ans;
vector<PII> v[MAX];
void DFS(int now , int fa){
	ans ++;
	for(auto ii : v[now]){
		int to = ii.A , dis = ii.B;
		if(to == fa) continue;
		if(p[now] + dis > x[to]) ok[to] = 0;
		else{
			p[to] = max(p[to] , p[now] + dis);
			DFS(to , now);
		}
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(mp(i , b));
		v[i].pb(mp(a , b));
	}
	REP(i , 1 , n + 1) ok[i] = 1;
	DFS(1 , 0);
	cout << n - ans << endl;
    return 0;
}