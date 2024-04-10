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
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005,B=160;
namespace bit{
	#define lb(x) (x&-x)
	int c[N];
	void upd(int x,int y){
		for(;x<N;x+=lb(x))c[x]+=y;
	}
	int qry(int l,int r){
		int res=0;
		for(;r;r-=lb(r)) res+=c[r];
		for(--l;l;l-=lb(l)) res-=c[l];
		return res;
	}
}
struct node{ int id,l,r; };
vector<node> ask[N];
vector<pii> owo[N];
set<pii> blk;
ll ans[N];
namespace AC{
	int t[N][26],trans[N][26],fail[N],pos[N];
	int f[N],g[N],rt=1,sz=1;
	vi tr[N],e[N];
	void ins(char s[],int id){
		int o=rt;
		for(int i=1;s[i];i++){
			if(!t[o][s[i]-'a']) t[o][s[i]-'a']=++sz;
			o=t[o][s[i]-'a'];
		}
		pos[id]=o;
	}
	void build(){
		rep(i,1,sz) memcpy(trans[i],t[i],sizeof t[i]);
		static int q[N];
		int l=0,r=0,u=rt;
		REP(t,26)
			if(!trans[u][t])trans[u][t]=u;
			else fail[q[r++]=trans[u][t]]=u;
		while(l<r){
			u=q[l++];
			REP(t,26)
				if(!trans[u][t])trans[u][t]=trans[fail[u]][t];
				else fail[q[r++]=trans[u][t]]=trans[fail[u]][t];
		}
		rep(i,1,sz)REP(c,26)
			if(t[i][c]) tr[i].pb(t[i][c]);
		rep(i,2,sz) e[fail[i]].pb(i);
	}
	void dfs1(int u){
		for(auto v:e[u]) g[v]+=g[u],dfs1(v);
	}
	void dfs2(int u){
		f[u]+=g[u]; for(auto v:tr[u]) f[v]+=f[u],dfs2(v);
	}
	void doit(int k,int l,int r){
		if(blk.empty())return;
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		for(int i=l;i<=r&&i<N;i++) g[pos[i]]++;
		dfs1(rt),dfs2(rt);
		for(auto x:blk) ans[x.fi]+=f[pos[x.se]];
	}
	int in[N],out[N],clk;
	void pre(int u){
		in[u]=++clk; for(auto v:e[u]) pre(v); out[u]=clk;
	}
	void dfs(int u){
		bit::upd(in[u],1);
		for(auto x:ask[u]) rep(i,x.l,x.r)
			ans[x.id]+=bit::qry(in[pos[i]],out[pos[i]]);
		for(auto v:tr[u]) dfs(v);
		bit::upd(in[u],-1);
	}
	void solve(){ pre(rt); dfs(rt); }
}
char s[N];
int n,Q;

int main(){
	read(n),read(Q);
	rep(i,1,n) scanf("%s",s+1),AC::ins(s,i);
	AC::build();
	rep(i,1,Q){
		int l,r,k;
		read(l),read(r),read(k);
		if(l/B==r/B)ask[AC::pos[k]].pb((node){i,l,r});
		else{
			int a=(l/B+1)*B,b=r/B*B-1;
			if(l<a)ask[AC::pos[k]].pb((node){i,l,a-1});
			if(b<r)ask[AC::pos[k]].pb((node){i,b+1,r});
			owo[l/B+1].pb(mp(i,k));
			owo[r/B].pb(mp(-i,k));
		}
	}
	rep(i,0,n/B){
		for(auto x:owo[i])
			if(x.fi<0)blk.erase(mp(-x.fi,x.se));
			else blk.insert(x);
		AC::doit(i,i*B,(i+1)*B-1);
	}
	AC::solve();
	rep(i,1,Q) printf("%lld\n",ans[i]);
	return 0;
}