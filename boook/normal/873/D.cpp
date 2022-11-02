/*input
5 6
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
#define MAX 1000090
#define INF 0x3f3f3f3f

int n , k , ans[MAX] , po = 1;
void solve(int l , int r){
	if(l + 1 == r || k == 0){
		REP(i , l , r) ans[i] = po ++;
	}
	else {
		int mid = ((l + r) >> 1);
		k -= 2;
		solve(mid , r);
		solve(l , mid);
	}
}
int32_t main(){
	cin >> n >> k;
	if(k % 2 == 0) cout << -1 << endl;
	else {
		k-- , solve(0 , n);
		if(k) cout << -1 << endl;
		else {
			REP(i , 0 , n) cout << ans[i] << " ";
			cout << endl;
		}
	}
    return 0;
}