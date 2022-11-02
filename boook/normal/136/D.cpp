/*input
0 0
4 4
4 0
0 4
1 2
2 3
3 2
2 1
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
#define int long long
#define MAX 10
#define INF 0x3f3f3f3f

int n , sol[MAX];
PII x[MAX];
PII operator - (PII a , PII b){ return mp(b.A - a.A , b.B - a.B); }
PII operator + (PII a , PII b){ return mp(b.A + a.A , b.B + a.B); }
int DIS(PII a , PII b){
	PII tmp = b - a;
	return tmp.A * tmp.A + tmp.B * tmp.B;
}
int DOT(PII a , PII b){
	return a.A * b.A + a.B * b.B;
}
int check(){
	vector<int> q , w;
	REP(i , 0 , 4) REP(j , i + 1 , 4) q.pb(DIS(x[sol[i]] , x[sol[j]]));
	REP(i , 4 , 8) REP(j , i + 1 , 8) w.pb(DIS(x[sol[i]] , x[sol[j]]));
	sort(ALL(q));
	REP(i , 0 , 4) if(q[i] != q[0]) return 0;
	REP(i , 4 , 6) if(q[i] != q[0] * 2) return 0;
	sort(ALL(w));
	if(w[0] != w[1]) return 0;
	if(w[2] != w[3]) return 0;
	if(w[4] != w[5]) return 0;
	if(w[4] != w[0] + w[2]) return 0;
	if(DOT(x[sol[5]] - x[sol[4]] , x[sol[7]] - x[sol[4]]) != 0) return 0;
	if(DOT(x[sol[6]] - x[sol[5]] , x[sol[4]] - x[sol[5]]) != 0) return 0;
	if(DOT(x[sol[7]] - x[sol[6]] , x[sol[5]] - x[sol[6]]) != 0) return 0;
	if(DOT(x[sol[4]] - x[sol[7]] , x[sol[6]] - x[sol[7]]) != 0) return 0;
	return 1;
}
int32_t main(){
	IOS;
	REP(i , 0 , 8) cin >> x[i].A >> x[i].B;
	REP(i , 0 , 8) sol[i] = i;
	do{
		if(check()){
			cout << "YES" << endl;
			REP(i , 0 , 4) cout << sol[i] + 1 << " " ; cout << endl;
			REP(i , 4 , 8) cout << sol[i] + 1 << " " ; cout << endl;
			return 0;
		}
	}while(next_permutation(sol , sol + 8));
	cout << "NO" << endl;
    return 0;
}