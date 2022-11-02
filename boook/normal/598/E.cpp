/*input
4
2 2 1
2 2 3
2 2 2
2 2 4
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
#define INF 10000000000000000LL

int t , dp[35][35][55];

int DP(int n , int m , int k){
	if(dp[n][m][k] != -1) return dp[n][m][k];
	if(n * m == k || k == 0) return dp[n][m][k] = 0;
	if(n * m < k) return dp[n][m][k] = INF;
	int tmp = INF;
	REP(i , 1 , n){
		// i * m , (n - i) * m , cost = m * m;
		REP(j , 0 , k + 1){
			tmp = min(tmp , DP(i , m , j) + DP(n - i , m , k - j) + m * m);
		}
	}
	REP(i , 1 , m){
		REP(j , 0 , k + 1){
			tmp = min(tmp , DP(n , i , j) + DP(n , m - i , k - j) + n * n);
		}
	}
	return dp[n][m][k] = tmp;
}
int32_t main(){
	IOS , cin >> t;
	MEM(dp , -1);
	REP(times , 0 , t){
		int n , m , k;
		cin >> n >> m >> k;
		cout << DP(n , m , k) << endl;
	}
    return 0;
}