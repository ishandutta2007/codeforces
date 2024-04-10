#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define NO puts("NO"),exit(0)
#define forall(x,y) for (const int &y: e[x])

int n,p[300010];
vector<int> e[300010];

int id[300010],dep[300010],fat[300010];
void dfs0(int x,int d){
	dep[x]=d; id[x]=++*id;
	sort(all(e[x]),[&](const int &x,const int &y){return p[x]<p[y];});
	forall(x,y) dfs0(y,d+1);
}

int q[300010];

int stk[300010],top;
int que[300010],hd,tl;

void dfs1(int x){
	static int cnt;
	que[++tl]=id[x];
	stk[++top]=x;
	forall(x,y) dfs1(y);
	++cnt; if (cnt>=p[1]) return;
	if (cnt==p[1]-1){
		int z=-1;
		rep(i,1,n) if (p[i]==cnt){z=dep[i];break;}
		assert(~z);
		if (z>tl-hd) NO;
		rep(i,1,z-1) q[stk[i]]=que[hd+i+1];
		q[stk[z]]=que[hd+1];
		rep(i,z+1,top) q[stk[i]]=que[hd+i];
		return;
	}
	q[stk[top--]]=que[++hd];
}

void solve(){
	n=read();
	rep(i,1,n) p[i]=read();
	const int o=p[1];
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v); fat[v]=u;
	}
	dfs0(1,1);
	if (p[1]==1){
		rep(i,1,n) if (p[i]^id[i]) NO;
		puts("YES\n0");
		rep(i,1,n) printf("%d ",id[i]);
		puts(""); return;
	}
	ll ans=0;
	rep(i,1,n) if (p[i]<o){
		ans+=dep[i]-1;
	}
	rep(i,1,n) q[i]=id[i];
	dfs1(1);
	rep(i,1,n) if (p[i]^q[i]) NO;
	printf("YES\n%lld\n",ans);
	rep(i,1,n) printf("%d ",id[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}