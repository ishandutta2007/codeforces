#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int INF=(1<<20);
struct Dinic{
	struct edge{
		int to,cap,rev;
		edge(int to,int cap,int rev): to(to),cap(cap),rev(rev) {} 
	};
	vector<edge>g[90000];
	int lev[90000],iter[90000];
	void addedge(int u,int v,int w){
		g[u].push_back(edge(v,w,g[v].size()));
		g[v].push_back(edge(u,0,g[u].size()-1));
	}
	void bfs(int s){
		memset(lev,-1,sizeof(lev));
		queue<int>que;lev[s]=0,que.push(s);
		while(!que.empty()){
			int u=que.front();que.pop();
			for(auto x:g[u]){
				if(x.cap==0||lev[x.to]>=0)continue;
				lev[x.to]=lev[u]+1,que.push(x.to);
			}
		}
	}
	int dfs(int x,int t,int F){
		if(x==t)return F;
		for(int &i=iter[x];i<g[x].size();i++){
			edge &e=g[x][i];
			if(lev[e.to]>lev[x]&&e.cap>0){
				int d=dfs(e.to,t,min(F,e.cap));
				if(d>0){e.cap-=d,g[e.to][e.rev].cap+=d;return d;}
			}
		}
		return 0;
	}
	int maxflow(int s,int t){
		int ret=0;for(;;){
			bfs(s);if(lev[t]<0)return ret;
			memset(iter,0,sizeof(iter));int f;
			while((f=dfs(s,t,INF))>0)ret+=f; 
		}
	}
}Gr;
int n,q,N;set<pii>st;map<pii,int>mp;
vector<pii>add[10004],del[10004];
vector<pair<pii,pii> >reco;
int init0(int l,int r){
	int id=(l+r)|(l!=r);
	if(l==r){Gr.addedge(1,id+2,1);return id;}
	int md=(l+r)>>1;
	int ls=init0(l,md),rs=init0(md+1,r);
	Gr.addedge(ls+2,id+2,INF),Gr.addedge(rs+2,id+2,INF);
	return id;
}
int init1(int l,int r){
	int id=(l+r)|(l!=r);
	if(l==r){Gr.addedge(id+n*2+3,2,1);return id;}
	int md=(l+r)>>1;
	int ls=init1(l,md),rs=init1(md+1,r);
	Gr.addedge(id+n*2+3,ls+n*2+3,INF),Gr.addedge(id+n*2+3,rs+n*2+3,INF);
	return id;
}
void upd0(int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		int id=(l+r)|(l!=r);
		Gr.addedge(id+2,N,INF);
		return;
	}
	int md=(l+r)>>1;
	upd0(l,md,a,b),upd0(md+1,r,a,b);
}
void upd1(int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		int id=(l+r)|(l!=r);
		Gr.addedge(N,id+n*2+3,INF);
		return;
	}
	int md=(l+r)>>1;
	upd1(l,md,a,b),upd1(md+1,r,a,b);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		int A,B,C,D;scanf("%d%d%d%d",&A,&B,&C,&D);
		add[A].push_back({B,D}),del[C+1].push_back({B,D});
	}
	st.insert({1,n}),mp[{1,n}]=1;
	for(int i=1;i<=n;i++){
		for(auto [l,r]:del[i]){
			int L=l,R=r;
			auto it=st.lower_bound({L,n});
			if(it!=st.end()&&(*it).fi==r+1){
				auto [ld,rd]=*it;
				reco.push_back({{mp[{ld,rd}],i-1},{ld,rd}});
				R=rd,st.erase(it);
			}
			it=st.lower_bound({L,n});
			if(it!=st.begin()&&(*--it).se==l-1){
				auto [ld,rd]=*it;
				reco.push_back({{mp[{ld,rd}],i-1},{ld,rd}});
				L=ld,st.erase(it);
			}
			st.insert({L,R}),mp[{L,R}]=i;
		}
		for(auto [l,r]:add[i]){
			auto it=--st.upper_bound({l,n});
			auto [L,R]=*it;st.erase(it);
			reco.push_back({{mp[{L,R}],i-1},{L,R}});
			if(L!=l)st.insert({L,l-1}),mp[{L,l-1}]=i;
			if(R!=r)st.insert({r+1,R}),mp[{r+1,R}]=i;
		}
	}
	for(auto [L,R]:st)reco.push_back({{mp[{L,R}],n},{L,R}});
	init0(1,n),init1(1,n),N=4*n+4;
	for(auto [x,y]:reco)if(x.fi<=x.se&&y.fi<=y.se)
		++N,upd0(1,n,x.fi,x.se),upd1(1,n,y.fi,y.se);
	printf("%d",Gr.maxflow(1,2));
}