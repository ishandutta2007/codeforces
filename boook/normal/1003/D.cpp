/*input
5 4
2 4 8 2 4
8
5
14
10
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , v[MAX] , m;
map<int , int> cc;
int32_t main(){
	IOS;
	REP(i , 0 , 60 + 1) cc[(1LL << i)] = i;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i] , v[cc[x[i]]] ++;

	
	REP(i , 1 , m + 1){
		int val , ans = 0;
		cin >> val;
		RREP(j , 40 , 0){
			int need = val / (1LL << j);
			int sml = min(need , v[j]);
			val -= sml * (1LL << j) , ans += sml;
		}
		if(val == 0) cout << ans << endl;
		else cout << -1 << endl;
	}
    return 0;
}