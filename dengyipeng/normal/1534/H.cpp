#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;

int n,i,j,k;
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int f[maxn],d[maxn],dep[maxn],fa[maxn];
int cmp(int x,int y){return x>y;}
void dfs1(int x,int p){
	dep[x]=dep[p]+1,fa[x]=p;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs1(e[i],x);
	f[x]=0; int w=0;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		d[++w]=max(0,f[e[i]]-1);
	sort(d+1,d+1+w,cmp);
	for(int i=1;i<=w;i++) f[x]=max(f[x],d[i]+i);
}
	
int ans,nex[maxn],g[maxn];
struct arr{int x,f;} a[maxn];
int cmp1(arr a,arr b){return a.f>b.f;}
void dfs2(int x,int p,int f0){
	int w=0; if (p) d[++w]=max(f0-1,0);
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p) d[++w]=max(f[e[i]]-1,0);
	sort(d+1,d+1+w,cmp);
	if (w==1) ans=max(ans,d[1]+1); else {
		int mx=0;
		for(int i=2;i<=w;i++) mx=max(mx,d[i]+i);
		ans=max(ans,mx+d[1]);
	}
	w=0;
	if (p) a[++w]=(arr){p,max(f0-1,0)};
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p) a[++w]=(arr){e[i],max(f[e[i]]-1,0)};
	sort(a+1,a+1+w,cmp1);
	nex[w+1]=0;
	for(int i=w;i>=1;i--) nex[i]=max(nex[i+1],a[i].f+i-1);
	int pre=0;
	for(int i=1;i<=w;i++) {
		int y=a[i].x;
		if (y!=p) g[y]=max(pre,nex[i+1]);
		pre=max(pre,a[i].f+i);
	}
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs2(e[i],x,g[e[i]]);
}

int ansa,ansb;

int bz[maxn];
vector<int> P[maxn];
int cmp2(int x,int y){return f[x]>f[y];}

int check(int x);
int find(int x){
	for(int i=0;i<P[x].size();i++){
		int y=P[x][i];
		if (!bz[y]){
			int tmp=check(y);
			if (tmp) return tmp;
		}
	}
	return x;
}

int check(int x){
	int now=x;
	while (1){
		int y=0;
		for(int i=ls[now];i;i=nx[i]) if (dep[e[i]]>dep[now]&&!bz[e[i]])
			if (!y||f[e[i]]>f[y]) y=e[i];
		if (!y) break; now=y;
	}
	printf("? %d\n",now),fflush(stdout);
	int y; scanf("%d",&y);
	if (dep[y]<dep[x]) return 0;
	while (now!=y) bz[now]=1,now=fa[now];
	return find(now);
}

void doit(int x){
	for(int y=1;y<=n;y++) {
		for(int i=ls[y];i;i=nx[i]) if (e[i]!=fa[y])
			P[y].push_back(e[i]);
		sort(P[y].begin(),P[y].end(),cmp2);
	}
	
	int w=0;
	for(int i=ls[x];i;i=nx[i]) a[++w]=(arr){e[i],f[e[i]]};
	sort(a+1,a+1+w,cmp1);
	int tp=0;
	for(int i=1;i<=w;i++){
		int tmp=check(a[i].x);
		if (tmp) {
			tp++;
			if (tp==1) ansa=tmp; else 
				{ansb=tmp;return;}
		} 
	}
	if (!ansa) ansa=x; if (!ansb) ansb=x;
}

int main(){
//	freopen("ceshi.in","r",stdin);
//	FILE* file=fopen("ceshi.in","r");
//	fscanf(file,"%d",&n);
	scanf("%d",&n);
	if (n==1) printf("0\n! 1 1\n"),exit(0);
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
//		fscanf(file,"%d%d",&j,&k),insert(j,k);
	dfs1(1,0);
	ans=0,dfs2(1,0,0);
	printf("%d\n",ans),fflush(stdout);
//	fclose(file);
	int rt; scanf("%d",&rt);
	dfs1(rt,0);
	doit(rt);
	printf("! %d %d\n",ansa,ansb),fflush(stdout);
}