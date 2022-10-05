#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=500005;
const ll inf=1e18;
ll f[N][20],g[N][20],T[N][20],d[N];
int lg[N],fa[N][20],in[N],out[N],cur[N];
int n,Q,a,b,c;
vi e[N],w[N];
ll ans;

int clk;
void dfs(int u,int father){
	fa[u][0]=father;
	in[u]=++clk;
	if(e[u].size()==0)T[in[u]][0]=d[u];
	else T[in[u]][0]=inf;
	//printf("%d %d\n",u,d[u]);
	REP(k,e[u].size())
		if(e[u][k]!=father){
			d[e[u][k]]=d[u]+w[u][k];
			dfs(e[u][k],u);
		}
	out[u]=clk;
}

inline ll qry(int l,int r){
	if(l>r)return inf;
	int tmp=lg[r-l+1];
	return min(T[l][tmp],T[r-(1<<tmp)+1][tmp]);
}

void init(){
	lg[0]=-1;
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	//rep(i,1,n)printf("# %d %lld\n",i,T[i][0]);
	rep(j,1,19)rep(i,1,n){
		T[i][j]=T[i][j-1];
		if(i+(1<<(j-1))<=n)
			T[i][j]=min(T[i][j],T[i+(1<<(j-1))][j-1]);
	}
	f[0][0]=g[0][0]=inf;
	f[1][0]=g[1][0]=inf;
	in[0]=0,out[0]=clk+1;
	rep(i,1,n){
		ll best=inf;
		REP(k,e[i].size())if(e[i][k]!=fa[i][0]){
			f[e[i][k]][0]=best-2*d[i];
			best=min(best,qry(in[e[i][k]],out[e[i][k]]));
		}
		best=inf;
		per(k,e[i].size()-1,0)if(e[i][k]!=fa[i][0]){
			g[e[i][k]][0]=best-2*d[i];
			best=min(best,qry(in[e[i][k]],out[e[i][k]]));
		}
	}
	//rep(i,1,n)printf("%d %lld\n",i,f[i][0]);
	rep(j,1,19)rep(i,0,n){
		fa[i][j]=fa[fa[i][j-1]][j-1];
		f[i][j]=min(f[i][j-1],f[fa[i][j-1]][j-1]);
		g[i][j]=min(g[i][j-1],g[fa[i][j-1]][j-1]);
	}
}

inline ll calc(int x,int l,int r,int y){
	if(!y)y=1;
	l=max(l,in[y]),r=min(r,out[y]);
	return qry(l,r)+d[x]-2*d[y];
}

ll doitL(int x,int l,int r){
	if(l>r)return inf;
	ll ans=inf;
	int fi=x,la=x;
	per(j,19,0)
		if(in[fa[fi][j]]>r)fi=fa[fi][j];
	if(in[fi]>r)fi=fa[fi][0];
	per(j,19,0)
		if(l<in[fa[la][j]])la=fa[la][j];
	if(l<in[la])la=fa[la][0];
	ans=min(ans,calc(x,l,r,fi));
	ans=min(ans,calc(x,l,r,la));
	if(la!=fi){
		per(j,19,0)
			if(d[fa[fi][j]]>d[la]){
				ans=min(ans,f[fi][j]+d[x]);
				fi=fa[fi][j];
			}
	}
	return ans;
}

ll doitR(int x,int l,int r){
	if(l>r)return inf;
	ll ans=inf;
	int fi=x,la=x;
	per(j,19,0)
		if(out[fa[fi][j]]<l)fi=fa[fi][j];
	if(out[fi]<l)fi=fa[fi][0];
	per(j,19,0)
		if(r>out[fa[la][j]])la=fa[la][j];
	if(r>out[la])la=fa[la][0];
	ans=min(ans,calc(x,l,r,fi));
	ans=min(ans,calc(x,l,r,la));
	if(la!=fi){
		per(j,19,0)
			if(d[fa[fi][j]]>d[la]){
				ans=min(ans,g[fi][j]+d[x]);
				fi=fa[fi][j];
			}
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&Q);
	rep(i,2,n){
		scanf("%d%d",&a,&b);
		e[a].pb(i);
		w[a].pb(b);
	}
	dfs(1,0);
	init();
	while(Q--){
		scanf("%d%d%d",&a,&b,&c);
		if(e[a].size()==0&&b<=in[a]&&in[a]<=c)puts("0");
		else printf("%lld\n",min(doitL(a,b,min(c,in[a])),
								 doitR(a,max(b,in[a]),c)));
	}
	return 0;
}