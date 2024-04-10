/*input
997167959139 7344481199252
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m;
int32_t main(){
	cin >> n >> m;
	int now = 1 , ans = 0;
	if(m > n){
		ans = (ans + n % mod * ((m - n) % mod) % mod) % mod;
		m = n;
	}
	while(now <= m){
		int to = min(m , n / (n / now));
		// DB4("now = " , now , "to = " , to);
		int a = n % now + n % to;
		int b = to - now + 1;

		if(a % 2 == 0) a = a / 2 % mod , b %= mod;
		else b = b / 2 % mod , a %= mod;
		int tmp = a * b % mod;
		ans = (ans + tmp) % mod;

		now = to + 1;

	}
	cout << ans << endl;
    return 0;
}