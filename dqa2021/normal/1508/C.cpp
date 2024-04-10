#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
vector<int> e[200010];

struct D{
	int uu,vv,u,v,w;
}d[200010];

set<int> st;
bool vis[200010];
int c[200010];

void dfs0(int x,int col){
	c[x]=col;
	for (int y: e[x]) st.erase(y);
	vector<int> S;
	for (auto it: st) vis[it]=1,S.pb(it);
	st.clear();
	for (int y: e[x]) if (!vis[y]) st.insert(y);
	for (int y: S) dfs0(y,col);
}

int fat[200010];
int find(int x){
	return fat[x]?fat[x]=find(fat[x]):x;
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if (x^y) return fat[y]=x,1;
	return 0;
}

bool mrk[200010];

void solve(){
	n=read(),m=read();
	int msk=0;
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
		d[i]=(D){u,v,u,v,read()};
		msk^=d[i].w;
	}
	rep(i,1,n) st.insert(i);
	int q=0;
	rep(i,1,n) if (!vis[i]) vis[i]=1,st.erase(i),dfs0(i,++q);
	ll ans=0;
	rep(i,1,m) d[i].u=c[d[i].u],d[i].v=c[d[i].v];
	sort(d+1,d+m+1,[&](const D &x,const D &y){
		return x.w<y.w;
	});
	rep(i,1,m){
		if (merge(d[i].u,d[i].v)) ans+=d[i].w,mrk[i]=1;
	}
	if (1LL*n*(n-1)/2-m>n-q){
		printf("%lld\n",ans);
		return;
	}
	int z=msk;
	memset(fat,0,sizeof fat);
	rep(i,1,m) if (mrk[i]) merge(d[i].uu,d[i].vv);
	rep(i,1,m) if (find(d[i].uu)!=find(d[i].vv)) z=min(z,d[i].w);
	printf("%lld\n",ans+z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}