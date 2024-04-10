#include<bits/stdc++.h>
using namespace std;

int N,M;

int fa[200005],siz[200005];
int find(int x){return (fa[x]==x)?x:find(fa[x]);}
int stk_x[200005],stk_sizx[200005],len;
void Merge(int x,int y){
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;siz[y]+=siz[x]==siz[y];
	len++;stk_x[len]=x,stk_sizx[len]=siz[x]==siz[y];
}

int u[200005],v[200005],TL[200005],TR[200005],glen;
struct Edge{
	int u,v;
	bool operator <(const Edge b)const{return u<b.u||(u==b.u&&v<b.v);}
};map<Edge,int> S;
vector<int> tag[400005];

void Update(int x,int l,int r,int L,int R,int K){
	if(L<=l&&r<=R){tag[x].push_back(K);return;}
	int mid=(l+r)>>1;
	if(L<=mid) Update(x<<1,l,mid,L,R,K);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R,K);
}
void Solve(int x,int l,int r){
	bool flg=0;int tlen=len;
	for(int j=0,d=tag[x].size();j<d;j++){
		int e=tag[x][j];
		if(find(u[e])==find(v[e])) flg|=1;
		Merge(find(u[e]+N),find(v[e]));Merge(find(u[e]),find(v[e]+N));
	}
	int mid=(l+r)>>1;
	if(flg) for(int i=l;i<=r;i++) printf("NO\n");
	else if(l==r) printf("YES\n");
	else Solve(x<<1,l,mid),Solve(x<<1|1,mid+1,r);
	while(len!=tlen){
		siz[fa[stk_x[len]]]-=stk_sizx[len];
		fa[stk_x[len]]=stk_x[len];
		len--;
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=2*N;i++) fa[i]=i;
	for(int i=1;i<=M;i++){
		int tu,tv;scanf("%d%d",&tu,&tv);if(tu>tv) swap(tu,tv);
		if(S[(Edge){tu,tv}]) TR[S[(Edge){tu,tv}]]=i-1,S[(Edge){tu,tv}]=0;
		else S[(Edge){tu,tv}]=++glen,u[glen]=tu,v[glen]=tv,TL[glen]=i,TR[glen]=M;
	}
	for(int i=1;i<=glen;i++) Update(1,1,M,TL[i],TR[i],i);
	Solve(1,1,M);
}