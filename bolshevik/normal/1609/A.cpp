#include<cstdio>
#include<iostream>
using  namespace std;
const int o=20;
int T,n,a[o];long long ans,t;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i,ans=max(ans,t)){
			t=a[i];
			for(int j=1,v;j<=n;++j) if(i^j) for(v=a[j];v%2==0;v/=2) t*=2;
			for(int j=1,v;j<=n;++j) if(i^j){for(v=a[j];v%2==0;v/=2);t+=v;}
		}
	}
	return 0;
}