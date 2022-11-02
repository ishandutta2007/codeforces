/*input
3
UUU
100 100
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
const int MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;

string s;
int aa , bb , n;
int ud[MAX] , lr[MAX];
int32_t main(){
	IOS;
	cin >> n >> s >> aa >> bb , s = " " + s;
	REP(i , 1 , n + 1){
		if(s[i] == 'U') ud[i] = 1;
		if(s[i] == 'D') ud[i] = -1;
		if(s[i] == 'L') lr[i] = -1;
		if(s[i] == 'R') lr[i] = 1;
	}
	REP(i , 1 , n + 1) lr[i] += lr[i - 1];
	REP(i , 1 , n + 1) ud[i] += ud[i - 1];

	if(ud[n] == bb && lr[n] == aa) return cout << 0 << endl , 0;

	int ans = INF;
	REP(i , 1 , n + 1){
		int now = n + 1;
		RREP(j , 20 , 0){
			int to = now - (1 << j);
			if(to >= i){
				int len = to - i + 1;

				int l = ud[n] - (ud[to] - ud[i - 1]);
				int _ = lr[n] - (lr[to] - lr[i - 1]);
				l = abs(bb - l);
				_ = abs(aa - _);
				// if(i == 1 && to == 4){
				// 	DB4("l = " , l , "_ = " , _);
				// }
				if(l + _ <= len && (len - l - _) % 2 == 0) now = to;
			}			
		}
		// if(now <= n) DB4("i = " , i , "now = " , now);
		if(now <= n) ans = min(ans , now - i + 1);
	}
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}