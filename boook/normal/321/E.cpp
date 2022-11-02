/*input
3 2
0 2 0
2 0 3
0 3 0
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
#define MAX 4040
#define INF 0x3f3f3f3f

int n , m , x[MAX][MAX] , w[MAX][MAX] , dp[MAX][MAX] , id[MAX][MAX];
inline int rit(){
	char c = getchar();
	int res = 0;
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}
	return res;
}
int32_t main(){
	n = rit() , m = rit();
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) x[i][j] = rit();
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) x[i][j] += x[i][j - 1];
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) x[i][j] += x[i - 1][j];
	REP(i , 1 , n + 1) REP(j , i , n + 1) {
		w[i][j] = (x[j][j] - x[i - 1][j] - x[j][i - 1] + x[i - 1][i - 1]) / 2;
	}
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) dp[i][j] = INF;
	REP(i , 1 , n + 1) dp[i][1] = w[1][i] , id[i][1] = 0;

	REP(j , 2 , m + 1){
		id[n + 1][j] = n;
		RREP(i , n , j){
			REP(k , id[i][j - 1] , id[i + 1][j] + 1){
				if(dp[k][j - 1] + w[k + 1][i] < dp[i][j]){
					dp[i][j] = dp[k][j - 1] + w[k + 1][i];
					id[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", dp[n][m]);
    return 0;
}