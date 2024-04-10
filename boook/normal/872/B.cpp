/*input
5 1
-4 -5 -3 -2 -1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , fr[MAX] , ba[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	int sml = x[1] , big = x[1];
	REP(i , 1 , n + 1) sml = min(sml , x[i]);
	REP(i , 1 , n + 1) big = max(big , x[i]);
	if(m == 1) cout << sml << endl;
	else if(m == 2){
		int ans = x[1];
		fr[1] = x[1] , ba[n] = x[n];
		REP(i , 2 , n + 1)  fr[i] = min(fr[i - 1] , x[i]);
		RREP(i , n - 1 , 1) ba[i] = min(ba[i + 1] , x[i]);
		REP(i , 1 , n + 0) ans = max(ans , max(fr[i] , ba[i + 1]));
		cout << ans << endl;
	}
	else  cout << big << endl;
    return 0;
}