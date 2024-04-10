#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
VI e[N];
int q[N],hs[N],hv[N],dep[N],id[N],l[N],r[N],bel[N],s[N],f[N],tot;
ll ret[N],ret2[N];
int n,m,Q,C,fla[N],c[N],ty,u,w,W;
void dfs(int u,int f) {
	id[l[u]=++tot]=u;
	dep[u]=dep[f]+1;
	if (hv[u]) dfs(hv[u],u);
	rep(j,0,SZ(e[u])) if (e[u][j]!=f&&e[u][j]!=hv[u])
		dfs(e[u][j],u);
	r[u]=tot;
}
void HLDoT(int rt) {
	int t=1;
	q[0]=rt;
	rep(i,0,n) {
		int u=q[i];
		rep(j,0,SZ(e[u])) if (e[u][j]!=f[u])
			f[e[u][j]]=u,dep[q[t++]=e[u][j]]=dep[u]+1;
	}
	per(i,0,n) {
		int u=q[i],p=f[u];
		s[u]++,s[p]+=s[u];
		if (!l[u]) l[u]=1;
		if (hs[p]<s[u]) hs[p]=s[u],hv[p]=u,l[p]=l[u]+1;
	}
	rep(i,0,n) {
		int u=q[i];
		if (!bel[u]) bel[u]=u;
		if (hv[u]) bel[hv[u]]=bel[u];
	}
	dfs(rt,0);
}

const int M=20100000;
struct node {
	node *l,*r;
	int d;
	ll s;
}pool[M],*cur=pool,*rt[N];

node* newnode() {
	node *p=cur++; p->l=p->r=0; p->d=0;
	return p;
}
void modify(node *p,int l,int r,int pl,int pr,int v,int d) {
	if (l==pl&&r==pr) {
//		printf("ff %d %d %lld %lld\n",l,r,p->s,2ll*d*(p->s+(ll)v*(r-l+1)));
		ret2[W]+=2ll*d*(p->s+(ll)v*(r-l+1));
		p->s+=(ll)(pr-pl+1)*d;
		p->d+=d;
	} else {
		p->s+=(ll)(pr-pl+1)*d;
		v+=p->d;
		int md=(l+r)>>1;
		if (pl<=md) {
			if (!p->l) p->l=newnode();
			modify(p->l,l,md,pl,min(pr,md),v,d);
		}
		if (pr>md) {
			if (!p->r) p->r=newnode();
			modify(p->r,md+1,r,max(md+1,pl),pr,v,d);
		}
	}
}

void add(int u,int val) {
	int w=fla[u];
	while (u) {
		W=w;
		modify(rt[w],1,n,l[bel[u]],l[u],0,val);
		ret2[W]+=l[u]-l[bel[u]]+1;
		ret[W]+=val*(l[u]-l[bel[u]]+1);
		u=f[bel[u]];
	}
}
void build() {
	cur=pool;
	rep(i,1,m+1) rt[i]=newnode(),ret[i]=ret2[i]=0;
	rep(i,1,n+1) add(i,1);
}
int main() {
	scanf("%d%d%d%d",&n,&m,&Q,&C);
	rep(i,1,n+1) scanf("%d",fla+i);
	rep(i,2,n+1) {
		scanf("%d",f+i);
		e[f[i]].pb(i);
	}
	HLDoT(1);
	build();
	rep(i,1,m+1) scanf("%d",c+i);
//	rep(i,1,m+1) printf("%d %lld %lld\n",i,ret[i],ret2[i]);
	rep(i,0,Q) {
		scanf("%d%d",&ty,&u);
		if (ty==1) {
			scanf("%d",&w);
			add(u,-1);
			fla[u]=w;
			add(u,1);
		} else {
			printf("%.10f\n",(1.*ret2[u]*c[u]*c[u]-2.*ret[u]*c[u]*C+1.*C*C*n)/n);
		}
		if (cur-pool>=M-2000) build();
//		rep(i,1,m+1) printf("%d %lld %lld\n",i,ret[i],ret2[i]);
	}
}