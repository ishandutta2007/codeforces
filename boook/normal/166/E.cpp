/*input
4
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
#define MAX 10000090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int dp[MAX][4];
int32_t main(){
	dp[0][3] = 1;
	REP(i , 1 , MAX){
		REP(j , 0 , 4){
			REP(k , 0 , 4){
				if(j != k){
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
				}
			}
		}
	}
	int n;
	cin >> n;
	cout << dp[n][3] << endl;
    return 0;
}