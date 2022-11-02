/*input
5
1 2 3 4 5
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	int ans = 0;
	x[0] = 0;
	REP(i , 1 , n + 1) cin >> x[i];
	x[++n] = 1001;
	REP(i , 0 , n + 1) REP(j , i , n + 1){
		if(x[j] - x[i] + 1 == j - i + 1){
			ans = max(ans , j - i + 1 - 2);
		}
	}
	cout << ans << endl;
    return 0;
}