#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e4;
int prime[MAX_N],top_prime=0;
bool vis[MAX_N];
void Euler(int n){
	for(int i=2;i<=n;++i) vis[i]=1;
	for(int i=2;i<=n;++i){
		if(vis[i]) prime[++top_prime]=i;
		for(int j=1;j<=top_prime&&i*prime[j]<=n;++j){
			vis[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}
int cnt(int x,int k){
	int ret=0;
	while(x%k==0) x/=k,++ret;
	return ret;
}
vector<int> g[MAX_N];
vector<int> lca(vector<int> a,vector<int> b){
	vector<int> c; c.resize(a.size());
	for(int i=0;i<a.size();++i)
		if(a[i]==b[i]) c[i]=a[i];
		else {
			c[i]=min(a[i],b[i]);
			break;
		}
	return c;
}
int id[MAX_N],stk[MAX_N];
int top_stk=0;
struct Graph{
	struct Edge{ int to,nxt,key; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1; }
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k};
		head[x]=top;
	}
	inline void add2(int x,int y,int k){
//		printf("(%d %d %d)",x,y,k);
		add(x,y,k); add(y,x,k);
	}
}G;
int dep(vector<int> s){
	int ret=0;
	for(auto x:s) ret+=x;
	return ret;
}
int sz[MAX_N],d[MAX_N],n;
void dfs1(int x,int pre){
	sz[x]=d[x];
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs1(y,x);
			sz[x]+=sz[y];
		}
	}
}
int dfs2(int x,int pre){
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			if(sz[y]>n-sz[y])
				return dfs2(y,x);
		}
	}
	return x;
}
ll dfs3(int x,int pre,ll dist){
	ll ret=dist*d[x];
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre)
			ret+=dfs3(y,x,dist+G.edge[j].key);
	}
	return ret;
}
void print(vector<int> x){
	for(auto a:x) printf("(%d)",a);
	puts("");
}
int main(){
	int top=5000;
	Euler(top);
	for(int i=0;i<=top;++i)
		g[i].resize(top_prime);
	for(int j=1;j<=top_prime;++j)
		for(int i=1;i*prime[j]<=top;++i)
			g[i*prime[j]][top_prime-j]+=cnt(i*prime[j],prime[j]);
	for(int i=1;i<=top;++i){
		for(int j=0;j<g[i].size();++j)
			g[i][j]+=g[i-1][j];
//		print(g[i]);
	}
	vector<vector<int> > h;
//	puts("---------------");
	for(int i=0;i<=top;++i) h.push_back(g[i]);
	for(int i=1;i<=top;++i){
		h.push_back(lca(g[i-1],g[i]));
//		print(lca(g[i-1],g[i]));
	}
	sort(h.begin(),h.end());
	h.erase(unique(h.begin(),h.end()),h.end());
	stk[top_stk=1]=0;
	for(int i=1;i<h.size();++i){
		while(lca(h[stk[top_stk]],h[i])!=h[stk[top_stk]])
			--top_stk;
		G.add2(stk[top_stk],i,dep(h[i])-dep(h[stk[top_stk]]));
		stk[++top_stk]=i;
	}
//	puts("-----------------");
//	for(auto x:h) print(x);
	for(int i=0;i<=top;++i)
		id[i]=lower_bound(h.begin(),h.end(),g[i])-h.begin();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		d[id[x]]++;
	}
	dfs1(0,-1);
	int pos=dfs2(0,-1);
	printf("%lld\n",dfs3(pos,-1,0));
	return 0;
}