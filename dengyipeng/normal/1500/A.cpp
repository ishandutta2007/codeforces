#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define maxm 2500005
using namespace std;

int n,i,j,k,a[maxn],d[maxm][2],d0[maxm][2],p[maxn],cnt[maxm],D1[maxn],D2[maxn];
int cmp(int i,int j){return a[i]<a[j];}

int main(){
//	freopen("ceshi1.out","w",stdout);
	scanf("%d",&n),k=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i,cnt[a[i]]++;
	for(i=1;i<maxm;i++) if (cnt[i]>=2){
		if (k){
			int x=k,y=i;
			for(j=1;j<=n;j++) if (a[j]==x) D1[++D1[0]]=j;
			else if (a[j]==y)  D2[++D2[0]]=j;
			if (a[D1[1]]+a[D2[1]]!=a[D1[2]]+a[D2[2]])
				printf("!");
			printf("YES\n%d %d %d %d\n",D1[1],D2[1],D1[2],D2[2]);
			return 0;
		} else k=i;
	}
	for(i=1;i<maxm;i++) if (cnt[i]>=4){
		for(j=1;j<=n;j++) if (a[j]==i)
			D1[++D1[0]]=j;
		printf("YES\n%d %d %d %d\n",D1[1],D1[2],D1[3],D1[4]);
		return 0;
	}
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++){
			int x=p[i],y=p[j]; k=a[y]-a[x];
			if (d[k][0]){
				if (x==d[k][0]||x==d[k][1]||y==d[k][0]||y==d[k][1]){
					if (d0[k][0]){
						if (x==d0[k][0]||x==d0[k][1]||y==d0[k][0]||y==d0[k][1]){
						} else {
							if (a[d0[k][0]]+a[y]!=a[d0[k][1]]+a[x])
								printf("!");
							printf("YES\n%d %d %d %d\n",d0[k][0],y,d0[k][1],x);
							return 0;
						}
					} else d0[k][0]=x,d0[k][1]=y;
				} else {
					if (a[d[k][0]]+a[y]!=a[d[k][1]]+a[x])
						printf("!");
					printf("YES\n%d %d %d %d\n",d[k][0],y,d[k][1],x);
					return 0;
				}
			} else d[k][0]=x,d[k][1]=y;
		}
	}
	printf("NO\n");
}