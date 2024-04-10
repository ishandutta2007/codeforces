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
#define MAX 1010
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

void Read(){}

void Solve(){}

double x[MAX][2];
double dp[MAX] , pa[MAX];

int main(){
	int n , m;	
	RII(n , m);
	REPNM(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];

	double l = 0 , r = INF;

	REP(times , 100){
		double k = (l + r) / 2;
		// DBGG("k = " , k);
		// MEM(dp , INF);
		fill(dp , dp + MAX , INF);
		dp[0] = 0;
		REPNM(i , 1 , n + 1){
			// dp[i] = INF;
			REPNM(j , 0 , i){
				double tmp = dp[j] + sqrt(abs(x[i][0] - x[j][0] - m)) - k * x[i][1];
				if(tmp < dp[i]) dp[i] = tmp , pa[i] = j;
			}
		}
		if(dp[n] <= 0) r = k;
		else l = k;
	}
	stack<int> cc;
	while(n != 0) cc.push(n) , n = pa[n];
	printf("%d", cc.top()) , cc.pop();

	while(cc.size()) printf(" %d", cc.top()) , cc.pop();
	puts("");
    return 0;
}