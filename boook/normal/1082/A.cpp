/*input
3
10 4 5 2
5 1 3 4
20 4 19 3
*/
#include <bits/stdc++.h>
using namespace std;
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
#define int long long
#define MAX 
const int INF = 1e17;

int t , n , x , y , d;
int F(int now){
	return now / d + (now % d != 0);
}
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 1 , t + 1){
		cin >> n >> x >> y >> d;
		if(x == y) cout << 0 << endl;
		else {
			if(abs(y - x) % d == 0) cout << abs(y - x) / d << endl;
			else {
				int v1 = INF , v2 = INF;
				if(1 % d == y % d) v1 = F(abs(x - 1)) + abs(y - 1) / d;
				if(n % d == y % d) v2 = F(abs(x - n)) + abs(n - y) / d;

				int ans = min(v1 , v2);
				cout << (ans == INF ? -1 : ans) << endl;
			}
		}
	}
    return 0;
}