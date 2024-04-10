#include<cstdio>
using namespace std;
const int o=110;
int T,n,a[o],ans;
int main(){
	for(scanf("%d\n",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) for(int k=i;k<=j;++k) ans+=1+!a[k];
	}
	return 0;
}