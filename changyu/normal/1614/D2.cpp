#include<bits/stdc++.h>
const int A=2e7+3,N=1e5+3,P=1.5e6;
bool np[A];
int n,a[N],c[A],p[P],cnt;
long long dp[A],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),++c[a[i]];
	for(int i=2;i<A;i++)if(!np[i]){
		p[++cnt]=i;
		for(int j=(A-1)-(A-1)%i;j>=i;j-=i){
			np[j]=1;
			c[j/i]+=c[j];
		}
	}
	for(int i=A-1;i;i--){
		dp[i]=(long long)c[i]*i;
		for(int k=1,j;k<=cnt&&i*p[k]<A;k++){
			j=i*p[k];
			dp[i]=std::max(dp[i],dp[j]+(long long)(c[i]-c[j])*i);
		}
		if(c[i]==n)ans=std::max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}