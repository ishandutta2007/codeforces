#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,a[o],dp[o],pd[o],f[o];long long ans;
void upd(int i){
	if(i>n) return;
	int Dp=0,Pd=n+1;
	if(pd[i-1]<a[i]) Dp=max(Dp,a[i-1]);
	if(a[i-1]<a[i]) Dp=max(Dp,dp[i-1]);
	if(dp[i-1]>a[i]) Pd=min(Pd,a[i-1]);
	if(a[i-1]>a[i]) Pd=min(Pd,pd[i-1]);
	if(Dp==dp[i]&&Pd==pd[i]) return;
	dp[i]=Dp;pd[i]=Pd;
	if(Dp||Pd<=n) upd(i+1),f[i]=f[i+1]+1;
	else f[i]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i;ans+=f[i--]) dp[i]=n+1,pd[i]=0,upd(i+1),f[i]=f[i+1]+1;
	printf("%lld",ans);
	return 0;
}