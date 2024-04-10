#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 5090
#define INF 0x3f3f3f3f
#define debug 1

void Solve(){}
LL n , m , k , x[MAX] , dp[MAX][MAX];
LL pre[MAX];
int main(){
	RLLL(n , k , m);
	REPNM(i , 1 , n + 1) RL(x[i]) , pre[i] = pre[i - 1] + x[i];
	
	dp[k][1] = pre[k];
	REPNM(i , k + 1 , n + 1) dp[i][1] = max(dp[i - 1][1] , pre[i] - pre[i - k]);
	REPNM(i , 2 , m + 1){
		dp[k][i] = dp[k][i - 1];
		REPNM(j , k + 1 , n + 1){
			dp[j][i] = max(dp[j - 1][i - 1] , dp[j - k][i - 1] + pre[j] - pre[j - k]);
			dp[j][i] = max(dp[j][i] , dp[j - 1][i]);
			// printf("dp[%d][%d] = %lld %lld\n" , j , i, dp[j][i] , dp[j - 1][i]);
		}
	}
	cout << dp[n][m] << endl;
    return 0;
}