#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int dp[N],bas[N],ff[N],cur[N],vis[N],s[N];
int f[N][20],in[N],out[N],d[N],stk[N],o[N];
int n,top,cnt,clk,K,m;
vi e[N],t[N];
ll tim[N];

int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	per(i,19,0){
		if(d[f[x][i]]>=d[y]) x=f[x][i];
	}
	if(x==y) return x;
	per(i,19,0){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
void dfs(int u,int fa){
	f[u][0]=fa;
	rep(i,1,19){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	in[u]=++clk;
	for(auto v:e[u]){
		if(v==fa) continue;
		d[v]=d[u]+1;
		dfs(v,u);
	}
	out[u]=clk;
}

struct event{
	int u,ex; ll t;
	friend bool operator < (event a,event b){
		return a.t>b.t||a.t==b.t&&a.ex<b.ex;
	}
};
priority_queue<event> Q;

int cmp(int a,int b){
	return in[a]<in[b];
}
int isanc(int a,int b){
	return in[a]<=in[b]&&out[b]<=out[a];
}
void adde(int a,int b){
	t[a].pb(b),t[b].pb(a);
}
void solve(){
	read(K),read(m),cnt=0;
	rep(i,1,K){
		read(o[++cnt]);
		dp[o[cnt]]=i;
		tim[o[cnt]]=i-1;
		bas[o[cnt]]=0;
		read(s[i]);
	}
	rep(i,1,m){
		read(o[++cnt]);
		cur[i]=o[cnt];
	}
	sort(o+1,o+cnt+1,cmp);
	cnt=unique(o+1,o+cnt+1)-o-1;
	stk[top=1]=o[1];
	int total=cnt;
	rep(i,2,cnt){
		int las=0;
		while(top&&!isanc(stk[top],o[i])){
			las=stk[top--];
		}
		if(las){
			int nw=lca(las,o[i]);
			if(!top||stk[top]!=nw){
				o[++total]=nw;
				ff[las]=nw,ff[nw]=stk[top];
				stk[++top]=nw;
			}
		}
		if(top) ff[o[i]]=stk[top];
		stk[++top]=o[i];
	}
	cnt=total;
	rep(i,1,cnt){
		if(ff[o[i]]) adde(ff[o[i]],o[i]);
		if(tim[o[i]]>=0) Q.push((event){o[i],0,tim[o[i]]});
	}	
	while(!Q.empty()){
		int u=Q.top().u; Q.pop();
		if(vis[u]) continue; vis[u]=1;
		//printf("# %d %lld %d\n",u,tim[u],dp[u]);
		for(auto v:t[u]){
			int dis=abs(d[u]-d[v]);
			int owo=max(0,(dis-bas[u]+s[dp[u]]-1))/s[dp[u]];
			ll aim=tim[u]+(ll)owo*K;
			int ex=bas[u]+owo*s[dp[u]]-dis;
			if(tim[v]==-1||aim<tim[v]||aim==tim[v]&&ex>bas[v]){
				dp[v]=dp[u],tim[v]=aim,bas[v]=ex;
				Q.push((event){v,ex,aim});
			}
		}
	}
	rep(i,1,m){
		printf("%d ",dp[cur[i]]);
	}
	puts("");
	rep(i,1,cnt){
		dp[o[i]]=0;
		tim[o[i]]=-1;
		bas[o[i]]=0;
		t[o[i]].clear();
		ff[o[i]]=0;
		vis[o[i]]=0;
	}
}

int main(){
	read(n);
	rep(i,1,n-1){
		int u,v;
		read(u),read(v);
		e[u].pb(v),e[v].pb(u);
	}
	d[1]=1,dfs(1,0);
	int Q; read(Q);
	memset(tim,-1,sizeof tim);
	while(Q--) solve();
	return 0;
}