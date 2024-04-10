/*input
2
2
1 3
1 4
3
1 5
1 1
2 3
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
#define MAX 6000
#define INF 0x3f3f3f3f

int t , n , a[MAX] , b[MAX] , sol[MAX];
int ans[MAX];
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 1 , t + 1){
		cin >> n;
		REP(i , 1 , n + 1) cin >> a[i] >> b[i];
		int T = 1;
		REP(i , 1 , n + 1){
			T = max(T , a[i]);
			if(T > b[i]) ans[i] = 0;
			else ans[i] = T , T ++;
		}
		REP(i , 1 , n + 1) cout << ans[i] << " " ;cout << endl;
	}
    return 0;
}