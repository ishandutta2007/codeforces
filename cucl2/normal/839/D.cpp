#include <bits/stdc++.h>
using namespace std;
const int Mod=1000000007;

int ksmii(int a,int b){
	if(!b){
		return 1;
	}
	int ff=ksmii(a,b>>1);
	ff=1ll*ff*ff%Mod;
	if(b&1){
		ff=1ll*ff*a%Mod;
	}
	return ff;
}

int dp[1000005];
int n;
int a[200005];
int hv[1000005];

int getdp(int now){
	if(~dp[now]){
		return dp[now];
	}
	int ans=0;
	for(int i=1;i<=1000000/now;i++){
		ans+=hv[i*now];
		if(ans>=Mod){
			ans-=Mod;
		}
	}
	if(!ans){
		return 0;
	}
	ans=1ll*ksmii(2,ans-1)*ans%Mod;
	for(int i=2;i<=1000000/now;i++){
		ans-=getdp(i*now);
		if(ans<0){
			ans+=Mod;
		}
	}
	return dp[now]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		hv[a[i]]++;
	}
	int ans=0;
	for(int i=2;i<=1000000;i++){
		ans=(ans+1ll*getdp(i)*i)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}