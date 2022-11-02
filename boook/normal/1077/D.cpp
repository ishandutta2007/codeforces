/*input
15 2
1 2 1 1 1 2 1 1 2 1 2 1 1 1 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 200900;
const int INF = 0x3f3f3f3f;

int n , k , x[MAX] , c[MAX];
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) c[x[i]] ++;

	int ans = 1;
	RREP(i , 20 , 0){
		int to = ans + (1 << i);
		if(to <= n){
			int cnt = 0;
			REP(j , 0 , MAX) if(c[j]) cnt += c[j] / to;
			if(cnt >= k) ans = to;
		}
	}
	// cout << ans << endl;
	REP(i , 0 , MAX){
		while(k && c[i] >= ans){
			cout << i << " ";
			k --;
			c[i] -= ans;
		}
	}
	cout << endl;
    return 0;
}