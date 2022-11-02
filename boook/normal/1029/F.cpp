/*input
506 2708
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
#define INF 0x3f3f3f3f

int a , b , add , ans;
vector<int> aa , bb;

void solve(int v1 , int v2){
	for(auto to : aa) if(to <= v1 && a / to <= v2) {
		ans = min(ans , v1 + v2 + v1 + v2);
		return ;
	}	
	for(auto to : bb) if(to <= v1 && b / to <= v2) {
		ans = min(ans , v1 + v2 + v1 + v2);
		return ;
	}
}
int32_t main(){
	IOS;
	cin >> a >> b;
	add = a + b;
	ans = (a + b + 1) * 2;

	REP(i , 1 , INF + 1){
		if(i * i > a) break;
		else if(a % i == 0) aa.pb(i);
	}
	REP(i , 1 ,  INF + 1){
		if(i * i > b) break;
		else if(b % i == 0) bb.pb(i);
	}

	REP(i , 1 , INF + 1){
		if(i * i > add) break;
		else if(add % i == 0) solve(i , add / i);
	}
	cout << ans << endl;
    return 0;
}