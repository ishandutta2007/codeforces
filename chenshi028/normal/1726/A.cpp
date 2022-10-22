#include<cstdio>
#include<iostream>
using namespace std;
const int o=2010;
int T,n,a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&n);ans=-o;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<n;++i) ans=max(ans,a[n]-a[i]);
		for(int i=2;i<=n;++i) ans=max(ans,a[i]-a[1]);
		for(int i=1,lst=a[n];i<=n;++i) ans=max(ans,lst-a[i]),lst=a[i];
	}
	return 0;
}