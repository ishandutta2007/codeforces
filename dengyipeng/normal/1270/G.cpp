#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1000005
using namespace std;

int T,n,i,j,k,x,a[maxn],du[maxn],t,w,d[maxn],ans[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=i-a[i];
		for(i=1;i<=n;i++) du[i]=0;
		for(i=1;i<=n;i++) du[a[i]]++;
		t=w=0;
		for(i=1;i<=n;i++) if (!du[i]) d[++w]=i;
		while (t<w){
			x=d[++t];
			if (!--du[a[x]])	
				d[++w]=a[x];
		}
		for(i=1;i<=n;i++) if (du[i]){
			ans[0]=0,j=i;
			while (1){
				ans[++ans[0]]=j,j=a[j];
				if (i==j) break;
			}
			printf("%d\n",ans[0]);
			for(j=1;j<=ans[0];j++) printf("%d ",ans[j]);
			printf("\n"); break;
		}
	}
}