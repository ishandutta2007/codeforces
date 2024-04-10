#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define ffs fflush(stdout)
int n;bool act[200004];
vector<pii>tr[200004];
int fav[200004],fae[200004];
int sz[200004],sn[200004];
void dfs(int x,int fa){
	sz[x]=1;
	for(auto y:tr[x])if(y.fi!=fa){
		fav[y.fi]=x,fae[y.fi]=y.se;
		dfs(y.fi,x),sz[x]+=sz[y.fi];
		if(sz[y.fi]>sz[sn[x]])sn[x]=y.fi;
	}
}
int nxt[200004],dfn[200004],a[200004],tot;
void dfs1(int x,int H){
	nxt[x]=H,dfn[x]=++tot,a[tot]=fae[x];
	if(sn[x])dfs1(sn[x],H);
	for(auto y:tr[x])if(y.fi!=fav[x]&&y.fi!=sn[x])
		dfs1(y.fi,y.fi);
}
ll sum[524300][2];
int cnt[524300][2];
bool lz[524300];
void push(int i){
	swap(sum[i][0],sum[i][1]);
	swap(cnt[i][0],cnt[i][1]);
	lz[i]^=1;
}
void pushdown(int i){
	if(lz[i]){
		push(i<<1),push(i<<1|1);
		lz[i]=0;
	}
}
void pushup(int i){
	int ls=i<<1,rs=i<<1|1;
	sum[i][0]=sum[ls][0]+sum[rs][0];
	sum[i][1]=sum[ls][1]+sum[rs][1];
	cnt[i][0]=cnt[ls][0]+cnt[rs][0];
	cnt[i][1]=cnt[ls][1]+cnt[rs][1];
}
void rev(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return push(i);
	pushdown(i);
	int md=(l+r)>>1;
	rev(i<<1,l,md,a,b),rev(i<<1|1,md+1,r,a,b);
	pushup(i);
}
void upd(int i,int l,int r,int p){
	if(l==r){
		cnt[i][0]=1;
		sum[i][0]=a[p];
		return;
	}else{
		pushdown(i);
		int md=(l+r)>>1;
		if(p<=md)upd(i<<1,l,md,p);
		else upd(i<<1|1,md+1,r,p);
		pushup(i);
	}
}
void ACT(int x){
	act[x]=1;
	upd(1,1,n,dfn[x]);
	int xx=x;
	while(x){
		rev(1,1,n,dfn[nxt[x]],dfn[x]);
		x=fav[nxt[x]];
	}
	if(xx>1){
		if(cnt[1][0]!=cnt[1][1])puts("0");
		else printf("%lld\n",sum[1][1]);
	}
	ffs;
}
vector<int>tmp;
void dfs2(int x){
	sz[x]=1;
	for(auto y:tr[x])if(y.fi!=fav[x]&&act[y.fi])
		dfs2(y.fi),sz[x]+=sz[y.fi];
	if(sz[x]&1)tmp.push_back(fae[x]);
}
void ASK(){
	if(cnt[1][0]!=cnt[1][1])puts("0");
	else{
		tmp.clear();
		dfs2(1);
		sort(tmp.begin(),tmp.end());
		printf("%d ",tmp.size());
		for(auto x:tmp)printf("%d ",x);puts("");
	}
	ffs;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back({v,i}),tr[v].push_back({u,i});
	}
	dfs(1,0),dfs1(1,1),ACT(1);
	int op,v;
	while(scanf("%d",&op)){
		if(op==1)scanf("%d",&v),ACT(v);
		if(op==2)ASK();
		if(op==3)return 0;
	}
}