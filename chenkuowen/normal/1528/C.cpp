#include<bits/stdc++.h>
using namespace std;
const int N=5+3e5;
struct BIT{
	vector<int> c;
	BIT(int n=0){c=vector<int>(n+1,0); }
	inline void add(int x,int k){
		for(;x<c.size();x+=x&-x) c[x]+=k;
	}
	inline int query(int x){
		int ret=0;
		for(;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}bit;
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
}G1,G2;
int dfn[N],e[N],ti;
bool vis[N];
void dfs1(int x){
	dfn[x]=++ti;
	for(int j=G1.head[x];~j;j=G1.edge[j].nxt){
		int y=G1.edge[j].to;
		dfs1(y);
	}
	e[x]=ti;
}
void dfs2(int x){
	bit.add(dfn[x],1); bit.add(e[x]+1,-1);
	int key=bit.query(dfn[x]);
	for(int j=G2.head[x];~j;j=G2.edge[j].nxt){
		int y=G2.edge[j].to;
		dfs2(y);
	}
	int key2=bit.query(dfn[x]);
	vis[x]=key2-key!=0;
}
bool is_an(int x,int y){ return dfn[x]<=dfn[y]&&e[y]<=e[x]; }
struct Cmp{
	inline bool operator()(const int& x,const int& y)const { return dfn[x]<dfn[y]; }
};
struct OP{
	map<int,int,Cmp> d;
	multiset<int,Cmp> high;
	void clear(){ d.clear(); high.clear(); }
	vector<int> add_(int x){
		vector<int> ret;
		stack<int> stk;
		stk.push(x);
		while(1){
			auto it=high.lower_bound(x);
			if(it==high.end()||!is_an(x,*it)) break;
			while(!is_an(stk.top(),*it)) stk.pop();
			if(stk.top()==x) ret.push_back(*it);
			stk.push(*it); high.erase(it);
		}
		high.insert(x);
		return ret;
	}
	void add1(int x){
		vector<int> f=add_(x);
		for(auto y:f) d[y]--;
		d[x]++;
	}
	void add2(int x,int k){
		add_(x);
		d[x]+=k;
	}
	size_t size(){ return d.size(); }
}op[N];
void merge(OP& a,OP& b){
	if(a.size()<b.size()) swap(a,b);
	for(auto x:b.d)
		a.add2(x.first,x.second);
	b.clear();
}
void dfs3(int x){
	op[x].clear();
	for(int j=G2.head[x];~j;j=G2.edge[j].nxt){
		int y=G2.edge[j].to;
		dfs3(y);
		merge(op[x],op[y]);
	}
	if(!vis[x]) op[x].add1(x);
//	printf("[%d %d]",x,int(vis[x]));
}
int ans[N];
void dfs4(int x){
	for(int j=G1.head[x];~j;j=G1.edge[j].nxt){
		int y=G1.edge[j].to;
		ans[y]+=ans[x];
		dfs4(y);
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		G1=G2=Graph(n,n); bit=BIT(n); ti=0;
		for(int i=2;i<=n;++i){
			int x; scanf("%d",&x);
			G1.add(x,i);
		}
		for(int i=2;i<=n;++i){
			int x; scanf("%d",&x);
			G2.add(x,i);
		}
		dfs1(1); dfs2(1); dfs3(1);
		for(int x=1;x<=n;++x) ans[x]=op[1].d[x];
		dfs4(1);
		int ret=0;
		for(int x=1;x<=n;++x) ret=max(ret,ans[x]);
		printf("%d\n",ret);
	}	
	return 0;
}