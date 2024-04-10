/*input
8 2
6 3
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
#define MAX 280000
#define INF 0x3f3f3f3f

int n , m , x[MAX] , use[MAX];
vector<int> sol;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> x[i];
	int base = 1;
	stack<int> cc;
	REP(i , 1 , m + 1){
		while(cc.size() && cc.top() == base) cc.pop() , base ++;
		if(use[base]) return cout << -1 << endl , 0;
		cc.push(x[i]) , use[x[i]] = 1;
	}
	while(cc.size()){
		int now = cc.top(); 
		if(now == base){
			cc.pop();
			base ++;
		}
		else {
			RREP(i , now - 1 , base){
				if(use[i]) return cout << -1 << endl , 0;
				sol.pb(i) , use[i] = 1;
			}
			cc.pop();
			base = now + 1;
		}
	}
	RREP(i , n , base) sol.pb(i);

	REP(i , 1 , m + 1) cout << x[i] << " ";
	for(auto to : sol) cout << to << " " ;
	cout << endl;
    return 0;
}