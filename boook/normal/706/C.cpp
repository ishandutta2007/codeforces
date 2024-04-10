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
#define MAX 100900
#define INF 10000000000000000LL

int n , val[MAX];
int dp[MAX][2];
string s[MAX] , re[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> val[i];
	REP(i , 1 , n + 1) cin >> s[i];
	REP(i , 1 , n + 1) re[i] = s[i] , reverse(ALL(re[i]));
	
	REP(i , 1 , n + 1) dp[i][0] = dp[i][1] = INF;
	dp[1][0] = 0 , dp[1][1] = val[1];
	REP(i , 2 , n + 1){
		if(s[i] >= s[i - 1])  dp[i][0] = min(dp[i][0] , dp[i - 1][0]);
		if(s[i] >= re[i - 1]) dp[i][0] = min(dp[i][0] , dp[i - 1][1]);

		if(re[i] >= s[i - 1])  dp[i][1] = min(dp[i][1] , dp[i - 1][0] + val[i]);
		if(re[i] >= re[i - 1]) dp[i][1] = min(dp[i][1] , dp[i - 1][1] + val[i]);
	}

	if(dp[n][0] >= INF && dp[n][1] >= INF) cout << -1 << endl;
	else cout << min(dp[n][0] , dp[n][1]) << endl;
    return 0;
}