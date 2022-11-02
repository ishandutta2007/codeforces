#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , mod;
int h[MAX] , g[MAX];
int dp[1020][120][12];
void pre(){
	h[0] = 1 % mod , h[1] = 9 % mod;
	REP(i , 2 , n + 10) h[i] = h[i - 1] * 10 % mod;
	g[1] = 10 % m;
	REP(i , 2 , n + 10) g[i] = g[i - 1] * 10 % m;
}
int32_t main(){
	cin >> n >> m >> mod;
	pre();
	REP(i , 0 , 10){
		int tmp = i % m;
		dp[1][tmp][i] = 1 % mod;
	}
	int ans = 0 , po = n - 1;
	int gpo = 1;
	REP(i , 1 , n + 1){
		REP(j , 1 , 10){

			if(dp[i][0][j] != 0){
				ans = (ans + h[po] * dp[i][0][j]) % mod;
				// DB4(h[po] , po , j , dp[i][0][j]);
				dp[i][0][j] = 0;
			}
		}
		REP(j , 0 , m){
			REP(k , 0 , 10){
				REP(l , 0 , 10){
					int tmp = (j + g[gpo] * l) % m;
					dp[i + 1][tmp][l] = (dp[i + 1][tmp][l] + dp[i][j][k]) % mod;
				}
			}
		}
		po --;
		gpo ++;
	}
	cout << ans << endl;
    return 0;
}