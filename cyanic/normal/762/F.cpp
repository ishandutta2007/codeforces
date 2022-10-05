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

inline int read(){
	char ch=getchar();int x=0,op=0;
	while(!isdigit(ch))op|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return op?-x:x;
}

const int N=2005,M=15;
const int mod=1e9+7;
int fac[N],f[N][M],flag[M],pre[M][M][M];
vi e[N],E[M],s[M][M];
int n,m,x,y,rev;

int Ha[M][M];
int calc(int u,int fa,int rt){
	int res=1,sum=19260817,tmp;
	for(auto v:E[u])
		if(v!=fa){
			tmp=calc(v,u,rt);
			res=1ll*res*tmp%mod;
			sum=(sum+tmp)%mod;
		}
	res=1ll*res*sum%mod;
	return Ha[rt][u]=res;
}
void doit(int u,int fa,int rt){
	for(auto v:E[u])if(v!=fa){
		doit(v,u,rt);
		s[rt][u].pb(v);
	}
	int sz=s[rt][u].size();
	REP(i,sz){
		rep(j,0,i-1)
		if(Ha[rt][s[rt][u][i]]==Ha[rt][s[rt][u][j]])
			pre[rt][u][i]|=(1<<j);
	}
}
void init(){
	rep(i,1,m){
		calc(i,0,i);
		rep(j,1,i-1)
			if(Ha[i][i]==Ha[j][j]){
				flag[i]=1;break;
			}
		if(flag[i])continue;
		doit(i,0,i);
	}
}

inline void upd(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}

int g[1<<M],h[1<<M],rt,res;
void dfs(int u,int fa){
	vi c;
	for(auto v:e[u])
		if(v!=fa)dfs(v,u),c.pb(v);
	int cc=c.size();
	rep(i,1,m){
		int sz=s[rt][i].size();
		if(sz>cc){f[u][i]=0;continue;}
		REP(st,(1<<sz))g[st]=0;
		g[0]=1;
		REP(k,cc){
			REP(st,(1<<sz))h[st]=g[st];
			REP(st,(1<<sz))if(g[st])
				REP(j,sz)if(!(st>>j&1)&&f[c[k]][s[rt][i][j]]
					&&((st&pre[rt][i][j])==pre[rt][i][j]))
					upd(h[st|(1<<j)],1ll*g[st]*
							f[c[k]][s[rt][i][j]]%mod);
			REP(st,(1<<sz))g[st]=h[st];
		}
		f[u][i]=g[(1<<sz)-1];
	}
	res=(res+f[u][rt])%mod;
}

int solve(int k){
	rt=k,res=0;
	dfs(1,0);
	return res;
}

int main(){

	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		e[x].pb(y),e[y].pb(x);
	}
	scanf("%d",&m);
	rep(i,1,m-1){
		scanf("%d%d",&x,&y);
		E[x].pb(y),E[y].pb(x);
	}
	init();
	int ans=0;
	rep(i,1,m)if(!flag[i])
		ans=(ans+solve(i))%mod;
	printf("%d\n",ans);

	return 0;
}