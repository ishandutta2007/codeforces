#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6,MOD=998244353;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
bool is_pr[N];
int pr[N],top_pr,pre_pr[N],inv[N];
struct II{
	II(){
		inv[1]=1;
		for(int i=1;i<N;++i){
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		}
	}
}__ii;
void sieve(int n){
	top_pr=0; is_pr[1]=0;
	for(int i=2;i<=n;++i) is_pr[i]=1,pre_pr[i]=1;
	for(int i=2;i<=n;++i){
		if(is_pr[i]) pr[++top_pr]=i,pre_pr[i]=i;
		for(int j=1;j<=top_pr&&i*pr[j]<=n;++j){
			is_pr[i*pr[j]]=0;
			pre_pr[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
struct Graph{
	struct Edge{ int to,nxt,p1,p2; };
	vector<Edge> edge;
	vector<int> head;
	Graph(int n=0,int m=0){
		edge.clear(); edge.reserve(m);
		head=vector<int>(n+1,-1);
	}
	inline void add(int x,int y,int p1,int p2){
		edge.push_back((Edge){y,head[x],p1,p2});
		head[x]=edge.size()-1;
	}
}G;
inline void add2(int x,int y,int p1,int p2){
	G.add(x,y,p1,p2);
	G.add(y,x,p2,p1);
}
int key[N],ans;
void mul(int x){
	for(;x!=1;x/=pre_pr[x])
		key[pre_pr[x]]++;
}
void div(int x){
	for(;x!=1;x/=pre_pr[x]){
		key[pre_pr[x]]=max(0,key[pre_pr[x]]-1);
	}
}
void dfs1(int x,int pre,int p1,int p2){
	mul(p2); div(p1);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs1(y,x,G.edge[j].p1,G.edge[j].p2);
		}
	}
	mul(p1); div(p2);
}
void dfs2(int x,int pre,int mul){
	mo(ans+=mul);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre)
			dfs2(y,x,1ll*mul*G.edge[j].p2%MOD*inv[G.edge[j].p1]%MOD);
	}
}
int main(){
	sieve((int)2e5);
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		G=Graph(n,n);
		for(int i=1;i<=n;++i) key[i]=0;
		for(int i=1;i<n;++i){
			int x,y,p1,p2; scanf("%d%d%d%d",&x,&y,&p1,&p2);
			add2(x,y,p1,p2);
		}
		dfs1(1,0,1,1);
		ans=0; int mul=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=key[i];++j)
				mul=1ll*mul*i%MOD;
		}
		dfs2(1,0,mul);
		printf("%d\n",ans);
	}
	return 0;
}