#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10,P=1e9+7;

int n,m;
vector <Pii> G[N];

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

#define Gauss   rep(i,0,4) if(d[i]) rep(j,i+1,4) if(d[j]&(1<<i)) d[j]^=d[i];\
				drep(i,4,0) D=(D<<(i+1))|d[i];

int Ins(int &D,int x){
	int d[5];
	rep(i,0,4) d[i]=D&((1<<(i+1))-1),D>>=i+1;
	int f=0;
	drep(i,4,0) if(x&(1<<i)) {
		if(d[i]) x^=d[i];
		else { f=1,d[i]=x; break; }
	}
	if(!f) return 0;
	Gauss;
	return 1;
}

int Uni(int &D,int E){
	if(!E) return 1;
	int d[5];
	rep(i,0,4) d[i]=D&((1<<(i+1))-1),D>>=i+1;
	rep(i,0,4) {
		int x=E&((1<<(i+1))-1); E>>=i+1;
		if(!x) continue;
		int f=0;
		drep(i,4,0) if(x&(1<<i)) {
			if(d[i]) x^=d[i];
			else { f=1,d[i]=x; break; }
		}
		if(!f) return 0;
	}
	Gauss;
	return 1;
}

struct Table{
	int val[1<<15],a[1<<15],c;
	void Add(int x,int v) {
		if(!val[x]) a[c++]=x;
		val[x]+=v,Mod1(val[x]);
	}
	void clr(){
		rep(i,0,c-1) val[a[i]]=0;
		c=0;
	}
} dp[2];

int vis[N],dfn,dis[N],D,F,E[N],L,C;
void dfs(int u) {
	//cout<<"dfs "<<u<<' '<<f<<endl;
	vis[u]=++dfn;
	if(~E[u]) C++;
	for(Pii i:G[u]) if(i.first!=1) {
		int v=i.first;
		if(~E[u] && ~E[v]) L=E[u]^E[v]^i.second;
		if(!vis[v]) dis[v]=dis[u]^i.second,dfs(v);
		else if(vis[v]>vis[u]) {
			//cout<<"Cir "<<u<<' '<<v<<' '<<(dis[u]^dis[v]^i.second)<<endl;
			F&=Ins(D,dis[v]^dis[u]^i.second);
		}
	}
}

void Show(int D){
	rep(i,0,4) {
		int x=D&((1<<(i+1))-1); D>>=i+1;
		drep(j,i,0) cout<<((x>>j)&1);
		puts("");
	}
}

int main(){
	/*Show(16933); puts(""); Show(16384); puts(""); Show(16932); return 0;*/
	n=rd(),m=rd();
	rep(i,1,m) {
		int u=rd(),v=rd(),w=rd();
		G[u].pb(mp(v,w)),G[v].pb(mp(u,w));
	}
	rep(i,1,n) E[i]=-1;
	for(Pii i:G[1]) E[i.first]=i.second;
	int cur=0;
	dp[0].Add(0,1);
	for(Pii i:G[1]) {
		int v=i.first;
		//if(n>20) cout<<"$"<<v<<endl;
		if(vis[v]) continue;
		F=1,D=C=0,L=-1,dfs(v);
		if(!F) continue;
		dp[!cur].clr();
		//if(n>20) cout<<"$"<<C<<' '<<L<<' '<<D<<endl;
		if(~L) C-=2;
		C=qpow(2,C);
		rep(i,0,dp[cur].c-1) {
			int x=dp[cur].a[i],y=dp[cur].val[x];
			//cout<<"dp "<<x<<' '<<y<<endl;
			dp[!cur].Add(x,y);
			if(Uni(x,D)) {
				dp[!cur].Add(x,((~L?3ll:1ll)*C-1)*y%P);
				if(~L && Ins(x,L)) dp[!cur].Add(x,1ll*y*C%P);
			}
		}
		cur^=1;
	}
	int ans=0;
	rep(i,0,dp[cur].c-1) (ans+=dp[cur].val[dp[cur].a[i]])%=P;
	printf("%d\n",ans);
}