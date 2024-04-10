/*input
2 3 3 5
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

int a , b , l , r , tmp , N = 1000000000000000000;
int32_t main(){
	cin >> a >> b >> l >> r;
	vector<int> aa , bb , sol;

	tmp = 1;
	aa.pb(tmp);
	while(tmp <= N / a){
		aa.pb(tmp * a) , tmp *= a;
	}

	tmp = 1;
	bb.pb(tmp);
	while(tmp <= N / b){
		bb.pb(tmp * b) , tmp *= b;
	}
	// for(auto to : aa) cout << to << " "; cout << endl;
	// for(auto to : bb) cout << to << " "; cout << endl;
	sol.pb(l - 1);
	sol.pb(r + 1);
	for(auto i : aa) for(auto j : bb){
		if(l <= i + j && i + j <= r) sol.pb(i + j);
	}
	sort(ALL(sol));
	int ans = 0;
	REP(i , 1 , sol.size()){
		int fr = sol[i - 1] + 1;
		int ba = sol[i] - 1;
		ans = max(ans , ba - fr + 1);
	}
	cout << ans << endl;
    return 0;
}