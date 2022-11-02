/*input
3 3 1 2
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , u[MAX];

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(x[i] == i){
		cout << "YES" << endl;
		REP(j , 1 , n + 1) if(i != j) cout << i << " " << j << endl;
		return 0;
	}
	REP(i , 1 , n + 1) if(x[x[i]] == i){
		vector<PII> ans(1 , mp(i , x[i]));
		u[i] = u[x[i]] = 1;
		REP(ii , 1 , n + 1){
			if(u[ii]) continue;
			vector<int> sol;
			int now = ii;
			while(u[now] == 0) sol.pb(now) , u[now] = 1 , now = x[now];
			if(sol.size() % 2 == 1) return cout << "NO" << endl , 0;
			REP(jj , 0 , sol.size()){
				if(jj % 2 == 0) ans.pb(sol[jj] , i);
				if(jj % 2 == 1) ans.pb(sol[jj] , x[i]);
			}
		}
		cout << "YES" << endl;
		for(auto to : ans) cout << to.A << " " << to.B << endl;
		return 0;
	}
	cout << "NO" << endl; 
    return 0;
}