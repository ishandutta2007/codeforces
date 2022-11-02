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
#define MAX 200
#define INF 0x3f3f3f3f
#define debug 1

int x[MAX] , y[MAX];
int a[MAX] , b[MAX];
int main(){
	int n , m;
	while(~RII(n , m)){
		REP(i , n) RI(x[i]);
		REP(i , n) RI(y[i]);

		REPNM(i , 1 , n) a[i] = x[i] - x[i - 1];
		a[0] = x[0] + m - x[n - 1];
		REPNM(i , 1 , n) b[i] = y[i] - y[i - 1];
		b[0] = y[0] + m - y[n - 1];


		// REP(i , n) cout << a[i] << " ";cout << endl;
		// REP(i , n) cout << b[i] << " ";cout << endl;

		int ok = 0;
		// i - n - i -1
		REP(i , n){
			int oo = 1;
			REP(j , n - i){
				if(b[j] != a[i + j]) oo = 0;
				// DBGG(a[i + j] , b[j]);
			}
			int now = 0;
			REPNM(j , n - i , n){
				if(b[j] != a[now]) oo = 0;
				// DBGG(a[now] , b[j]);
				
				now ++;
			}
			if(oo == 1)ok = 1;
			// cout << endl;
		}
		if(ok) puts("YES");
		else puts("NO");

	}

    return 0;
}