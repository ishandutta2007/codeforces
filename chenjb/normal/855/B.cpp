#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
typedef long long ll;
int a[N],p,q,r,n;ll b[N],c[N];

int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	rep(i,n)scanf("%d",a+i);
	rep(i,n){
		b[i]=1ll*a[i]*p;
		if(i>1)b[i]=max(b[i],b[i-1]);
	}
	for(int i=n;i;--i){
		c[i]=1ll*a[i]*r;
		if(i<n)c[i]=max(c[i],c[i+1]);
	}
	ll ans=1ll*a[n]*q+b[n]+c[n];
	rep(i,n-1)ans=max(ans,1ll*a[i]*q+b[i]+c[i]);
	printf("%lld\n",ans);
	return 0;
}