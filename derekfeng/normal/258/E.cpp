#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans[100004],Ld[100004],Rd[100004];
vector<int>g[100004],qry[100004];
int L[9000000],R[9000000],lft[9000000],root[100004];
bool flg[9000000];
void dfs(int x,int par){Ld[x]=++cnt;for(int i=0;i<g[x].size();i++)if(g[x][i]!=par)dfs(g[x][i],x);Rd[x]=cnt;}
int built(int l,int r){int id=++cnt;lft[id]=r-l+1;if(l!=r)L[id]=built(l,(l+r)/2),R[id]=built((l+r)/2+1,r);return id;}
int upd(int l,int r,int id,int a,int b){
	if(flg[id]||r<a||b<l)return id;int id1=++cnt;
	if(a<=l&&r<=b){flg[id1]=1,lft[id1]=0;return id1;}
	L[id1]=upd(l,(l+r)/2,L[id],a,b),R[id1]=upd((l+r)/2+1,r,R[id],a,b),lft[id1]=lft[L[id1]]+lft[R[id1]];
	return id1;
}
int ok(int l,int r,int id,int pos){
	if(flg[id])return 1;
	if(l==r)return 0;
	if((l+r)/2>=pos)return ok(l,(l+r)/2,L[id],pos);
	return ok((l+r)/2+1,r,R[id],pos);
}
void dfs1(int x,int par){
	root[x]=root[par];
	if(!qry[x].empty())root[x]=upd(1,n,root[x],Ld[x],Rd[x]);
	for(int i=0;i<qry[x].size();i++){int a=qry[x][i];root[x]=upd(1,n,root[x],Ld[a],Rd[a]);}
	ans[x]=n-lft[root[x]]-ok(1,n,root[x],Ld[x]);
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par)dfs1(g[x][i],x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);g[u].push_back(v),g[v].push_back(u);}
	for(int i=0;i<m;i++){int a,b;scanf("%d%d",&a,&b);qry[a].push_back(b),qry[b].push_back(a);}
	dfs(1,-1),cnt=0,root[0]=built(1,n),dfs1(1,0);for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}