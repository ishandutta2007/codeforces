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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m , nn , sum , all , x[MAX] , p[MAX] , val[MAX] , dp[105][10005];

int32_t main(){
	IOS;
    cin >> n >> m;
    MEM(dp , INF) , dp[0][0] = 0;
    REP(i , 1 , n + 1){
    	cin >> nn , sum += nn;
    	REP(j , 1 , nn + 1) cin >> x[j] , all += x[j];
    	REP(j , 1 , nn + 1) p[j] = p[j - 1] + x[j];
    	REP(j , 1 , nn + 1) val[j] = INF;
    	REP(ii , 1 , nn + 1) REP(jj , ii , nn + 1) val[jj - ii + 1] = min(val[jj - ii + 1] , p[jj] - p[ii - 1]);
    	// REP(j , 1 , nn + 1) cout << val[j] << " "; cout << endl;

    	REP(j , 0 , 10005) dp[i][j] = dp[i - 1][j];
    	REP(j , 1 , nn + 1) REP(ii , j , 10005) dp[i][ii] = min(dp[i][ii] , dp[i - 1][ii - j] + val[j]);
    	// REP(j , 0 , 10) cout << dp[i][j] << " "; cout << endl;
    }
    cout << all - dp[n][sum - m] << endl;
    return 0;
}