#include<bits/stdc++.h>
const int N=200003,Q=200003,K=19,L=30;
struct edge{
	int u,v;
	bool operator<(const edge&b)const{return u==b.u?v<b.v:u<b.u;} 
};
int n,m,q,tp;
edge qry[Q];
std::vector<edge>add[1<<K];
std::map<edge,int>la,g;
struct linear_bases{
	int s[L];
	inline void Insert(int x){
		for(int j=L-1;~j;j--)if(x>>j&1)
			if(s[j])x^=s[j];
			else{s[j]=x;return;}
	}
	inline int Query(int x){
		for(int j=L-1;~j;j--)if(s[j]&&(x>>j&1))x^=s[j];
		return x;
	}
}st[K+3];
struct disjoint_set{
	int p[N],siz[N],b[N],st[N+Q],tp;
	int Find(int k){return p[k]==k?k:Find(p[k]);}
	int Calc(int k){return p[k]==k?0:Calc(p[k])^b[k];}
	void Init(){
		tp=0;
		for(int u=1;u<=n;u++)p[u]=u,siz[u]=1,b[u]=0;
	}
	inline bool Link(edge e){
		int u=Find(e.u),v=Find(e.v);
		st[++tp]=0;
		if(u==v)return 0;
		if(siz[u]>siz[v])std::swap(u,v);
		b[u]=Calc(e.u)^Calc(e.v)^g[e],p[u]=v,siz[v]+=siz[u];
		st[tp]=u;
		return 1;
	}
	inline void Undo(){
		int u=st[tp--],v=p[u];
		if(!u)return;
		siz[v]-=siz[u],p[u]=u,b[u]=0;
	}
	inline int Query(edge e){return Calc(e.u)^Calc(e.v);}
}t;
#define M (L+R>>1)
void Add(int l,int r,edge e,int L,int R,int k){
	if(l<=L&&R<=r){
		add[k].push_back(e);
		return;
	}
	if(l<=M)Add(l,r,e,L,M  ,k<<1  );
	if(r> M)Add(l,r,e,M+1,R,k<<1|1);
}
void Dfs(int L,int R,int k){
	++tp,st[tp]=st[tp-1];
	for(int i=0;i<add[k].size();i++)
		if(!t.Link(add[k][i]))
			st[tp].Insert(t.Query(add[k][i])^g[add[k][i]]);
	if(L==R){
		if(qry[L].u)printf("%d\n",st[tp].Query(t.Query(qry[L])));
		for(int i=(int)add[k].size()-1;~i;i--)t.Undo();
		tp--;
		return;
	}
	Dfs(L,M,k<<1),Dfs(M+1,R,k<<1|1);
	for(int i=(int)add[k].size()-1;~i;i--)t.Undo();
	tp--;
}
int main(){
	int u,v,c,o;
	edge e;
	scanf("%d%d",&n,&m);
	t.Init();
	for(int j=1;j<=m;j++){
		scanf("%d%d%d",&u,&v,&c);
		e=(edge){u,v};
		g[e]=c,la[e]=1;
	}
	scanf("%d",&q);
	for(int j=1;j<=q;j++){
		scanf("%d%d%d",&o,&u,&v);
		e=(edge){u,v};
		switch(o){
		case 1:
			scanf("%d",&c);
			g[e]=c,la[e]=j;
			break;
		case 2:
			Add(la[e],j,e,1,q,1);
			la.erase(e);
			break;
		case 3:qry[j]=e;
		}
	}
	for(auto it:la)Add(it.second,q,it.first,1,q,1);
	Dfs(1,q,1);
	return 0;
}