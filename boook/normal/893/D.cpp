/*input
5 10
-1 11 0 0 3
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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , lim , x[MAX];
int32_t main(){
	IOS , cin >> n >> lim;
	REP(i , 1 , n + 1) cin >> x[i];
	int l = 0 , r = 0 , ans = 0;
	REP(i , 1 , n + 1){
		if(x[i] != 0){
			l += x[i];
			r += x[i];
			r = min(r , lim);
		}
		else if(x[i] == 0){
			l = max(l , 0LL);
			if(r < l) ans ++ , r = lim;
		}
		if(l > lim) return cout << "-1" << endl , 0;
	}
	cout << ans << endl;
    return 0;
}