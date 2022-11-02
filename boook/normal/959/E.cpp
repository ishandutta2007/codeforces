/*input
1000000000000
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
#define int int_fast64_t
#define MAX 100
#define INF 0x3f3f3f3f

int n , v[MAX] , ans = 0;
void solve(int now){
	int base = 0;
	while((1LL << (base + 1)) - 1 <= now) base ++;
	ans += v[base];
	// DB4("base = " , base , ans , now);
	now -= (1LL << base);
	if(now >= 0){
		ans += (1LL << base);
		solve(now);
	}
}
int32_t main(){
	IOS;
	v[1] = 1;
	REP(i , 2 , 45 + 1) v[i] = v[i - 1] * 2 + (1LL << (i - 1));
	cin >> n , n --;
	solve(n);
	cout << ans << endl;
    return 0;
}