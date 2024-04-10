/*input
3 2
1 1 1
3 1
2 0
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
#define int int_fast64_t
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , x[MAX] , q[MAX][2] , ans[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , m + 1) cin >> q[i][0] >> q[i][1];
	REP(i , 1 , m + 1) v[q[i][0]].pb(i);
	vector<int> g;
	int zero = 0 , base = 1;
	REP(now , 1 , n + 1){
		int val = x[now];
		for(auto to : g) val = min(val , val ^ to);
		if(val == 0) base = (base * 2 % mod);
		else g.pb(val);

		for(auto i : v[now]){
			int tmp = q[i][1];
			for(auto to : g) tmp = min(tmp , tmp ^ to);
			if(tmp == 0) ans[i] = base;
			else ans[i] = 0;
		}
	}
	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}