/*input
4
2 2
8 2
-7 0
-2 6
1 -14
16 -12
11 -18
7 -14
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define A first
#define B second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }
PII operator * (PII x , PII y){ return mp(x.A * y.A , x.B * y.B); }

PII x[MAX] , y[MAX];
int n;
void solve(PII now){
	multiset<PII> cc;
	REP(i , 1 , n + 1) cc.insert(x[i]);
	REP(i , 1 , n + 1) {
		PII to = now - y[i];
		if(cc.find(to) == cc.end()) return;
		else cc.erase(cc.find(to));
	}
	cout << now.A << " " << now.B << endl;
	exit(0);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	REP(i , 1 , n + 1) cin >> y[i].A >> y[i].B;
	REP(i , 1 , n + 1) solve(x[1] + y[i]);
    return 0;
}