#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 2005
using namespace std;

int T,n,i,j,k,id,F,ans[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),id=0;
		for(i=1;i<n;i++) {
			printf("? 1 %d\n",n-i);
			printf("%d\n",i);
			for(j=i+1;j<=n;j++) printf("%d ",j);
			printf("\n");
			fflush(stdout);
			scanf("%d",&F);
			if (F) {id=i;break;}
		}
		int sum=F;
		ans[0]=0;
		for(i=id+1;i<=n;i++) {
			if (i==n){
				if (!sum) ans[++ans[0]]=i;
				break;
			}
			printf("? 1 1\n%d\n%d\n",id,i);
			fflush(stdout);
			scanf("%d",&F),sum-=F;
			if (!F) ans[++ans[0]]=i;
		}
		int l=1,r=id-1,mid,id0=0;
		while (l<=r){
			mid=(l+r)>>1;
			printf("? %d 1\n",id-mid);
			for(i=mid;i<=id-1;i++) printf("%d ",i); printf("\n");
			printf("%d\n",id);
			fflush(stdout);
			scanf("%d",&F);
			if (!F) r=mid-1; else l=mid+1,id0=mid;
		} 
		for(i=1;i<id;i++) if (i!=id0) ans[++ans[0]]=i;
		printf("! %d ",ans[0]);
		for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
}