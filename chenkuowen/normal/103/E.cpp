#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=605;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[N*N];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int c){
		edge[++top]=(Edge){y,head[x],c};
		head[x]=top;
	}
}G;
namespace FLOW{
	int iter[N],lev[N];
	bool bfs(int s,int t,int n){
		memcpy(iter,G.head,sizeof(int)*(n+1));
		memset(lev,0,sizeof(int)*(n+1));
		static int q[N],left,right;
		left=right=0; q[right++]=s; lev[s]=1;
		while(left!=right){
			int x=q[left++];
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[right++]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int o,int mi){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]==lev[x]+1){	
				int d=dfs(y,o,min(mi,G.edge[j].c));
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	ll solve(int s,int t,int n){
		ll ret=0,d;
		while(bfs(s,t,n)){
			while((d=dfs(s,t,(int)2e9))!=0) ret+=d; 
		}
		return ret;
	}
}
void add2(int x,int y,int c){
	G.add(x,y,c); G.add(y,x,0);
//	printf("[%d %d %d]",x,y,c);
}
int main(){
	int n; scanf("%d",&n);
	unordered_map<int,int> mp;
	for(int i=1;i<=n;++i){
		int m; scanf("%d",&m);
		for(int j=1;j<=m;++j){
			int x; scanf("%d",&x);
			if(mp.find(x)==mp.end())
				mp[x]=(int)mp.size()+1;
			x=mp[x];
			add2(i,n+x,(int)2e9);
		}
	}
	int s=0,t=(int)mp.size()+n+1;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x); x=-x; 
		if(x<0){
			add2(i,t,-x);
			add2(s,i,(int)1e9);
			ans+=(int)1e9;
		}else{
			add2(s,i,x+(int)1e9);
			ans+=x+(int)1e9;
		}
	}
	for(int i=1;i<=mp.size();++i)
		add2(n+i,t,(int)1e9);
	ans-=FLOW::solve(s,t,t);
//	printf("%lld\n",ans);
	printf("%lld\n",min(-ans,0ll));
	return 0;
}