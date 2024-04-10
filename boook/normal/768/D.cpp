/*input
1000 2
1000
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
#define MAX 1010
#define INF 0x3f3f3f3f

double dp[MAX * 10][MAX] , in;
int n , k;
double DP(int times , int get){
	if(dp[times][get] >= 0) return dp[times][get];
	double tma = DP(times - 1 , get - 0) * (double)get / (double)n;
	double tmb = DP(times - 1 , get - 1) * (double)(n - get + 1) / (double)n;
	// DB4(times , get , tma , tma + tmb);
	return dp[times][get] = tma + tmb;
}
int32_t main(){
	REP(i , 1 , MAX * 10) REP(j , 1 , MAX) dp[i][j] = -1;
	dp[1][1] = 1;
	cin >> n >> k;
	REP(ttt , 1 , k + 1){
		double big = 0;
		cin >> in;
		REP(i , 1 , MAX * 10){
			if(DP(i , n) * 2000 >= in){
				cout << i << endl;
				break;
			}
		}	
	}
    return 0;
}