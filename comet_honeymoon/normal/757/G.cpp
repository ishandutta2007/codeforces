#include<bits/stdc++.h>
#define ll long long
#define vei vector<Edge>::iterator
using namespace std;

const int _maxN=200005,maxN=400005;
int N,N0,Q;
int P[_maxN];

struct Edge{
	int u,v,c,used=0,rev;
	Edge(){}
	Edge(int u0,int v0,int c0){u=u0;v=v0;c=c0;}
};vector<Edge> G[maxN];
void add_E(int u,int v,int c){
	G[u].push_back(Edge(u,v,c));vei e0=G[u].end();e0--;
	G[v].push_back(Edge(v,u,c));vei e1=G[v].end();e1--;
	e0->rev=G[v].size()-1;e1->rev=G[u].size()-1;
}
namespace ToBinary{
	vector<Edge> _G[_maxN];
	int msk[_maxN],idx;
	void ADD_E(int u,int v,int c){idx++;add_E(idx,msk[u],0);add_E(idx,v,c);msk[u]=idx;}
	void dfs(int u,int f){for(auto e:_G[u])if(e.v!=f) ADD_E(u,e.v,e.c),dfs(e.v,u);}
	void Solve(){
		for(int i=1;i<=N;i++) msk[i]=i;idx=N;
		for(int i=1;i<N;i++){
			int u,v,c;scanf("%d%d%d",&u,&v,&c);
			_G[u].push_back(Edge(u,v,c));
			_G[v].push_back(Edge(v,u,c));
		}
		dfs(1,0);
		N0=idx;
	}
}

int s[maxN];
vei rt;int rtf;
void Get_siz(int x,int f){s[x]=1;for(auto e:G[x]) if(e.v!=f&&!e.used) Get_siz(e.v,x),s[x]+=s[e.v];}
void Get_rt(int x,int f,int S){
	for(vei e=G[x].begin();e!=G[x].end();e++)if(e->v!=f&&!e->used){
		if(max(s[e->v],S-s[e->v])<rtf) rtf=max(s[e->v],S-s[e->v]),rt=e;
		Get_rt(e->v,x,S);
	}
}
vei E[maxN];
int Es[maxN][2],tot; // 
vector<int> anc[maxN];vector<ll> dep[maxN];
void Get_dis(int x,int f,ll dis){
	anc[x].push_back(tot),dep[x].push_back(dis);
	if(anc[x].size()>=30){printf("ERROR");exit(0);}
	for(auto e:G[x]) if(e.v!=f&&!e.used) Get_dis(e.v,x,dis+e.c);
}

int BFZ(vei rte){
	int U=rte->u,V=rte->v,id=++tot;E[id]=rte;
	rte->used=1;G[V][rte->rev].used=1;
	Get_dis(U,V,0);
	Get_dis(V,U,0);
	int tot0=tot;
	rtf=0x3f3f3f3f;Get_siz(U,V);Get_rt(U,V,s[U]);if(rtf!=0x3f3f3f3f) Es[tot0][0]=BFZ(rt);else Es[tot0][0]=-1;
	rtf=0x3f3f3f3f;Get_siz(V,U);Get_rt(V,U,s[V]);if(rtf!=0x3f3f3f3f) Es[tot0][1]=BFZ(rt);else Es[tot0][1]=-1;
	return tot0;
}
bool LR(int x,int rtdep){
	if(anc[x].size()-1==rtdep) return E[anc[x][rtdep]]->v==x;
	return Es[anc[x][rtdep]][1]==anc[x][rtdep+1];
}

struct BFZT{
	int s[2];
	int cnt[2];ll dis[2];
}T[maxN*40];int idx;
int RT[maxN];
int NewNode(int x0){T[++idx]=T[x0];return idx;}
int Build(int id){
	if(id==-1) return -1;
	int x=NewNode(0);
	T[x].s[0]=Build(Es[id][0]);
	T[x].s[1]=Build(Es[id][1]);
	return x;
}
int Update(int x0,int u,int d){
	if(d>=anc[u].size()) return -1;
	int x=NewNode(x0);
	bool k=LR(u,d);
	T[x].cnt[k]++,T[x].dis[k]+=dep[u][d],T[x].s[k]=Update(T[x0].s[k],u,d+1);
	return x;
}
ll Query(int x,int u,int d){
	if(d>=anc[u].size()) return 0;
	bool k=LR(u,d);
	return (dep[u][d]+E[anc[u][d]]->c)*T[x].cnt[k^1]+T[x].dis[k^1]+Query(T[x].s[k],u,d+1);
}
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++) scanf("%d",&P[i]);
	ToBinary::Solve();
	Get_siz(1,0);rtf=0x3f3f3f3f;Get_rt(1,0,N0);
	BFZ(rt);
	T[0].s[0]=T[0].s[1]=-1;RT[0]=Build(1);
	for(int i=1;i<=N;i++) RT[i]=Update(RT[i-1],P[i],0);
	ll lstans=0;
	while(Q--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			l^=lstans,r^=lstans,x^=lstans;
			lstans=Query(RT[r],x,0)-Query(RT[l-1],x,0);
			printf("%lld\n",lstans);
			lstans&=(1<<30)-1;
		}
		else{
			int x;scanf("%d",&x);x^=lstans;
			swap(P[x],P[x+1]);
			RT[x]=Update(RT[x-1],P[x],0);
		}
	}
}