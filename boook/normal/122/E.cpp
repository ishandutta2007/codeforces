/*input
4 25
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 100000000000LL

vector<int> v , sol;
set<int> cc;
void DFS(int now){
	if(now > INF) return ;
	v.pb(now);
	DFS(now * 10 + 4);
	DFS(now * 10 + 7);
}
int gi[100];
int lucky(int now){ return cc.find(now) != cc.end(); }
int kth(int now){
	int cnt = 0;
	REP(i , 0 , sol.size()){
		if(sol[i] != -INF) cnt ++;
		if(cnt == now) {
			int ans = sol[i];
			sol[i] = -INF;
			return ans;
		}
	}
}
int32_t main(){
	IOS;
	DFS(4) , DFS(7) , sort(ALL(v));
	for(auto to : v) cc.insert(to);

	gi[0] = 1;
	REP(i , 1 , 20) gi[i] = gi[i - 1] * i;
	
	int n , k;
	cin >> n >> k;
	if(n <= 15 && k > gi[n]) return cout << -1 << endl , 0;
	int pos = n - 14 , ans = 0;
	for(auto to : v) if(to < pos) ans ++;
	RREP(i , 14 , 0) sol.pb(n - i);
	RREP(i , 15 , 1){
		int cnt = 1;
		while(k > gi[i - 1]) k -= gi[i - 1] , cnt ++;
		int val = kth(cnt);
		// DBGG("cnt = " , cnt);
		// DB4("at = " , pos , "val is = " , val);
		if(lucky(pos) && lucky(val)) ans ++;
		pos ++;
	}
	// cout << "ans = " ;
	cout << ans << endl;
	// REP(i , 1 , 20) DBGG(i , gi[i]);
	// REP(i , 0 , sol.size()) cout << sol[i] << endl;
    return 0;
}