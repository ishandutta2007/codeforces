/*input
9
-2 0 -1 0 -1 2 1 0 -1
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX] , ans;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) x[i] = abs(x[i]);
	REP(i , 1 , n + 1){
		int l = 0 , r = 0;
		REP(j , 1 , n + 1){
			if(x[i] > x[j] && i > j) l ++;
			if(x[i] > x[j] && i < j) r ++;
		}
		ans += min(l , r);
	}
	cout << ans << endl;
    return 0;
}