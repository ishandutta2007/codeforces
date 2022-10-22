#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define int long long
int a[N+1],b[N+1],dp[N+1],q[N],head,tail;
double son(int j,int k){return dp[j]-dp[k];}
double ma(int j,int k){return b[k]-b[j];}
double f(int j,int k){return son(j,k)/ma(j,k);}
signed main(){
	int n,i;scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",a+i);
	for(i=1;i<=n;i++)scanf("%lld",b+i);
	dp[1]=0;q[tail++]=1;
	for(i=2;i<=n;i++){
		while(head+1<tail&&f(q[head+1],q[head])<a[i])head++;
		dp[i]=dp[q[head]]+b[q[head]]*a[i];
		while(head+1<tail&&f(q[tail-1],q[tail-2])>=f(i,q[tail-1]))tail--;
		q[tail++]=i;
	}
	printf("%lld",dp[n]);
	return 0;
}
/*1
5
1 2 3 4 5
5 4 3 2 0
*/
/*2
6
1 2 3 10 20 30
6 5 4 3 2 0
*/