#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(19260817);
int n,ans,tot,prim[100004];
ll a[200004];
bool flg[1000004];
void init(){
	for(int i=2;i<=1e3;i++)if(!flg[i])
		for(int j=i*i;j<=1e6;j+=i)flg[j]=1;
	for(int i=2;i<=1e6;i++)if(!flg[i])prim[++tot]=i;
}
int go(ll x){
	ll ans=0;
	for(int i=0;i<n;i++){
		if(a[i]%x<x-a[i]%x&&a[i]>=x)ans+=a[i]%x;
		else ans+=x-a[i]%x;
	}
	if(ans>n)return n;
	return ans;
}
int sol(ll x){
	int res=n;
	for(int i=1;i<=tot&&prim[i]<=x/prim[i];i++)if(x%prim[i]==0){
		while(x%prim[i]==0)x/=prim[i];
		res=min(res,go(prim[i]));
	}
	if(x>1)res=min(res,go(x));
	return res;
}
int main(){
	init();
	scanf("%d",&n),ans=n;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int T=30;T;T--){
		int p=rng()%n;
		if(a[p]>1)ans=min(ans,sol(a[p]-1));
		ans=min(ans,sol(a[p]));
		ans=min(ans,sol(a[p]+1));
	}
	printf("%d",ans);
}