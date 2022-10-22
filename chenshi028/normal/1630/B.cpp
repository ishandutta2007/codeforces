#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,k,a[o],b[o],ans,t;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);t=(n+k+1)/2;ans=o;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		for(int i=1;i+t-1<=n;++i) ans=min(ans,b[i+t-1]-b[i]);
		for(int i=1,r=0;i<=n;++i) if(b[i+t-1]-b[i]==ans){
			printf("%d %d\n",b[i],b[i+t-1]);
			for(;--k;) for(int j=r+1,s=0;j<=n;++j)
				if(a[j]<b[i]||a[j]>b[i+t-1]) --s;
				else if((++s)>0){printf("%d %d\n",r+1,j);r=j;break;}
			printf("%d %d\n",r+1,n);
			break;
		}
	}
	return 0;
}