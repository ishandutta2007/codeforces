#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n,qu;
int a[N+1];
vector<int> nei[N+1];
int dfn[N+1],mng[N+1],mxdfn[N+1],nowdfn,dep[N+1];
void dfs(int x=1,int fa=0){
	dfn[x]=mxdfn[x]=++nowdfn;mng[nowdfn]=x;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		mxdfn[x]=max(mxdfn[x],mxdfn[y]);
	}
}
struct segtree{
	struct node{int l,r,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r){lz(p)=dep[mng[l]]&1?a[mng[l]]:-a[mng[l]];return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p))lz(p<<1)+=lz(p),lz(p<<1|1)+=lz(p),lz(p)=0;
	}
	void chg(int l,int r,int v,int p=1){
		if(l<=l(p)&&r>=r(p)){lz(p)+=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)chg(l,r,v,p<<1);
		if(r>mid)chg(l,r,v,p<<1|1);
	}
	int ask(int x,int p=1){
		if(l(p)==r(p))return dep[mng[x]]&1?lz(p):-lz(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		return ask(x,p<<1|(x>mid));
	}
}segt;
void chg(int x,int v){segt.chg(dfn[x],mxdfn[x],dep[x]&1?v:-v);}
int ask(int x){return segt.ask(dfn[x]);}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
//	for(int i=1;i<=n;i++)cout<<dfn[i]<<" ";puts("");
	segt.init();
//	for(int i=1;i<=n;i++)cout<<ask(i)<<" ";puts("");
	while(qu--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if(tp==1)scanf("%d",&y),chg(x,y);
		else printf("%d\n",ask(x));
//		for(int i=1;i<=n;i++)cout<<ask(i)<<" ";puts("");
	}
	return 0;
}
/*1
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
*/