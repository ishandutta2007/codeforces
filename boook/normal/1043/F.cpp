/*input
7
30 60 21 42 70 15 30
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f
#define mod 1000000087LL

int gi[MAX] , ni[MAX];
int n , x[MAX] , c[MAX] , p[MAX] , dp[MAX];
int C(int a , int b){
	if(a < b) return 0;
	return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
void solveinit(){
	gi[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;
}
int32_t main(){
	IOS;
	solveinit();
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) c[x[i]] ++;
	REP(i , 1 , MAX) for(int j = i ; j < MAX ; j += i) p[i] += c[j];

	int all = 0;
	REP(i , 1 , n + 1) all = __gcd(all , x[i]);
	if(all != 1) return cout << -1 << endl , 0;

	REP(i , 1 , MAX){
		RREP(j , MAX - 1 , 1){
			dp[j] = C(p[j] , i);
			for(int to = j + j ; to < MAX ; to += j){
				dp[j] = (dp[j] + mod - dp[to]) % mod;
			}
		}
		if(dp[1] != 0) return cout << i << endl , 0;
	}
    return 0;
}