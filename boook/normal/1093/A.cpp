/*input
4
2
13
37
100
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int t , n;
int32_t main(){
	IOS;
	cin >> t;
	REP(tiems , 0 , t){
		cin >> n;
		int ans;
		REP(i , 1 , n + 1){
			int l = 2 * i;
			int r = 7 * i;
			if(l <= n && n <= r) ans = i;
		}
		cout << ans << endl;
	}	
    return 0;
}