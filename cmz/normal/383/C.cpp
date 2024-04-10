#include<bits/stdc++.h> 
#define N 200005
using namespace std;
inline int read() {
	int e=0,m=1;
	char z=getchar();
	while(z<48||z>57) {
		if(z=='-') m=-1;
		z=getchar();
	}
	while(z>=48&&z<=57) {
		e=e*10+z-'0',z=getchar();
	}
	return e*m;
}
struct qwe {
	int v,w,next;
} e[2*N];
int tot,cnt=0,L[N],R[N],tr[N];
int n,m,p,head[N],dep[N];
void adde(int x,int y) {
	e[++tot].v=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int u,int fa) {
	L[u]=++cnt;
	for(int i=head[u]; i!=-1; i=e[i].next) {
		int v=e[i].v;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	R[u]=cnt;
}
int lowbit(int x) {
	return x&(-x);
}
inline void add(int x,int z) {
	while(x<=n) {
		tr[x]+=z;
		x+=x&(-x);
	}
}
int query(int l) {
	int ans=0;
	while(l) ans+=tr[l],l^=lowbit(l);
	return ans;
}
int u,v,b;
int val[N];
int main() {
	n=read(),m=read();
	memset(head,-1,sizeof(head));
	for(int q1=1; q1<=n; q1++) val[q1]=read();
	for(int q1=1; q1<n; q1++) {
		u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	for(int q1=1; q1<=m; q1++) {
		u=read(),v=read();
		if(u==1) {
			b=read();
			if(dep[v]&1) add(L[v],b),add(R[v]+1,-b);
			else add(L[v],-b),add(R[v]+1,b);
		}
		else {
			int z1=query(L[v]);
			if (dep[v]&1) printf("%d\n",val[v]+z1);
			else printf("%d\n",val[v]-z1);
		}
	}
	return 0;
}