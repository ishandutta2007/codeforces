#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5,MOD=1e9+7;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[N],inv[N],ifac[N];
struct II{
	II(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
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
}G;
int f[N][205],g[205],sz[N],n,k,h[205];
void dfs(int x,int pre){
	sz[x]=1; f[x][0]=2; f[x][1]=2;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x); 
			memset(g,0,sizeof(int)*(min(k,sz[x]+sz[y])+1));
			for(int i=0;i<=min(k,sz[x]);++i)
				for(int j=0;j<=min(k,sz[y])&&i+j<=k;++j)
					g[i+j]=(g[i+j]+1ll*f[x][i]*f[y][j])%MOD;
			memcpy(f[x],g,sizeof(int)*(min(k,sz[x]+sz[y])+1));
			sz[x]+=sz[y];
		}
	}
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			for(int j=0;j<=min(k,sz[y]);++j){
				mo(h[j]+=MOD-f[y][j]);	
				mo(h[j+1]+=MOD-f[y][j]);
			}
			mo(h[1]+=1);
			mo(h[0]+=1);
		}
	}
	mo(f[x][1]+=MOD-1);
	for(int j=0;j<=min(k,sz[x]);++j)
		mo(h[j]+=f[x][j]);
	mo(h[0]+=MOD-1);
}
int main(){
	scanf("%d%d",&n,&k);
	G=Graph(n,n+n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	dfs(1,0);
	int ans=0;
	for(int t=0;t<=k;++t){
		int key=0;
		for(int i=0;i<=t;++i){
			int cnt=0;
			for(int j=0;j<=i;++j){
				cnt=(cnt+1ll*fpow(j,t)*comb(i,j)%MOD*(i-j&1?MOD-1:1))%MOD;
			}
			key=(key+1ll*h[i]*cnt)%MOD;
		}

		ans=(ans+1ll*comb(k,t)*(k-t&1?MOD-1:1)%MOD*key)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}