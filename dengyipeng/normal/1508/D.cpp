#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 2005
#define db long double
using namespace std;

int n,i,j,k,x[maxn],y[maxn],p[maxn],rt,fa[maxn],a[maxn];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
db arc[maxn];
int cmp(int i,int j){return arc[i]<arc[j];}
int ans[maxn*2][2],cnt;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&p[i]);
	for(i=1;i<=n;i++) if (p[i]!=i&&(!rt||x[i]<x[rt])) rt=i;
	if (!rt) printf("0"),exit(0);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++) if (father(i)!=father(p[i])) fa[fa[i]]=fa[p[i]];
	int tot=0;
	for(i=1;i<=n;i++) if (p[i]!=i&&i!=rt) 
		a[++tot]=i,arc[i]=atan2(y[i]-y[rt],x[i]-x[rt]);
	sort(a+1,a+1+tot,cmp);
	for(i=2;i<=tot;i++) if (father(a[i])!=father(a[i-1])){
		cnt++,ans[cnt][0]=a[i],ans[cnt][1]=a[i-1];
		swap(p[a[i]],p[a[i-1]]);
		fa[father(a[i])]=father(a[i-1]);
	}
	while (p[rt]!=rt){
		cnt++,ans[cnt][0]=rt,ans[cnt][1]=p[rt];
		swap(p[rt],p[p[rt]]);
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}