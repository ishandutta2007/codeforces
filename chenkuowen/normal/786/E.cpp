#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e6;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int c){
		edge[++top]=(Edge){y,head[x],c};
		head[x]=top;
	}
}G,G1;
namespace FLOW{
	int iter[MAX_N],lev[MAX_N];
	bool bfs(int s,int t,int n){
		static int q[MAX_N],left,right;
		memcpy(iter,G.head,sizeof(int)*(n+1));
		memset(lev,0,sizeof(int)*(n+1));
		q[left=right=1]=s; lev[s]=1;
		while(left<=right){
			int x=q[left++];
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[++right]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int mi,int o){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]>lev[x]){
				int d=dfs(y,min(mi,G.edge[j].c),o);
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int solve(int s,int t,int n){
		int ret=0,d;
		while(bfs(s,t,n))
			while((d=dfs(s,1e9,t))!=0) ret+=d;
		return ret;
	}
}
void add2(int x,int y,int c){
	G.add(x,y,c); G.add(y,x,0);
}
const int N=5+2e4;
int fa[18][N],pos[18][N],dep[N],top_node=0;
struct C{ int x,y; }a[N];
int id[N];
void dfs(int x,int pre){
	fa[0][x]=pre; dep[x]=dep[pre]+1;
	for(int l=1;l<=15;++l) fa[l][x]=fa[l-1][fa[l-1][x]];
	for(int j=G1.head[x];~j;j=G1.edge[j].nxt){
		int y=G1.edge[j].to;
		if(y!=pre){
			id[y]=(j>>1)+1;
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int l=15;l>=0;--l)
		if(dep[fa[l][x]]>=dep[y])
			x=fa[l][x];
	for(int l=15;l>=0;--l)
		if(fa[l][x]!=fa[l][y])
			x=fa[l][x],y=fa[l][y];
	return x==y?x:fa[0][x];
}
void add_list(int x,int y,int id){
	for(int l=15;l>=0;--l)
		if(dep[fa[l][x]]>=dep[y]){
			add2(pos[l][x],id,1e9);
			x=fa[l][x];
		}
}
int main(){
	int n,m; scanf("%d%d",&n,&m);

	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G1.add(x,y,0); G1.add(y,x,0);
	}
	dfs(1,0);
	top_node=m;
	for(int l=0;l<=15;++l)
		for(int i=1;i<=n;++i)
			if(fa[l][i]!=0||(l==0&&i==1)){
				pos[l][i]=++top_node;
//				printf("(%d %d %d)",i,fa[l][i],pos[l][i]);
				if(l>0){
					add2(pos[l-1][i],pos[l][i],1e9);
					add2(pos[l-1][fa[l-1][i]],pos[l][i],1e9);
				}
			}
//	puts("");
	for(int i=1;i<=n;++i)
		add2(0,pos[0][i],1);
	++top_node;
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		a[i]=(C){x,y};
		int d=lca(x,y);
		add_list(x,d,i);
		add_list(y,d,i);
		add2(i,top_node,1);
	}
	printf("%d\n",FLOW::solve(0,top_node,top_node));
	vector<int> ret1,ret2;
	for(int i=1;i<=m;++i)
		if(FLOW::lev[i]>0) ret1.push_back(i);
	for(int i=1;i<=n;++i)
		if(FLOW::lev[i+m]==0){
//			printf("{%d}",i);
			ret2.push_back(i);
		}
	cout<<ret1.size()<<" ";
	for(auto x:ret1) cout<<x<<" ";
	cout<<'\n'<<ret2.size()<<" ";
	for(auto y:ret2) cout<<id[y]<<" ";
	return 0;
}