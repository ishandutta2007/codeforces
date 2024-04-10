/*input
100 5000 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5200
#define INF 0x3f3f3f3f
#define mod 998244353LL

int c[MAX][MAX];
int C(int a , int b){
	if(a == b) return 1;
	if(a < b) return 0;

	if(a <= MAX && b <= MAX) return c[a][b];
	else cout << a << " " << b << endl;
	exit(0); 
	// cout << a << " " << b << endl;
	// assert(a <= MAX && b <= MAX);
	return c[a][b];
}
int calc(int s , int p , int m){
	int ans = 0;
	REP(i , 0 , p + 1){
		int val = C(p , i) * C(s + p - 1 - i * (m + 1) , p - 1);
		if(i % 2 == 0) ans = (ans + val) % mod;
		if(i % 2 == 1) ans = (ans - val + mod) % mod;	
	}
	// cout << "\t\tcalc = ";
	// DB4(s , p , m , ans);
	return ans;
}
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int inv(int val){
	return ppow(val , mod - 2);
}
int32_t main(){
	IOS;
	REP(i , 0 , MAX) REP(j , 0 , i + 1){
		if(j == 0 || j == i) c[i][j] = 1;
		else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}

	int p , s , r , sum = 0;
	cin >> p >> s >> r;
	REP(i , r , s + 1) REP(j , 0 , p){
		int lasS = s - j * i - i;
		if(lasS >= 0){
			// DB4("here" , calc(lasS , p - 1 - j , i - 1) , "j = " , j);
			int tmp = calc(lasS , p - 1 - j , i - 1) * inv(j + 1) % mod * c[p - 1][j];
			sum = (sum + tmp) % mod;
		}
	}

	// cout << "ideal sum = " << 7 * inv(2) % mod << endl;
	int total = calc(s - r , p , s);
	// DB4("sum = " , sum , "total = " , total);
	cout << sum * inv(total) % mod << endl;
    return 0;
}