/*input
3
1 1 1
2 2 1
3 3 1
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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX][3] , ans[MAX] , bit[MAX];
vector<int> sol[MAX];
void update(int from , int val){ for(int i = from + 10 ; i < MAX ; i += i & -i) bit[i] += val; }
int query(int from){
	int res = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		res += bit[i];
	return res;
}
void solve(int id){
	for(auto to : sol[id]){
		if(x[to][0] == 1) update(x[to][1] ,  1);
		if(x[to][0] == 2) update(x[to][1] , -1);
		if(x[to][0] == 3) ans[to] = query(x[to][1]);
	}
	for(auto to : sol[id]){
		if(x[to][0] == 1) update(x[to][1] , -1);
		if(x[to][0] == 2) update(x[to][1] ,  1);
	}
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 0 , n) REP(j , 0 , 3) cin >> x[i][j];

	vector<int> uni;

	REP(i , 0 , n) uni.pb(x[i][1]);
	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) x[i][1] = lower_bound(ALL(uni) , x[i][1]) - uni.begin();	

	uni.clear();
	REP(i , 0 , n) uni.pb(x[i][2]);
	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) x[i][2] = lower_bound(ALL(uni) , x[i][2]) - uni.begin();

	REP(i , 0 , n) sol[x[i][2]].pb(i);
	REP(i , 0 , uni.size()){
		solve(i);
	}
	REP(i , 0 , n){
		if(x[i][0] == 3) cout << ans[i] << endl;
	}
    return 0;
}