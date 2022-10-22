#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6,MOD=1e9+7;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
inline int mo(int x){ return x>=MOD?x-MOD:x; }
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1; }
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
	inline void add2(int x,int y){ 
//		printf("(%d %d)",x,y); 
		add(x,y); add(y,x); 
	}
}G,G1;
int top_node,n;
namespace BUILD{
	int stk[MAX_N],top_stk,dfn[MAX_N],low[MAX_N],ti=0;
	void tarjan(int x,int pre){
		dfn[x]=low[x]=++ti; stk[++top_stk]=x;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(y!=pre){
				if(dfn[y]==0){
					tarjan(y,x); low[x]=min(low[x],low[y]);
					if(low[y]>=dfn[x]){
						++top_node;
						G1.add2(x,top_node);
						while(stk[top_stk+1]!=y){
							G1.add2(stk[top_stk],top_node);
							--top_stk;
						}
					}
				}else low[x]=min(low[x],dfn[y]);
			}
		}
	}
}
struct Key{
	int x0,x1,x2;
	Key(int _x0=1,int _x1=0,int _x2=0){ x0=_x0,x1=_x1,x2=_x2; }
	inline Key operator*(int p){
		return Key(1ll*x0*p%MOD,1ll*x1*p%MOD,1ll*x2*p%MOD);
	}
	inline Key operator+(int d){
		return Key(x0,(x1+1ll*d*x0)%MOD,(x2+2ll*d*x1+1ll*d*d%MOD*x0)%MOD);
	}
	void print(){
		printf("{%d %d %d}",x0,x1,x2);
	}
};
inline Key operator*(Key a,Key b){
	return Key(1ll*a.x0*b.x0%MOD,(1ll*a.x1*b.x0+1ll*a.x0*b.x1)%MOD
		,(1ll*a.x2*b.x0+1ll*a.x0*b.x2+2ll*a.x1*b.x1)%MOD);
}
inline Key operator+(Key a,Key b){
	return Key(mo(a.x0+b.x0),mo(a.x1+b.x1),mo(a.x2+b.x2));
}
Key f[MAX_N][3],g[MAX_N][2][3];
void dfs(int x,int pre){
	vector<int> son;
	for(int j=G1.head[x];~j;j=G1.edge[j].nxt){
		int y=G1.edge[j].to;
		if(y!=pre){
			dfs(y,x);
			son.push_back(y);
		}
	}
	if(x<=n){
		f[x][0]=Key()*(MOD+1>>1); f[x][1]=Key()*(MOD+1>>1);
		for(auto y:son){
			f[x][0]=f[x][0]*(f[y][0]+(f[y][1]+1)+(f[y][2]+2));
			f[x][1]=f[x][1]*(f[y][0]+f[y][1]+f[y][2]);
		}
	}else{
		for(int i=0;i<2;++i) 
			for(int j=0;j<3;++j) 
				g[0][i][j]=Key(0,0,0);
		g[0][0][0]=f[son[0]][0];
		g[0][1][2]=f[son[0]][1];
		for(int i=1;i<son.size();++i)
			for(int t=0;t<2;++t){
				g[i][t][0]=f[son[i]][0]*(g[i-1][t][0]
					+(g[i-1][t][1]+1)+(g[i-1][t][2]+1));
				g[i][t][1]=f[son[i]][1]*(g[i-1][t][0]
					+g[i-1][t][1]);
				g[i][t][2]=f[son[i]][1]*g[i-1][t][2];
			}
		f[x][0]=g[son.size()-1][0][0];
		f[x][1]=(g[son.size()-1][1][0]+(MOD-1))+g[son.size()-1][0][1]
			+g[son.size()-1][1][2];
		f[x][2]=g[son.size()-1][1][1]+(MOD-1);
	}
//	printf("[%d](%d %d %d)(%d %d %d)(%d %d %d)\n",x
//		,f[x][0].x0,f[x][0].x1,f[x][0].x2
//		,f[x][1].x0,f[x][1].x1,f[x][1].x2
//		,f[x][2].x0,f[x][2].x1,f[x][2].x2);
}
int main(){
//	printf("<%lld>",(2ll*fpow(8,MOD-2)+13ll*fpow(16,MOD-2))%MOD);
//	printf("|%lld|\n",3ll*fpow(8,MOD-2)%MOD);
	int m;  scanf("%d%d",&n,&m); top_node=n;
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		if(x!=y) G.add2(x,y);
	}
	BUILD::tarjan(1,0);
	dfs(1,0);
	Key ans=f[1][0]+(f[1][1]+1);
//	printf("[%d %d]",ans.x1,ans.x2);
	printf("%lld\n",(ans.x2+MOD-1ll*ans.x1*ans.x1%MOD)%MOD);
	return 0;
}