/*input
5
42 42 42
43 43 43
44 44 44
45 45 45
46 46 46
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
#define INF 0x3f3f3f3f
#define N 1000900

int t , n , m , k , dv[N] , p[N] , po = 0;
void solveinit(){
	REP(i , 2 , N){
		if(dv[i] == 0) dv[i] = i , p[po ++] = i;
		REP(j , 0 , po){
			if(i * p[j] >= N) break;
			dv[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int solve(int a , int b){
	vector<int> v;
	while(b != 1){
		if(v.size() && v.back() == dv[b]);
		else v.pb(dv[b]);
		b /= dv[b];
	}
	int all = 0 , nn = v.size();
	// cout << v.size() << endl;
	// for(auto to : v) cout << to << " " ; cout << endl;
	REP(i , 0 , (1 << nn)){
		int sum = 1 , pp = 1;
		REP(j , 0 , v.size()) if(i & (1 << j)) sum *= v[j] , pp = -pp;
		// DBGG("sum = " , sum);
		all = all + (a / sum) * pp;
		// DBGG("all = " , all);
	}
	return all;
}
int32_t main(){
	IOS;
	solveinit();
	cin >> t;
	REP(times , 1 , t + 1){
		cin >> n >> m >> k;
		if(m == 1) cout << n + k << endl;
		else {
			k += solve(n , m);
			// DBGG("k = " , k);
			int ans = 0;
			// RREP(i , 10 , 0){
			RREP(i , 30 , 0){
				int to = ans + (1LL << i);
				if(solve(to , m) < k) ans = to;
			}
			cout << ans + 1 << endl;
		}
	}
    return 0;
}