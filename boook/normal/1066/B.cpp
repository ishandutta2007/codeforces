/*input
10 3
0 0 1 1 0 1 0 0 0 1
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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , r , x[MAX];
int32_t main(){
	IOS;
	cin >> n >> r;
	REP(i , 1 , n + 1) cin >> x[i];
	int now = 1 , ans = 0;
	while(now <= n){
		int idx = -1;
		REP(i , 1 , n + 1) if(x[i]){
			int v1 = i - r + 1;
			int v2 = i + r - 1;
			if(v1 <= now && now <= v2) idx = i;
		}
		if(idx == -1) return cout << -1 << endl , 0;
		ans ++;
		now = idx + r - 1 + 1;
	}
	cout << ans << endl;
    return 0;
}