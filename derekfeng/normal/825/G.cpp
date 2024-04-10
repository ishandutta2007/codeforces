#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n,L[1000004],R[1000004],rt,a[1000004],b[1000004],cnt,q;
vector<int>g[1000004];
int lstans;
void dfs(int x,int p){
	L[x]=++cnt;
	for(auto y:g[x])if(y!=p)a[y]=min(a[x],y),dfs(y,x);
	R[x]=cnt;
}
int dat[2097200];
void built(int l,int r,int id){
	if(l==r){
		dat[id]=b[l];
		return;
	}
	dat[id]=n+1;
	int mid=(l+r)>>1;
	built(l,mid,id<<1),built(mid+1,r,id<<1|1);
}
void upd(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[id]=min(dat[id],x);
		return;
	}
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b,x),upd(mid+1,r,id<<1|1,a,b,x);
}
int qry(int l,int r,int id,int p,int x){
	x=min(x,dat[id]);
	if(l==r)return x;
	int mid=(l+r)>>1;
	if(p<=mid)return qry(l,mid,id<<1,p,x);
	return qry(mid+1,r,id<<1|1,p,x);
}
int main(){
	scanf("%d%d",&n,&q);q--;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);  
	}
	scanf("%d%d",&rt,&rt),rt=rt%n+1,a[rt]=rt,dfs(rt,0);
	for(int i=1;i<=n;i++)b[L[i]]=a[i];
	built(1,n,1);
	while(q--){
		int op,x;
		scanf("%d%d",&op,&x);x=(x+lstans)%n+1;
		if(op==1)upd(1,n,1,1,L[x]-1,a[x]),upd(1,n,1,R[x]+1,n,a[x]);
		else printf("%d\n",(lstans=qry(1,n,1,L[x],n+1)));
	}
}