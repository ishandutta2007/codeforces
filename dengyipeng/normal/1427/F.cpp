#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1205
using namespace std;

int n,i,j,k,a[maxn],bz[maxn],du[maxn],used[maxn],res;
int d[maxn][3],id[maxn],c[maxn],p[maxn][3],tot,w,fa[maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=3*n;i++) scanf("%d",&k),a[k]=1;
	for(i=1;i<=6*n;i++){
		if (!w||a[d[w][0]]!=a[i])
			w++,d[w][0]=i,c[w]=1,id[w]=++tot;
		else {
			d[w][c[w]++]=i;
			if (c[w]==3) {
				k=id[w],fa[k]=id[w-1],bz[k]=a[d[w][0]];
				memcpy(p[k],d[w],sizeof(p[k]));
				w--;
			}
		}
	}
	for(i=1;i<=tot;i++) du[fa[i]]++;
	for(i=1;i<=tot;i++) if (fa[i]==0&&bz[i]==0) res++;
	for(i=1;i<=2*n;i++){
		int c=i&1,x=0;
		for(j=1;j<=tot;j++) if (du[j]==0&&!used[j]&&bz[j]==c){
			if (i<2*n&&c==0&&fa[j]==0&&res==1) continue;
			x=j;break;
		}
		printf("%d %d %d\n",p[x][0],p[x][1],p[x][2]);
		du[fa[x]]--,used[x]=1;
		if (c==0&&fa[x]==0) res--;
	}
}