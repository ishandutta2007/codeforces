#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 400005
using namespace std;

int m,i,j,k,tot,cnt;
struct node{int x,y;node(int _x=0,int _y=0){x=_x,y=_y;}} a[maxn][2],p[maxn];
int operator<(node a,node b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
int operator==(node a,node b){return a.x==b.x&&a.y==b.y;}
map<node,int> num; node pnum[maxn];
map<int,int> sum;
map<int,int> ::iterator it;
int nm(node a){
	if (num.find(a)==num.end()) 
		num[a]=++tot,pnum[tot]=a;
	return num[a];
}

int _2[31];
int getb(node a,int x,int y,int k){
	if (a.x<x+_2[k]&&a.y<y+_2[k]) return 0;
	if (a.x>=x+_2[k]) return 1;
	return 2;
}
int cmp(node a,node b){
	int x=0,y=0;
	for(int k=30;k>=0;k--) {
		int t1=getb(a,x,y,k),t2=getb(b,x,y,k);
		if (t1==t2){
			if (t1==1) x+=_2[k];
			if (t1==2) y+=_2[k];
		} else {
			if (t1==0){
				if (t2==1) return 1;
				if (t2==2) return a.x==x;
			} 
			if (t2==0){
				if (t1==1) return 0;
				if (t1==2) return b.x!=x;
			}
			return t1>t2;
		}
	}
	return 0;
}

node lca(node a,node b){
	int x=0,y=0;
	for(int k=30;k>=0;k--){
		int t1=getb(a,x,y,k),t2=getb(b,x,y,k);
		if (t1==t2) {
			if (t1==1) x+=_2[k];
			if (t1==2) y+=_2[k];
		} else {
			if (t1+t2==3) return node(x,y);
			if (t2==0) swap(t1,t2),swap(a,b);
			if (t2==1) b=node(x+_2[k]-1,y);
			if (t2==2) b=node(x,y+_2[k]-1);
		}
	}
	return a;
}

int em,e[maxn],nx[maxn],ls[maxn],w,fa[maxn],c0[maxn],c1[maxn];
node d[maxn]; 
void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	fa[y]=x;
}

void maketree(){
	d[w=1]=node(0,0);
	for(i=1;i<=cnt;i++){
		node x=p[i];
		if (x==d[w]) continue;
		node y=lca(d[w],x);
		if (y==d[w]) d[++w]=x; else {
			while (cmp(y,d[w-1]))
				insert(nm(d[w-1]),nm(d[w])),w--;
			if (y==d[w-1]){
				insert(nm(d[w-1]),nm(d[w]));
				d[w]=x;
			} else {
				insert(nm(y),nm(d[w]));
				d[w]=y,d[++w]=x;
			}
		}
	}
	while (w>1) insert(nm(d[w-1]),nm(d[w])),w--;
}

void cover(int l,int r){
	sum[l]^=1,sum[r+1]^=1;
}

void dfs(int x){
	for(int i=ls[x];i;i=nx[i]) 
		dfs(e[i]),c0[x]+=c0[e[i]];
	if (c0[x]) 
		cover(pnum[x].x+pnum[x].y,pnum[x].x+pnum[x].y);
	c0[x]+=c1[x];
	if (c0[x]&&fa[x]) 
		cover(pnum[fa[x]].x+pnum[fa[x]].y+1,pnum[x].x+pnum[x].y-1);
}

int main(){
	for(i=0;i<=30;i++) _2[i]=1<<i;
	scanf("%d",&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d%d",&a[i][0].x,&a[i][0].y,&a[i][1].x,&a[i][1].y);
		p[++cnt]=a[i][0],p[++cnt]=a[i][1];
	}
	sort(p+1,p+1+cnt,cmp);
	maketree();
	for(i=1;i<=m;i++) {
		c0[nm(a[i][0])]++,c0[nm(a[i][1])]++;
		c1[nm(lca(a[i][0],a[i][1]))]-=2;
	}
	dfs(nm(node(0,0)));
	int ans=0;
	for(it=sum.begin();it!=sum.end();it++) 
		ans+=(*it).second;
	ans=ans-sum[0];
	printf("%d\n",ans);
}