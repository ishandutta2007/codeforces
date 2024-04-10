/*input
5 20 25
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int gi[MAX] , ni[MAX] , n , m , k , x[MAX];
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int C(int a , int b){
	if(a < b) return 0;
	return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
	IOS;
	gi[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 1 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
	cin >> n >> m >> k;
	REP(i , 1 , min(n , k) + 1) x[i] = ppow(i , n);
	REP(i , 1 , min(n , k) + 1) REP(j , 1 , i) x[i] = (x[i] - C(i , j) * x[j] % mod + mod) % mod;
	if(m == 1) cout << ppow(k , n) << endl;
	else {
		int ans = 0;
		REP(i , 1 , min(n , k) + 1){
			REP(j , 0 , i + 1){
				int las = k - i + j , mid = n * (m - 2);
				int val = x[i] * x[i] % mod * C(k , i) % mod * C(k - i , i - j) % mod * C(i , j) % mod;
				val = val * ppow(j , mid) % mod;
				ans = (ans + val) % mod;
			}
		}
		cout << ans << endl;
	}
    return 0;
}