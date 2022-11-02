/*input
3121
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

string s;
int x[MAX] , n = 0 , dp[MAX][3];
int32_t main(){
    IOS;
    cin >> s;
    reverse(ALL(s));

    int ans = 0;
    REP(i , 0 , s.size()) x[++n] = s[i] - '0';
    
    REP(i , 0 , n + 1) REP(j , 0 , 3) dp[i][j] = -INF;
	dp[0][0] = 0;
    REP(i , 0 , n){
    	REP(j , 0 , 3){
    		if(x[i + 1] == 0){
    			dp[i + 1][0] = max(dp[i + 1][0] , dp[i][j] + 1);
    			dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
    		}
    		else {
    			int val = (j + x[i + 1]) % 3;
    			dp[i + 1][val] = max(dp[i + 1][val] , dp[i][j] + (val == 0));
    			dp[i + 1][0] = max(dp[i + 1][0] , dp[i][j]);
    		}
    	}
    }
    int big = 0;
    big = max(big , dp[n][0]);
    big = max(big , dp[n][1]);
    big = max(big , dp[n][2]);
    cout << big << endl;
    return 0;
}