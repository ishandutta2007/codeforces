#include<bits/stdc++.h>
using namespace std;
#define N 100
char s[N+5];
int Sum[N+1],dp[N+1],path[N+1];
bitset<N+1> sp;
int main(){
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	int n,i,now;scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)Sum[i]=Sum[i-1]+(s[i]=='1'?1:-1);
	for(i=1;i<=n;i++)for(int j=0;j<i;j++)
		if(Sum[i]-Sum[j]&&dp[j]+1<dp[i])dp[i]=dp[j]+1,path[i]=j;
	printf("%d\n",dp[n]);
	now=n;
	while(now)sp.set(now),now=path[now];
	for(i=1;i<=n;i++)putchar(s[i]),sp[i]?putchar(' '):0;
	return 0;
}
/*1
1
1
*/
/*2
2
10
*/
/*3
6
100011
*/