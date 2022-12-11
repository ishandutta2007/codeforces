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
const ll INF=1e17;

int n; ll K;
ll pre[100010],suf[100010];

vector<int> e[100010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

const int X=1<<18;
ll ta[X],tb[X],mb[X],mc[X],md[X],mdr[X];

inline void pushdown(int x){
	const int L=ls,R=rs;
	if (ta[x]){
		ta[L]+=ta[x];
		mc[L]+=ta[x];
		md[L]+=ta[x];
		mdr[L]+=ta[x];
		ta[R]+=ta[x];
		mc[R]+=ta[x];
		md[R]+=ta[x];
		mdr[R]+=ta[x];
		ta[x]=0;
	}
	if (tb[x]){
		tb[L]+=tb[x];
		mb[L]+=tb[x];
		mc[L]+=tb[x];
		tb[R]+=tb[x];
		mb[R]+=tb[x];
		mc[R]+=tb[x];
		tb[x]=0;
	}
}

inline ll pushup(int x,int l,int r,const ll mx){
	if (mx<=mb[x]) return mc[x]-mx;
	if (l==r) return mc[x]-mx;
	pushdown(x);
	const int L=ls,R=rs;
	if (mx<=mb[L]) return min(mc[L]-mx,pushup(R,mid+1,r,mx));
	return min(pushup(L,l,mid,mx),mdr[x]);
}

inline void pushup(int x,int l,int r){  // pushdowned
	const int L=ls,R=rs;
	mb[x]=min(mb[L],mb[R]);
	mc[x]=min(mc[L],mc[R]);
	md[x]=min(md[L],mdr[x]=pushup(R,mid+1,r,mb[L]));
}

void build(int x,int l,int r){
	if (l==r) return mb[x]=mc[x]=suf[l],md[x]=mc[x]-INF,void();
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x,l,r);
}

void add(int x,int l,int r,int ql,int qr,const ll v,const int o){
	if (ql<=l&&r<=qr){
		if (o==1) ta[x]+=v,mc[x]+=v,md[x]+=v,mdr[x]+=v;  // constant
		else tb[x]+=v,mb[x]+=v,mc[x]+=v;  // variable
		return;
	}
	pushdown(x);
	if (ql<=mid) add(ls,l,mid,ql,qr,v,o);
	if (mid<qr) add(rs,mid+1,r,ql,qr,v,o);
	pushup(x,l,r);
}

int query(int x,int l,int r,int p,const ll lim,const ll mx){
	//printf("  query %d  %d %d  %d  %lld %lld\n",x,l,r,p,lim,mx);
	if (p>=r){
		const ll A=pushup(x,l,r,mx);
		if (A>lim) return -1;
		if (l==r) return l;
		/*pushdown(x);
		const ll B=pushup(rs,mid+1,r,mx);
		if (B<=lim) return query(rs,mid+1,r,p,lim,mx);*/
	}
	pushdown(x);
	if (p<=mid) return query(ls,l,mid,p,lim,mx);
	const int t=query(rs,mid+1,r,p,lim,min(mx,mb[ls]));
	return ~t?t:query(ls,l,mid,p,lim,mx);
}

#undef mid
#undef ls
#undef rs

int stk[100010],top;
ll S[100010];
int ans;

void dfs(int x){
	//printf("dfs %d: ",x);
	//rep(i,1,top) printf("%d ",stk[i]); puts("");
	
	stk[++top]=x;
	
	int lim=top;
	per(i,0,16) if (lim>(1<<i)&&S[top-1]-S[lim-(1<<i)-1]<=K) lim-=1<<i;
	lim=stk[lim-1]-1;
	
	//printf("  lim %d\n",lim);
	
	if (x>1) add(1,1,n,1,x-1,INF,1),add(1,1,n,1,x-1,INF,2);
	const int y=query(1,1,n,lim,K,INF);
	if (x>1) add(1,1,n,1,x-1,-INF,1),add(1,1,n,1,x-1,-INF,2);
	assert(~y&&y>=x);
	//printf("  dfs x %d y %d\n",x,y);
	ans=max(ans,y-x+1);
	
	for (const int &v: e[x]){
		const ll &V=pre[v]-pre[x];
		S[top]=S[top-1]+V;
		add(1,1,n,x,n,V,1);
		if (x-1>1){
			add(1,1,n,1,x-2,V,2);
			add(1,1,n,x-1,x-1,V,1);
		}
		dfs(v);
		add(1,1,n,x,n,-V,1);
		if (x-1>1){
			add(1,1,n,1,x-2,-V,2);
			add(1,1,n,x-1,x-1,-V,1);
		}
	}
	
	--top;
}

void solve(){
	n=read(),K=read();
	static int w[100010],g[100010];
	rep(i,1,n-1) w[i]=read();
	rep(i,1,n) g[i]=read();
	rep(i,2,n) pre[i]=pre[i-1]+g[i-1]-w[i-1];
	per(i,1,n-1) suf[i]=suf[i+1]+g[i+1]-w[i];
	
	per(i,1,n){
		while (top&&pre[stk[top]]>=pre[i]) --top;
		if (top) e[stk[top]].pb(i);
		else e[n+1].pb(i);
		stk[++top]=i;
	}
	
	build(1,1,n);
	top=0; stk[top]=n+1;
	for (const int &v: e[n+1]) dfs(v);
	
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}