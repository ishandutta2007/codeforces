/*input
4
4 2 4 3
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n , greater<int>());
	int ans = 0;
	REP(i , 1 , n + 1){
		if(x[i] == -1) continue;
		ans ++;
		REP(j , i + 1 , n + 1){
			if(x[j] == -1) continue;
			if(x[i] > x[j]) x[i] = x[j] , x[j] = -1;
		}
	}
	cout << ans << endl;
    return 0;
}