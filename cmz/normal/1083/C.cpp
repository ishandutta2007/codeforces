#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
const int N=2e5+5;
int n,m,top,t,a[N],xu[N],head[N],ru[N],chu[N],dis[N],f[N][25];
struct node {
	int x,y;
} tree[N*4];
int kkkkk;
struct node2 {
	int too,next;
} edge[N];
#define gc getchar
inline int read() {
	int ret=0,f=0;
	char c=gc();
	while(!isdigit(c)) {
		if(c=='-')f=1;
		c=gc();
	}
	while(isdigit(c)) {
		ret=ret*10+c-48;
		c=gc();
	}
	if(f)return -ret;
	return ret;
}
void add(int a,int b) {
	edge[++top].too=b;
	edge[top].next=head[a];
	head[a]=top;
}
void dfs(int u,int fa) {
	ru[u]=++t;
	for(int i=head[u]; i; i=edge[i].next) {
		int v=edge[i].too;
		f[v][0]=u;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
	chu[u]=++t;
}
bool pd(int x,int y) {
	if(ru[x]<=ru[y]&&chu[x]>=chu[y])return true;
	return false;
}
int LCA(int x,int y) {
	if(pd(x,y))return x;
	if(pd(y,x))return y;
	int k=x;
	for(int i=20; i>=0; i--)
		if(!pd(f[k][i],y))k=f[k][i];
	return f[k][0];
}
int dist(int a,int b) {
	int lca=LCA(a,b);
	return dis[a]+dis[b]-2*dis[lca];
}
node hb(node a,int b) {
	if(a.x<0||b<0)return (node) {
		-1,-1
	};
	int aa=a.x,bb=a.y;
	int d1=dist(aa,b);
	int d2=dist(bb,b);
	int d3=dist(aa,bb);
	if(d1+d2==d3)return (node) {
		aa,bb
	};
	if(d1+d3==d2)return (node) {
		b,bb
	};
	if(d2+d3==d1)return (node) {
		aa,b
	};
	return (node) {
		-1,-1
	};
}
node merge(node a,node b) {
	if(a.x<0||b.x<0)return (node) {
		-1,-1
	};
	node jia=hb(a,b.x);
	if(jia.x<0)return (node) {
		-1,-1
	};
	else return hb(jia,b.y);
}
void pushup(int nod) {
	tree[nod]=merge(tree[nod*2],tree[nod*2+1]);
}
void build(int nod,int l,int r) {
	if(l==r) {
		tree[nod]=(node) {
			xu[l],xu[l]
		};
		return;
	}
	build(nod*2,l,mid);
	build(nod*2+1,mid+1,r);
	pushup(nod);
}
void change(int nod,int l,int r,int x) {
	if(l==r) {
		tree[nod]=(node) {
			xu[l],xu[l]
		};
		return;
	}
	if(x<=mid)change(nod*2,l,mid,x);
	else change(nod*2+1,mid+1,r,x);
	pushup(nod);
}
int query(node &xjh,int nod,int l,int r) {
	if(tree[nod].x>=0) {
		if(xjh.x<0) {
			xjh=tree[nod];
			return r+1;
		}
		node jia=merge(xjh,tree[nod]);
		if(jia.x>=0) {
			xjh=jia;
			return r+1;
		}
	}
	if(l==r)return l;
	int res=query(xjh,nod*2,l,mid);
	if(res<=mid)return res;
	else return query(xjh,nod*2+1,mid+1,r);
}
int main() {
	n=read();
	for(int i=1; i<=n; i++) {
		a[i]=read()+1;
		xu[a[i]]=i;
	}
	for(int i=2; i<=n; i++)add(read(),i);
	f[1][0]=1;
	dfs(1,0);
	for(int i=1; i<=20; i++)
		for(int j=1; j<=n; j++)
			f[j][i]=f[f[j][i-1]][i-1];
	build(1,1,n);
	m=read();
	while(m--) {
		int opt=read();
		if(opt==1) {
			int l=read(),r=read();
			swap(xu[a[l]],xu[a[r]]);
			swap(a[l],a[r]);
			change(1,1,n,a[l]);
			change(1,1,n,a[r]);
		} else {
			node xjh=(node) {
				-1,-1
			};
			int ans=query(xjh,1,1,n);
			printf("%d\n",ans-1);
		}
	}
	return 0;
}