/*input
10
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 998244353LL

int n , gi[MAX] , suf[MAX];

int32_t main(){
	IOS;
	cin >> n;
	gi[0] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	int len = n * gi[n];
	int ans = (len - n + 1 + mod) % mod;
	suf[n + 1] = 1;
	suf[n] = n;
	RREP(i , n - 1 , 1) suf[i] = suf[i + 1] * i % mod;
	int las = 0;
	RREP(i , n - 1 , 1){
		int val = 1 * suf[i + 2] % mod * i % mod;
		las = (las + val * i) % mod;
		// DBGG("val = " , val);
	}
	ans = (ans + mod - las) % mod;
	cout << ans << endl;
    return 0;
}