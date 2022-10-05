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
	if(f)x=-x;
}

const int N=1e5+5,inf=1e5;
struct L{
	ll k,b;
	L(ll _k=0,ll _b=1e18){k=_k,b=_b;}
	ll operator () (ll x){return k*x+b;}
};
struct seg{
	L x; seg *lc,*rc;
	seg():x(){lc=rc=0;};
	void add(L y,ll l=-inf,ll r=inf){
		ll m=(l+r)/2;
		if(y(m)<x(m)) swap(x,y);
		if(x(l)>y(l)){
			if(!lc) lc=new seg;
			lc->add(y,l,m);
		}
		else if(x(r)>y(r)){
			if(!rc) rc=new seg;
			rc->add(y,m+1,r);
		}
	}
	ll qry(ll k,ll l=-inf,ll r=inf){
		ll res=x(k),m=(l+r)/2;
		if(k<=m&&lc) res=min(res,lc->qry(k,l,m));
		if(k>m&&rc) res=min(res,rc->qry(k,m+1,r));
		return res;
	}
}*s[N];

void merge(seg* &u,seg *v,ll l=-inf,ll r=inf){
	if(!v||!u){
		if(!u) u=v;
		return;
	}
	ll m=(l+r)/2;
	u->add(v->x,l,r);
	merge(u->lc,v->lc,l,m);
	merge(u->rc,v->rc,m+1,r);
}

int a[N],b[N],n,x,y;
vi e[N]; ll f[N];

void dfs(int u,int fa){
	if(fa&&e[u].size()==1){
		f[u]=0,s[u]=new seg;
		s[u]->add(L(b[u],0));
		return;
	}
	s[u]=new seg;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		merge(s[u],s[v]);
	}
	f[u]=s[u]->qry(a[u]);
	s[u]->add(L(b[u],f[u]));
}

int main(){
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	rep(i,1,n-1){
		read(x),read(y);
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0);
	rep(i,1,n) printf("%lld ",f[i]);
	puts("");
	return 0;
}