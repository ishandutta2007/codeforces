#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN=100005;
int N,N0;

struct Vec{
	ll x,y;
	Vec(ll x0=0,ll y0=0){x=x0;y=y0;}
	Vec operator +(const Vec b){return Vec(x+b.x,y+b.y);}
	Vec operator -(const Vec b){return Vec(x-b.x,y-b.y);}
	long double operator ^(const Vec b){return (long double)x*b.y-(long double)y*b.x;}
	bool operator <=(const Vec b){return ((*this)^b)>=0;}  // 
};
bool cmp(Vec a,Vec b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
struct Convex_Hull{
	vector<Vec> A;
	Convex_Hull(){A.clear();}
//	Convex_Hull operator +(Vec b){
//		Convex_Hull c;for(auto p:A) c.A.push_back(p+b);return c;
//	}
	Convex_Hull operator +(Convex_Hull b){
		if(!b.A.size()) return *this;
		if(!A.size()) return b;
		Convex_Hull c; Vec p=A[0]+b.A[0]; c.A.push_back(p);
		int i=0,j=0;
		while(i+1<A.size()||j+1<b.A.size())
			if(i+1<A.size()&&(j+1>=b.A.size()||((b.A[j+1]-b.A[j])<=(A[i+1]-A[i]))))
				p=p+(A[i+1]-A[i]),i++,c.A.push_back(p);
			else
				p=p+(b.A[j+1]-b.A[j]),j++,c.A.push_back(p);
		return c;
	}
};
Convex_Hull Build(vector<Vec> d){
	Convex_Hull c;
	sort(d.begin(),d.end(),cmp);
	#define len c.A.size()
	for(auto p:d){
		while(len>=2&&((c.A[len-1]-c.A[len-2])<=(p-c.A[len-2]))) c.A.pop_back();
		c.A.push_back(p);
	}
	#undef len
	return c;
}
vector<Vec> ans;
Convex_Hull ANS;

struct Edge{
	int u,v,w1,w2,id;
	Edge (int u0=0,int v0=0,int w10=0,int w20=0,int id0=0){u=u0;v=v0;w1=w10;w2=w20;id=id0;}
};
namespace T{
	vector<Edge> G[maxN<<1];
	bool used[maxN<<2];int tot;
	void add_E(int u,int v,int c1,int c2){
		G[u].push_back(Edge(u,v,c1,c2,++tot));
		G[v].push_back(Edge(v,u,c1,c2,++tot));
	}
	int s[maxN<<1],f[maxN<<2];
	Edge rt;
	void Get_s(int x,int fa){
		s[x]=1;
		for(auto e:G[x])if(e.v!=fa&&!used[e.id])
			Get_s(e.v,x),s[x]+=s[e.v];
	}
	void Get_rt(int x,int fa,int S){
		for(auto e:G[x])if(e.v!=fa&&!used[e.id]){
			if((f[e.id]=max(s[e.v],S-s[e.v]))<f[rt.id]) rt=e;
			Get_rt(e.v,x,S);
		}
	}
	vector<Vec> dis[2];
	void Get_dis(int x,int fa,ll SW1,ll SW2,int k){
		dis[k].push_back(Vec(SW1,SW2));
		for(auto e:G[x])if(e.v!=fa&&!used[e.id])
			Get_dis(e.v,x,SW1+e.w1,SW2+e.w2,k);
	}
	void BFZ(int x){
		Get_s(x,0);if(s[x]==1){return;}
		rt=Edge(0,0,0,0,0);
		Get_rt(x,0,s[x]);
		used[rt.id]=1;used[((rt.id+1)^1)-1]=1;
		int U=rt.v,V=rt.u;dis[0].clear();dis[1].clear();
		Get_dis(U,0,rt.w1,rt.w2,0);Get_dis(V,0,0,0,1);
		Convex_Hull tmp=Build(dis[0])+Build(dis[1]);
		for(auto p:tmp.A) ans.push_back(p);
		BFZ(U);BFZ(V);
	}
	void Solve(){
		f[0]=0x3f3f3f3f;
		BFZ(1);
	}
}
namespace tmpT{
	vector<Edge> G[maxN];
	void add_E(int u,int v,int c1,int c2){
		G[u].push_back(Edge(u,v,c1,c2));
		G[v].push_back(Edge(v,u,c1,c2));
	}
	int idx;int msk[maxN];
	void ADD_E(int u,int v,int c1,int c2){
		idx++;T::add_E(idx,v,c1,c2);T::add_E(msk[u],idx,0,0);
		msk[u]=idx;
	}
	void dfs(int x,int fa){
		for(auto e:G[x])if(e.v!=fa){
			ADD_E(x,e.v,e.w1,e.w2);
			dfs(e.v,x);
		}
	}
	void Build(){
		for(int i=1;i<=N;i++) msk[i]=i;
		idx=N;
		dfs(1,0);
		N0=idx;
	}
}

int M;

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<N;i++){
		int u,v,w1,w2;scanf("%d%d%d%d",&u,&v,&w1,&w2);
		tmpT::add_E(u,v,w1,w2);
	}
	tmpT::Build();
	ans.push_back(Vec(0,0));
	T::Solve();
	ANS=Build(ans);
	for(int t=0,j=0;t<M;t++){
		while(j+1<ANS.A.size()&&ANS.A[j+1].x*t+ANS.A[j+1].y>=ANS.A[j].x*t+ANS.A[j].y) j++;
		printf("%lld ",ANS.A[j].x*t+ANS.A[j].y);
	}
}