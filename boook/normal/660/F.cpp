/*input
3
-60 -70 -80
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int n , x[MAX] , y[MAX] , ans[MAX] , b[MAX];
int cross(int id1 , int id2 , int id3){
	return (b[id1] - b[id2]) * (id2 - id3) <= (b[id2] - b[id3]) * (id1 - id2);
}
int query(int i , int j){ return -x[i] * j + b[j]; }
void solve(int l , int r , vector<int> sol){
	if(l == r) return;
	vector<int> lth , rth;
	for(auto to : sol){
		if(to <= mid + 0) lth.pb(to);
		if(mid + 1 <= to) rth.pb(to);
	}
	solve(l , mid + 0 , lth) , solve(mid + 1 , r , rth);

	vector<int> v;
	REP(i , l , mid + 1){
		while(v.size() >= 2 && cross(v[v.size() - 2] , v[v.size() - 1] , i)) v.pop_back();
		v.pb(i); 
	}
	int pos = 0;
	for(auto i : rth){
		while(pos + 1 < v.size() && query(i , v[pos]) <= query(i , v[pos + 1])) pos ++;
		ans[i] = max(ans[i] , query(i , v[pos]));
	}
}
int cmp(int a , int b){ return -x[a] < -x[b]; }
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) y[i] = x[i] * i;
	REP(i , 1 , n + 1) x[i] += x[i - 1];
	REP(i , 1 , n + 1) y[i] += y[i - 1];
	REP(i , 1 , n + 1) b[i] = x[i] * i - y[i];
	vector<int> sol;
	REP(i , 1 , n + 1) sol.pb(i);
	sort(ALL(sol) , cmp);
	solve(1 , n , sol);
	int res = 0;
	REP(i , 1 , n + 1) res = max(res , ans[i] + y[i]);
	cout << res << endl;
    return 0;
}