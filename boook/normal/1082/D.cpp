/*input
3
1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 505
#define INF 0x3f3f3f3f

int n , x[MAX] , u[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	vector<int> sol;
	REP(i , 1 , n + 1) if(x[i] >= 2) sol.pb(i) , u[i] = 1;
	vector<PII> ans;
	int b = -1 , f = -1 , pos = 0;
	for(auto to : sol) x[to] -= 2;
	REP(i , 1 , n + 1) if(u[i] == 0){
		if(b == -1){ b = i; continue; }
		if(f == -1){ f = i; continue; }
		while(pos < sol.size() && x[sol[pos]] == 0) pos ++;
		if(pos == sol.size()) return cout << "NO" << endl , 0;
		else {
			ans.pb(i , sol[pos]);
			x[sol[pos]] --;
		}
	}
	if(b != -1) ans.pb(b , sol[0]);
	if(f != -1) ans.pb(f , sol.back());
	REP(i , 1 , sol.size()) ans.pb(sol[i - 1] , sol[i]);
	int len = sol.size() - 1;
	if(b != -1) len ++;
	if(f != -1) len ++;

	cout << "YES " << len<< endl;
	cout << ans.size() << endl;
	for(auto to : ans) cout << to.F << " " << to.S << endl;
    return 0;
}