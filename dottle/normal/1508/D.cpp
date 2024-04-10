#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int N=2e6+5;

int t[N],x[N],y[N],n;

int bel[N],size[N],cnt;

int L;

int tot,fr[N],to[N];

void dfs(int u) {
	if(bel[u]) return ;
	bel[u]=cnt,++size[cnt],dfs(t[u]);
}

int id[N];

inline bool cmp(int a,int b) {
	if(t[a]==a) return 0;
	if(t[b]==b) return 1;
	return atan2(y[a]-y[id[1]],x[a]-x[id[1]])<atan2(y[b]-y[id[1]],x[b]-x[id[1]]);
}

int f[N];

int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}

int main() {
	scanf("%d",&n);
	for(int i=1 ; i<=n ; ++i) scanf("%d%d%d",&x[i],&y[i],&t[i]);
	for(int i=1 ; i<=n ; ++i) if(!bel[i]) ++cnt,dfs(i);
	if(cnt==1) {
		while(t[1]!=1) {
			++tot;
			fr[tot]=1,to[tot]=t[1];
			swap(t[1],t[t[1]]);
		}
	}
	else {
		for(int i=1 ; i<=n ; ++i) id[i]=i;
		for(int i=1 ; i<=cnt ; ++i) f[i]=i;
		int L=0;x[0]=0x3fffffff;
		for(int i=1 ; i<=n ; ++i) if(x[i]<x[L]&&size[bel[i]]!=1) L=i;
		swap(id[1],id[L]);
		sort(id+2,id+n+1,cmp);
		for(int i=2 ; i<n ; ++i) {
			int u=bel[id[i]],v=bel[id[i+1]];
			if(size[u]==1||size[v]==1) continue ;
			int r1=find(u),r2=find(v);
			if(r1==r2) continue ;
			++tot,fr[tot]=id[i],to[tot]=id[i+1];
			f[r1]=r2,swap(t[id[i]],t[id[i+1]]);
		}
		int now=id[1];
		while(t[now]!=now) {
			++tot,fr[tot]=now,to[tot]=t[now];
			swap(t[now],t[t[now]]);
		}
	}
	printf("%d\n",tot);
	for(int i=1 ; i<=tot ; ++i) printf("%d %d\n",fr[i],to[i]);
	return 0;
}