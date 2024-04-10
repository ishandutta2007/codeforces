#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e6;
int T,n,ans,c[2];char a[o],b[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%s%s",&n,a+1,b+1);ans=o;
		for(int t=0;t<2;++t){
			c[0]=c[1]=0;
			for(int i=1;i<=n;++i) if(a[i]^b[i]^t) ++c[a[i]-48];
			if((c[0]+c[1])%2==t%2&&c[1]<=c[0]+1&&c[0]<=c[1]) ans=min(ans,c[0]+c[1]);
		}
		if(ans==o) ans=-1;
	}
	return 0;
}