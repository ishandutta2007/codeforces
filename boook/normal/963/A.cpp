/*input
8 1 1 3
++-
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
#define MAX 1000000
#define INF 0x3f3f3f3f
#define mod 1000000009LL

int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int ni(int now){ return ppow(now , mod - 2); }
int n , m , a , b;
int x[MAX] , y[MAX];
string s;
int32_t main(){
	IOS;
	cin >> n >> a >> b >> m >> s;
	x[0] = y[0] = 1;
	REP(i , 1 , MAX) x[i] = x[i - 1] * a % mod;
	REP(i , 1 , MAX) y[i] = y[i - 1] * b % mod;
	int ans = 0;
	REP(i , 0 , s.size()){
		int v0 = ((s[i] == '-') ? (mod - 1) : 1) * ppow(a , n - i) % mod * y[i] % mod;
		int r = ni(x[m]) * y[m] % mod , kk = (n + 1) / m , val;
		if(r == 1) val = v0 * kk % mod;
		else val = v0 * (ppow(r , kk) + mod - 1) % mod * (ni((r + mod - 1) % mod)) % mod;
		// DBGG(kk , v0 * (ppow(r , kk) + mod - 1) % mod);
		ans = (ans + val) % mod;
	}
	cout << ans << endl;
    return 0;
}