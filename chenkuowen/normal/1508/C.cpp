#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5;
template<class T> void chmin(T& x,T y){ y<x?void(x=y):void(); }
template<class T> void chmax(T& x,T y){ y>x?void(x=y):void(); }
struct DSF{
	vector<int> fa;
	DSF(int n){
		fa.resize(n);
		for(int i=0;i<n;++i) fa[i]=i;
	}
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
};
struct E{ int x,y,w; };
bool cmp(E a,E b){ return a.w<b.w; }
struct Graph{
	struct Edge{ int to,nxt; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
	inline void add2(int x,int y){ /*printf("[%d %d]",x,y);*/ add(x,y),add(y,x); }
}G;
vector<map<int,int> > e;
pair<ll,int> mst(){
	ll ans=0; int cnt=0,n=e.size(),top1=0;
	G=Graph(n,n);
	vector<int> id(n,-1);
	multiset<int> s;
	for(int x=0;x<n;++x) s.insert(x);
	for(int x=0;x<n;++x){
		if(id[x]!=-1) continue;
		queue<int> q; q.push(x); s.erase(s.find(x));
		while(!q.empty()){
			int x=q.front(); q.pop();
			id[x]=top1;
			vector<int> f; f.push_back(-1);
			for(auto d:e[x]) f.push_back(d.first);
			for(auto d:f){
				while(1){
					auto it=s.upper_bound(d);
					if(it!=s.end()&&e[x][*it]==0){
						G.add2(x,*it);
						++cnt; q.push(*it); s.erase(it);
					}else break;
				}
			}
		}
		top1++;
	}
//	for(auto x:id) printf("[%d]",x); puts("");
	vector<E> e1;
	for(int x=0;x<n;++x)
		for(auto d:e[x])
			e1.push_back((E){x,d.first,d.second});
	sort(e1.begin(),e1.end(),cmp);
	DSF dsf(top1);
	for(int i=0;i<e1.size();++i)
		if(dsf.fs(id[e1[i].x])!=dsf.fs(id[e1[i].y])){
			dsf.fa[dsf.fs(id[e1[i].x])]=dsf.fs(id[e1[i].y]);
			G.add2(e1[i].x,e1[i].y);
			ans+=e1[i].w;
//			printf("<%d>",e1[i].w);
		}
	return make_pair(ans,cnt);
}
int s[N];
vector<int> dfs(int x,int pre,int& ans){
	s[x]=(pre==-1?0:s[pre])+int(e[x][pre]==0);
	vector<int> g; g.push_back(x);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			vector<int> f=dfs(y,x,ans);
			for(auto y:g)
				for(auto z:f){
					if(e[y][z]==0) continue;
					if(s[y]-s[x]>0) chmin(ans,e[y][z]);
					if(s[z]-s[x]>0) chmin(ans,e[y][z]);
				}
			for(auto z:f) g.push_back(z);
		}
	}
	return g;
}
int main(){
	int n,m,sum=0; scanf("%d%d",&n,&m);
	e.resize(n);
	for(int i=0;i<m;++i){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		--x; --y;
		e[x][y]=e[y][x]=w;
		sum^=w;
	}
	ll cnt1=1ll*n*(n-1)/2-m;
	pair<ll,int> ret=mst();
//	exit(0);
	if(ret.second<cnt1) printf("%lld\n",ret.first);
	else{
		int ans=sum;
		dfs(0,-1,ans);
		printf("%lld\n",ans+ret.first);
	}
	return 0;
}