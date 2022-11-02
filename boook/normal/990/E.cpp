/*input
7 4 3
2 4 5 6
3 14 15
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
#define MAX 3000900
#define INF 1e17

int n , m , k , u[MAX] , x[MAX] , p[MAX] , in;
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , m + 1) cin >> in , u[in] = 1;
	REP(i , 1 , k + 1) cin >> x[i];

	if(u[0] == 1) return cout << -1 << endl , 0;

	REP(i , 0 , n + n){
		if(u[i] == 1) p[i] = p[i - 1];
		else p[i] = i;
	}
	int ans = INF;
	REP(i , 1 , k + 1){
		int now = 0 , ok = 1 , cnt = 0;
		while(now < n){
			if(p[now + i] <= now){
				ok = 0;
				break;
			}
			else now = p[now + i] , cnt ++;
		}
		if(ok == 1) ans = min(ans , cnt * x[i]);
	}
	if(ans == INF) cout << "-1" << endl;
	else cout << ans << endl;
    return 0;
}