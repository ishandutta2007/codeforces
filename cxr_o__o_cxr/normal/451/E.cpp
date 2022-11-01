// 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=24,mod=1e9+7;
#define ll long long
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if((1<<i)&r)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
int n,inv[N];
ll a[N],m,ans=0;
inline int C(ll y,int x){//x 
	if(y<0||x<0||y<x)return 0;
	y%=mod;//lucas
	if(y==0||x==0)return 1;
	int ret=1;
	for(int i=0;i<x;i++)
		ret=(ll)ret*(y-i)%mod;
	for(int i=1;i<=x;i++)
		ret=(ll)ret*inv[i]%mod;
	return ret;
}
int main(){
	for(int i=1;i<=20;i++)
		inv[i]=ksm(i,mod-2);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ans=C(n+m-1,n-1);
	for(int i=1;i<1<<n;i++){
		ll t=n+m;
		int p=0;
		for(int j=0;j<n;j++)
			if((1<<j)&i){
				p++;
				t-=a[j+1];
			}
		t-=p+1;
		if(p&1)ans=(ans-C(t,n-1)+mod)%mod;
		else ans=(ans+C(t,n-1)+mod)%mod;
	}
	cout<<ans;
	return (0-0);
}