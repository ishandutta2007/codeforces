/*input
9 12 4
bbaaababb
abbbabbaaaba
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
#define MAX 1010
#define INF 0x3f3f3f3f

short n , m , k , dp[MAX][MAX][11][2];
string a , b;
int32_t main(){
	IOS;
	cin >> n >> m >> k >> a >> b;
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			REP(ii , 1 , k + 1){
				if(a[i - 1] == b[j - 1]){
					short tmp = 0;
					tmp = max(tmp , dp[i - 1][j - 1][ii - 1][0]);
					tmp = max(tmp , dp[i - 1][j - 1][ii - 1][1]);
					tmp = max(tmp , dp[i - 1][j - 1][ii][1]);
					dp[i][j][ii][1] = tmp + 1;
					tmp = 0;
					tmp = max(tmp , dp[i - 1][j][ii][0]);
					tmp = max(tmp , dp[i - 1][j][ii][1]);
					tmp = max(tmp , dp[i][j - 1][ii][0]);
					tmp = max(tmp , dp[i][j - 1][ii][1]);
					dp[i][j][ii][0] = tmp;
				}
				else {
					short tmp = 0;
					tmp = max(tmp , dp[i - 1][j][ii][0]);
					tmp = max(tmp , dp[i - 1][j][ii][1]);
					tmp = max(tmp , dp[i][j - 1][ii][0]);
					tmp = max(tmp , dp[i][j - 1][ii][1]);
					dp[i][j][ii][0] = tmp;
					dp[i][j][ii][1] = 0;
				}
			}
		}
	}
	short ans = 0;
	REP(i , 1 , k + 1) ans = max(ans , dp[n][m][i][0]);
	REP(i , 1 , k + 1) ans = max(ans , dp[n][m][i][1]);
	cout << ans << endl;
    return 0;
}