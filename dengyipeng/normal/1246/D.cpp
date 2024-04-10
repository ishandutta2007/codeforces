#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int n,m,i,j,k,mxdep,dep[maxn],fa[maxn],cnt[maxn];
int x,d[maxn],vis[maxn],tot,ans[maxn];
int em,e[maxn],nx[maxn],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	cnt[x]++;
}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&n);
	dep[0]=1;
	for(i=1;i<n;i++) {
		scanf("%d",&fa[i]),dep[i]=dep[fa[i]]+1;
		x=(dep[i]>dep[x])?i:x;
		insert(fa[i],i);
	}
	mxdep=dep[x];
	while (cnt[x]==0&&x) d[++d[0]]=x,vis[x]=1,cnt[fa[x]]--,x=fa[x];
	for(tot=1;tot<=n-mxdep;tot++){
		for(int &i=ls[x];i;i=nx[i]) if (!vis[e[i]]){
			x=e[i],ans[tot]=d[d[0]];
			break;
		}
		while (cnt[x]==0&&x) d[++d[0]]=x,vis[x]=1,cnt[fa[x]]--,x=fa[x];
	}
	printf("0 ");
	while (d[0]) printf("%d ",d[d[0]--]);
	printf("\n%d\n",n-mxdep);
	for(i=n-mxdep;i>=1;i--) printf("%d ",ans[i]);
}