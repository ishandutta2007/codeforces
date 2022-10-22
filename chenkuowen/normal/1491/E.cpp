#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
struct Graph{
	struct Edge{ int to,nxt; bool mark; }edge[N*2];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int sz[N],f[N],top,fa[N];
void dfs(int x,int pre){
	sz[x]=1; fa[x]=pre;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&!G.edge[j].mark){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
}
int dfs2(int x,int pre,int kk){
	int ret=-1;
	if(sz[x]==f[kk-1]||sz[x]==f[kk-2]) ret=x;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&!G.edge[j].mark){
			int k=dfs2(y,x,kk);
			if(k!=-1) return k;
		}
	}
	return ret;
}
bool check(int x){
	dfs(x,0);
	if(sz[x]<=2) return true;
	int k=lower_bound(f,f+top+1,sz[x])-f;
	if(sz[x]!=f[k]) return false;
//	printf("<%d %d>",x,k);
	int y=dfs2(x,0,k);
	for(int j=G.head[y];~j;j=G.edge[j].nxt){
		int z=G.edge[j].to;
		if(z==fa[y]&&!G.edge[j].mark){
			G.edge[j].mark=G.edge[j^1].mark=1;
			return check(z)&&check(y);
		}
	}
	return false;
}
int main(){
	f[0]=f[1]=1;
	for(top=2;;++top){
		f[top]=f[top-1]+f[top-2];
		if(f[top]>1e8) break;
	}
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	if(check(1)) puts("YES");
	else puts("NO");
	return 0;
}