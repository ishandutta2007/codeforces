#include<bits/stdc++.h>
using namespace std;
int n,dfn[300004],sz[300004],N;
vector<int>t1[300004],t2[300004];
int bit[300004],cur,ans;
void add(int i,int x){
	for(;i<=n;i+=i&-i)bit[i]+=x;
}
int qry(int i){
	int res=0;
	for(;i;i-=i&-i)res+=bit[i];
	return res;
}
int ask(int l,int r){
	return qry(r)-qry(l-1);
}
int tr[1200004];
void add1(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){tr[i]=x;return;}
	if(tr[i]!=-1)tr[i<<1]=tr[i<<1|1]=tr[i],tr[i]=-1;
	int md=(l+r)>>1;
	add1(l,md,i<<1,a,b,x),add1(md+1,r,i<<1|1,a,b,x);
}
int qry1(int l,int r,int i,int p){
	if(l==r)return tr[i];
	if(tr[i]!=-1)tr[i<<1]=tr[i<<1|1]=tr[i],tr[i]=-1;
	int md=(l+r)>>1;
	if(p<=md)return qry1(l,md,i<<1,p);
	return qry1(md+1,r,i<<1|1,p);
}
void dfs1(int u){
	int del=0,ins=0,v;
	v=qry1(1,n,1,dfn[u]);
	if(v!=0)add1(1,n,1,dfn[v],dfn[v]+sz[v]-1,0),add(dfn[v],-1),cur--,del=v;
	v=ask(dfn[u],dfn[u]+sz[u]-1);
	if(v==0)ins=u,add1(1,n,1,dfn[u],dfn[u]+sz[u]-1,u),add(dfn[u],1),cur++;
	ans=max(ans,cur);
	for(auto y:t1[u])dfs1(y);
	if(ins)add1(1,n,1,dfn[u],dfn[u]+sz[u]-1,0),add(dfn[u],-1),cur--;
	if(del)add1(1,n,1,dfn[del],dfn[del]+sz[del]-1,del),add(dfn[del],1),cur++;
}
void dfs2(int u){
	dfn[u]=++N,sz[u]=1;
	for(auto y:t2[u])dfs2(y),sz[u]+=sz[y];
}
void sol(){
	scanf("%d",&n),N=0,cur=0,ans=0;
	for(int i=1;i<=n;i++)t1[i].clear(),t2[i].clear();
	for(int i=2,x;i<=n;i++)scanf("%d",&x),t1[x].push_back(i);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),t2[x].push_back(i);
	dfs2(1);
	dfs1(1);
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}