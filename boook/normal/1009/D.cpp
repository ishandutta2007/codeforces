/*input
6 12
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
#define MAX 
#define INF 0x3f3f3f3f

// int N = 600;
int n , m;
int32_t main(){
	IOS;
	cin >> n >> m;
	if(m < n - 1) return cout << "Impossible" << endl , 0;
	else {
		vector<PII> ans;
		REP(i , 2 , n + 1) ans.pb(mp(1 , i));
		if(n >= 600){
			REP(i , 2 , 600 + 1) REP(j , i , 600 + 1){
				if(ans.size() != m && __gcd(i , j) == 1) ans.pb(mp(i , j));
			}
		}
		else {
			REP(i , 2 , n + 1) REP(j , i , n + 1){
				if(ans.size() != m && __gcd(i , j) == 1) ans.pb(mp(i , j));
			}
		}
		if(ans.size() != m) return cout << "Impossible" << endl , 0;
		else{
			cout << "Possible" << endl;
			for(auto to : ans) cout << to.A << " " << to.B << endl;
		}

		// int cnt =0 ;
		// REP(i , 1 , N + 1) REP(j , i , N + 1) if(__gcd(i , j) == 1) cnt ++;

		// cout << cnt << endl;

	}
    return 0;
}