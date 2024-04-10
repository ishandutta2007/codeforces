/*input
13
1 1 1 1 1 1 1 1 1 1 1 1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX] , l[MAX] , r[MAX];
int32_t main(){
	IOS;
	cin >> n , n --;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(x[i] >= 2) l[i] = l[i - 1] + x[i] - (x[i] % 2 == 1);
	RREP(i , n , 1)    if(x[i] >= 2) r[i] = r[i + 1] + x[i] - (x[i] % 2 == 1);
	REP(i , 1 , n + 1) dp[i] = dp[i - 1] + x[i] - (x[i] % 2 == 0);
	
	// REP(i , 1 , n + 1) cout << l[i] << " "; cout << endl;
	// REP(i , 1 , n + 1) cout << r[i] << " "; cout << endl;
	// REP(i , 1 , n + 1) cout << dp[i] << " "; cout << endl;
	int ans = 0 , big = 0;
	REP(i , 1 , n + 2){
		big = max(big , l[i - 1] - dp[i - 1]);
		ans = max(ans , big + r[i] + dp[i - 1]);
	}
	cout << ans << endl;
    return 0;
}