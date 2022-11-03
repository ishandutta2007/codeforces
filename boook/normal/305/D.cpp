/*input
7 1 3
1 5
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
#define int int_fast64_t
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int n , m , k , x[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	int ans = 1 , sml = INF , big = -INF;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if(a + 1 == b) continue;
		else if(b - a != k + 1) return cout << 0 << endl , 0;
		else x[a] = 1 , sml = min(sml , a) , big = max(big , a);
	}
	if(sml <= big && big - sml > k) return cout << 0 << endl , 0;

	REP(i , 1 , n + 1) x[i] += x[i - 1];
	REP(i , 1 , n + 1){
		int now = min(i , sml);
		int to = min(now + k , n - k - 1);
		if(now <= to && i <= to && to + k + 1 <= n && x[to] - x[now - 1] == x[n]){
			if(x[i] - x[i - 1] == 0){
				// DBGG(i , to);
				ans = (ans + ppow(2 , (to - i) - (x[to] - x[i - 1]))) % mod;
			}
		}
	}
	cout << ans << endl;
    return 0;
}