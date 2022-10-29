#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200005
#define maxt 800005
using namespace std;

int n,i,j,k,d[maxn],tmpd[maxn];
struct node{
	int x,i;
	node(int _x=0,int _i=0){x=_x,i=_i;}
};

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

struct Graph{
	int tot,dfn[maxn],sz[maxn],used[maxn];
	int em,e[maxn*2],nx[maxn*2],ls[maxn],E[maxn];
	vector<node> t[2][maxt]; int fi[2][maxt],ed[2][maxt];
	
	void insert(int x,int y){
		em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
		em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
	}
	void dfs(int x,int p){
		dfn[x]=++tot,sz[x]=1;
		for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
			dfs(e[i],x),sz[x]+=sz[e[i]];
	}
	void init(){
		for(int i=2;i<=n;i++) 
			read(E[i]),insert(i,E[i]);
		dfs(1,0);
	}
	
	void add(int tp,int x,int l,int r,int p,node q){
		t[tp][x].push_back(q),ed[tp][x]++;
		if (l==r) return; 
		int mid=(l+r)>>1;
		if (p<=mid) add(tp,x<<1,l,mid,p,q);
		else add(tp,x<<1^1,mid+1,r,p,q);
	}
	
	void find(int tp,int x,int l,int r,int ll,int rr){
		if (l>rr||r<ll) return;
		if (ll<=l&&r<=rr) {
			if (fi[tp][x]<ed[tp][x]){
				node now=t[tp][x][fi[tp][x]];
				while ((tp)?now.x>rr:now.x<ll){
					if (!used[now.i])
						tmpd[++tmpd[0]]=now.i,used[now.i]=1;
					if (++fi[tp][x]==ed[tp][x]) break;
					now=t[tp][x][fi[tp][x]];
				}
			}
			return;
		}
		int mid=(l+r)>>1;
		find(tp,x<<1,l,mid,ll,rr),find(tp,x<<1^1,mid+1,r,ll,rr);
	}
} G[2];

struct com{int x,y,i;} a[maxn];
int cmp1(com a,com b){return a.x<b.x;}
int cmp2(com a,com b){return a.y>b.y;}
void prepare(int p){
	int q=p^1;
	for(i=2;i<=n;i++) {
		a[i-1].x=G[p].dfn[G[q].E[i]],a[i-1].y=G[p].dfn[i],a[i-1].i=i-1;
		if (a[i-1].x>a[i-1].y) swap(a[i-1].x,a[i-1].y);
	}
	sort(a+1,a+n,cmp1);
	for(i=1;i<n;i++) G[p].add(0,1,1,n,a[i].y,node(a[i].x,a[i].i));
	sort(a+1,a+n,cmp2);
	for(i=1;i<n;i++) G[p].add(1,1,1,n,a[i].x,node(a[i].y,a[i].i));
}

void Doit(){
	d[0]=1,read(d[1]),G[1].used[d[1]]=1;
	int p=0,q=1;
	while (d[0]){
		if (p) printf("Red\n"); else printf("Blue\n");
		sort(d+1,d+1+d[0]);
		for(int i=1;i<=d[0];i++) printf("%d ",d[i]); printf("\n");
		tmpd[0]=0;
		while (d[0]){
			int x=d[d[0]]+1;
			if (G[p].dfn[x]<G[p].dfn[G[p].E[x]])	
				x=G[p].E[x];
			G[p].find(0,1,1,n,G[p].dfn[x],G[p].dfn[x]+G[p].sz[x]-1);
			G[p].find(1,1,1,n,G[p].dfn[x],G[p].dfn[x]+G[p].sz[x]-1);
			d[0]--;
		}
		while (tmpd[0]) d[++d[0]]=tmpd[tmpd[0]--];
		p^=1,q^=1;
	}
}

int main(){
	read(n);
	G[0].init(),G[1].init();
	prepare(0),prepare(1);
	Doit();
}