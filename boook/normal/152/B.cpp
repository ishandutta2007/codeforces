/*input
10 10
1 2
1
-1 0
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m , x , y , k;

int32_t main(){
	IOS , cin >> n >> m >> x >> y >> k;
	int ans = 0;
	REP(i , 0 , k){
		int dx , dy , now = 0;
		cin >> dx >> dy;
		RREP(j , 30 , 0){
			int to = now + (1 << j);
			int tox = x + dx * to;
			int toy = y + dy * to;
			if(1 <= tox && tox <= n && 1 <= toy && toy <= m) now = to;
		}
		// DBGG("now = " , now);
		x += dx * now;
		y += dy * now;
		ans += now;
	}
	cout << ans << endl;
    return 0;
}