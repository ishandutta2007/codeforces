#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",n-ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1,j,res;i<=n;++i) if(a[i]^a[i-1]){
			for(j=i;j<n&&a[j+1]==a[i];++j);
			res=j-i+1;
			if(j<n){
				++res;
				for(int k=j+1,l,r,md;k<=n;res+=((k=l)<=n))
					for(l=k+1,r=n+1;l<r;) if(a[md=l+r>>1]-a[k]>=a[k]-a[i]) r=md;else l=md+1;
			}
			ans=max(ans,res);
		}
	}
	return 0;
}