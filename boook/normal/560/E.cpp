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
#define MAX 200900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int n , m , k , dp[MAX] , c[MAX] , mc[MAX];
int C(int a , int b){
	return c[a] * mc[b] % mod * mc[a - b] % mod;
}
PII x[MAX];
int32_t main(){

	c[0] = 1;
	REP(i , 1 , MAX) c[i] = c[i - 1] * i % mod;
	REP(i , 0 , MAX) mc[i] = ppow(c[i] , mod - 2);

	cin >> n >> m >> k;
	REP(i , 0 , k) cin >> x[i].A >> x[i].B; x[k] = mp(n , m);
	sort(x , x + k + 1);

	dp[0] = C(x[0].A + x[0].B - 2 , x[0].A - 1);

	REP(i , 1 , k + 1){
		int sum = C(x[i].A + x[i].B - 2 , x[i].A - 1);
		int cnt = 0;
		REP(j , 0 , i){
			int q = x[i].A - x[j].A , w = x[i].B - x[j].B;
			if(q >= 0 && w >= 0) cnt = (cnt + dp[j] * C(q + w , q)) % mod;
		}
		sum = (sum + mod - cnt) % mod;
		dp[i] = sum;

	}
	cout << dp[k] << endl;
    return 0;
}