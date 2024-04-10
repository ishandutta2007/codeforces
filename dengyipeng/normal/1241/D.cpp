#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 300005
using namespace std;

int q,n,i,j,k,l[maxn],r[maxn],bz[maxn],ans,mx,cnt;

int main(){
	scanf("%d",&q);
	while (q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) bz[i]=l[i]=r[i]=0;
		ans=0;
		for(i=1;i<=n;i++) {
			scanf("%d",&k);
			if (!bz[k])	bz[k]=1,l[k]=r[k]=i,ans++;
			else l[k]=min(l[k],i),r[k]=max(r[k],i);
		}
		mx=cnt=k=0;
		for(i=1;i<=n;i++) if (bz[i]){
			if (l[i]>k) cnt++;
			else cnt=1;
			k=r[i],mx=max(mx,cnt);
		}
		printf("%d\n",ans-mx);
	}
}