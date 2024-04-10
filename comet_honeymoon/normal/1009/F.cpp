#include<bits/stdc++.h>
using namespace std;

const int maxN=1000005;

int N;
int lnk[maxN];
int pre[maxN<<1],tgt[maxN<<1],cnt;
void add_E(int u,int v){
	pre[++cnt]=lnk[u],tgt[cnt]=v,lnk[u]=cnt;
}
int maxv[maxN*28],maxp[maxN*28],lc[maxN*28],rc[maxN*28],idx;
void pushup(int x){
	if(!lc[x]||!rc[x]) maxv[x]=maxv[lc[x]+rc[x]],maxp[x]=maxp[lc[x]+rc[x]];
	else{
		if(maxv[lc[x]]>=maxv[rc[x]]) maxv[x]=maxv[lc[x]],maxp[x]=maxp[lc[x]];
		else maxv[x]=maxv[rc[x]],maxp[x]=maxp[rc[x]];
	}
}
void Update(int &x,int l,int r,int pos){
	if(!x) x=++idx;
	if(l==r){maxp[x]=l,maxv[x]++;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) Update(lc[x],l,mid,pos);
	else Update(rc[x],mid+1,r,pos);
	pushup(x);
}
void Merge(int &x,int y,int l,int r){
	if(!x||!y){x=x+y;return;}
	if(l==r){maxp[x]=l,maxv[x]+=maxv[y];return;}
	int mid=(l+r)>>1;
	Merge(lc[x],lc[y],l,mid);
	Merge(rc[x],rc[y],mid+1,r);
	pushup(x);
}

int dep[maxN],rt[maxN];
int ans[maxN];
void Solve(int x,int f){
	dep[x]=dep[f]+1;
	Update(rt[x],1,N,dep[x]);
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=f)
		Solve(tgt[e],x),Merge(rt[x],rt[tgt[e]],1,N);
	ans[x]=maxp[rt[x]]-dep[x];
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int u,v;scanf("%d%d",&u,&v);
		add_E(u,v);add_E(v,u);
	}
	Solve(1,0);
	for(int i=1;i<=N;i++) printf("%d\n",ans[i]);
}