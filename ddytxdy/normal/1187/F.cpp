#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ma(a,b,c) max(a,max(b,c))
#define mi(a,b,c) min(a,min(b,c))
#define LL long long
#define int LL
using namespace std;
const int N=2e5+50,mod=1e9+7;
int n,l[N],r[N],p[N],c[N],q[N],d[N];LL sum,ans;
int power(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
signed main(){
	scanf("%d",&n);//r[0]=1e9;
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]),r[i]++;
	for(int i=1;i<=n;i++)c[i]=power(r[i]-l[i],mod-2);
//	p[1]=0;
	for(int i=1;i<=n;i++)p[i]=1ll*max(0ll,min(r[i],r[i-1])-max(l[i],l[i-1]))*c[i-1]%mod*c[i]%mod;
	for(int i=1;i<=n;i++)q[i]=(1+mod-p[i])%mod;
	for(int i=1;i<n;i++)d[i]=(1+mod-p[i+1]-p[i]+1ll*max(0ll,mi(r[i+1],r[i],r[i-1])-ma(l[i+1],l[i],l[i-1]))*c[i-1]%mod*c[i]%mod*c[i+1]%mod)%mod;	
	for(int i=1;i<=n;i++)sum+=q[i];sum%=mod;
	for(int i=1;i<=n;i++){
		ans+=q[i]+q[i]*(sum-q[i-1]-q[i]-q[i+1])%mod+d[i]+d[i-1];
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}