#include<cstdio>
using namespace std;
const int o=1010;
int T,n,a[o][o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
		for(int i=4;i<=n*2;i+=4)
			if(i-1<=n) for(int j=1,k=i-1;k>0;j+=2,k-=2) ans^=a[j][k]^a[j][n-k+1];
			else for(int j=i-n,k=n;j<=n;j+=2,k-=2) ans^=a[j][k]^a[j][n-k+1];
	}
	return 0;
}