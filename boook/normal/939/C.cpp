/*input
5
1 2 3 4 1
1 3
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , s , t;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) x[i] += x[i - 1];
	cin >> s >> t;
	int len = t - s , big = 0 , ans = 1;
	REP(i , 1 , n + 1){
		int to = i + len - 1 , val;
		if(to <= n) val = x[to] - x[i - 1];
		else to -= n , val = x[n] - x[i - 1] + x[to];
		// cout << val << endl;
		if(val > big){
			ans = 1;
			big = val;
			if(i > s) ans += s - i + n;
			else ans += s - i;
		}
		else if(val == big){
			int tmp = 1;
			if(i > s) tmp += s - i + n;
			else tmp += s - i;	
			ans = min(ans , tmp);
		}
	}
	cout << ans << endl;
    return 0;
}