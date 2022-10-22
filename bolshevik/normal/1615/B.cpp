#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,l,r,ans,a[o][20];
int main(){
	for(int i=0;i<20;++i) for(int j=1;j<o;++j) a[j][i]=a[j-1][i]+!((j>>i)&1);
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%d",&l,&r);ans=r;
		for(int i=0;i<20;++i) ans=min(ans,a[r][i]-a[l-1][i]);
	}
	return 0;
}