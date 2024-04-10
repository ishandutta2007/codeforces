#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
///---------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
#define debug 1
typedef pair< PLL , PLL> PLLL;
LL n , l , r;
LL a[MAX] , c[MAX];
PLLL x[MAX];
LL tmp[MAX] , ans[MAX];
int main(){
	RLLL(n , l , r);
	REP(i , n) RL(a[i]);
	REP(i , n) RL(c[i]);
	REP(i , n){
		x[i].A.A = c[i];
		x[i].A.B = i;
		x[i].B.A = l - a[i];
		x[i].B.B = r - a[i];
	}
	sort(x , x + n);

	LL ok = 1 , now = x[0].B.A;
	tmp[0] = now;


		// DBGG("now = " , now);

	REPNM(i , 1 , n){
		if(now + 1 > x[i].B.B) ok = 0;
		if(!ok)break;
		now = max(now + 1 , x[i].B.A);
		tmp[i] = now;
	// DBGG("now" , x[i].A.A);
	// DBGG("now" , x[i].A.B);
	// DBGG("now" , x[i].B.A);
	// DBGG("now" , x[i].B.B);
		// DBGG("now = " , now);
	}
	if(!ok) puts("-1");
	else {
		REP(i , n){
			LL tma = x[i].A.B;
			ans[tma] = tmp[i] + a[tma];
		}
		printf("%lld", ans[0]);
		REPNM(i , 1 , n) printf(" %lld", ans[i]);
		puts("");
	}
    return 0;
}