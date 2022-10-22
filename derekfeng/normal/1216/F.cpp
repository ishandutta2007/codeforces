#include<bits/stdc++.h>
#define N 200005
#define INF 0x3f3f3f3f3f3f3f3fll
int n,k,h,t,Q[N];
long long dp[N];
char a[N];
long long val(int x){
	return a[x]=='1'?dp[std::max(1,x-k)-1]+x:INF;
}
void push(int i){
	while(h<=t&&val(Q[t])>=val(i))--t;
	Q[++t]=i;
}
int main(){
	scanf("%d%d%s",&n,&k,a+1);
	dp[0]=0,h=t=0;
	for(register int i=1;i<=k;++i)push(i);
	for(register int i=1;i<=n;++i){
		if(h<=t&&Q[h]<i-k)++h;
		if(i+k<=n)push(i+k);
		dp[i]=std::min(val(Q[h]),dp[i-1]+i);
	}
	printf("%lld\n",dp[n]);
}