#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e6,MOD=998244353;
struct Edge{ int to,nxt; }edge[MAX_N];
int head[MAX_N],top_edge=-1,sz[MAX_N];
inline void add_edge(int x,int y){
	edge[++top_edge]=(Edge){y,head[x]};
	head[x]=top_edge;
}
ll dfs(int x,int pre){
	int ret=1,cnt=0; sz[x]=1;
	for(int j=head[x];j!=-1;j=edge[j].nxt){
		int y=edge[j].to;
		if(y!=pre){
			ret=1ll*ret*dfs(y,x)%MOD*(++cnt)%MOD;
			sz[x]+=sz[y];
		}
	}
	return x==1?1ll*ret*sz[x]%MOD:1ll*ret*(cnt+1)%MOD;
}
int main(){
	memset(head,-1,sizeof(head));
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		add_edge(x,y); add_edge(y,x);
	}
	printf("%lld\n",dfs(1,0));
	return 0;
}