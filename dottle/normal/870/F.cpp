#include<bits/stdc++.h>
const int N=1.14514e7;
using namespace std;

int d[N],v[N],phi[N],p[N],a[N],sum[N],cnt;
int n;

void init(){
	for(int i=2;i<=n;i++){
		if(!v[i]){
			d[i]=i;
			p[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;i*p[j]<=n;j++){
			d[i*p[j]]=p[j];
			phi[i*p[j]]=phi[i]*p[j];
			v[i*p[j]]=1;
			if(i%p[j]==0)break;
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
		a[d[i]]++;
	}
	for(int i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
}
int S(int l,int r){
	return max(0,sum[r]-sum[l-1]);
}

main(){
	cin>>n;
	init();
	long long ans=1ll*(n-1)*(n-2)/2;
	for(int i=2;i<=n;i++)
		ans+=phi[i]-1;
	for(int i=1;i<=cnt;i++){
		ans+=1ll*a[p[i]]*S(max(p[i]+1,n/p[i]+1),n);
		ans-=3ll*a[p[i]]*S(max(p[i]+1,(n>>1)+1),n);
	}
	cout<<ans;
}