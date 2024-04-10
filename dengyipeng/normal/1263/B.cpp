#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 11
#define maxm 10000
using namespace std;

int T,n,a[maxn],i,j,k,bz[maxm],b[maxn],ans;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(bz,0,sizeof(bz)),ans=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) if (bz[a[i]]) {
			ans++;
			for(j=0;j<=9;j++) if (!bz[a[i]/10*10+j]){
				for(k=i;k<=n;k++) if (a[i]/10*10+j==a[k])
					break;
				if (k>n){
					b[i]=a[i]/10*10+j;
					break;
				}
			}
			bz[b[i]]=1;
		} else b[i]=a[i],bz[b[i]]=1;
		printf("%d\n",ans);
		for(i=1;i<=n;i++) {
			if (b[i]<1000) printf("0");
			if (b[i]<100) printf("0");
			if (b[i]<10) printf("0");
			printf("%d\n",b[i]);
		}
	}
}