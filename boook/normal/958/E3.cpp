/*input
4
6 6
5 1
2 4
4 0
5 4
1 2
2 1
3 5
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
#define MAX 30000
#define INF 0x3f3f3f3f

PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }
int cross(PII x , PII y){ return x.A * y.B - x.B * y.A; }

short n , ans[MAX];
PII x[MAX] , tmp;
int cmp(int v1 , int v2){
	return cross(x[v1] - tmp , x[v2] - tmp) > 0;
}
int trs(int now){ return now < n; }
void solve(vector<short> v){
	if(v.size() == 0) return;
	else {
		int nn = v.size() , pre = 0;
		PII id = mp(-1 , 0);
		REP(i , 0 , v.size()) if(x[v[0]] > x[v[i]]) swap(v[0] , v[i]);

		tmp = x[v[0]] , sort(v.begin() + 1 , v.end() , cmp);

		REP(i , 1 , v.size()){
			if(trs(v[0]) != trs(v[i])){
				if(pre == 0) id = max(id , mp(min(i - 1 , nn - 1 - i) , i));
				pre --;
			}
			if(trs(v[0]) == trs(v[i])) pre ++;
			// if(id.A != -1 && rand() % 3 == 0) break;
		}
		// cout << endl;
		ans[v[id.B]] = v[0];
		ans[v[0]] = v[id.B];
		vector<short> v1 , v2;
		REP(i , 1 , id.B + 0)  v1.pb(v[i]);
		REP(i , id.B + 1 , nn) v2.pb(v[i]);
		// DB4("match = " , v[0] , v[id.B] , (trs(v[0]) != trs(v[id.B])));
		// for(auto to : v) cout << to << " "; cout << endl;
		// for(auto to : v1) cout << to << " "; cout << endl;
		// for(auto to : v2) cout << to << " "; cout << endl;
		vector<short> ().swap(v);
		solve(v1) , solve(v2);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	vector<short> sol;// = {6 , 1 , 3 , 4};
	REP(i , 0 , n + n) cin >> x[i].A >> x[i].B;
	REP(i , 0 , n + n) sol.pb(i);
	solve(sol);
	// REP(i , 0 , n + n) cout << ans[i] << " "; cout << endl;
	REP(i , 0 , n) cout << ans[i] + 1 - n << endl;
    return 0;
}