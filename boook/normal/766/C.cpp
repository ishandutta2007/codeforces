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
#define MAX 3000
#define INF 0x3f3f3f3f
#define debug 1
#define MOD 1000000007LL
LL _ , use[MAX] , pre[MAX];
LL dp[MAX][MAX] , tmpr[MAX];
LL can[MAX][MAX] , cpre[MAX];
string s , sc;
int main(){
	IOS;
	cin >> _ >> sc;
	s = "." + sc;
	LL sec = 0;
	REP(i , 26) cin >> use[i];

	REPNM(i , 1 , s.size()){
		LL mm = INF;
		RREP(j , i , 0){
			if(j == 0) pre[i] = 0 , sec = max(sec , LL(i));
			else {
				mm = min(mm , use[s[j] - 'a']);
				if(i - j + 1 > mm){
					pre[i] = j;
					sec = max(sec , (LL)i - (LL)j);
					break;
				}
			}
		}
	}

	MEM(dp , 0);
	MEM(can , 0);
	REPNM(i , 1 , s.size()){
		if(pre[i] == 0) dp[i][1] = 1 , can[i][1] = 1;
		else break;	
	}

	REPNM(j , 2 , s.size()){

		REPNM(i , 1 , s.size()){
			tmpr[i] = (tmpr[i - 1] + dp[i][j - 1]) % MOD;
			cpre[i] = cpre[i - 1] + can[i][j - 1];
		}


		REPNM(i , 1 , s.size()){
			if(pre[i] == 0) dp[i][j] = (dp[i][j] + tmpr[i - 1]) % MOD;
			else dp[i][j] = (dp[i][j] + tmpr[i - 1] - tmpr[pre[i] - 1]) % MOD;
			if(pre[i] == 0){
				if(cpre[i - 1]) can[i][j] = 1;
			}
			else if(cpre[i - 1] - cpre[pre[i] - 1] > 0) can[i][j] = 1;
		}

	}
	LL ans = 0 , thr = INF;
	REPNM(i , 1 , s.size()) ans = (ans + dp[_][i]) % MOD;
	RREP(i , s.size() - 1 , 1){
		if(can[_][i] != 0) thr = min(thr , LL(i));
	}
	cout << ans << endl;
	cout << sec << endl;
	cout << thr << endl;

    return 0;
}