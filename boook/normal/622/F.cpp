/*input
1000000 123
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
#define int int_fast64_t
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int ni[MAX] , ng[MAX] , a[MAX];
int n , k;
int getni(int l , int r){
	int tmp = ng[r] * ng[-l] % mod;
	if((-l) % 2 == 0) return tmp;
	if((-l) % 2 == 1) return mod - tmp;
}
int32_t main(){
	IOS;
	ni[0] = ni[1] = ng[0] = 1;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 1 , MAX) ng[i] = ng[i - 1] * ni[i] % mod;

	cin >> n >> k;
	REP(i , 1 , MAX) a[i] = (a[i - 1] + ppow(i , k)) % mod;
	if(n < MAX) return cout << a[n] << endl , 0;

	int ans = 0 , res = 1 , to = k + 2;
	REP(i , 1 , to + 1) res = (res * (n - i)) % mod;

	REP(i , 1 , to + 1){
		int top = res * ppow(n - i , mod - 2) % mod;
		int dwn = getni(i - to , i - 1);
		int tmp = a[i] * top % mod * dwn % mod;
		ans = (ans + tmp) % mod;
	}
	cout << ans << endl;
    return 0;
}