/*input
100
()(()))))(()((((()())()))(()))()()))(((()))))))))(
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
///-----------------------------------------------------------
#define int long long
#define MAX 210
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , dp[MAX][MAX][MAX] , to[MAX] , qq[MAX][MAX];
string s;
void U(int &now , int val){
	now = ((now + val) % mod + mod) % mod;
}
int f[MAX] , pos;
int32_t main(){
	IOS;
	
	cin >> n >> s;
	
    f[0] = pos = -1;
    REP(i , 1 , s.size()){
        while(pos != -1 && s[pos + 1] != s[i]) pos = f[pos];
        if(s[pos + 1] == s[i]) pos ++;
        f[i] = pos;
    }
    REP(i , 0 , s.size() - 1){
    	pos = f[i];
    	while(pos != -1 && s[pos + 1] == s[i + 1]) pos = f[pos];
    	if(s[pos + 1] != s[i + 1]) pos ++;
    	to[i + 1] = pos + 1;
    }
    qq[0][1] = 1;
	REP(i , 0 , n + n) REP(j , 1 , i + 10){
		U(qq[i + 1][j + 1] , qq[i][j]);
		U(qq[i + 1][j - 1] , qq[i][j]);
	}
    // REP(i , 0 , s.size()) cout << f[i] << " ";cout << endl;
    // REP(i , 0 , s.size()) cout << to[i] << " ";cout << endl;

	dp[0][1][0] = 1;
	REP(i , 0 , n + n) REP(j , 1 , i + 2) REP(k , 0 , s.size()){
		if(s[k] == ')'){
			U(dp[i + 1][j - 1][k + 1] , dp[i][j][k]);
			U(dp[i + 1][j + 1][to[k]] , dp[i][j][k]);
		}
		if(s[k] == '('){
			U(dp[i + 1][j - 1][to[k]] , dp[i][j][k]);
			U(dp[i + 1][j + 1][k + 1] , dp[i][j][k]);
		}
	}
	// REP(i , 1 , n + n + 1) REP(j , 1 , i + 5) REP(k , 0 , s.size())
	// 	if(dp[i][j][k]) DB4(i , j - 1 , k , dp[i][j][k]);
	int ans = 0;
	REP(i , 0 , s.size()) (ans += dp[n + n][1][i]) %= mod;
	ans = qq[n + n][1] + mod - ans;
	cout << ans % mod << endl;
    return 0;
}