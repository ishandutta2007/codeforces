#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , k , dp[MAX][MAX];
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int32_t main(){
    IOS;
    cin >> n >> k;
    dp[0][0] = 1;
    REP(i , 1 , k + 1) REP(j , 1 , k + 1) 
   		dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (n - (j - 1))) % mod;
   	int ans = 0;
   	REP(i , 1 , min(n , k) + 1) ans = (ans + dp[k][i] * ppow(2 , n - i)) % mod;
   	cout << ans << endl;
    return 0;
}