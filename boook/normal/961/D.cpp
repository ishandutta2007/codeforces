
 /*input
5
0 0
0 1
1 1
1 -1
2 2
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n;
PII x[MAX];
PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }
int cross(PII x , PII y){
	return x.A * y.B - x.B * y.A;
}
int line(PII a , PII b , PII c){
	PII aa = b - a , bb = c - a;
	return cross(aa , bb) == 0;
}
int solve(PII a , PII b){
	vector<PII> sol;
	REP(i , 1 , n + 1){
		if(x[i] == a || x[i] == b) continue;
		else if(line(a , b , x[i])) continue;
		else sol.pb(x[i]);
	}
	REP(i , 2 , sol.size()) if(line(sol[0] , sol[1] , sol[i]) == 0) return 0;
	return 1;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	if(n <= 3) return cout << "YES" << endl , 0;
	else {
		int id = -1 , ok = 0;
		REP(i , 3 , n + 1) if(line(x[1] , x[2] , x[i]) == 0) id = i;
		if(id == -1) return cout << "YES" << endl , 0;
		else {
			if(solve(x[1] , x[2])) ok = 1;
			else if(solve(x[1] , x[id])) ok = 1;
			else if(solve(x[id] , x[2])) ok = 1;

			if(ok) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
    return 0;
}