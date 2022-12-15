#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN=500005;

int N,Q;
int lnk[maxN];
int pre[maxN<<1],tgt[maxN<<1],cnt;int val[maxN<<1];
int pos[maxN];
void add_E(int u,int v,int c){
	pre[++cnt]=lnk[u],tgt[cnt]=v,val[cnt]=c,lnk[u]=cnt;
} 

int dep[maxN],wdep[maxN];
int Tin[maxN],Tout[maxN];
int dfn[maxN<<1],idx;
void dfs(int x,int f){
	dfn[++idx]=x;Tin[x]=idx;
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=f)
		pos[(e+1)>>1]=tgt[e],dep[tgt[e]]=dep[x]+1,wdep[tgt[e]]=wdep[x]+val[e],dfs(tgt[e],x),dfn[++idx]=x;
	Tout[x]=idx;
}

int W[maxN<<3][2],M[maxN<<3],LM[maxN<<3][2],MR[maxN<<3][2],LMR[maxN<<3][2],Lzy[maxN<<3];
void push_up(int x){
	M[x]=max(M[x<<1],M[x<<1|1]);
	for(int k=0;k<2;k++){	
		W[x][k]=max(W[x<<1][k],W[x<<1|1][k]);
		LM[x][k]=max(LM[x<<1][k],LM[x<<1|1][k]);
		MR[x][k]=max(MR[x<<1][k],MR[x<<1|1][k]);
		LMR[x][k]=max(LMR[x<<1][k],LMR[x<<1|1][k]);
		LM[x][k]=max(LM[x][k],W[x<<1][k]+M[x<<1|1]);
		MR[x][k]=max(MR[x][k],M[x<<1]+W[x<<1|1][k]);
	}
	for(int k1=0;k1<2;k1++)
	for(int k2=0;k2<2;k2++)
		LMR[x][k1^k2]=max(LMR[x][k1^k2],max(LM[x<<1][k1]+W[x<<1|1][k2],W[x<<1][k1]+MR[x<<1|1][k2]));
}
void Rev(int x){
	swap(W[x][0],W[x][1]);
	swap(LM[x][0],LM[x][1]);
	swap(MR[x][0],MR[x][1]);
	Lzy[x]^=1;
}
void push_down(int x){if(!Lzy[x]) return;Rev(x<<1);Rev(x<<1|1);Lzy[x]=0;}
void Build(int x,int l,int r){
	if(l==r){
		int k=wdep[dfn[l]]&1;
		W[x][k]=dep[dfn[l]];M[x]=-2*dep[dfn[l]];
		LM[x][k]=MR[x][k]=-dep[dfn[l]];
		W[x][k^1]=-0x3f3f3f3f;
		LM[x][k^1]=MR[x][k^1]=-0x3f3f3f3f;
		return;
	}
	int mid=(l+r)>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	push_up(x);
}
void Update(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R){Rev(x);return;}
	int mid=(l+r)>>1;
	push_down(x);
	if(L<=mid) Update(x<<1,l,mid,L,R);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R);
	push_up(x);
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int u,v,c;scanf("%d%d%d",&u,&v,&c);
		add_E(u,v,c);add_E(v,u,c);
	}
	dfs(1,0);
	Build(1,1,idx);
	scanf("%d",&Q);
	while(Q--){
		int d;scanf("%d",&d);
		Update(1,1,idx,Tin[pos[d]],Tout[pos[d]]);
		printf("%d\n",LMR[1][0]);
	}
}