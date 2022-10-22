#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T> void chmax(T& x,T y){ y>x?x=y:T(); }
template<class T> void chmin(T& x,T y){ y<x?x=y:T(); }
const int N=5+2e5;
struct Graph{
	struct Edge{ int to,nxt,k; bool mark; }edge[N*2];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k,false};
		head[x]=top;
	}
	inline void add2(int x,int y,int k){add(x,y,k),add(y,x,k);}
}G;
int sz[N],val[N],w[N];
void get_sz(int x,int pre){
	sz[x]=1; val[x]=0;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(!G.edge[j].mark&&y!=pre){
			get_sz(y,x); sz[x]+=sz[y];
			chmax(val[x],sz[y]);
		}
	}
}
int get_rt(int x,int pre,int size){
	int rt=x; chmax(val[x],size-sz[x]);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(!G.edge[j].mark&&y!=pre){
			int k=get_rt(y,x,size);
			if(val[k]<val[rt]) rt=k;
		}
	}
	return rt;
}
ld dfs(int x,int pre,int d){
	ld ret=(ld)w[x]*powl(d,1.5);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre) ret+=dfs(y,x,d+G.edge[j].k);
	}
	return ret;
}
pair<ld,int> ans(1e60,-1);
void dc(int x){
	get_sz(x,0);
	x=get_rt(x,0,sz[x]);
	get_sz(x,0);
	pair<ld,int> ret(-1,-1);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(!G.edge[j].mark)
			ret=max(ret,make_pair(dfs(y,x,G.edge[j].k+1)-dfs(y,x,G.edge[j].k-1),j));
	}
	ans=min(ans,make_pair(dfs(x,0,0),x));
	if(ret.second!=-1){
		int j=ret.second,y=G.edge[j].to;
		G.edge[j].mark=G.edge[j^1].mark=1;
		dc(y);
	}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&w[i]);
	for(int i=1;i<n;++i){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		G.add2(x,y,w);
	}
	dc(1);
	printf("%d %.14Lf\n",ans.second,ans.first);
	return 0;
}