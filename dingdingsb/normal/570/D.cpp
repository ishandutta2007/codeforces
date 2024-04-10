#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define mid (l+r>>1)
const int N=5e5+10,M=N<<2;
int n,m;bool ans[N];
vector<int>e[N];char str[N];
vector<pair<int,int>>q[N];
//C*F****
int lc[M],rc[M],val[M];
int st[M],tp,tot;
int newnode(){
	int x;if(tp)x=st[tp--];else x=++tot;
	lc[x]=rc[x]=val[x]=0;return x;
}
void upd(int&x,int l,int r,int pos,int kk){
	if(!x)x=newnode();
	if(l==r){
		val[x]^=1<<kk;
		return;
	}
	if(pos<=mid)upd(lc[x],l,mid,pos,kk);
	else upd(rc[x],mid+1,r,pos,kk);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x^y;
	st[++tp]=y;
	if(l==r){
		val[x]^=val[y];
		return x;
	}
	lc[x]=merge(lc[x],lc[y],l,mid);
	rc[x]=merge(rc[x],rc[y],mid+1,r);
	return x;
}
int qry(int x,int l,int r,int pos){
	if(!x)return 0;
	if(l==r)return val[x];
	if(pos<=mid)return qry(lc[x],l,mid,pos);
	else return qry(rc[x],mid+1,r,pos);
}
//asdashbsdfj
int mdep[N],dep[N],sz[N],fa[N],rt[N];
void dfs1(int u){
	mdep[u]=dep[u]=dep[fa[u]]+1;;
	sz[u]=1;
	for(auto v:e[u])dfs1(v),sz[u]+=sz[v],mdep[u]=max(mdep[u],mdep[v]);
}
void dfs2(int u){
	sort(e[u].begin(),e[u].end(),[&](const int&x,const int&y)->bool{return sz[x]>sz[y];});
	for(auto v:e[u])
		dfs2(v),rt[u]=merge(rt[u],rt[v],1,mdep[1]);
	upd(rt[u],1,mdep[1],dep[u],str[u]-'a');
	for(auto&[b,id]:q[u])
		if(b<=mdep[1])
			ans[id]=__builtin_popcount(qry(rt[u],1,mdep[1],b))<=1;
		else ans[id]=1;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
		scanf("%d",&fa[i]),e[fa[i]].pb(i);
	scanf("%s",str+1);
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		q[a].pb(mp(b,i));
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=m;i++)
		puts(ans[i]?"Yes":"No");
    return 0;
}