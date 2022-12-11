#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
typedef long long ll;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,m;
vector<int> e[500010];
int tot;
int p[500010],q[500010];
list<int> lst;
vector<int> g[500010];


int que[500010],hd,tl;
int ban[500010];
vector<int> h[500010];
bool dp[500010];
void dfs(int x,int f){
	bool s=1; int z=-1;
	for (int y: h[x]) dfs(y,x),s&=dp[y],z=y;
	if (s){
		dp[x]=0;
		if (!f) g[z].pb(x);
	}
	else{
		dp[x]=1;
		for (int y: h[x]) if (!dp[y]) g[x].pb(y);
	}
}
void bfs(int S){
	hd=tl=0; que[++tl]=S;
	while (hd<tl){
		int u=que[++hd];
		for (int v: e[u]) ban[v]=u;
		for (auto cur=lst.begin(),nxt=cur;cur!=lst.end();cur=nxt){
			nxt=cur,++nxt;
			if (ban[*cur]^u)  h[u].pb(*cur),que[++tl]=*cur,lst.erase(cur);
		}
	}
	dfs(S,0);
}

void solve(){  //init
	n=read(); m=read();
	
	tot=0;
	rep(i,1,n) e[i].clear(),g[i].clear(),h[i].clear(),ban[i]=0;
	lst.clear();
	
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	rep(i,1,n) if (int(e[i].size())==n-1) p[i]=q[i]=++tot; else lst.pb(i);
	while (lst.begin()!=lst.end()){
		int u=*lst.begin(); lst.erase(lst.begin());
		bfs(u);
	}
	rep(i,1,n){
		if (!g[i].size()) continue;
		int S=g[i].size();
		rep(j,0,S-1) p[g[i][j]]=tot+j+1,q[g[i][j]]=tot+j+2;
		p[i]=tot+S+1; q[i]=tot+1;
		tot+=S+1;
	}
	rep(i,1,n) printf("%d%c",p[i]," \n"[i==n]);
	rep(i,1,n) printf("%d%c",q[i]," \n"[i==n]);
}
int main()
{
	for (int T=read();T--;) solve();
}