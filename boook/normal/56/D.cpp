/*input
ACCEPTED
WRONGANSWER
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

string a , b;
int dp[MAX][MAX] , pa[MAX][MAX];
void solve(int l , int r){
	if(l == 0 && r == 0) return;
	if(pa[l][r] == 0) solve(l - 1 , r - 1);
	if(pa[l][r] == 1){
		cout << "REPLACE " << l << " " << b[r - 1] << endl;
		solve(l - 1 , r - 1);
	}
	if(pa[l][r] == 2){
		cout << "DELETE " << l << endl;
		solve(l - 1 , r);
	}
	if(pa[l][r] == 3){
		cout << "INSERT " << l + 1 << " " << b[r - 1] << endl;
		solve(l , r - 1);
	}
}
int32_t main(){
	IOS;
	cin >> a >> b;
	MEM(dp , INF);
	dp[0][0] = 0;
	REP(i , 1 , a.size()) dp[i][0] = i , pa[i][0] = 2;
	REP(i , 1 , b.size()) dp[0][i] = i , pa[0][i] = 3;
	REP(i , 1 , a.size() + 1){
		REP(j , 1 , b.size() + 1){
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				int v1 = dp[i - 1][j - 1] + 1;
				int v2 = dp[i - 1][j - 0] + 1;
				int v3 = dp[i - 0][j - 1] + 1;
				if(v1 <= v2 && v1 <= v3){
					dp[i][j] = v1;
					pa[i][j] = 1;
				}
				else if(v2 <= v1 && v2 <= v3){
					dp[i][j] = v2;
					pa[i][j] = 2;
				}
				else if(v3 <= v1 && v3 <= v2){
					dp[i][j] = v3;
					pa[i][j] = 3;
				}
				// dp[i - 1][j - 1] + 1;
				// dp[i - 1][j]; delete
				// dp[i][j - 1] insert
			}
		}
	}
	cout << dp[a.size()][b.size()] << endl;
	solve(a.size() , b.size());
    return 0;
}