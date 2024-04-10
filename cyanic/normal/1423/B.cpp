#include <bits/stdc++.h>
using namespace std;
const int MAXN=20010,INF=2e9;
struct Edge {
	int u,v,w;
}e[12*MAXN];
int n,m,s,t,x,y,z,eg,l[MAXN],hd[MAXN];
int ver[12*MAXN],f[12*MAXN],cap[12*MAXN],nx[12*MAXN],cur[MAXN];
int q[MAXN],qh,qt;
bool cmp (Edge a,Edge b) {return a.w<b.w;}
void add_edge (int x,int y,int z) {
	ver[++eg]=y;
	nx[eg]=hd[x],cap[eg]=z,f[eg]=0;
	hd[x]=eg;
	return;
}
bool bfs () {
	memset(l,0,sizeof(l));
	qh=1,qt=0;
	q[++qt]=s,l[s]=1;
	while (qh<=qt) {
		int a=q[qh++];
		for (int i=hd[a];i;i=nx[i]) {
			if (l[ver[i]]||cap[i]<=f[i]) {continue;}
			l[ver[i]]=l[a]+1;
			q[++qt]=ver[i];
		}
	}
	return (l[t]>0);
}
int dfs (int p,int mc) {
	if (p==t) {return mc;}
	int res=0;
	for (int i=cur[p];i&&res<mc;i=nx[i]) {
		cur[p]=i;
		if (l[ver[i]]!=l[p]+1||cap[i]<=f[i]) {continue;}
		int tmp=dfs(ver[i],min(mc-res,cap[i]-f[i]));
		f[i]+=tmp,f[i^1]-=tmp;
		res+=tmp;
	}
	return res;
}
int dinic () {
	int ans=0;
	while (bfs()) {
		for (int i=1;i<=t;i++) {cur[i]=hd[i];}
		ans+=dfs(s,INF);
	}
	return ans;
}
bool chk (int x) {
	eg=1;
	memset(hd,0,sizeof(hd));
	for (int i=1;i<=x;i++) {
		add_edge(e[i].u,e[i].v,1);
		add_edge(e[i].v,e[i].u,0);
	}
	for (int i=1;i<=n;i++) {
		add_edge(s,i,1);
		add_edge(i,s,0);
	}
	for (int i=1;i<=n;i++) {
		add_edge(i+n,t,1);
		add_edge(t,i+n,0);
	}
	return (dinic()==n);
}
int main () {
	scanf("%d%d",&n,&m);
	s=2*n+1,t=2*n+2;
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].v+=n;
	}
	sort(e+1,e+m+1,cmp);
	int l=1,r=m;
	if (!chk(m)) {printf("-1\n");return 0;}
	while (l<r) {
		int mid=(l+r)>>1;
		if (chk(mid)) {r=mid;}
		else {l=mid+1;}
	}
	printf("%d\n",e[l].w);
	return 0;
}