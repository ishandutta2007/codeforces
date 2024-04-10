#include<bits/stdc++.h>
using namespace std;
vector<int>g[100004];
int a[100004],n,root,m,rt[100004];
int cnt,dat[2500000],s[2][2500000];
int Dep,dep[100004],tms,L[100004],R[100004];
vector<int>dp[100004];
void dfs(int x,int par){
	dp[dep[x]].push_back(x),Dep=max(Dep,dep[x]);
	L[x]=++tms;
	for(auto y:g[x])if(y!=par)dep[y]=dep[x]+1,dfs(y,x);
	R[x]=tms;
}
int ins(int l,int r,int id,int p,int x){
	int id1=++cnt;
	s[0][id1]=s[0][id],s[1][id1]=s[1][id],dat[id1]=min(dat[id],x);
	if(l<r){
		int mid=(l+r)>>1;
		if(p<=mid)s[0][id1]=ins(l,mid,s[0][id1],p,x);
		else s[1][id1]=ins(mid+1,r,s[1][id1],p,x);
	}
	return id1;
}
int qry(int l,int r,int id,int a,int b){
	if(r<a||b<l||!id)return 1e9;
	if(a<=l&&r<=b)return dat[id];
	int mid=(l+r)>>1;
	return min(qry(l,mid,s[0][id],a,b),qry(mid+1,r,s[1][id],a,b));
}
int main(){
	dat[0]=1e9;
	scanf("%d%d",&n,&root);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(root,0);
	for(int i=0;i<=Dep;i++){
		if(i)rt[i]=rt[i-1];
		for(auto x:dp[i])rt[i]=ins(1,n,rt[i],L[x],a[x]);
	}
	scanf("%d",&m);
	int lst=0;
	while(m--){
		int x,k;scanf("%d%d",&x,&k);
		x=(x+lst)%n+1,k=(k+lst)%n;
		int ver=min(Dep,dep[x]+k);
		printf("%d\n",(lst=qry(1,n,rt[ver],L[x],R[x])));
	}
}