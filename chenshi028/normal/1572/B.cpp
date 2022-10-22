#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o],ans[o],cnt;bool flg;
int main(){
	for(scanf("%d",&T);T--;cnt=0,putchar('\n')){
		scanf("%d",&n);flg=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=b[i-1]^a[i];
		if(n&1){
			for(int i=n-2;i>0;i-=2) ans[++cnt]=i,b[i]=b[i+2],b[i+1]=b[i-1];
			for(int i=1;i<=n-2;i+=2) ans[++cnt]=i,b[i]=b[i+2],b[i+1]=b[i-1];
		}
		else{
			for(int i=1;i<n;i+=2) if(!b[i]){
				for(int j=i-2;j>0;j-=2) ans[++cnt]=j,b[j]=b[j+2],b[j+1]=b[j-1];
				for(int j=i+1;j<=n-2;j+=2) ans[++cnt]=j,b[j]=b[j+2],b[j+1]=b[j-1];
				break;
			}
			for(int i=n-2;i>0;i-=2) ans[++cnt]=i,b[i]=b[i+2],b[i+1]=b[i-1];
		}
		for(int i=1;i<=n;++i) flg|=b[i];
		if(flg) printf("NO");
		else{
			printf("YES\n%d\n",cnt);
			for(int i=1;i<=cnt;++i) printf("%d ",ans[i]);
		}
	}
	return 0;
}