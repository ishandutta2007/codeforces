#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=300005;
int t,n,a[N],ans,pos,f[E*2],e,p[N],q[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	for(int i=2;i<=1000000;++i)
		if(!f[i])
			for(int j=i*2;j<=1000000;j+=i)
				f[j]=1;
	f[1]=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&e);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			p[i]=q[i]=0;
		}
		long long ans=0;
		for(int i=1;i<=e;++i)
			for(int j=i;j<=n;j+=e)
				if(!f[a[j]]){
					int k;
					for(k=j+e;k<=n&&a[k]==1;k+=e)
						++p[j];
					j=k-e;
				}
		reverse(a+1,a+1+n);
		for(int i=1;i<=e;++i)
			for(int j=i;j<=n;j+=e)
				if(!f[a[j]]){
					int k;
					for(k=j+e;k<=n&&a[k]==1;k+=e)
						++q[j];
					j=k-e;
				}
		for(int i=1;i<=n;++i)
			ans+=1ll*(p[i]+1)*(q[n-i+1]+1)-1;
		printf("%lld\n",ans);
	}
}