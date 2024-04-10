/*input
5
10 6 9 8 2
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
#define MAX (1 << 22) + 100
#define INF 0x3f3f3f3f
#define N (1 << 22)

int n , x[MAX] , dp[MAX][2];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 0 , N)     dp[i][0] = -1;
	REP(i , 1 , n + 1) dp[x[i]][0] = x[i];

	RREP(i , 21 , 0){
		int now = i % 2 , pre = (i + 1) % 2;
		REP(j , 0 , N){
			if(j & (1 << i)) dp[j][now] = max(dp[j][pre] , dp[j - (1 << i)][pre]);
			else 			 dp[j][now] = dp[j][pre];
		}
	}

	REP(i , 1 , n + 1){
		int tmp = 0;
		REP(j , 0 , 22) if((x[i] & (1 << j)) == 0) tmp |= (1 << j);
		cout << dp[tmp][0] << " " ;
	}
	cout << endl;
    return 0;
}