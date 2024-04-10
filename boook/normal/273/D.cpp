/*input
3 4
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 200
#define INF 0x3f3f3f3f
#define mod 1000000007

int nn , m , dp[MAX][MAX][MAX][2][2] , pre[MAX][MAX][2][2] , ans;
void U(int &now , int val){ now = (now + val) % mod; }
int query(int a , int b , int l , int r , int ql , int qr){
	if(l > r || ql > qr) return 0;
	int tmp = pre[r][qr][a][b] + pre[l - 1][ql - 1][a][b]
	        - pre[r][ql - 1][a][b] - pre[l - 1][qr][a][b];
	return (tmp % mod + mod) % mod;
}
int32_t main(){
	IOS;
	cin >> nn >> m;
	REP(line , 1 , nn + 1){
		REP(i , 1 , m + 1) REP(j , 1 , m + 1) REP(ii , 0 , 2) REP(jj , 0 , 2)
			pre[i][j][ii][jj] = dp[line - 1][i][j][ii][jj];
		REP(i , 1 , m + 1) REP(j , 1 , m + 1) REP(ii , 0 , 2) REP(jj , 0 , 2)
			U(pre[i][j][ii][jj] , pre[i][j - 1][ii][jj]);
		REP(i , 1 , m + 1) REP(j , 1 , m + 1) REP(ii , 0 , 2) REP(jj , 0 , 2)
			U(pre[i][j][ii][jj] , pre[i - 1][j][ii][jj]);

		REP(l , 1 , m + 1) REP(r , l , m + 1){
			U(dp[line][l][r][0][0] , query(0 , 0 , 1 , l + 0 , r + 0 , m));
			U(dp[line][l][r][0][0] , query(1 , 0 , 1 , l - 1 , r + 0 , m));
			U(dp[line][l][r][0][0] , query(0 , 1 , 1 , l + 0 , r + 1 , m));
			U(dp[line][l][r][0][0] , query(1 , 1 , 1 , l - 1 , r + 1 , m));

			U(dp[line][l][r][0][1] , query(0 , 1 , 1 , l + 0 , l , r));
			U(dp[line][l][r][0][1] , query(1 , 1 , 1 , l - 1 , l , r));

			U(dp[line][l][r][1][0] , query(1 , 0 , l , r , r + 0 , m));
			U(dp[line][l][r][1][0] , query(1 , 1 , l , r , r + 1 , m));

			U(dp[line][l][r][1][1] , query(1 , 1 , l , r , l , r));

			U(dp[line][l][r][1][1] , 1);
		}
	}

	REP(line , 1 , nn + 1) REP(i , 1 , m + 1) REP(j , i , m + 1)
		REP(ii , 0 , 2) REP(jj , 0 , 2) U(ans , dp[line][i][j][ii][jj]);

	cout << ans << endl;
    return 0;
}