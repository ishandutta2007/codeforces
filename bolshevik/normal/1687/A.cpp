#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,k;long long a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]),a[i]+=a[i-1];
		if(k<=n){
			for(int i=k;i<=n;++i) ans=max(ans,a[i]-a[i-k]);
			ans+=k*(k-1ll)/2;
		}
		else ans=a[n]+(2*k-n-1ll)*n/2;//n*(n-1ll)/2+(k-n)/(n-1)*n*(n-1)+(k-n)%(n-1)*((k-n)%(n-1)+1);
	}
	return 0;
}