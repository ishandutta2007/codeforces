#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=200005;
int n,pnt[MAXN],dep[MAXN],a[MAXN],m,ans[MAXN][2],ccav;
bool f[MAXN];
long long s;
struct node{
	int v;
	node *next;
}pool[2*MAXN],*h[MAXN];
int cnt;
void addedge(int u,int v){
	node *o=&pool[cnt++];
	o->v=v,o->next=h[u],h[u]=o;
	o=&pool[cnt++];
	o->v=u,o->next=h[v],h[v]=o;
}
int Findfar(int u){
	int ret=u,t;
	for(node *o=h[u];o;o=o->next)if(o->v!=pnt[u]){
		pnt[o->v]=u;
		dep[o->v]=dep[u]+1;
		t=Findfar(o->v);
		if(dep[t]>dep[ret])ret=t;
	}
	return ret;
}
void dfs(int u,int num){
	if(dep[u])s+=dep[u]+max(num,m-num);
	for(node *o=h[u];o;o=o->next)if((!f[o->v])&&o->v!=pnt[u]){
		pnt[o->v]=u;
		dep[o->v]=dep[u]+1;
		dfs(o->v,num);
	}
	if(dep[u]){
		ans[++ccav][0]=u;
		if(num>m-num)ans[ccav][1]=a[0];
		else ans[ccav][1]=a[m];
	}
}
int main(){
	scanf("%d",&n);
	int u,v,w;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),addedge(u,v);
	dep[1]=pnt[1]=0;
	u=Findfar(1);
	dep[u]=pnt[u]=0;
	v=Findfar(u);
	m=dep[v];
	w=v;
	while(w)f[w]=1,a[dep[w]]=w,w=pnt[w];
	for(int i=0;i<=m;i++)pnt[a[i]]=0,dep[a[i]]=0,dfs(a[i],i);
	for(int i=m;i;i--)ans[++ccav][0]=a[i],ans[ccav][1]=a[0],s+=i;
	printf("%I64d\n",s);
	for(int i=1;i<=ccav;i++)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][0]);
	return 0;
}