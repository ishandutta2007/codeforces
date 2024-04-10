/*input
2
2 3
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
#define MAX 9000
#define INF 0x3f3f3f3f

int n , x[MAX];
set<int> cc;
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc.insert(x[i]);
	int val = x[1];
	REP(i , 1 , n + 1) val = __gcd(val , x[i]);
	if(cc.find(val) == cc.end()) return cout << -1 << endl , 0;
	vector<int> ans;
	REP(i , 1 , n + 1){
		ans.pb(x[i]);
		ans.pb(val);
	}
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " "; cout << endl;
    return 0;
}