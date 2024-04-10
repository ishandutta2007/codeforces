/*input
5 3 3
1 2 3 1 1
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , p[MAX] , dp[MAX] , m , k;
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) p[i] = p[i - 1] + x[i];
	int pos = n , ans = 0;
	RREP(i , n , 1){
		while(p[pos] - p[i - 1] > k) pos --;
		dp[i] = dp[pos + 1] + 1;
		if(dp[i] <= m) ans = max(ans , n - i + 1);
	}
	cout << ans << endl;
    return 0;
}