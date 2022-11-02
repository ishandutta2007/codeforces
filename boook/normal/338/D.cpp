/*input
108 942 35
1 1 3 1 1 3 1 1 3 1 1 3 1 1 3 1 1 3 1 1 3 1 1 3 31 1 3 1 1 3 1 1 3 1 1
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
#define MAX 10090
#define INF 0x3f3f3f3f

int mul(int a , int b , int mod){
	if(b == 0) return 0;
	if(b % 2 == 0) return mul((a + a) % mod , b >> 1 , mod);
	if(b % 2 == 1) return (mul((a + a) % mod , b >> 1 , mod) + a) % mod;
}
void extgcd(int a , int b , int &d , int &x , int &y){
	if(b == 0) d = a , x = 1 , y = 0;
	else extgcd(b , a % b , d , y , x) , y -= (a / b) * x;
}
int N , M , k , a[MAX] , v[MAX] , m[MAX];
int32_t main(){
	IOS;
	cin >> N >> M >> k;
	REP(i , 1 , k + 1) cin >> a[i];
	int dot = 1;
	REP(i , 1 , k + 1){
		dot = dot / __gcd(dot , a[i]) * a[i];
		if(dot > N) return cout << "NO" << endl , 0;
	}
	REP(i , 1 , k + 1) m[i] = a[i];
	REP(i , 1 , k + 1) v[i] = (m[i] - i % m[i] + 1) % m[i];
	int ans = v[1] , mod = m[1];
	REP(i , 2 , k + 1){
		int res = (v[i] - ans) , d , x , y;
		extgcd(mod , m[i] , d , x , y);

		if(ans > M || res % d != 0) return cout << "NO" << endl , 0;
		x = (x % m[i] + m[i]) % m[i];
		// int tmp = (res / d * x % m[i] + m[i]) % m[i];
		res = (mul(res / d , x , m[i]) + m[i]) % m[i];
		// res = (res / d * x % m[i] + m[i]) % m[i];
		// if(res != tmp){
		// 	DBGG(res , tmp);
		// }
		ans = ans + mod * res;
		mod = mod * (m[i] / d);
		ans = (ans % mod + mod) % mod;
	}
	if(ans == 0) ans = mod;
	if(ans + k - 1 > M) return cout << "NO" << endl , 0;
	REP(i , 1 , k + 1){
		if(__gcd(dot , ans + i - 1) != a[i]){
			return cout << "NO" << endl , 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}